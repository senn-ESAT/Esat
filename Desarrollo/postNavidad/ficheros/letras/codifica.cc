#include <stdio.h>
#include <string.h>

FILE *f;
char copia[255] = {"\0"};

void writeClose(){
  fputs(copia, f);
  fclose(f);
}

void decCod(bool ope){
  for(int i = 0; i<strlen(copia); i++){
  if(ope == true)
    copia[i]+=3;
  else
    copia[i]-=3;
  }
}

int main(){
  printf("TEXTO?\n");
  fgets(copia, 255, stdin);

  f=fopen("./original.txt", "w");
  writeClose();

  decCod(true);
  f=fopen("./encriptado.txt", "w");
  writeClose();

  decCod(false);
  f=fopen("./post.txt", "a");
  writeClose();
  
  return 0;
}