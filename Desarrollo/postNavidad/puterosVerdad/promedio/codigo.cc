#include <stdio.h>
#include <stdlib.h>

struct TDato{
  unsigned char nace, altura, peso;
};

FILE *f;
char *puntero = nullptr;

int main(){
  TDato valor;

  f = fopen("muestreo.dat", "rb");
  int lineas = 1;

  // todo esta mal

  while(fread(&valor, sizeof(valor), 1, f)){
    if(lineas == 1){
      puntero = (char*)malloc(sizeof(valor.));
    }
    else{
      puntero = (char*)realloc(puntero, lineas*sizeof(TDato));
    }
    lineas++;
  }
  fclose(f);

  int year;
  printf("Nacimiento: ");
  scanf("%d", &year);

  for(int i = 0; i < lineas; i++){
    if()
  }

  free(puntero); 
  return 0;
}