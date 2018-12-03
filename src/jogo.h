#include "../lib/comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 50
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

/* Inicializa todos os elementos do jogo e devolve o lugar de inicio */
Elemento inicializa_elementos (Tabela tab);

/* Inicializa todas as funções genéricas numa tabela */
void inicializa_funcoes (Tabela_f tab);

/* Percorre todos os elementos da tabela e em cada um, se houver,
   executa o campo animacao
*/
void animacoes_automaticas(Tabela tab, Elemento lugar_atual);

/* Recebe duas strings que são o nome de duas salas, e liga a saida
   uma na outra
*/
void liga_salas(Tabela tab, char * s1, char * s2, char dir1, char dir2);

/* Definições para flex */

int yyparse(Tabela, Tabela_f, Elemento, Elemento *, int *);
