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

int tabela_insere (Tabela T, char *n, void *val);
// Devolve 1 se o elemento foi inserido com sucesso, 0 caso contrário

Elemento tabela_busca (Tabela T, char *n);
// Devolve NULL caso a busca não tenha sucesso

int tabela_retira (Tabela T, char *n);
// Devolve 1 se o elemento foi retirado com sucesso, 0 caso contrário.
