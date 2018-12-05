%{
#include <stdio.h>
#include <stdlib.h>
#include "../lib/comandos.h"
int yylex();
void yyerror(Tabela, Tabela_f, Elemento, Elemento *, int *, char *s);
 void rosa_dos_ventos(Elemento *, Elemento, int *, char);
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
%token SAIR INVENTARIO EOL AJUDA NORTE SUL LESTE OESTE

%%

input   : EOL                     {printf("Tô perando!\n");}
        | cmd               
        | SAIR                    {printf("\nSaindo...\n"); exit(0);}
        | INVENTARIO              {inventario(jogador, NULL, NULL);} eol
        | AJUDA                   {printf("Digite algum verbo que você queira fazer. Tente fazer referência às coisas que já foram descritas. Digite i para ver seu inventário. Digite ir para ir para outras sala.\n");} eol
        | input cmd               
        | input SAIR              {printf("\nSaindo...\n"); exit(0);}
        | input AJUDA             {printf("Digite algum verbo que você queira fazer. Tente fazer referência às coisas que já foram descritas. Digite i para ver seu inventário. Digite ir para ir para outra sala.\n");} eol
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
    if (e != NULL && e->conhecido) {
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
    printf("Acho que não sei fazer isso\n");
  else if (f == pegar || f == deixar || f == ir_para ||
           e1 == NULL || e2 == NULL || !(e1->conhecido) || !(e2->conhecido))
    printf("Não sei fazer isso com essas coisas\n");
  else
    f(e1, e2, NULL);
  
 } eol
        | dir
        | OBJ dir
        | error 
;

dir     : NORTE {rosa_dos_ventos(pos_atual, jogador, acabei_de_chegar, 'N');} eol
        | SUL   {rosa_dos_ventos(pos_atual, jogador, acabei_de_chegar, 'S');} eol
        | LESTE {rosa_dos_ventos(pos_atual, jogador, acabei_de_chegar, 'L');} eol
        | OESTE {

          if (*pos_atual == tabela_busca(tab_jogo, "Pátio")) {
            printf("Daqui do pátio tem três saídas a oeste: a sala dos alunos de IC, a sala dos pesquisadores e a sala de máquinas.\n");
          }
          else
            rosa_dos_ventos(pos_atual, jogador, acabei_de_chegar, 'O');
          } eol
        ;
          
eol: EOL {return 1;}

%%

void yyerror (Tabela t, Tabela_f t_f, Elemento e1, Elemento * e2,
              int *i, char *s)
{
  fprintf(stderr, "Não entendi...\n");
}

void rosa_dos_ventos(Elemento * pos_atual, Elemento jogador,
                     int * acabei_de_chegar, char dir)
{
  /* Elemento temp = *pos_atual; */
  /* printf("saidas da sala atual: \n\n"); */
  /* lista_imprime_chaves(temp->detalhe.saidas); */
  /* printf("\n"); */
  char *s = malloc(sizeof(char));
  *s = dir;


  Elemento nova_sala, e = lista_busca((*pos_atual)->detalhe.saidas, s);
  if (e == NULL) {
    printf("Essa sala não tem saída ");
    switch (dir) {
    case 'N': printf("ao norte.\n"); break;
    case 'S': printf("ao sul.\n"); break;
    case 'L': printf("a leste.\n"); break;
    case 'O': printf("a oeste.\n"); break;
    }
    return;
  }
  nova_sala = ir_para(e, jogador, *pos_atual);
  if (nova_sala != NULL) {
    *pos_atual = nova_sala;
    *acabei_de_chegar = 1;
  }
}

