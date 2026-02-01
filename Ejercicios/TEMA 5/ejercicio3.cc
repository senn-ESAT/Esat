#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float num, result = 0;

float factorial(int num){
  if(num == 0){
    return 1;
  }
  else{
    num * factorial(num-1);
  }
}

int main(){
  printf("Numero:");
  scanf("%f", num);
  result = factorial(num);
  printf("Factorial: %f", result);
  return 0;
}