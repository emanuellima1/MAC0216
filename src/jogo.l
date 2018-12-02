%{

#include "../lib/comandos.h"
#include "jogo.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/* Redefinição da entrada do Flex para usar o readline */
#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);

/* Função que substitui a entrada */
static int mygetinput(char *buf, int size) {
  char *line;
  /* final de arquivo */
  if (feof(yyin))
    return YY_NULL;

  /* Lê uma linha, com o prompt "> " */
  line = readline("--> ");
  if(!line)
    return YY_NULL;

  /* segurança */
  if(strlen(line) > size-2) {
    fprintf(stderr,"input line too long\n");
    return YY_NULL;
  }

  /* copia para o buffer de enrtada */
  sprintf(buf,"%s\n",line);
  /* adiciona ao histórico */
  add_history(line);

  /* libera memória */
  free(line);
  return strlen(buf);
}   

%}

%option caseless
%option nounput
%option noinput

%%

(fim|chega|sair|quit)             {return SAIR;}
<<EOF>>                           {return SAIR;}
i(nvent(a|á|Á)rio)?               {return INVENTARIO;}

    /* Ignora artigos, espaços e preposições seguidos de palavras */

[ \t]+
[ao]|uma?|seu|sua


    /* Isso vai ter que alterar! porque ele quer um adjetivo */
    /* (ver segunda bolinha do ponto 5.2) */
(d[oae]|em|n[ao]|para)[ \t]+[[:alnum:]]+


[a-zA-Z_]+ {
  yylval.s = malloc(sizeof(yytext));
  strcpy(yylval.s, yytext);
  return OBJ;
}

[\n;]                              {return EOL;}


%%

int yywrap () {
return 1;
}
