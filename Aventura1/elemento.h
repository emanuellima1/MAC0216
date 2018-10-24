/* Ver seção 2.1 do roteiro para descrição detalhada dos elementos.
 * Optamos por definir um tipo Elemento, com 'E' maiúsculo, que é um
 * ponteiro para um elemento, com 'e' minúsculo.
 */

#define TAM_NOME 80

typedef struct{
  char *n; // Nome padrão
  char *curta; // Descrição curta do Elemento
  char *longa; // Descrição detalhada do elemento
  short int ativo; // Booleano que indica se o elemento está ativo no jogo
  short int visivel; // Booleano que indica se o elemento está visível
  short int conhecido; // Indica se o elemento já é conhecido do jogador

} elemento;

typedef elemento *Elemento;

Elemento elemento_cria (char *n);
void elemento_destroi (Elemento el);
