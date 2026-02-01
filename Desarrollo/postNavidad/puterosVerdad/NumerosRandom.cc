#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *p = nullptr;


int main(){
  srand(time(NULL));
  int NumIn;
  int espacio = rand()%1000;


  printf("Bloque en heap de %d elementos\n", espacio);

  // reserva espacio malloc calloc realloc

  p=(int*)malloc(espacio*sizeof(int));

  for(int i = 0; i < espacio; i++){
    *(p+i)= 1+rand()%100;
  }

  printf("valor a buscar: ");
  scanf("%d", &NumIn);

  int encuentro = 0;
//no funcica

  for(int i = 0; i < espacio; i++){
    if(&(p+i) == NumIn){
      encuentro++;
    }
  }

  printf("\n%d ", encuentro);
  return 0;
}