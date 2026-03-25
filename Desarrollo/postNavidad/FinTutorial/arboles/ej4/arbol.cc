#include <stdio.h>
#include <stdlib.h>
#include "barbol.cc"

int main(){
  Tree *animales;
  bool restart = true, end = false;
  FILE *file;

  initTree(&animales);

  while(restart){
    printf("Has pensando en un animal?");
    while(!end){
    Questions(animales, getchar());

    }
  }

  return 0;
}