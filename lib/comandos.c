#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>

Elemento ir_para(Elemento e1, Elemento e2, Elemento e3) {
  /* e1 é a nova sala, e2 é o jogador e e3 é a velha sala.
     Devolve a nova sala
  */

  if (e1 == NULL || e2 == NULL || e3 == NULL) {
    printf("Você quer ir para onde?\n");
    return(NULL);
  }

  if (lista_busca_valor(e3->detalhe.saidas, e1) == NULL) {
    if (e1->conhecido)
      printf("Não é possível ir para %s%s a partir daqui.\n",
             e1->artigo, e1->nome);
    else
      printf("Você quer ir para onde?\n");
    return (NULL);
  }

  lista_retira(e3->conteudo, e2->nome); //Remove o jogador da sala antiga
  lista_insere(e1->conteudo, e2, e2->nome); //Insere o jogador na sala nova
  return (e1);
}

Elemento inventario(Elemento e1, Elemento e2, Elemento e3) {

  /* e1 é o jogador */
  if (e1 == NULL) {
    /* printf("Erro: tentou mostrar o inventário mas não passou o jogador como parâmetro\n"); */
    printf("O que que é?\n");
    return (NULL);
  }

  if (lista_vazia(e1->conteudo))
    printf("Você não está carregando nada neste momento.\n");
  else {
    printf("Inventário:\n");
    elemento_imprime_conteudo(e1);
  }
  return (NULL);
}

