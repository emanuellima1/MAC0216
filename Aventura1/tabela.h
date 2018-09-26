#include "elemento.h"
#include "lista.h"

Tabela tabela_cria (int tam);

void tabela_destroi (Tabela t);

int tabela_insere (Tabela t, char *n, Elemento val);

Elemento tabela_busca (Tabela t, char *n);

int tabela_retira (Tabela t, char *n);

typedef struct {
  Lista *v;
  int tam;
} tabela;

typedef tabela *Tabela;
