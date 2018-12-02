%{
#include <stdio.h>
#include <stdlib.h>
#include "../lib/comandos.h"
int yylex();
void yyerror(Tabela, Tabela_f, Elemento, Elemento *, int *, char *s);
%}

%parse-param {Tabela tab_jogo} {Tabela_f tab_f_jogo} {Elemento jogador} {Elemento * pos_atual} {int * acabei_de_chegar}

/* Ver: https://www.gnu.org/software/bison/manual/html_node/Parser-Function.html */
/* Agora podemos chamar, na função main,
   yyparse(tab_jogo, tab_f_jogo, pos_atual, jogador)
*/


%union {
  char *s;
}

%token <s> OBJ
%token SAIR INVENTARIO EOL


%%

input   : EOL                     {printf("tô perando\n");}
        | cmd               
        | SAIR                    {printf("saindo\n"); exit(0);}
        | INVENTARIO              {inventario(jogador, NULL, NULL);} eol
        | input cmd               
        | input SAIR                    {printf("saindo\n"); exit(0);}
        | input INVENTARIO              {inventario(jogador, NULL, NULL);} eol
        ;


cmd     : OBJ {
  
  p_comando f = (p_comando)tabela_f_busca(tab_f_jogo, $1);
  if (f != NULL)
    f(NULL, NULL, NULL);
  else
    printf("Acho que não sei %s\n", $1);
} eol

        | OBJ OBJ {

  p_comando f = (p_comando)tabela_f_busca(tab_f_jogo, $1);
  Elemento nova_sala, e = tabela_busca(tab_jogo, $2);

  if (f != NULL) {
    if (e != NULL) {
      if (f == pegar || f == deixar || f == ir_para)
        nova_sala = f(e, jogador, *pos_atual);
      else
        nova_sala = f(e, NULL, NULL);
      
      if (nova_sala != NULL) {
        *pos_atual = nova_sala;
        *acabei_de_chegar = 1;
      }
    }
    else { 
      if (f == ir_para)
        printf("Ir aonde?\n");
      else
        printf("%s o que?\n", $1);
    }
  }
  else
    printf("Acho que não sei %s\n", $1);
  
} eol

        | OBJ OBJ OBJ {

  p_comando f = (p_comando)tabela_f_busca(tab_f_jogo, $1);
  Elemento e1 = tabela_busca(tab_jogo, $2);
  Elemento e2 = tabela_busca(tab_jogo, $3);

  if (f == NULL)
    printf("Acho que não sei %s\n", $1);
  
  else if (f == pegar || f == deixar || f == ir_para)
     printf("Não sei %s essas coisas\n", $1);
  else
    f(e1, e2, NULL);
  
 } eol
        | error 

;

eol: EOL {return 1;}

%%

void yyerror (Tabela t, Tabela_f t_f, Elemento e1, Elemento * e2,
              int *i, char *s)
{
  fprintf(stderr, "Não entendi...\n");
}
