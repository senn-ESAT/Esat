#include <stdlib.h>
#include <stdio.h>

enum Posicion{
  actual,
  proximo
};

struct TLista{
  int info;
  TLista *prox;
};

void CrearLista(TLista **lista){
  lista = nullptr;
}

void InsertarLista(TLista **lista, int a){
  TLista *aux;
  aux = (TLista*)malloc(1*sizeof(TLista));
  
  aux->prox = *lista;
  aux->info = a;
  *lista = aux;
}

void MuestraLista(TLista *lista){
  TLista *p;
  for(p = lista; p != nullptr; p = p->prox){
    printf(" %d, ", p->info);
  }
}

TLista* IndexaLista(TLista *lista, int posicion){
  TLista *p = nullptr;
  for(int i = 0; i <= posicion && lista != nullptr; lista = lista->prox){
    if(i == posicion){
      p = lista;
    }
    i++;
  }

  return p;
}

TLista* BuscarLista(TLista *lista, int n, Posicion actual){
  TLista *aux;

  for(aux = lista; aux != nullptr; aux = aux->prox){
    if(aux->info == n)
      return aux;
  }
  return aux;
} 

void EliminaEnLista(TLista **lista, int n){
  TLista *aux = nullptr;
  TLista *anterior = nullptr;
  TLista *respuesta = nullptr;
  aux = *lista;

  while(aux->prox != nullptr){
    if(aux->info == n){
      anterior->prox = aux->prox;
    }
    
    anterior = aux;
    aux = aux->prox;
  }
  (*lista) = respuesta;
  // free(respuesta);
  // respuesta = nullptr;
}