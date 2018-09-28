/********************************************************************\         
* Aventura - Parte 1                                                *
*                                                                   *
* Emanuel Lima  NUSP 9009493                                        *
* João Seckler  NUSP 4603521                                        *
*                                                                   *
\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabela.h"

char *gera_string (char *s, int tamanho);

int main() {
  printf("===========================================\n");
  printf("Iniciando o Teste.\n");
  printf("===========================================\n");

  int i, j, r1, r2;
  char c[TAM_NOME];
  time_t t;
  Elemento vetor_el[500];
  
  /* Cria vetor de elementos de nomes aleatórios */
  printf("\nTeste de Elemento:\n\n");

  printf("Criando um elemento isolado...\n");
  Elemento vida_curta = elemento_cria("Vida Curta");
  printf("Foi criado um elemento chamado %s.\n", vida_curta->n);
  printf("Tentando destruir o %s...\n", vida_curta->n);
  elemento_destroi(vida_curta);
  printf("Elemento destruído.\n\n");

  printf("Tentando criar um vetor de 500 elementos aleatórios...\n");
  srand((unsigned) time(&t));
  for (i = 0; i < 500; i++) {
    r2 = (rand() % (TAM_NOME - 4)) + 3; 
    // 80 - 1: Tem que deixar 1 para o '\0'.
    // Tamanho mínimo é 3, para evitar strings vazias
    for (j = 0; j < r2; j++) {
      r1 = (rand() % 94) + 32; // Caracteres ascci vão de 32 a 126
      c[j] = r1;
    }
    c[r2] = '\0';
    vetor_el[i] = elemento_cria(c);
  }
  printf("Foram criados %d elementos.\n\n", i);
  
  if (i != 500) {
    printf("Erro ao criar o vetor. Saindo...\n");
    return EXIT_FAILURE;
  }
  
  printf("Todos os testes de elemento passaram.\n");
  printf("===========================================\n");

  /* TESTE DO MÓDULO DE LISTAS */
  printf("\nTeste de Lista:\n\n");
  printf("Criando uma lista...\n");
  Lista l = lista_cria(), vetor_l[500]; // TESTA "CRIA"
  printf("Criada uma lista vazia.\n");

  printf("Tentando inserir 500 elementos na lista\n");
  for (i = 0; i < 500; i++)
     vetor_l[i] = lista_insere(l, vetor_el[i]); // TESTA "INSERE"
  printf("Foram inseridos %d elementos na lista vazia.\n", i);

  if (i != 500) {
    printf("Erro ao inserir. Saindo...\n");
    return EXIT_FAILURE;
  }
  
  printf("Executando busca e retirada na lista...\n");
  for (i = 0; i < 500; i++) {
    if (vetor_el[i] != lista_busca(l, vetor_el[i]->n)) { // "TESTA BUSCA"
      printf("Erro de busca para %d\n", i);
      return EXIT_FAILURE;
    }
    if (vetor_l[i]->val != vetor_el[i]) {
      printf("Erro de retorno da função insere para vetor_l[%d]\n", i); // TESTA O RETORNO DE "INSERE"
      return EXIT_FAILURE;
    }
    lista_retira(l, vetor_el[i]); // TESTA "RETIRA"
    if (lista_busca(l, vetor_el[i]->n) != NULL) { // TESTA O RETORNO DE "BUSCA"
      printf("Erro ao retirar %d\n", i);
      printf("Busquei %s em l, que não deveria estar lá\n", vetor_el[i]->n);
      /* return EXIT_FAILURE; */
    }
  }
  printf("Fim dos testes de busca e retirada.\n");
  printf("Se não houveram mensagens de erro, os testes passaram. \n\n");

  printf("Destruindo a lista criada...\n\n");
  lista_destroi(l); // TESTA DESTROI

  printf("Todos os testes de lista passaram\n");
  printf("===========================================\n");

  /* TESTE DO MÓDULO DE TABELAS */
  printf("\nTeste de Tabela:\n\n");
  printf("Tentando criar uma tabela de 10 entradas...\n");
  Tabela tab;
  tab = tabela_cria (10);
  printf("Feito.\n");

  printf("Tentando preencher a tabela usando elementos e strings aleatórias...\n");
  int retorno_erro;
  char *str;
  str = malloc(80 * sizeof(char));
  for(i = 0; i < 500; i++) {
    str = gera_string(str, 80);
    retorno_erro = tabela_insere (tab, str, vetor_el[i]);
    if (retorno_erro == FALHA) {
      printf("Erro ao inserir na tabela. Saindo...\n");
      return EXIT_FAILURE;
    }
  }
  printf("Foram inseridos %d chaves e valores na tabela.\n", i);
  printf("Destruindo a tabela...\n");
  tabela_destroi(tab);
  printf("Feito.\n\n");

  printf("Tentando criar uma nova tabela...\n");
  Tabela tab2;
  tab2 = tabela_cria(10);
  printf("Feito.\n");
  Elemento elem, tmp;
  elem = elemento_cria("novo_elemento");
  
  if (tabela_insere(tab2, "Chave", elem)) {
    printf("Inserido um novo elemento na Tabela 2.\n");
  } else {
    printf("Erro ao inserir. Saindo...\n");
    return EXIT_FAILURE;
  }

  printf("Tentando buscar o elemento recém incerido na tabela...\n");
  tmp = tabela_busca(tab2, "Chave");
  if (tmp == NULL) {
    printf("Busca realizada com sucesso.\n");
  } else {
    printf("Erro na busca. Saindo...\n");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

char *gera_string (char *s, int tamanho) {
  int r;
  time_t t;
  srand((unsigned) time(&t));
  for (int j = 0; j < tamanho; j++) {
    r = (rand() % 94) + 32; // Caracteres ascci vão de 32 a 126
    s[j] = r;
  }
  s[tamanho] = '\0';
  return s;
}
