#include <stdlib.h>
#include "elemento.h"

Elemento elemento_cria (char *nome) {
  Elemento el;
  int i;

  el = malloc (sizeof(elemento));
  el->nome = malloc (TAM_NOME * sizeof(char));
  for (i = 0; i < TAM_NOME; i++)
    el->nome[i] = nome[i];

  el->curta = NULL;
  el->longa = NULL;
  el->ativo = 0;
  el->visivel = 0;
  el->conhecido = 0;
  el->conteudo = lista_cria();
  el->acoes = lista_cria();
  el->animacao = NULL;
  el->detalhe.atributos = lista_cria();

  return el;
}

void elemento_destroi (Elemento el) {
  free(el->nome);
  free(el->curta);
  free(el->longa);
  lista_destroi(el->conteudo);
  lista_destroi(el->acoes);
  lista_destroi(el->detalhe.atributos);
  free(el);
}

