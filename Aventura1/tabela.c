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

void tabela_destroi (Tabela T) {
  free (T->v);
  free (T);
}

int tabela_insere(Tabela T, char *n, Elemento val) {
  int i = tabela_hash (n, T->tam);

  // Checa se o Elemento é repetido
  if (lista_busca (T->v[i], val) == NULL) {
    lista_insere(T->v[i], val);
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}

Elemento tabela_busca (Tabela T, char *n) {
  int i = tabela_hash(n, T->tam);
  return (lista_busca(T->v[i], n));
}

int tabela_hash (char *n, int tam) {
  unsigned long int h = 5831;
  for(int i = 0; n[i] != '\0'; i++)
    h = (h * 33) ^ n[i];
  return (h % tam);
}
