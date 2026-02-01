#include <stdio.h>
int var1, var2;

void Swap(int *a, int *b){
  int interm;
  interm = *a;
  *a = *b;
  *b = interm;  
}

void Muestra(int a, int b){
  printf("%d %d \n", a, b);
}

int main(){
  printf("Numero 1:");
  scanf("%d", &var1);
  printf("Numero 2:");
  scanf("%d", &var2);
  Muestra(var1, var2);
  Swap(&var1, &var2);
  Muestra(var1, var2);
}