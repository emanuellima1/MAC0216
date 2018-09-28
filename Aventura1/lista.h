#include "elemento.h"

/* conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html 
 * Fazemos de acordo com PF, que diz que uma lista é simplesmente um ponteiro
 * para um elo.
 */

typedef struct elo {
  struct elo *next;
  Elemento val;
  char *chave;
} Elo;

typedef Elo *Lista;

Lista lista_cria ();

void lista_destroi (Lista l);

Lista lista_insere (Lista l, Elemento val, char *chave);

/* Essa função devolve Lista pois Lista é um ponteiro para Elo. Portanto,
 * ela devolve o ponteiro para o elo do elemento que acabamos de inserir */

Elemento lista_busca (Lista l, char *n);
// Deve retornar NULL caso o elemento não seja encontrado. 

void lista_retira (Lista l, char *chave);
// remove o elemento *val da tabela, sem removê-lo da memória.

int compara_str(char *n, char *m);
// Devolve 1 se as strings são iguais, 0 caso contrário.
