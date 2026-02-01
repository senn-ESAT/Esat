#include <stdio.h>
int num1;
int main(){
  printf("Numero?");
  scanf("%d", &num1);
  for(int i = 0; i <= num1; i++){
    //Esto calcula los espacios 
    for(int j = num1; j > i; j--){
      if(i > j){
        printf("*");
      }
      else{
	      printf(" ");
      }
    }
    printf("*");
    //esto llena el rombo 
    for(int y = 0; y < i*2; y++){
      printf("*");
    }
    printf("\n");
  }
  for(int i = num1-1; i >= 0; i--){
    //Esto calcula los espacios
    for(int j = num1; j > i; j--){
      if(i > j){
        printf("*");
      }
      else{
	      printf(" ");
      }
    }
    printf("*");
    //esto llena el rombo
    for(int y = 0; y < i*2; y++){
      printf("*");
    }
    printf("\n");
  }
}