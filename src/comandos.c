#include "comandos.h"
#include <stdio.h>

Elemento ir_para(Elemento e1, Elemento e2, Elemento e3) {
  /* e1 é a nova sala, e2 é o jogador e e3 é a velha sala.
     Devolve a nova sala
  */

  if (lista_busca_valor(e3->detalhe.saidas, e1) == NULL) {
    printf("Não é possível ir para %s %s a partir daqui.\n",
           e1->artigo, e1->nome);
    return (NULL);
  }

  lista_retira(e3->conteudo, e2->nome); //Remove o jogador da sala antiga
  lista_insere(e1->conteudo, e2, e2->nome); //Insere o jogador da sala nova
  return (e1);
}


Elemento examinar(Elemento e1, Elemento e2, Elemento e3) {

  p_funcao_void p;
  p_comando q;

  if (e1 == NULL) {
    printf("Erro: chamou a funcao examinar sem nenhum elemento");
    return(NULL);
  }

  if (e2 == NULL)
    printf("%s\n", e1->longa);
  return (NULL);

  p = lista_f_busca(e2->acoes, "examinar");
  if (p == NULL) {
    printf("Não consigo examinar %s %s com %s %s.\n",
           e1-> artigo, e1->nome, e2->artigo, e2->nome);
   return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento falar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "falar");
  if (p == NULL) {
    printf("Acho que você não quer falar com %s %s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}


Elemento perguntar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "perguntar");
  if (p == NULL) {
    printf("Acho que você não quer perguntar sobre %s %s para %s %s.\n",
           e2->artigo, e2->nome, e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

/* Comandos de interação com objetos*/
Elemento pegar(Elemento e1, Elemento e2, Elemento e3) {
  /* e1 é o objeto, e2 é o jogador e e3 é a sala */

  lista_retira(e3->conteudo, e1->nome);
  lista_insere(e2->conteudo, e1, e1->nome);
  printf("Você pegou %s %s\n", e1->artigo, e1->nome);
  return(NULL);
}


Elemento abrir(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "abrir");
  if (p == NULL) {
    printf("Você não consegue abrir %s %s.\n",
           e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento fechar(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "abrir");
  if (p == NULL) {
    printf("Você não consegue fechar %s %s.\n",
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
  printf("Você deixou %s %s aí.\n", e1->artigo, e1->nome);
  return(NULL);
}

Elemento comer(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "comer");
  if (p == NULL) {
    printf("Você não consegue comer %s %s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}

Elemento beber(Elemento e1, Elemento e2, Elemento e3) {
  p_funcao_void p;
  p_comando q;
  p = lista_f_busca(e2->acoes, "comer");
  if (p == NULL) {
    printf("Você não consegue comer %s %s.\n", e1->artigo, e1->nome);
    return(NULL);
  }
  q = (p_comando)p;
  return(q(e1, e2, e3));
}
