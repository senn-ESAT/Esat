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
  TLista *aux;
  TLista *proximo;
  aux = *lista;
  do{
    printf("a");
    proximo = aux->prox;

    if(aux->info == n){
      aux->info = proximo->info;
      aux->prox = proximo->prox;
    }

    if(proximo->info == n){
      printf("b");

      aux->prox = proximo->prox;
    }
    else{
      printf("c");
      aux = aux->prox;
    }
  }while(aux->prox != nullptr);
}