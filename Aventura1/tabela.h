#include "lista.h"

#define SUCESSO 1
#define FALHA 0

typedef struct {
  Lista *v;
  int tam;
} tabela;

typedef tabela *Tabela;

Tabela tabela_cria (int tam);

void tabela_destroi (Tabela T);

int tabela_insere (Tabela T, char *n, Elemento val);

Elemento tabela_busca (Tabela T, char *n);

int tabela_retira (Tabela T, char *n);
