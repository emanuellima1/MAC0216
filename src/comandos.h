/* Esse módulo implementa os comandos que o jogador pode usar  */

#include "elemento.h"

typedef Elemento (*p_comando)(Elemento e1, Elemento e2, Elemento e3);

/* Comandos de percepção */
Elemento examinar(Elemento e1, Elemento e2, Elemento e3);

/* Comandos de interação humana */

Elemento falar(Elemento e1, Elemento e2, Elemento e3);
Elemento perguntar(Elemento e1, Elemento e2, Elemento e3);

/* Comandos de interação com objetos*/

Elemento pegar(Elemento e1, Elemento e2, Elemento e3);
Elemento abrir(Elemento e1, Elemento e2, Elemento e3);
Elemento fechar(Elemento e1, Elemento e2, Elemento e3);

Elemento deixar(Elemento e1, Elemento e2, Elemento e3);

Elemento comer(Elemento e1, Elemento e2, Elemento e3);
Elemento beber(Elemento e1, Elemento e2, Elemento e3);


