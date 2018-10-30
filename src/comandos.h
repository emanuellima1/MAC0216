/* Esse módulo implementa os comandos que o jogador pode usar  */

/* Comandos de percepção */
int (*examinar)(Elemento e1, Elemento e2);

/* Comandos de movimento */
int (*ir_para)(Elemento e1, NULL);

/* Comandos de interação humana */

int (*falar)(Elemento e1, NULL);
int (*perguntar)(Elemento e1, NULL);


/* Comandos de interação com objetos*/

int (*pegar)(Elemento e1, NULL);
int (*abrir)(Elemento e1, NULL);
int (*fechar)(Elemento e1, NULL);

int (*atirar)(Elemento e1, Elemento e2);
int (*deixar)(Elemento e1, NULL);

int (*comer)(Elemento e1, NULL);
int (*beber)(Elemento e1, NULL);


