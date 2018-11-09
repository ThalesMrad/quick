#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "quicksort.h"

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara, int *troca) {

  int esq, dir;
  elemento pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vetor[inicio];

  while(esq < dir){
    while(vetor[esq].ch <= pivo.ch && esq < fim) { // vetor[esq] <= pivo
      (*compara)++;
      esq++;
    }

    while(pivo.ch < vetor[dir].ch){ //  vetor[dir] > pivo
      dir--;
      (*compara)++;
    }

    if(dir < inicio || esq > fim) printf("\nERRO\n\n");

    if(esq < dir){
      aux = vetor[esq]; // troca vetor[esq] com vetor[dir]
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
      (*troca)++;
    }
  }

  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  // printf("Vetor ordenado entre %d e %d\n", inicio, fim);
  // for (int i=inicio; i < fim; i++)
  //     printf("%d ", vetor[i].ch);
  // printf("\n");
  return dir;               //retorna dir, que é o índice que vai dividir o vetor
}

void quickStruct(elemento *vetor, int inicio, int fim, int *compara, int *troca){

  int pivo;

  if(inicio < fim){
    pivo = particionaStruct(vetor, inicio, fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickStruct(vetor, inicio, pivo-1, compara, troca); // realiza a partição para a parte da esquerda
    quickStruct(vetor, pivo+1, fim, compara, troca); // e realiza a partição para a parte de direita
  }
}


int particionaInt(int *vetor, int inicio, int fim, int *compara, int *troca){

  int esq, dir;
  int pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vetor[inicio];

  while(esq<dir){
    while(vetor[esq] <= pivo && esq<fim) { // vetor[esq] <= pivo
      esq++;
      (*compara)++;
    }

    while(pivo < vetor[dir]) { //  vetor[dir] > pivo
      (*compara)++;
      dir--;
    }

    if(dir < inicio || esq > fim) printf("\nERRO\n\n");

    if(esq < dir){
      aux = vetor[esq]; // troca vetor[esq] com vetor[dir]
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
      (*troca)++;
    }
  }

  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  return dir;               //retorna dir, que é o índice que vai dividir o vetor
}

void quickInt(int *vetor, int inicio, int fim, int *compara, int *troca){

  int pivo;

  if(inicio < fim){
    pivo = particionaInt(vetor,inicio,fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickInt(vetor, inicio, pivo-1, compara, troca); // realiza a partição para a parte da esquerda
    quickInt(vetor, pivo+1, fim, compara, troca); // e realiza a partição para a parte de direita
  }
}

//Função para particionar a Lista colocando o pivo no meio, tudo que for menor
//antes e todos os maiores depois
Elem* particionaLista(Elem* esq, Elem* dir){
  int x = dir->num;
  Elem* i,j = dir->ant;
  for(i = esq;i!= dir;i=i->prox){
    while(i->num > x){
      if(j->num <= x){
        troca(&(i->num),&(j->num));
      }else{
        j = j->ant;
      }
    }
  }
  troca(&(j->num),&(dir->num));
  return j;
}

void quickLista(Elem* esq,Elem* dir){
  Elem* pivo;
  if (dir != NULL && esq != dir && esq != dir->prox){
    pivo =  particionaLista(esq, dir);
    printf("pivo = %d\n",pivo->num);
    quickLista(esq, pivo->ant);
    quickLista(pivo->prox, dir);
  }
  }
