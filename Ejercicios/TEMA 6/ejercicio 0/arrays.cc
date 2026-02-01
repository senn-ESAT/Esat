#include <stdio.h>

const int A = 4;
int num[A] = {4, 2, 68, 4};

void Muestra(){
  for(int i = 0; i<A; i++){
    printf("%d ", num[i]);
  }
  printf("\n");
}

void Modifica(int v[A]){
  for(int i = 0; i<A; i++){
    v[i]++;
  }
}

int main(){
  Muestra();
  Modifica(num);
  Muestra();
}