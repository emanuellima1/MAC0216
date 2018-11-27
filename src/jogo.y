%{
#include <stdio.h>
#include "elemento.h"

int yylex();
int yyerror(char *);
%}


%parse-param {Tabela tab_jogo} {Tabela_f tab_f_jogo} {Elemento jogador} {Elemento pos_atual} 
/* Ver: https://www.gnu.org/software/bison/manual/html_node/Parser-Function.html */
/* Agora podemos chamar, na função main, yyparse(tab_jogo, tab_f_jogo, pos_atual, jogador) */


%union {
  char *s;
}

%token <s> VERBO ELEMENTO
%token SAIR INVENTARIO EOL

%%


input  : EOL                {printf("Tô perando...\n");}
       | INVENTARIO EOL     {inventario(jogador, NULL, NULL)}
       | SAIR EOL           {printf("Saindo...\n"); return 0;} 
       | cmd EOL

cmd    : VERBO EOL {

  f = tabela_f_busca(tab_f_jogo, $1);
  if (f != NULL)
    return (f(NULL, NULL, NULL));
  printf("Acho que não sei %s", $1);
  return (NULL);
}

       | VERBO ELEMENTO EOL {

  f = tabela_f_busca(tab_f_jogo, $1);
  e = tabela_busca(tab_jogo, $1);

  if (f == NULL) {
    printf("Acho que não sei %s\n", $1);
    return (NULL);
  }
  if (f == pegar || f == deixar || f == ir_para)
    return (s (e1, jogador, pos_atual));
  return (s (e1, NULL, NULL));
}

      | VERBO ELEMENTO ELEMENTO EOL {

  f = tabela_f_busca(tab_f_jogo, $1);
  e1 = tabela_busca(tab_jogo, $2);
  e2 = tabela_busca(tab_jogo, $3);

  if (f == NULL) {
    printf("Acho que não sei %s\n", $1);
    return (NULL);
  }
  if (f == pegar || f == deixar || f == ir_para) {
     printf("Não sei %s essas coisas\n", $1);
     return (NULL);
  }
  return (s (e1, e2, NULL));
}