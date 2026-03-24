#include <stdio.h>
#include <stdlib.h>
#include "barbol.cc"

Tree *animales;
bool restart = true;
int main(){
  initTree(&animales);

  while(restart){
    printf("Has pensando en un animal?");
    Questions(animales, getchar());
    

  }

  return 0;
}