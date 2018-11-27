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

void * tabela_busca (Tabela T, char *n);
// Devolve NULL caso a busca não tenha sucesso

int tabela_retira (Tabela T, char *n);
// Devolve 1 se o elemento foi retirado com sucesso, 0 caso contrário.


/* TABELA DE PONTEIRO DE FUNÇÃO */
/* As funções abaixo impelementam uma biblioteca de tabela equivalente, mas para
   ponteiros de função
*/

typedef struct {
  Lista_f *v;
  int tam;
} tabela_f;

typedef tabela_f *Tabela_f;

Tabela_f tabela_cria (int tam);
void tabela_f_destroi (Tabela_f T);
int tabela_f_insere (Tabela_f T, char *n, void *val);
void * tabela_f_busca (Tabela_f T, char *n);
int tabela_f_retira (Tabela_f T, char *n);
