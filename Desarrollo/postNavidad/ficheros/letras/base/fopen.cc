#include <stdio.h>

FILE *f;
char character;

int main(){
  // si no se encontro el fichero
  if((f=fopen("./hola.txt", "r")) == NULL){
    printf("ERROR: fichero no encontrado");
  }
  else{
    do{
      character = fgetc(f);
      printf("%c", character);
    }while(!feof(f));
    fclose(f);
  }

  return 0;
}