#include <stdio.h>

FILE *f, *write;
int valor;

int main(){
  int i = 0;
  int par = 0;

  f = fopen("numeros.dat", "rb");
  
    
  while(fread(&valor, sizeof(valor), 1, f)){
    if(valor % 2 == 0){
      write = fopen("par.dat", "ab");
      fwrite(&valor, sizeof(valor), 1, write);
      fclose(write);

      printf(" %03d ", valor);
      par++;
      if(par%20 == 0){
        printf("\n");
      }
    }
    else{
      write = fopen("inpar.dat", "ab");
      fwrite(&valor, sizeof(valor), 1, write);
      write = fopen("inpar.dat", "ab");
    }
    i++;
  }
  fclose(f);

  return 0;
}