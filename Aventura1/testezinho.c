#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabela.h"


int main() {

  Elemento el1, el2, el3, el4;
    /* el5, el6; */
  el1 = elemento_cria("elemento 1!!!!");
  el2 = elemento_cria("elemento 2!! 2 mesmo!!!");
  el3 = elemento_cria("elemento 1 sqn! eh o 3!!!");


  Lista l = lista_cria();
  lista_insere(l, el1);
  lista_insere(l, el2);
  lista_insere(l, el3);

  printf("%s\n", ((l -> next) -> val) -> n);
  printf("%s\n", (((l -> next) -> next) -> val) -> n);
  printf("%s\n", ((((l -> next) -> next) -> next) -> val) -> n);

  /* el4 = lista_busca(l, "elemento 1!!!!"); */
  /* el4 = lista_busca(l, "elemento 2!! 2 mesmo!!!"); */
  el4 = lista_busca(l, "elemento 1 sqn! eh o 3!!!");
  printf("%s\n", el4 -> n);
}

