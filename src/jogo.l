%{
#include "jogo.tab.h"
#include "elemento.h"
#include <readline/readline.h>
#include <readline/history.h>


/* Redefinição da entrada do Flex para usar o readline */
#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);

/* Função que substitui a entrada */
static int mygetinput(char *buf, int size) {
char *line;
/* final de arquivo */
if (feof(yyin))  return YY_NULL;

/* Lê uma linha, com o prompt "> " */
line = readline("--> ");
if(!line)        return YY_NULL;

/* segurança */
if(strlen(line) > size-2){
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

%%

(fim|chega|sair|quit)             {return SAIR;}
<<EOF>>                           {return SAIR;}
i(nvent(a|á|Á)rio)?               {return INVENTARIO;}

    /* Ignora artigos, espaços e preposições seguidos de palavras */

[ \t]+
[ao]|uma?                         

    /* Isso vai ter que alterar! porque ele quer um adjetivo */
    /* (ver segunda bolinha do ponto 5.2) */
(d[oae]|em|n[ao])[ \t]+[[:alnum:]]+


    /* Se for a primeira palavra, é verbo (pode ter espaço antes dela)*/
^[ \t]?[[:alnum:]]+               {yylval.s = yytext; return VERBO;}

    /* As demais palavras são objetos*/
[[:alnum:]]                       {yylval.s = yytext; return OBJETO;} 
[\n;]                             {return EOL;}


%%

int yywrap () {
return 1;
}
