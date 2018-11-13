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
    
    printf("Estou aqui!");

    el_b = tabela_busca(tab_jogo, b);
    el_c = tabela_busca(tab_jogo, c);
    el_d = tabela_busca(tab_jogo, d);
    p = lista_f_busca(l_comandos, a);
    q = (p_comando)p;
    examinar(el_b, el_c, el_d);
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
  tabela_insere(tab, "Você", el);


  /* Inicializa salas */
  el = elemento_cria("A sala de IC");
  el->artigo = "";
  el->curta = "A sala de iniciação científica é grande, tem alguns computadores e uma mesa, onde você sempre trabalha.\n";
  el->longa = "A sala de iniciação científica é grande. À sua esquerda, vê-se três computadores, um do adolfo, outro do rodrigo, seus colegas, e outro é um servidor. É gelado, por que o ar condicionado está sempre ligado. Tem uma porta que leva ao corredor, ao sul.\n";
  el->ativo = 1;
  el->visivel = 1;
  el->conhecido = 0;
  tabela_insere(tab, "A sala de IC", el);

  return(el);
}
