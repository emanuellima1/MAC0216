#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html */

Lista lista_cria () {
  Lista l; // Lista vazia: aponta para NULL
  l = malloc (sizeof(Elo));
  l->next = NULL;
  return l;
}

void lista_destroi (Lista l) {
  Elo *p_elo, *tmp = l;

  for (p_elo = l->next; p_elo != NULL; p_elo = p_elo -> next) {
    free(tmp);
    tmp = p_elo;
  }
  free(tmp);
}

Lista lista_insere (Lista l, Elemento val) {
  Elo *p_elo = l;

  while (p_elo->next != NULL) {
    p_elo = p_elo->next;
  }
  p_elo->next = malloc (sizeof(Elo));
  (p_elo->next)->next = NULL;
  (p_elo->next)->val = val;
  
  return p_elo->next;
}

Elemento lista_busca (Lista l, char *n) {
  Elo *p = l->next;
  
  while (p != NULL && compara_str((p->val)->n, n) == 0) {
    p = p->next;
  }
  
  if (p == NULL) {
    return NULL;
  }
  return p->val;
}

void lista_retira (Lista l, Elemento val) {
  Elo *p1 = l, *p2 = l->next;
  while (p2 != NULL && p2->val != val) {
    p1 = p2;
    p2 = p2 -> next;
  }

  if (p2 != NULL) {
    p1->next = p2->next;
  }
}

int compara_str(char *n, char *m) {
  int i;
  for (i = 0; n[i] != 0 && m[i] != 0; i++)
    if (n[i] != m[i])
      return 0;
  if (n[i] != m[i])
    return 0;
  return 1;
}
