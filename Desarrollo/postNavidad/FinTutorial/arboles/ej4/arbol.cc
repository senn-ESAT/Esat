#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "barbol.cc"

int main(){
  Tree *animales = nullptr;
  bool restart = true, end = false;
  FILE *file;
  char result;
  initTree(&animales);

  while(restart){
    printf("Has pensando en un animal?");

    result = Question(&animales);
    Answere(&animales, result);

    printf("\n\nQuieres intentarlo de nuevo?\n");
    
    do{
      result = getch();
    }while(result != 's' && result != 'S' && result != 'n' && result != 'N');

    if(result == 's' || result == 'S'){
      restart = true;
    }else{
      restart = false;
    }
  }
  
  return 0;
}