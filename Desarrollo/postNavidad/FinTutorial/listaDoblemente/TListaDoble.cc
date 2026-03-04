#include <stdio.h>
#include <stdlib.h>

struct TLista2{
  int numero;
  TLista2 *prox;
  TLista2 *pre;
};

TLista2* CrearLista(){
  return nullptr;
}

void InsertarLista(TLista2 **lista, int num){
  TLista2 *temp;
  printf("[Malloc ");

  temp = (TLista2*)malloc(1 * sizeof(TLista2));

  temp->numero = num;
  temp->prox = *lista;
  temp->pre = nullptr;

  // Si la lista no estaba vacía
  if(*lista != nullptr){
    (*lista)->pre = temp;
  }
  
  *lista = temp;
}

void MostrarLista(TLista2 *lista){
  TLista2 *loop = nullptr;
  for(loop = lista; loop != nullptr; loop = loop->prox){
    printf("%d-", loop->numero);
  }
}