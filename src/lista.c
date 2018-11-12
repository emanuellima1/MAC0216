#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html */

int compara_str(char *n, char *m) {
  int i;
  for (i = 0; n[i] != 0 && m[i] != 0; i++)
    if (n[i] != m[i])
      return 0;
  if (n[i] != m[i])
    return 0;
  return 1;
}

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

Lista lista_insere (Lista l, void *val, char *chave) {
  Elo *p_elo = l;

  while (p_elo->next != NULL) {
    p_elo = p_elo->next;
  }
  p_elo->next = malloc (sizeof(Elo));
  (p_elo->next)->next = NULL;
  (p_elo->next)->val = val;
  (p_elo->next)->chave = chave;
  
  return p_elo->next;
}

void * lista_busca(Lista l, char *n) {
  Elo *p = l->next;
  
  while (p != NULL && compara_str(p->chave, n) == 0) {
    p = p->next;
  }
  
  if (p == NULL) {
    return NULL;
  }
  /* printf("\nEu sou o lista_busca e eu achei o val %s associado à chave %s\n\n", ((Elemento)p->val)->n, n); */
  /* printf("Isso quer dizer que as strings \n%s\n%s \n são iguais\n", p->chave, n); */
  return p->val;
}

char * lista_busca_valor (Lista l, void *val) {
  Elo *p = l->next;
  
  while (p != NULL && val != p->val) {
    p = p->next;
  }
  
  if (p == NULL) {
    return NULL;
  }
  return p->chave;
}

void lista_retira (Lista l, char *chave) {
  Elo *p1 = l, *p2 = l->next;
  while (p2 != NULL && compara_str(p2->chave, chave) == 0) {
    p1 = p2;
    p2 = p2 -> next;
  }

  if (p2 != NULL) {
    p1->next = p2->next;
  }
}

void lista_imprime_chaves (Lista l) {
  
  Elo *p = l->next;
  while (p != NULL) {
    printf("%s ", p->chave);
    p = p->next;
  }

  printf("\n");
}

int lista_vazia (Lista l) {
  if (l->next == NULL)
    return 1;
  return 0;
}