Elemento examinar(Elemento e1, Elemento e2, Elemento e3) {

  p_funcao_void p;
  p_comando q;

  if (e1 == NULL) {
    /* printf("Erro: chamou a funcao examinar sem nenhum elemento\n"); */
    printf("O que que é?\n");
    return(NULL);
  }

  if (e2 == NULL) {
    printf("%s\n", e1->longa);
    e1->conhecido = 1;
  }
  return (NULL);

  p = lista_f_busca(e2->acoes, "examinar");
  if (p == NULL) {
    printf("Não consigo examinar %s%s com %s%s.\n",
           e1->artigo, e1->nome, e2->artigo, e2->nome);
   return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento falar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "falar");
  if (p == NULL) {
    printf("Acho que você não quer falar com %s%s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}


Elemento perguntar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "perguntar");
  if (p == NULL) {
    printf("Acho que você não quer perguntar sobre %s%s para %s%s.\n",
           e2->artigo, e2->nome, e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

/* Comandos de interação com objetos*/
Elemento pegar(Elemento e1, Elemento e2, Elemento e3) {
  /* e1 é o objeto, e2 é o jogador e e3 é a sala */

  if (e1 
== NULL || e2 == NULL || e3 == NULL) {
    printf("Você quer pegar o que?.\n");
    return(NULL);
  }
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "pegar");
  if (p != NULL) {
    q = (p_comando)p;
    return(q(e1, e2, e3));
  }
  
  if (lista_busca(e2->conteudo, e1->nome) != NULL) {
    printf("Você já está carregando %s%s\n", e1->artigo, e1->nome);
    return (NULL);
  }

  if (e1->carregavel) {
    lista_retira(e3->conteudo, e1->nome);
    lista_insere(e2->conteudo, e1, e1->nome);
    printf("Você pegou %s%s\n", e1->artigo, e1->nome);
  }
  else
    printf("Você não consegue pegar %s%s\n", e1->artigo, e1->nome);
  return(NULL);
}


Elemento abrir(Elemento e1, Elemento e2, Elemento e3) {
 
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "abrir");
  if (p == NULL) {
    printf("Você não consegue abrir %s%s\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento fechar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "fechar");
  if (p == NULL) {
    printf("Você não consegue fechar %s%s.\n",
           e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento deixar(Elemento e1, Elemento e2, Elemento e3) {
  /* e1 é o objeto, e2 é o jogador e e3 é a sala */

  lista_retira(e2->conteudo, e1->nome);
  lista_insere(e3->conteudo, e1, e1->nome);
  printf("Você deixou %s%s aí.\n", e1->artigo, e1->nome);
  return(NULL);
}

Elemento comer(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "comer");
  if (p == NULL) {
    printf("Você não consegue comer %s%s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento beber(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e1->acoes, "beber");
  if (p == NULL) {
    printf("Você não consegue comer %s%s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}



/* -------------------------------------------------------------------*/
/* -------------- Comandos específicos de elementos ------------------*/
/* -------------------------------------------------------------------*/

Elemento janela_abrir(Elemento e1, Elemento e2, Elemento e3) {

  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 1) {
    printf("A janela já está aberta.\n");
    return NULL;
  }

  printf("Você abre a janela e sente a brisa e o frescor da noite entrar na sala.");

  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 1;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 1;
  return (NULL);

  return (NULL);
}

Elemento livros_abrir(Elemento e1, Elemento e2, Elemento e3) {

  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 1) {
    printf("Você já abriu o livro.\n");
    return NULL;
  }

  printf("Você abre um livro de álgebra linear, e começa a ler: \"Vectors  in R n are  impossible to visualize unless n is 1, 2, or 3. However, familiar objects like lines and planes still make sense for any value of n. Die Geschichte aller bisherigen Gesellschaft ist die Geschichte von Klassenkämpfen\". Seus olhos desfocam, e você pisca. Você passou o dia inteiro lendo esses livros, e não aguenta mais!\n");

  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 1;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 1;
  return (NULL);
}

Elemento seu_notebook_abrir(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 1) {
    printf("O notebook já está aberto.\n");
    return NULL;
  }
  printf("Você abre o notebook e vê na tela o seu terminal:\n\n leonardo@CLIAR:~$\n\n");
  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 1;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 1;

  return (NULL);
}

Elemento notebook_do_pedro_abrir(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 1) {
    printf("O notebook já está aberto.\n");
    return NULL;
  }
  printf("Você abre o notebook e vê a tela inicial do gdm3 (o pessoal usa debian por aqui). Você não sabe a senha do Pedro.\n");
  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 1;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 1;

  return (NULL);
}

Elemento notebook_da_alice_abrir(Elemento e1, Elemento e2, Elemento e3) {

  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 1) {
    printf("O notebook já está aberto.\n");
    return NULL;
  }
  printf("Você abre o notebook e vê a tela inicial do gdm3 (o pessoal usa debian por aqui). Você não sabe a senha da Alice.\n");
  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 1;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 1;
  return (NULL);
}

Elemento supercomputador_abrir(Elemento e1, Elemento e2, Elemento e3) {
  printf("O exterior desse supercomputador são placas metálicas parafusadas. Os parafusos parecem bem firmes. Você tem um chave de fenda?\n");
  return (NULL);
}

Elemento janela_fechar(Elemento e1, Elemento e2, Elemento e3) {

  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 0) {
    printf("A janela já está aberta.\n");
    return NULL;
  }
  printf("Você fecha a janela.\n");

  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 0;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 0;
  return (NULL);

}

Elemento livros_fechar(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 0) {
    printf("O livro já está fechado.\n");
    return NULL;
  }
  printf("Você fecha o livro de álgebra linear.\n");
  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 0;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 0;
  return (NULL);
}

Elemento seu_notebook_fechar(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p, i;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 0) {
    printf("O notebook já está fechado.\n");
    return NULL;
  }
  printf("Você fecha o notebook.\n");
  if (p == NULL) {
    i = 0;
    lista_insere(l, &i, "aberto");
  }
  else
    *p = 0;
  return (NULL);
}

Elemento notebook_do_pedro_fechar(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p, i;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 0) {
    printf("O notebook já está fechado.\n");
    return NULL;
  }
  printf("Você fecha o notebook.\n");
  if (p == NULL) {
    i = 0;
    lista_insere(l, &i, "aberto");
  }
  else
    *p = 0;
  return (NULL);
}

Elemento notebook_da_alice_fechar(Elemento e1, Elemento e2, Elemento e3) {
  Lista l;
  short int *p;

  l = e1->detalhe.atributos;
  p = lista_busca(l, "aberto");
  if (p != NULL && *p == 0) {
    printf("O notebook já está fechado.\n");
    return NULL;
  }
  printf("Você fecha o notebook.\n");
  if (p == NULL) {
    p = malloc(sizeof(int));
    *p = 0;
    lista_insere(l, p, "aberto");
  }
  else
    *p = 0;
  return (NULL);
}

Elemento supercomputador_fechar(Elemento e1, Elemento e2, Elemento e3) {

  printf("Você fecha o supercomputador. Eu só me pergunto como você conseguiu abrir ele.\n");
  return (NULL);
}

Elemento papeis_comer(Elemento e1, Elemento e2, Elemento e3) {
  printf("Voce coloca alguns papéis na boca e mastiga eles. Não dá muito certo engolir eles, mas as anotações sobre funções lineares em hiperplanos eram as mais gostosas.\n");
  return (NULL);
}

Elemento xicara_comer(Elemento e1, Elemento e2, Elemento e3) {
  
  int *p;
  p = lista_busca(e1->detalhe.atributos, "cheio");
  if (p == NULL || *p == 1) {
    printf("Você tenta muito mastigar o café, mas tudo que você consegue fazer é babar um pouco e beber o resto! Ah, e estava horrível. Devia estar parado aí faz umas cinco horas. Blergh! No entanto, você está mais desperto.\n");
    *p = 0;
  }
  else {
    printf("Nem vai dar pra tentar comer o café, porque a xícara esta vazia.");
  }
  return(NULL);
}


Elemento xicara_beber(Elemento e1, Elemento e2, Elemento e3) {
  int *p;
  p = lista_busca(e1->detalhe.atributos, "cheio");
  if (p == NULL || *p == 1) {
    printf("Você bebe a xícara de café. Estava horrível. Devia estar parado aí faz umas cinco horas. Blergh! No entanto, você está mais desperto.\n");
    *p = 0;
  }
  else {
    printf("A xícara esta vazia.\n");
  }
  return(NULL);
}
