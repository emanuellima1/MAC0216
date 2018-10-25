#include <stdlib.h>
#include "elemento.h"

Elemento elemento_cria (char *n) {
  Elemento el;
  int i;

  el = malloc (sizeof(elemento));
  el->n = malloc (TAM_NOME * sizeof(char));
  for (i = 0; i < TAM_NOME; i++)
    el->n[i] = n[i];

  return el;
}

void elemento_destroi (Elemento el) {
  free(el->n);
  free(el);
}
