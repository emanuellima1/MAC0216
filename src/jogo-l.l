%{

#include "../lib/comandos.h"
#include "jogo-y.h"
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

(a[jc]ud[ae]|help)                {return AJUDA;}
(fim|chega|sair|quit)             {return SAIR;}
<<EOF>>                           {return SAIR;}
i(nvent(a|á|Á)rio)?               {return INVENTARIO;}

(n|N|Norte|NORTE)                 {return NORTE;}
(s|S|Sul|SUL)                     {return SUL;}
(l|L|Leste|LESTE)                 {return LESTE;}
(w|W|Oeste|OESTE)              {return OESTE;} 





    /* Ignora artigos, espaços e preposições seguidos de palavras */

[ \t]+
[ao]s?|uma?|seu|sua|para|pr[oa]
(d[oae]s?|em|n[ao])[ \t]+[a-zA-Z_áéíóúÁÉÍÓÚçÇàÀ]+    


  /* Casos especiais */

sala[ \t]+(d[eoa]s?)?[ \t]+(m(a|á)quinas?) {
  yylval.s = "maquinas";
  return OBJ;
} 
sala[ \t]+(d[eoa]s?)?[ \t]+(servidor(es)?) {
  yylval.s = "servidores";
  return OBJ;
} 
sala[ \t]+(d[eoa]s?)?[ \t]+(pesquisa(dor)?([ea]s)?) {
  yylval.s = "pesquisadores";
  return OBJ;
} 
sala[ \t]+(d[eoa]s?)?[ \t]+(alunos?)?[ \t]*(d[eoa]s?)?[ \t]*(i|I)?(c|C)? {
  yylval.s = "ic";
  return OBJ;
} 
notebook[ \t]do[ \t]pedro {
  yylval.s = "pedro";
  return OBJ;
}
notebook[ ]da[ ]alice {
  yylval.s = "alice";
  return OBJ;
}

[a-zA-Z_áéíóúÁÉÍÓÚçÇàÀêÊôÔãÃõÕ]+ {
  yylval.s = malloc(sizeof(yytext));
  strcpy(yylval.s, yytext);
  return OBJ;
}

[;\n]                              {return EOL;}
.

%%

int yywrap () {
return 1;
}
