#include <stdio.h>
#include <stdlib.h>

int num, fact;

void SumaSerie(int j){
  int sum = 0;
  for(int y = 0; y <= j; y++){
    sum += y;
  }
  printf("%10d", sum);
}

void Factorial(int j){
  fact = 1;
  for(int y = 1; y <= j; y++){
    fact *= y;
  }
  printf("%70d", fact);
}

void Primo(){
  bool primo = true;
  int count = 2;
  do{
    if(fact%count == 0){
      for(int y = count; y <= fact; y++){
        if(fact%y == 0){
          printf(" %d,", y);
        }
      }
      primo = false;
    }
    count++;
  }while(fact < count && primo == true);
  if(primo == true){
    printf("Es primo");
  }
}

int main(){
  printf("Limite?");
  scanf("%d", &num);
  for(int i = 1; i <= num; i++){
    printf("%03d", i);
    SumaSerie(i);
    Factorial(i);
    Primo();
    printf("\n");
  }
  return 0;
}