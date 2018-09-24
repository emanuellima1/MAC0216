#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

TabSim tabela_cria(int max)
{
  int i;
  Tabela T = malloc(sizeof(tabela));
  T -> v = malloc(tam * sizeof(Lista));
  T -> max = max;
  for (i = 0; i < tam; i ++)
    T -> v[i] = NULL;
  return T;
}

void tabela_destroi(Tabela T)
{
  free(T -> v);
  free(T);
}

int tabela_insere(Tabela T, char *n, Elemento val)
{
  int i = tabela_hash(n, T -> max);
  
  // Checa se o Elemento é repetido
  if (lista_busca(T -> v[i], val) == NULL) {
    lista_insere(T -> v[i], val);
    return 1;
  }
  return 0;
}

Elemento tabela_busca(Tabela T, char *n)
{
  int i = tabela_hash(n, T -> max);
  return (lista_busca(T -> v[i]));
}

int tabela_hash(char *n, int max)
{
  unsigned long h = 5831;
  int i;
  for(i = 0; n[i] != '\0'; i++)
    h = (h * 33) ^ n[i];
  return (h % max);
}
