#include <stdlib.h>
#include "elemento.h"

Elemento elemento_cria(char * n) {
  Elemento el;
  int i;

  el = malloc(sizeof(elemento));
  el -> n = malloc(NAME_SIZE * sizeof(char));
  for (i = 0; i < NAME_SIZE; i++)
    el -> n[i] = n[i];

  return el;
}

void elemento_destroi(Elemento el)
{
  free(el -> n);
  free(el);
}
