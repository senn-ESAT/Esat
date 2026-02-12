#include <stdlib.h>
#include <stdio.h>

enum Posicion{
  actual,
  proximo
};

struct TConjunto{
  int info;
  TConjunto *prox;
};

TConjunto* CrearConjunto(){
  TConjunto *a = nullptr;
  return a;
}

void IncluirConjunto(TConjunto **conj, int n){
  TConjunto *i;
  bool noRepite = true;
  for(i = *conj; i != nullptr; i = i->prox){
    if(i->info == n){
      noRepite = false;
    }
  }
  if(noRepite){
    free(i);
    i = nullptr;
    i = (TConjunto*)malloc(1*sizeof(TConjunto));
    
    i->prox = *conj;
    i->info = n;
    *conj = i;
  }
}

void MuestraConjunto(TConjunto *conj){
  TConjunto *i;
  for(i = conj; i != nullptr; i = i->prox){
    printf(" %d, ", i->info);
  }
}

void UnionConjunto(TConjunto *conj1, TConjunto *conj2, TConjunto **resp){
  TConjunto *i;
  bool repite = false;

  for(i = conj1; i != nullptr; i = i->prox){
    IncluirConjunto(resp, i->info);
  }
  for(i = conj2; i != nullptr; i = i->prox){
    IncluirConjunto(resp, i->info);
  }
}

void InterseccionConjunto(TConjunto *conj1, TConjunto *conj2, TConjunto **resp){
  TConjunto *i;
  TConjunto *j;
  TConjunto *a;
  
  for(i = conj1; i != nullptr; i = i->prox){
    bool presente = false;
    for(j = conj2; j != nullptr; j = j->prox){
      if(i->info == j->info){
        presente = true;
      }
    }
    if(presente){
      IncluirConjunto(&a, i->info);
      *resp = a;
    }
  }
}