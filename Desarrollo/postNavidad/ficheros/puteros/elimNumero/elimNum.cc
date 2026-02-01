#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *f;
const int numSize = 10;
int del;

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
  printf("\nNumero:\n");
  scanf("%d", &del);
}

void printFile(){
  File *temp;
  f = fopen("fichero.dat", "rb+");
  temp = fopen("temp.dat", "wd");
  
  int valor;
  while(fread(&valor, sizeof(valor), 1, f)){
    if(del != valor){
      fwrite(&del, sizeof(del), 1, temp);
    }
  }
  fclose(f);
  fclose(temp);

  remove("fichero.dat");
  rename("temp.dat", "fichero.dat");
}

int main(){
  srand(time(NULL));

  aperturaFichero();

  inputUser();

  printFile();

  return 0;
}