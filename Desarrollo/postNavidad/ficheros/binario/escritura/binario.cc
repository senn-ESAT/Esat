#include <stdio.h>

FILE *f;
int valor;

int main(){
  f = fopen("cincoN.dat", "wb");
  for(int i = 0; i < 5; i++){
    printf("\nNumero:");
    scanf("%d", &valor);

    fwrite(&valor, sizeof(valor), 1, f);
  }
  fclose(f);

  f = fopen("cincoN.dat", "rb");
  while(!feof(f)){
    fread(&valor, sizeof(valor), 1, f);
    printf("%d\n", valor);
  }
  fclose(f);

  return 0;
}