#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

Tabela tabela_cria (int tam) {
  int i;
  Tabela T = malloc (sizeof(tabela));
  T->v = malloc (tam * sizeof(Lista));
  T->tam = tam;
  for (i = 0; i < tam; i++)
    T->v[i] = lista_cria ();
  return T;
}

int tabela_hash (char *n, int tam) {
  int h = 5831;
  for(int i = 0; n[i] != '\0'; i++)
    h = ((h * 33) ^ n[i]) % tam;
  return h;
}

void tabela_destroi (Tabela T) {
  int i;
  for (i = 0; i < T->tam; i++)
    lista_destroi(T->v[i]);
  free (T->v);
  free (T);
}

int tabela_insere(Tabela T, char *n, void * val) {
  int i;
  i = tabela_hash (n, T->tam);

  // Checa se o Elemento é repetido
  if (lista_busca(T->v[i], n) == NULL) {
    lista_insere(T->v[i], val, n);
    return SUCESSO;
  }
  return FALHA;
}

void * tabela_busca (Tabela T, char *n) {
  int i;
  
  if (n == NULL || n[0] == '\0')
    return NULL;

  i = tabela_hash(n, T->tam);
  return (lista_busca(T->v[i], n));
}

int tabela_retira (Tabela T, char *n) {
  int i;
  i = tabela_hash(n, T->tam);

  if (lista_busca(T->v[i], n) == NULL) {
    return FALHA;
  }

  lista_retira(T->v[i], n);
  return SUCESSO;
}



/* Funções para tabela de funções */

Tabela_f tabela_f_cria (int tam) {
  int i;
  Tabela_f T = malloc (sizeof(tabela_f));
  T->v = malloc (tam * sizeof(Lista_f));
  T->tam = tam;
  for (i = 0; i < tam; i++)
    T->v[i] = lista_f_cria ();
  return T;
}

void tabela_f_destroi (Tabela_f T) {
  int i;
  for (i = 0; i < T->tam; i++)
    lista_f_destroi(T->v[i]);
  free (T->v);
  free (T);
}

int tabela_f_insere(Tabela_f T, char *n, void * val) {
  int i;
  i = tabela_hash (n, T->tam);

  // Checa se o Elemento é repetido
  if (lista_f_busca(T->v[i], n) == NULL) {
    lista_f_insere(T->v[i], val, n);
    return SUCESSO;
  }
  return FALHA;
}

void * tabela_f_busca (Tabela_f T, char *n) {
  int i;
  
  if (n == NULL || n[0] == '\0')
    return NULL;

  i = tabela_hash(n, T->tam);
  return (lista_f_busca(T->v[i], n));
}

int tabela_f_retira (Tabela_f T, char *n) {
  int i;
  i = tabela_hash(n, T->tam);

  if (lista_f_busca(T->v[i], n) == NULL) {
    return FALHA;
  }

  lista_f_retira(T->v[i], n);
  return SUCESSO;
}
