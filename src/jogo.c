#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM_TABELA 50

Elemento inicializa_elementos (Tabela tab);

int main () {

  Lista l;
  Tabela tab_jogo = tabela_cria(TAM_TABELA);
  Elemento lugar, el;
  lugar = inicializa_elementos(tab_jogo);
  char *c;

  char introducao[] = "Você está na sala de IC e de repente um monte de coisa ruim acontece. O que você quer fazer? (isso é a introdução do jogo!)\n";
  printf("%s", introducao);

  /* Laço principal*/
  while (1) {

    /* Apresenta o local */
    printf("\n%s\n\n", lugar->nome); 
    if (lugar -> conhecido)
      printf("%s", lugar->curta);
    else
      printf("%s", lugar->longa);

    /* Relaciona o conteúdo visível */
    if (!lista_vazia (lugar->conteudo)) {
      printf("Aqui você ve: ");
      l = lugar->conteudo;
      l = l->next;
      while (l != NULL) {
        el = l->val;
        if (el->visivel)
          printf("%s, %s, ", el->artigo, el->nome);
        l = l->next;
      }
    }
    scanf("%s", c);
  }
}

Elemento inicializa_elementos (Tabela tab) {
  /* Devolve o elemento que é o lugar atual do aventureiro */
  /* Essa função liga as salas e coloca os objetos em seus lugares */

  Elemento el;

  /* Inicializa aventureiro */
  el = elemento_cria("Você");
  el->artigo = "";
  el->curta = "Voce é jovem e feio.\n";
  el->longa = "Voce é um estudante de ciência da computação, que faz iniciação científica em Inteligência Artificial. Teve uma infância feliz e superprotegida, mas uma adolescência solitária por ser muito tímido. Você nunca se achou particularmente bonito, atlético ou popular, mas sempre pôde contar com sua própria inteligência. Isso te fez achar que nada mais importava e que a razão irá resolver todos os problemas do planeta.\n Mas seres humanos são falhos. São emotivos. São irracionais.\n Você, então, pôs em si próprio a missão de criar uma máquina de raciocínio perfeito. Racional, justa e infalível. E está obcecado com a ideia.\n";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  tabela_insere(tab, "Você", el);


  /* Inicializa salas */
  el = elemento_cria("A sala de IC");
  el->artigo = "";
  el->curta = "A sala de iniciação científica é grande, tem alguns computadores e uma mesa, onde você sempre trabalha.\n";
  el->longa = "A sala de iniciação científica é grande. À sua esquerda, vê-se três computadores, um do adolfo, outro do rodrigo, seus colegas, e outro é um servidor. É gelado, por que o ar condicionado está sempre ligado. Tem uma porta que leva ao corredor, ao sul.\n";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, "A sala de IC", el);

  return(el);
}
