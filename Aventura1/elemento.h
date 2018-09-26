/* Ver seção 2.1 do roteiro para descrição detalhada dos elementos.
 * Optamos por definir um tipo Elemento, com 'E' maiúsculo, que é um
 * ponteiro para um elemento, com 'e' minúsculo.
 */

#define TAM_NOME 80

typedef struct{
  char *n;
} elemento;

typedef elemento *Elemento;

Elemento elemento_cria (char *n);
void elemento_destroi (Elemento el);
