#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int intentos = 10, random, input;
  srand(time(NULL)); /*genera semilla para numeros randoms de verdad*/
  random = (" %03d", rand()%100)+1;
  do{
    printf("adivina el numero %d intentos \n", intentos);
    scanf("%03d", &input);
    intentos--;
  }while(intentos >= 1 && input != random);
  if(input != random){
    printf("El numero es %d", random);
  }
  else{
    printf("GANASTE");
  }
  return 0;
}