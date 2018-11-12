#include "tabela.h"

/* Ver seção 2.1 do roteiro para descrição detalhada dos elementos.
 * Optamos por definir um tipo Elemento, com 'E' maiúsculo, que é um
 * ponteiro para um elemento, com 'e' minúsculo.
 */

#define TAM_NOME 80

typedef struct{
  char *nome; // Nome padrão
  char *artigo; // Qual artigo é para ser usado com o nome
  char *curta; // Descrição curta do Elemento
  char *longa; // Descrição detalhada do elemento
  char *artigo; // Indica que artigo (o, um, ...) usa-se com esse elemento
  short int ativo; // Booleano que indica se o elemento está ativo no jogo
  short int visivel; // Booleano que indica se o elemento está visível
  short int conhecido; // Indica se o elemento já é conhecido do jogador
  Lista conteudo; // Lista de objetos contidos no elemento
  Lista acoes; // Lista de funções especiais para este elemento.
  int (*animacao)();
  // Ponteiro para função que será chamada ao final de cada iteração.
  union {
    Lista atributos; // Campo para objetos
    Lista saidas; // Campo para lugares (por padrão, N, S, L, O)
  } detalhe;
} elemento;

typedef elemento *Elemento;


/* A seguinte função cria um elemento, lhe atribuindo um nome
 * e inicializando o resto dos campos como NULL ou 0;*/
Elemento elemento_cria (char *nome); 

void elemento_destroi (Elemento el);