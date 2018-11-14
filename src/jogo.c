#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 50

Elemento inicializa_elementos (Tabela tab);

int main () {

  Lista l;
  Lista_f l_comandos = lista_f_cria();
  p_funcao_void p;
  p_comando q;
  Tabela tab_jogo = tabela_cria(TAM_TABELA);
  Elemento lugar, el, el_b, el_c, el_d;
  lugar = inicializa_elementos(tab_jogo);
  char a[100];
  char b[100];
  char c[100];
  char d[100];

  p = (p_funcao_void)examinar;
  lista_f_insere(l_comandos, p, "examinar");
  p = (p_funcao_void)falar;
  lista_f_insere(l_comandos, p, "falar");
  p = (p_funcao_void)perguntar;
  lista_f_insere(l_comandos, p, "perguntar");
  p = (p_funcao_void)pegar;
  lista_f_insere(l_comandos, p, "pegar");
  p = (p_funcao_void)abrir;
  lista_f_insere(l_comandos, p, "abrir");
  p = (p_funcao_void)fechar;
  lista_f_insere(l_comandos, p, "fechar");
  p = (p_funcao_void)deixar;
  lista_f_insere(l_comandos, p, "deixar");
  p = (p_funcao_void)beber;
  lista_f_insere(l_comandos, p, "beber");

  char introducao[] = "Você está na sala de IC e de repente um monte de coisa ruim acontece. O que você quer fazer? (isso é a introdução do jogo!)\n";
  printf("%s", introducao);

  /* Laço principal*/
  while (1) {

    /* Apresenta o local */
    printf("\n%s\n\n", lugar->nome);  // título (nome da sala)
    if (lugar -> conhecido)
      printf("%s", lugar->curta);
    else
      printf("%s", lugar->longa);


    /* Relaciona o conteúdo visível */
    if (!lista_vazia (lugar->conteudo)) {
      printf("Aqui você vê: ");
      l = lugar->conteudo;
      l = l->next;
      while (l != NULL) {
        el = l->val;
        if (el->visivel)
          printf("%s, %s, ", el->artigo, el->nome);
        l = l->next;
      }
    }

    printf("Digite o nome da acao que quer executar:\n");
    scanf("%s", a);
    printf("Digite o nome do primeiro parametro (digite espaço se não houver):\n");
    scanf("%s", b);
    printf("Digite o nome do segundo parametro (digite espaco se nao houver):\n");
    scanf("%s", c);
    printf("Digite o nome do terceiro parametro (digite espaco se nao houver):\n");
    scanf("%s", d);
    

    el_b = tabela_busca(tab_jogo, b);
    el_c = tabela_busca(tab_jogo, c);
    el_d = tabela_busca(tab_jogo, d);

    p = lista_f_busca(l_comandos, a);
    q = (p_comando)p;
    q(el_b, el_c, el_d);
  }
}

Elemento inicializa_elementos (Tabela tab) {
  /* Devolve o elemento que é o lugar atual do aventureiro */
  /* Essa função liga as salas e coloca os objetos em seus lugares */

  Elemento el;

  /* Inicializa aventureiro */
  el = elemento_cria("Você");
  el->artigo = "";
  el->curta = "Voce é jovem e feio.\n";
  el->longa = "Voce é um estudante de ciência da computação, que faz iniciação científica em Inteligência Artificial. Teve uma infância feliz e superprotegida, mas uma adolescência solitária por ser muito tímido. Você nunca se achou particularmente bonito, atlético ou popular, mas sempre pôde contar com sua própria inteligência. Isso te fez achar que nada mais importava e que a razão irá resolver todos os problemas do planeta.\n Mas seres humanos são falhos. São emotivos. São irracionais.\n Você, então, pôs em si próprio a missão de criar uma máquina de raciocínio perfeito. Racional, justa e infalível. E está obcecado com a ideia.\n";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  tabela_insere(tab, el->nome, el);


  /* Inicializa salas */
  el = elemento_cria("Sala dos alunos de IC");
  el->artigo = "a";
  el->curta = "Tomando duas paredes, uma mesa grande, em L, usada por todos os alunos, cheia de papéis, livros e alguns notebooks espalhados.";
  el->longa = "Tomando duas paredes, uma mesa grande, em L, usada por todos os alunos, cheia de papéis e livros espalhados. Vários notebooks repousam sobre a mesa, um deles ligado. Neste, um terminal diz:\n leonardo@CLIAR: ~ $\n Em outra parede, uma estante de madeira repleta de livros sobre inteligência artificial, álgebra linear e probabilidade.\n De uma pequena janela é possível ver o céu noturno. ";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala dos pesquisadores");
  el->artigo = "a";
  el->curta = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador.";
  el->longa = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, há um porta retrato com a foto de uma mulher sorridente. O porta retrato está úmido. Você reconhece na foto a esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.\n Os computadores da sala estão ligados, mas protegidos por senha.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala de Máquinas");
  el->artigo = "a";
  el->curta = "É uma sala fria e barulhenta, repleta de cabos espalhados pelo chão. Um nobreak imponente toma a maior parte do espaço da sala.";
  el->longa = "É uma sala fria e barulhenta, repleta de cabos espalhados pelo chão. Um nobreak imponente toma a maior parte do espaço da sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Pátio");
  el->artigo = "o";
  el->curta = "Um grande pátio que se estende por todo o comprimento do andar. Possui um café, mesas e várias plantas decorativas. Uma parede separa a área de convivência da mesa de recepção. A porta de saída se encontra logo à frente.";
  el->longa = "Um grande pátio que se estende por todo o comprimento do andar. Possui um café, mesas e várias plantas decorativas. Uma parede separa a área de convivência da mesa de recepção. A porta de saída se encontra logo à frente.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);
  
  el = elemento_cria("Sala do servidor");
  el->artigo = "a";
  el->curta = "A maior sala do andar. Muito fria e barulhenta. Possui um supercomputador enorme que ocupa quase toda a sala.";
  el->longa = "A maior sala do andar. Muito fria e barulhenta. Possui um supercomputador enorme que ocupa quase toda a sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  return(el);
}
