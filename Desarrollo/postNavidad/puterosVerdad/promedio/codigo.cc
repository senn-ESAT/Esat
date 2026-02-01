#include <stdio.h>
#include <stdlib.h>

struct TDato{
  unsigned char nace, altura, peso;
};

FILE *f;
TDato *puntero = nullptr;

int main(){
  TDato valor;

  f = fopen("muestreo.dat", "rb");
  int lineas = 0;

  int year;
  printf("Nacimiento: ");
  scanf("%d", &year);

  if(f != NULL){
    while(fread(&valor, sizeof(valor), 1, f) == 1){
      // si multiplico x 0 se rompe pero necesito inicializar en 0 para futuros bucles
      puntero = (TDato*)realloc(puntero, (lineas+1)*sizeof(TDato));
      
      if(puntero && year == (int)valor.nace){
        
        puntero[lineas] = valor;
        lineas++;
      }
    }
    fclose(f);
  }
  else{
    printf("404");
  }

  int altura = 0, peso = 0;

  for(int i = 0; i < lineas; i++){
    altura += (int)puntero[i].altura;
    peso += (int)puntero[i].peso;
  }

  printf("Peso promedio es: %d y la altura es: %d", peso/lineas, altura/lineas);

  free(puntero); 
  puntero = nullptr;
  return 0;
}