#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int A = 100;
int num[A] = {0}, random;

void Control(int rand){
  for(int i = 0; i<A; i++){
    if(i == rand){
      num[i]++;
    }
  }
}

void Generacion(){
  for(int i = 0; i<1000; i++){
    random = (" %03d", rand()%100);
    Control(random);
  }
}

void Resultado(){
  for(int i = 0; i<A; i++){
    printf("[%03d]: %03d ", i+1, num[i]);
    if((i+1)%5 == 0)printf("\n");
  }
}

void MyM(){
  int min = 1000, max = 0, imin = 0, imax = 0;
  for(int i = 0; i<A; i++){
    if(min > num[i]){
      min = num[i];
      imin = i+1;
    }
    if(max < num[i]){
      max = num[i];
      imax = i+1;
    }
  }
  printf("Mas repetido: %d \nMenos repetido: %d", imax, imin);
}

int main(){
  srand(time(NULL)); /*genera semilla para numeros randoms de verdad*/
  
  Generacion();
  Resultado();
  MyM();
}