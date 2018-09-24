#include "elemento.h"
#include "lista.h"

Tabela tabela_cria(int tam);
void tabela_destroi(TabSim t);
int tabela_insere(TabSim t, char *n, Elemento val);
Elemento tabela_busca(TabSim t, char *n);
int tabela_retira(TabSim t, char, *n);

typedef struct {
  Lista *v;
  int tam;
} tabela;

typedef tabela * Tabela;
