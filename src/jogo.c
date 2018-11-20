#include "jogo.h"

int main () {

  int i;
  char ans;
  const char PROMPT = '>';

  /* Tabela principal que contém todos os elementos do jogo */
  Tabela tab_jogo = tabela_cria(TAM_TABELA);
  Elemento el, lugar_atual = inicializa_elementos(tab_jogo);

  /* Booleano armazena se acabamos de chegar na sala (indiferente se ela é
     conhecida ou não) */
  short int acabei_de_chegar = 1;

  printf("=========================================\n");
  printf(" _____          _____         \n");
  printf("|_   _|   /\\   |  __ \\     /\\   \n");
  printf("  | |    /  \\  | |__) |   /  \\ \n");
  printf("  | |   / /\\ \\ |  _  /   / /\\ \\ \n");
  printf(" _| |_ / ____ \\| | \\ \\  / ____ \\ \n");
  printf("|_____/_/    \\_\\_|  \\_\\/_/    \\_\\ \n");
  printf("========================================\n");

  printf("\nPor Emanuel Lima e João Seckler.\n");
  printf("\nVocê gostaria de ler as instruções? [s/N]\n");
  scanf("%c", &ans);
  switch (ans) {
    case 'S':
    case 's':
      printf("\nInstruções: Por enquanto, nada. Eu só me auto-testo.\n\n");
      break;
  
    default:
      break;
  }

  printf("ATO 1\n");
  printf("Dor de cabeça. Esta é a primeira coisa que você sente ao acordar na sua mesa de trabalho.\
  Aos poucos você vai se lembrando do que aconteceu. O seu orientador te pediu para por a nova versão da\
  inteligência artificial que vocês construíram juntos em produção. Depois de 48h acordado tentando completar a tarefa,\
  você desmaiou de exaustão em cima dos seus livros e do seu notebook. Mas agora você está acordado. O que você faz? \n");


  /* ----- Inicialização dos comandos ------ */

  /* Vamos entrar em todas as salas, examinar todos os objetos dela
     tentar pegar todos eles e fazer algumas ações específicas deles */

  p_comando v_verbos[] = {examinar, examinar, examinar, examinar, examinar,
                          pegar, pegar, pegar, pegar, pegar,
                          ir_para, // pátio
                          examinar, examinar, examinar, examinar, examinar,
                          pegar, pegar, pegar, pegar, pegar,
                          ir_para, // sala dos pesquisadores
                          examinar, examinar, examinar,
                          examinar, examinar, examinar,
                          pegar, pegar, pegar, pegar, pegar, pegar,
                          ir_para, ir_para, // sala de máquinas
                          examinar, examinar,
                          pegar, pegar,
                          ir_para, ir_para, // sala do servidor
                          examinar, pegar};


  /* O vetor abaixo só serve para imprimir na tela que comando
     está sendo executado a cada iteração, e deve ser
     igual a v_verbos, mas com strings*/
  char *nomes_comandos[] = {"examinar", "examinar", "examinar", "examinar", "examinar",
                            "pegar", "pegar", "pegar", "pegar", "pegar",
                            "ir_para", // pátio
                            "examinar", "examinar", "examinar", "examinar", "examinar",
                            "pegar", "pegar", "pegar", "pegar", "pegar",
                            "ir_para", // sala dos pesquisadores
                            "examinar", "examinar", "examinar",
                            "examinar", "examinar", "examinar",
                            "pegar", "pegar", "pegar", "pegar", "pegar", "pegar",
                            "ir_para", "ir_para", // sala de máquinas
                            "examinar", "examinar",
                            "pegar", "pegar",
                            "ir_para", "ir_para", // sala do servidor
                            "examinar", "pegar"};

  char *s1[] = {"janela", "notebook do Pedro", "notebook da Alice",
                "seu notebook", "estante",
                "janela""", "notebook do Pedro", "notebook da Alice",
                "seu notebook", "estante",
                "Pátio",
                "café", "mesas", "plantas", "parede", "recepção",
                "café", "mesas", "plantas", "parede", "recepção",
                "Sala dos pesquisadores",
                "mesas", "papéis", "livros", "monitores", "xícara", "retrato",
                "mesas", "papéis", "livros", "monitores", "xícara", "retrato",
                "Pátio",
                "Sala de máquinas",
                "cabos", "nobreak",
                "cabos", "nobreak",
                "Pátio",
                "Sala do servidor",
                "supercomputador", "supercomputador"};

  char *s2[] = {"NULL", "NULL", "NULL", "NULL", "NULL",
                "Você", "Você", "Você", "Você", "Você",
                "Você", // Pátio
                "NULL", "NULL", "NULL", "NULL", "NULL",
                "Você", "Você", "Você", "Você", "Você",
                "Você", // Sala dos pesquisadores
                "NULL", "NULL", "NULL", "NULL", "NULL", "NULL",
                "Você", "Você", "Você", "Você", "Você", "Você",
                "Você", "Você", // Sala de máquinas
                "NULL", "NULL",
                "Você", "Você",
                "Você", "Você", // Sala do servidor
                "NULL", "Você"};

  char *s3[] = {"NULL", "NULL", "NULL", "NULL", "NULL",
                "Sala dos alunos de IC", "Sala dos alunos de IC",
                "Sala dos alunos de IC", "Sala dos alunos de IC",
                "Sala dos alunos de IC",
                "Sala dos alunos de IC", // Pátio
                "NULL", "NULL", "NULL", "NULL", "NULL",
                "Pátio", "Pátio", "Pátio", "Pátio", "Pátio",
                "Pátio", // Sala dos pesquisadores
                "NULL", "NULL", "NULL", "NULL", "NULL", "NULL",
                "Sala dos pesquisadores", "Sala dos pesquisadores",
                "Sala dos pesquisadores", "Sala dos pesquisadores",
                "Sala dos pesquisadores", "Sala dos pesquisadores",
                "Sala dos pesquisadores", "Pátio", // Sala de máquinas
                "NULL", "NULL",
                "Sala de máquinas", "Sala de máquinas",
                "Sala de máquinas", "Pátio", // Sala do servidor
                "NULL", "Sala de máquinas"};

  Elemento v_arg1[QTDE_COMANDOS];
  Elemento v_arg2[QTDE_COMANDOS];
  Elemento v_arg3[QTDE_COMANDOS];

  for (i = 0; i < QTDE_COMANDOS; i++) {
    v_arg1[i] = tabela_busca(tab_jogo, s1[i]);
    v_arg2[i] = tabela_busca(tab_jogo, s2[i]);
    v_arg3[i] = tabela_busca(tab_jogo, s3[i]);
  }

  /* Laço principal*/
  for (i = 0; i < QTDE_COMANDOS; i++) {

    printf("%c", PROMPT);
    printf("\n");

    if (acabei_de_chegar) {
      /* Apresenta o local */
      printf("\n%s\n", lugar_atual->nome);  // título (nome da sala)
      if (lugar_atual->conhecido)
        printf("%s", lugar_atual->curta);
      else
        printf("%s", lugar_atual->longa);
      acabei_de_chegar = 0;

      /* Relaciona o conteúdo visível */
      if (!lista_vazia(lugar_atual->conteudo)) {
        printf("\nAqui você vê:\n");
        elemento_imprime_conteudo(lugar_atual);
      }
    }
    
    printf("\n--> Executando o comando %s(%s, %s, %s) <--\n",
           nomes_comandos[i], s1[i], s2[i], s3[i]);
    el = v_verbos[i](v_arg1[i], v_arg2[i], v_arg3[i]);

    /* Caso especial: se o comando é ir_para */    
    if (v_verbos[i] == ir_para && el != NULL) {
      acabei_de_chegar = 1;
      lugar_atual = el;
    }

    /* Faz todas as animações */
    animacoes_automaticas(tab_jogo, lugar_atual);
  }
  return 0;
}

