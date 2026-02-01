#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *f;
const int numSize = 10;
int cambio;

void aperturaFichero(){
  f = fopen("fichero.dat", "wb+");

  for(int i = 0; i < numSize; i++ ){
    int num = i;
    fwrite(&num, sizeof(num), 1, f);
    printf(" %d ", num);
  }
  fclose(f);

}

void inputUser(){
  int pos, cambio;
  printf("\nNumero:\n");
  scanf("%d", &pos);
  
  printf("\nChange:\n");
  scanf("%d", &cambio);
}

void printFile(){
  printf("-------------");
  f = fopen("fichero.dat", "rb+");
  
  int valor;
  while(fread(&valor, sizeof(valor), 1, f)){

    if(cambio == valor){
      fseek(f, -1*sizeof(cambio), SEEK_CUR);
      fwrite(&cambio, sizeof(cambio), 1, f);
      fseek(f, +1*sizeof(cambio), SEEK_CUR);
    }
  }
}

int main(){
  srand(time(NULL));

  aperturaFichero();

  inputUser();

  printFile();
  fclose(f);

  return 0;
}