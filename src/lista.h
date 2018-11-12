/* Essa biblioteca implementa uma lista ligada, em que cada elo tem
 * 3 campos: o ponteiro "next" para o próximo elo, um ponteiro void
 * "val" e uma string "chave" */


/* Conferir https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html 
 * Fizemos de acordo com PF, que diz que uma lista é simplesmente um ponteiro para um elo.
 */

typedef struct elo {
  struct elo *next;
  void *val;
  char *chave;
} Elo;

typedef Elo *Lista;

Lista lista_cria ();

void lista_destroi (Lista l);

Lista lista_insere (Lista l, void *val, char *chave);
/* Essa função devolve Lista pois Lista é um ponteiro para Elo. Portanto,
 * ela devolve o ponteiro para o elo do valor que acabamos de inserir */

void * lista_busca (Lista l, char *n);
/* Recebe uma chave e devolve o valor associada a ela*/
/* retorna NULL caso o valor não seja encontrado.  */

char * lista_busca_valor (Lista l, void *);
/* Recebe um valor e devolve a chave associada a ela */
/* retorna NULL caso o valor não seja encontrado.  */


void lista_retira (Lista l, char *chave);
/* remove o valor associado à chave dada da tabela, sem removê-lo da memória. */

int compara_str(char *n, char *m);
/* Devolve 1 se as strings são iguais, 0 caso contrário. */

void lista_imprime_chaves(Lista l);
/* Dada uma Lista l, imprime todas as suas chaves, na ordem em que estão */