Elemento inicializa_elementos (Tabela tab) {
  /* Devolve o elemento que é o lugar atual do aventureiro */
  /* Essa função liga as salas e coloca os objetos em seus lugares */
  
  Elemento el, el2;
  Lista l;

  /* Inicializa aventureiro */
  el = elemento_cria("Você");
  el->artigo = "";
  el->curta = "Voce é um ambicioso estudante de ciência da computação.\n";
  el->longa = "Voce é um estudante de ciência da computação, que faz iniciação científica em Inteligência Artificial. Teve uma infância feliz e superprotegida, mas uma adolescência solitária por ser muito tímido. Você nunca se achou particularmente bonito, atlético ou popular, mas sempre pôde contar com sua própria inteligência. Isso te fez achar que nada mais importava e que a razão irá resolver todos os problemas do planeta.\n";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  tabela_insere(tab, el->nome, el);

  /* Inicializa IARA */
  el = elemento_cria("IARA");
  el->artigo = "a";
  el->curta = "Inteligência Artificial Realísticamente Autônoma.\n";
  el->longa = "A Inteligência Artificial Realísticamente Autônoma, IARA, foi criada por pesquisadores do CLIAR que almeijavam criar uma IA tão inteligente quanto qualquer ser humano.\n";
  el->ativo = 1;
  el->visivel = 0;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  /* Inicializa salas */
  el = elemento_cria("Sala dos alunos de IC");
  el->artigo = "a";
  el->curta = "Tomando duas paredes, há uma mesa grande, em L, usada por todos os alunos, cheia de papéis, livros e alguns notebooks espalhados.";
  el->longa = "Tomando duas paredes, há uma mesa grande, em L, usada por todos os alunos, cheia de papéis e livros espalhados. Vários notebooks repousam sobre a mesa, apenas o seu ligado. \nEm outra parede, uma estante de madeira repleta de livros sobre inteligência artificial, álgebra linear e probabilidade.\nDe uma pequena janela é possível ver o céu noturno.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala dos pesquisadores");
  el->artigo = "a";
  el->curta = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador.";
  el->longa = "Três mesas em frente a três paredes compõem o visual da sala. Cada mesa contém um misto de papéis, livros e monitores de computador. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, há um porta retrato com a foto de uma mulher sorridente. O porta retrato está úmido. Você reconhece na foto a esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.\n Os computadores da sala estão desligados.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Sala de máquinas");
  el->artigo = "a";
  el->curta = "Uma sala fria e barulhenta que guarda um nobreak imponente que toma a maior parte do espaço da sala.";
  el->longa = "É uma sala fria e barulhenta, repleta de cabos espalhados pelo chão. Um nobreak imponente toma a maior parte do espaço da sala.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("Pátio");
  el->artigo = "o";
  el->curta = "Um grande pátio, atualmente vazio, que se estende por todo o comprimento do andar. Possui um café, mesas e várias plantas decorativas. A porta de saída se encontra logo à frente. Bossa nova está a tocar no sistema de som.";
  el->longa = "Um grande pátio que se estende por todo o comprimento do andar. Bossa nova está a tocar no sistema de som. Não se econtra um ser humano no café lindamente decorado que ocupa a parte sul do ambiente. Uma parede de mármore carrara separa a área de convivência da imensa mesa de madeira da recepção. Uma porta automática de saída se encontra logo à frente.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, el->nome, el);
  
  el = elemento_cria("Sala do servidor");
  el->artigo = "a";
  el->curta = "A maior sala do andar. Muito fria e barulhenta. Possui um supercomputador enorme que ocupa quase toda a sala.";
  el->longa = "A maior sala do andar. Muito fria e barulhenta. Você se lembra que aqui é onde fica o enorme supercomputador onde você deveria ter feito o deploy da IA.";
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
  el->carregavel = 1;
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("notebook do Pedro");
  el->artigo = "o";
  el->curta = "É o notebook do seu colega Pedro";
  el->longa = "É o notebook do seu colega Pedro, que também pesquisa inteligência artificial aqui no CLIAR.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  el->carregavel = 1;
  lista_f_insere(el->acoes, (p_funcao_void)notebook_do_pedro_abrir, "abrir");
  lista_f_insere(el->acoes, (p_funcao_void)notebook_do_pedro_fechar, "fechar");
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("notebook da Alice");
  el->artigo = "o";
  el->curta = "É o notebook da sua colega Alice";
  el->longa = "É o notebook da sua colega Alice que também pesquisa inteligência artificial aqui no CLIAR.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 1;
  el->carregavel = 1;
  lista_f_insere(el->acoes, (p_funcao_void)notebook_da_alice_abrir, "abrir");
  lista_f_insere(el->acoes, (p_funcao_void)notebook_da_alice_fechar, "fechar");
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
  lista_f_insere(el->acoes, (p_funcao_void)janela_abrir, "abrir");
  lista_f_insere(el->acoes, (p_funcao_void)janela_fechar, "fechar");
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);


  /* Elementos na sala dos pesquisadores */
  el2 = tabela_busca(tab, "Sala dos pesquisadores");
  l = el2->conteudo;

  el = elemento_cria("mesas");
  el->artigo = "as";
  el->curta = "São três mesas em frente a três paredes. As três estão cheias de papéis, anotações e livros, além de um monitor em cima de cada.";
  el->longa = "São três mesas em frente a três paredes. Em cima delas, você vê anotações à mão, cadernos, papers impressos e monitores. Em uma das mesas, uma xícara de café frio faz as vezes de peso de papel. Em outra, a do seu orientador, há um porta retrato com a foto de uma mulher sorridente.";
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
  el->carregavel = 1;
  lista_f_insere(el->acoes, (p_funcao_void)papeis_comer, "comer");
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);
  
  el = elemento_cria("livros");
  el->artigo = "os";
  el->curta = "São livros que os pesquisadores estão estudando e deixaram em cima da mesa essa noite.";
  el->longa = "São livros que os pesquisadores estão estudando e deixaram em cima da mesa essa noite. São principalmente sobre álgebra linear e inteligência artificial. Exceto os Grundrisse, que está na mesa da direita. Alguns deles você já viu na estante da sala de interligência artificial.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  el->carregavel = 1;
  lista_f_insere(el->acoes, (p_funcao_void)livros_abrir, "abrir");
  lista_f_insere(el->acoes, (p_funcao_void)livros_fechar, "fechar");
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
  el->carregavel = 1;
  lista_f_insere(el->acoes, (p_funcao_void)xicara_comer, "comer");
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  el = elemento_cria("retrato");
  el->artigo = "o";
  el->curta = "É o retrato da esposa do seu orientador.";
  el->longa = "É o retrato da esposa do seu orientador. Um calafrio sobe a sua coluna quando você lembra que recentemente ela se envolveu num acidente de carro e que atualmente está de coma num hospital.";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  el->carregavel = 1;
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
  el->longa = "É um grande nobreak no meio da sala. Existe uma tela de LCD onde se lê: \"Todos os sistemas: OK\" .";
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
  el->longa = "É o café do CLIAR. Aqui você sempre pega o seu café e senta na mesa, muitas vezes sozinho. Agora, no entanto, ele está fechado, e todos os funcionários foram para casa.";
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
  lista_f_insere(el->acoes, (p_funcao_void)supercomputador_abrir, "abrir");
  lista_f_insere(el->acoes, (p_funcao_void)supercomputador_fechar, "fechar");
  lista_insere(l, el, el->nome);
  tabela_insere(tab, el->nome, el);

  /* Aventureiro é conteúdo da sala do início */
  el = tabela_busca(tab, "Você");
  el2 = tabela_busca(tab, "Sala dos alunos de IC"); 
  lista_insere(el2->conteudo, el, el->nome);

  /* Devolve o lugar de início */
  return(el2);
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
      /* printf("%s\n", el->nome); */
      if (el->animacao != NULL) {
        f = (p_comando)el->animacao;
        f(lugar_atual, NULL, NULL);
      }
      p = p->next;
    }
  }
}
