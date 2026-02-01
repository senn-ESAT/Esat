#include <stdio.h>

const int mx = 6;
int num1[mx+1] = {1,0,0,1,0,1}, num2[mx+1] = {1,1,0,1,0,0}, suma[mx+1] = {0};

int Suma(int j){
  int extra = 0;
  if(num1[j] != num2[j]){
    suma[j] = 1;
  }
  else{
    if(num1[j] == 0){
      suma[j] = 0;
    }
    else{
      suma[j] = 0;
      extra = 1;
    }
  }
  return extra;
}

void Extra(int j){
  if(num1[j+1] == 1){
    num1[j+1] = 0;
  }
  else{
    num1[j+1] = 1;
  }
}

void Dysplay(){
  for(int i = 0; i<mx; i--){
    printf("%d",num1[i]);
  }
  printf("+\n");
  for(int i = 0; i<mx; i--){
    printf("%d",num2[i]);
  }
  printf("=\n");
  for(int i = 0; i<mx; i--){
    printf("%d",suma[i]);
  }
}

int main(){
  for(int i = mx; i>0; i--){
    printf("%d", Suma(i));
    if(Suma(i) == 1){
      Extra(i);
    }
  }
  Dysplay();
}