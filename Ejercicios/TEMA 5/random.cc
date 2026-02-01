#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int tope = 100;

int main(){
  srand(time(NULL)); /*genera semilla para numeros randoms de verdad*/
  for(int i=1; i<=tope; i++){
    printf(" %03d", rand()%100);
    if(i%10 == 0){
      printf("\n");
    }
  }
  return 0;
}