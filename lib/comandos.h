/* Esse módulo implementa os comandos que o jogador pode usar  */

#include "elemento.h"

typedef Elemento (*p_comando)(Elemento e1, Elemento e2, Elemento e3);

/* e1 é o jogador, e2 é a sala nova e e3 é a sala velha. Devolve a nova sala */
Elemento ir_para(Elemento e1, Elemento e2, Elemento e3);

/* Imprime o inventário. e1 é o jogador*/
Elemento inventario(Elemento e1, Elemento e2, Elemento e3);

/* Examina e1 com e2. Se e2 tiver uma ação de examinar, executa ela.
   Se não, imprime que não consegue. Se e2 for NULL, descreve e1
*/
Elemento examinar(Elemento e1, Elemento e2, Elemento e3);

Elemento falar(Elemento e1, Elemento e2, Elemento e3);
Elemento perguntar(Elemento e1, Elemento e2, Elemento e3);
Elemento pegar(Elemento e1, Elemento e2, Elemento e3);

/* e1 é o objeto, e2 é o jogador e e3 é a sala */
Elemento abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento deixar(Elemento e1, Elemento e2, Elemento e3);
Elemento comer(Elemento e1, Elemento e2, Elemento e3);
Elemento beber(Elemento e1, Elemento e2, Elemento e3);



/* -------------------------------------------------------------------*/
/* -------------- Comandos específicos de elementos ------------------*/
/* -------------------------------------------------------------------*/

Elemento janela_abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento livros_abrir(Elemento e1, Elemento e2, Elemento e3);

Elemento seu_notebook_abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento notebook_do_pedro_abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento notebook_da_alice_abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento supercomputador_abrir(Elemento e1, Elemento e2, Elemento e3);

Elemento janela_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento livros_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento seu_notebook_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento notebook_do_pedro_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento notebook_da_alice_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento supercomputador_fechar(Elemento e1, Elemento e2, Elemento e3);
Elemento papeis_comer(Elemento e1, Elemento e2, Elemento e3);
Elemento xicara_comer(Elemento e1, Elemento e2, Elemento e3);
Elemento xicara_beber(Elemento e1, Elemento e2, Elemento e3);
