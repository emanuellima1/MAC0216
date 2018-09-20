#include "elemento.h"

/* conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html 
 * Fazemos de acordo com PF, que diz que uma lista é simplesmente um ponteiro
 * para um elo */

struct elo {
  struct elo *next;
  Elemento val;
};

typedef struct elo Elo;
typedef Elo * Lista;


Lista lista_cria();
void lista_destroi(Lista l);
Lista lista_insere(Lista l, Elemento val);
// Lista insere(Lista l, Elemento *val) caso Elemento não seja ponteiro

/* Essa função devolve Lista pois Lista é um ponteiro para Elo. Portanto,
 * ela devolve o ponteiro para o elo do elemento que acabamos de inserir */

Elemento lista_busca(Lista l, char *n);
// Deve retornar NULL caso o elemento não seja encontrado. 

void lista_retira(Lista l, Elemento val);
// Elemento *retira(Lista l, Elemento *val) caso Elemento não seja ponteiro
// remove o elemento *val da tabela, sem removê-lo da memória.

