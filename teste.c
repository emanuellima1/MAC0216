#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lista.h"

int main() {

  int i, j, r1, r2;
  char c[80];
  time_t t;
  Elemento vetor_el[500];
  
  /* Cria vetor de elementos de nomes aleatórios */
  
  srand((unsigned) time(&t));
  for (i = 0; i < 500; i++) {
    r2 = rand() % 79; // 80 - 1: Tem que deixar 1 para o '\0';
    for (j = 0; j < r2; j++) {
      r1 = (rand() % 94) + 32; // Caracteres ascci vão de 32 a 126
      c[j] = r1;
    }
    c[r2] = '\0';
    vetor_el[i] = elemento_cria(c);
  }

  /* TESTE DO MÓDULO DE LISTAS */
  
  Lista l = lista_cria(), vetor_l[500]; // TESTA "CRIA"
  
  for (i = 0; i < 500; i++)
    vetor_l[i] = lista_insere(l, vetor_el[i]); // TESTA "INSERE"
  
  for (i = 0; i < 500; i++) {
    if (vetor_el[i] != lista_busca(l, vetor_el[i] -> n)) // "TESTA BUSCA"
      printf("Não ok para %d\n", i);

    if (vetor_l[i] -> val != vetor_el[i])
      printf("Não ok para vetor_l[%d]\n", i); // TESTA O RETORNO DE "INSERE"

    lista_retira(l, vetor_el[i]); // TESTA "RETIRA"
    if (lista_busca(l, vetor_el[i] -> n) != NULL) // TESTA O RETORNO DE "BUSCA"
      printf("Não ok para retirar %d\n", i);
  }
  
  lista_destroi(l); // TESTA DESTROI
}
