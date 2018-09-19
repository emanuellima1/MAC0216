#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html */

Lista cria()
{
  Lista l = NULL; // Lista vazia: aponta para NULL
  return l;
}

void destroi(Lista l)
{

  Elo * p_elo, * tmp = l;

  for (p_elo = l -> next; p_elo != NULL; p_elo = p_elo -> next) {
    free(tmp);
    tmp = p_elo;
  }

  free(tmp);
  free(p_elo);
}

Lista insere(Lista l, Elemento val)
{
  Elo *p_elo;

  for (p_elo = l; p_elo != NULL; p_elo = p_elo -> next)
    continue;
  /* Iniciliza elo como l (ou seja, como ponteiro do primeiro elo) 
   * se não for NULL, soma 1 no índice e elo torna-se o
   * ponteiro do próximo elo */
  
  p_elo = malloc(sizeof(Elo));
  p_elo -> next = NULL;
  p_elo -> val = val;
  return p_elo;
}

Elemento busca(Lista l, char * n)
{
  Elo * p_elo = l;
  while (p_elo != NULL && (p_elo -> val) -> n != n)
    p_elo = p_elo -> next;
  
  return p_elo -> val;
}

void retira(Lista l, Elemento val)
{
  Elo * p1, * p2 = l;
  p2 = l;
  while (p2 != NULL && p2 -> val != val) {
    p1 = p2;
    p2 = p2 -> next;
  }

  if (p2 != NULL) {
    p1 -> next = p2 -> next;
  }
}
