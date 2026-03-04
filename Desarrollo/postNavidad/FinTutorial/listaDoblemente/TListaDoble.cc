#include <stdio.h>
#include <stdlib.h>

struct TLista2{
  int numero, info;
  TLista2 *prox;
  TLista2 *pre;
};

TLista2* CrearLista(){
  return nullptr;
}

void InsertarLista(TLista2 **lista, int num){
  TLista2 *temp;

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
    printf("%d ", loop->numero);
  }
}
TLista2* BuscarEnLista(TLista2 *lista, int num){
  TLista2 *loop = nullptr;
  for(loop = lista; loop != nullptr; loop = loop->prox){
    if(loop->numero == num){
      loop->info = loop->numero;
      return loop;
    }
  }
  return nullptr;
}

void InvertidoMostrarLista(TLista2 *lista){
  TLista2 *loop = nullptr;
  TLista2 *end = nullptr;
  for(loop = lista; loop != nullptr; loop = loop->prox){
    if(loop->prox == nullptr){
      for(end = loop; end != nullptr; end = end->pre){
        printf("%d ", end->numero);
      }
    }
  }
}

TLista2* ExtraerLista(TLista2 **lista){
  TLista2* value;
  value = *lista;
  value->info = value->numero;
  (*lista)->prox->pre = nullptr;
  (*lista) = (*lista)->prox;
  return value;
}

void EliminarElemento(TLista2 **lista, int num){
  bool encontrado = false;
  while((*lista)->prox != nullptr){
    // if numero entonces pre prox = actual prox and prox pre = actual pre
    // else lista = lita
    if((*lista)->numero == num){
      (*lista)->pre->prox = (*lista)->prox;
      (*lista)->prox->pre = (*lista)->pre;
      encontrado = true;
    }
    (*lista) = (*lista)->prox;
  }
  // no verifica el ultimos por como hice el while
  if((*lista)->numero == num){
    (*lista)->pre->prox = nullptr;
  }
  // posicion actual de lista es el ultimo asi que volvemos al inicio
  while((*lista)->pre != nullptr){
    (*lista) = (*lista)->pre;
  }
}

int LongitudLista(TLista2 *lista){
  TLista2 *loop = nullptr;
  int i = 0;
  for(loop = lista; loop != nullptr; loop = loop->prox){
    i++;
  }
  return i;
}