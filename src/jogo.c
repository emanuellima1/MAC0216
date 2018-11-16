#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 50

/* Inicializa todos os elementos do jogo e devolve o lugar de inicio */
Elemento inicializa_elementos (Tabela tab);

/* Percorre todos os elementos da tabela e em cada um, se houver,
   executa o campo animacao
 */
void animacoes_automaticas(Tabela tab, Elemento lugar_atual);

/* Recebe duas strings que são o nome de duas salas, e liga a saida
   uma na outra
*/
void liga_salas(Tabela tab, char * s1, char * s2);

int main () {

  int i;

  /* Tabela principal que contém todos os elementos do jogo */
  Tabela tab_jogo = tabela_cria(TAM_TABELA);
  Elemento el, lugar_atual = inicializa_elementos(tab_jogo);

  /* Booleano armazena se acabamos de chegar na sala (indiferente se ela é
     conhecida ou não) */
  short int acabei_de_chegar = 1;

  char introducao[] = "Você está na sala de IC e de repente um monte de coisa ruim acontece. O que você quer fazer? (isso é a introdução do jogo!)\n";
  printf("%s", introducao);

  /* Laço principal*/
  while (1) {

    /* Apresenta o local */
    if (acabei_de_chegar) {
      printf("\n%s\n\n", lugar_atual->nome);  // título (nome da sala)
      if (lugar_atual->conhecido)
        printf("%s", lugar_atual->curta);
      else
        printf("%s", lugar_atual->longa);
      acabei_de_chegar = 0;
    }

    /* Relaciona o conteúdo visível */
    if (!lista_vazia(lugar_atual->conteudo)) {
      printf("Aqui você vê:\n");
      elemento_imprime_conteudo(lugar_atual);
    }

    scanf("%d", &i);

    /* Faz todas as animações */
    animacoes_automaticas(tab_jogo, lugar_atual);
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
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala dos pesquisadores");
  el->artigo = "a";
  el->curta = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador.";
  el->longa = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, há um porta retrato com a foto de uma mulher sorridente. O porta retrato está úmido. Você reconhece na foto a esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.\n Os computadores da sala estão ligados, mas protegidos por senha.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala de máquinas");
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

  /* Liga as saídas das salas umas nas outras*/
  liga_salas(tab, "Sala dos alunos de IC", "Pátio");
  liga_salas(tab, "Sala dos pesquisadores", "Pátio");
  liga_salas(tab, "Sala de máquinas", "Pátio");
  liga_salas(tab, "Sala do servidor", "Pátio");

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


  /* Elementos na sala dos pesquisadores */
  el2 = tabela_busca(tab, "Sala dos pesquisadores");
  l = el2->conteudo;

  el = elemento_cria("mesas");
  el->artigo = "as";
  el->curta = "São três mesas em frente a três paredes. As três estão cheias de papéis, anotações e livros, além de um monitor em cima de cada.";
  el->longa = "São três mesas em frente a três paredes. Em cima delas, você vê anotações à mão, cadernos, papers impressos e monitores. Os monitores estão protegidos por senha. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, a do seu orientador, há um porta retrato com a foto de uma mulher sorridente.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("papéis");
  el->artigo = "os";
  el->curta = "São anotações e impressões de quem pesquisa inteligência artificial";
  el->longa = "São anotações e impressões de quem pesquisa inteligência artificial: papers, cadernos, anotações à mão, etc.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);
  
  el = elemento_cria("livros");
  el->artigo = "os";
  el->curta = "São livros que os pesquisadores estão estudando e deixaram em cima da mesa essa noite.";
  el->longa = "São livros que os pesquisadores estão estudando e deixaram em cima da mesa essa noite. São principalmente sobre álgebra linear e inteligência artificial. Exceto os grundrisse, que está na mesa da direita. Alguns deles você já viu na estante da sala de interligência artificial.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("monitores");
  el->artigo = "os";
  el->curta = "São três monitores das torres dos pesquisadores.";
  el->longa = "São três monitores das torres dos pesquisadores. Todos estão protegidos por senha. Cada um está sobre uma mesa.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("xícara");
  el->artigo = "a";
  el->curta = "É uma xícara meio cheia de café frio";
  el->longa = "É uma xícara meio cheia de café frio. Nela lê-se: \"XVII Symposium Künstliche Intelligenz\". Embaixo dela, alguns papéis soltos, onde se vê algumas gotas secas desse mesmo café derramado.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("retrato");
  el->artigo = "o";
  el->curta = "É o retrato da esposa do seu orientador.";
  el->longa = "É o retrato da esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  /* Elementos na sala de máquinas */
  el2 = tabela_busca(tab, "Sala de máquinas");
  l = el2->conteudo;

  el = elemento_cria("cabos");
  el->artigo = "os";
  el->curta = "São vários cabos de energia e força que atravessam a sala, se ligam às máquinas e saem pelas paredes.";
  el->longa = "São vários cabos que saem da parede, e se ligam nas máquinas. Os cabos que saem do nobreak são especialmente grandes; aqui se consome muita energia. Fora os de força, há alguns cabos de internet. Atravessando a sala."; 
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("nobreak");
  el->artigo = "o";
  el->curta = "É um grande nobreak no meio da sala.";
  el->longa = "É um grande nobreak no meio da sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  /* Elementos no Pátio */
  el2 = tabela_busca(tab, "Pátio");
  l = el2->conteudo;
  
  el = elemento_cria("café");
  el->artigo = "o";
  el->curta = "É o café do CLIAR.";
  el->longa = "É o café do CLIAR. Aqui você sempre pega o seu café e vai senta na mesa, muitas vezes sozinho. Agora, no entanto, ele está fechado, e todos os funcionários foram para casa.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("mesas");
  el->artigo = "as";
  el->curta = "São cinco mesas com cadeiras no meio do pátio.";
  el->longa = "São cinco mesas com cadeiras no meio do pátio. Você sempre toma café aqui. Uma delas está suja de (surprise, surprise) café.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("plantas");
  el->artigo = "as";
  el->curta = "São duas pequenas palmeiras em dois grandes vasos, uma de cada lado da sala.";
  el->longa = "São duas pequenas palmeiras em dois grandes vasos, uma de cada lado da sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  /* Elementos na Sala do servidor */
  el2 = tabela_busca(tab, "Sala do servidor");
  l = el2->conteudo;
  
  el = elemento_cria("supercomputador");
  el->artigo = "o";
  el->curta = "É um computador grande e barulhento.";
  el->longa = "É um computador grande e barulhento. Você sabe que aí rodam os programas mais sofisticados de inteligência artificial que esse centro de pesquisa produz.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);


  /* Devolve o lugar de início */
  el = tabela_busca(tab, "Sala dos alunos de IC");
  return(el);
}


void liga_salas(Tabela tab, char * s1, char * s2) {

  Elemento el1, el2;
  el1 = tabela_busca(tab, s1);
  el2 = tabela_busca(tab, s2);
  if (el1 == NULL || el2 == NULL) {
    printf("Erro: liga_salas recebeu um nome que não é nenhum elemento");
    return;
  }
  lista_insere(el1->detalhe.saidas, el2, el2->nome);
  lista_insere(el2->detalhe.saidas, el1, el1->nome);
}

void animacoes_automaticas(Tabela tab, Elemento lugar_atual) {
  /* Ver tabela.h e tabela.c para ver porque funciona assim */
  int i;
  Elo * p;
  Elemento el;
  p_comando f;

  for (i = 0; i < tab->tam; i++) {
    p = tab->v[i];
    p = p->next;
    while (p != NULL) {
      el = p->val;
      if (el->animacao != NULL) {
        f = (p_comando)el->animacao;
        f(lugar_atual, NULL, NULL);
      }
      p = p->next;
    }
  }
}
