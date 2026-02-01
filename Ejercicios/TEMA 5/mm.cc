#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r, r1, r2, r3, r4, numero, n1, n2, n3, n4, intentos;

void random(){
  do{
    srand(time(NULL)); /*genera semilla para numeros randoms de verdad*/
    r = (" %03d", rand()%10000);
    r1 = r/1000;
    r2 = (r-r1*1000)/100;
    r4 = r%10;
    r3 = (r%100 - r4)/10;
  }while(r1==r2 || r1==r3 || r1==r4 || r2==r3 || r2==r4 || r3=r4);
}

void juego(){
  printf("Numero intentos?");
  scanf();

/*loop juegi y despues llama input*/  
}

void input(){

}

int main(){
  random();
  juego();
  return 0;
}