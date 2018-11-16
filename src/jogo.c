#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 50

Elemento inicializa_elementos (Tabela tab);

int main () {

  int i;
  Lista l;
  Lista_f l_comandos = lista_f_cria();
  p_comando q[] = {examinar};
  Tabela tab_jogo = tabela_cria(TAM_TABELA);
  Elemento el, lugar_atual;
  lugar_atual = inicializa_elementos(tab_jogo);

  char introducao[] = "Você está na sala de IC e de repente um monte de coisa ruim acontece. O que você quer fazer? (isso é a introdução do jogo!)\n";
  printf("%s", introducao);

  /* Laço principal*/
  while (1) {

    /* Apresenta o local */
    printf("\n%s\n\n", lugar_atual->nome);  // título (nome da sala)
    if (lugar_atual -> conhecido)
      printf("%s", lugar_atual->curta);
    else
      printf("%s", lugar_atual->longa);


    /* Relaciona o conteúdo visível */
    if (!lista_vazia (lugar_atual->conteudo)) {
      printf("Aqui você vê: ");
      l = lugar_atual->conteudo;
      l = l->next;
      while (l != NULL) {
        el = l->val;
        if (el->visivel)
          printf("%s, %s, ", el->artigo, el->nome);
        l = l->next;
      }
    }
  }
}

Elemento inicializa_elementos (Tabela tab) {
  /* Devolve o elemento que é o lugar atual do aventureiro */
  /* Essa função liga as salas e coloca os objetos em seus lugares */

  Elemento el, el2;
  Lista l;

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
  lista_insere(el->detalhe.saidas, NULL, "norte");
  lista_insere(el->detalhe.saidas, NULL, "sul");
  lista_insere(el->detalhe.saidas, NULL, "leste");
  lista_insere(el->detalhe.saidas, NULL, "oeste");
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala dos pesquisadores");
  el->artigo = "a";
  el->curta = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador.";
  el->longa = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, há um porta retrato com a foto de uma mulher sorridente. O porta retrato está úmido. Você reconhece na foto a esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.\n Os computadores da sala estão ligados, mas protegidos por senha.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(el->detalhe.saidas, NULL, "norte");
  lista_insere(el->detalhe.saidas, NULL, "sul");
  lista_insere(el->detalhe.saidas, NULL, "leste");
  lista_insere(el->detalhe.saidas, NULL, "oeste");
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala de Máquinas");
  el->artigo = "a";
  el->curta = "É uma sala fria e barulhenta, repleta de cabos espalhados pelo chão. Um nobreak imponente toma a maior parte do espaço da sala.";
  el->longa = "É uma sala fria e barulhenta, repleta de cabos espalhados pelo chão. Um nobreak imponente toma a maior parte do espaço da sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(el->detalhe.saidas, NULL, "norte");
  lista_insere(el->detalhe.saidas, NULL, "sul");
  lista_insere(el->detalhe.saidas, NULL, "leste");
  lista_insere(el->detalhe.saidas, NULL, "oeste");
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Pátio");
  el->artigo = "o";
  el->curta = "Um grande pátio que se estende por todo o comprimento do andar. Possui um café, mesas e várias plantas decorativas. Uma parede separa a área de convivência da mesa de recepção. A porta de saída se encontra logo à frente.";
  el->longa = "Um grande pátio que se estende por todo o comprimento do andar. Possui um café, mesas e várias plantas decorativas. Uma parede separa a área de convivência da mesa de recepção. A porta de saída se encontra logo à frente.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(el->detalhe.saidas, NULL, "norte");
  lista_insere(el->detalhe.saidas, NULL, "sul");
  lista_insere(el->detalhe.saidas, NULL, "leste");
  lista_insere(el->detalhe.saidas, NULL, "oeste");
  tabela_insere(tab, el->nome, el);
  
  el = elemento_cria("Sala do servidor");
  el->artigo = "a";
  el->curta = "A maior sala do andar. Muito fria e barulhenta. Possui um supercomputador enorme que ocupa quase toda a sala.";
  el->longa = "A maior sala do andar. Muito fria e barulhenta. Possui um supercomputador enorme que ocupa quase toda a sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(el->detalhe.saidas, NULL, "norte");
  lista_insere(el->detalhe.saidas, NULL, "sul");
  lista_insere(el->detalhe.saidas, NULL, "leste");
  lista_insere(el->detalhe.saidas, NULL, "oeste");
  tabela_insere(tab, el->nome, el);

  /* Liga as saídas das salas umas nas outras*/
  //TODO

  /* Elementos na sala dos alunos de IC */
  el2 = tabela_busca(tab, "Sala dos alunos de IC");
  l = el2->conteudo;

  el = elemento_cria("seu notebook");
  el->artigo = "o";
  el->curta = "É o seu notebook";
  el->longa = "É o seu notebook, que você usa para fazer pesquisa. Se você abre ele, você vê um terminal que diz: \n leonardo@CLIAR:~$.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("notebook do Pedro");
  el->artigo = "o";
  el->curta = "É o notebook do seu colega Pedro";
  el->longa = "É o notebook do seu colega Pedro, que também pesquisa inteligência artificial aqui no CLIAR. Se você abre ele, vê que o gdm está pedindo a senha de usuário.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("notebook da Alice");
  el->artigo = "o";
  el->curta = "É o notebook da sua colega Alice";
  el->longa = "É o notebook da sua colega Alice que também pesquisa inteligência artificial aqui no CLIAR. Se você abre ele, vê que o gdm está pedindo a senha de usuário.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("estante");
  el->artigo = "a";
  el->curta = "É uma estante de livros dos alunos de IC.";
  el->longa = "É uma estante de livros dos alunos de IC. Tem livros principalmente sobre inteligência artificial, álgebra linear e probabilidade. Você estudou alguns deles.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("janela");
  el->artigo = "a";
  el->curta = "É uma pequena janela no canto da parede";
  el->longa = "É uma pequena janela no canto da parede. Vê-se o céu noturno, sem estrelas, por causa das luzes da cidade.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);


  return(el);
}
