#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int lim = 10;
int matriz[lim+1][lim+1] = {0};

void Generacion(){
  int sum = 0;
  srand(time(NULL));
  for(int i = 0; i<=lim; i++){
    for(int j = 0; j<=lim; j++){
      matriz[i][j] = ("%03d", rand()%100);
      sum += matriz[i][j];
    }
    Lineas(sum, i);
    sum = 0;
  }
}

void Lineas(int result, int index){
  matriz[index][lim] = result;
}

void SumCol(){
  int sum= 0
  for(i = 0; i<lim-1; i++){
    for(int j = 0; j<lim-1; j++){
      sum += matriz[j][i];
    }
    matriz[lim][j] = sum;
    sum = 0;
  }
}

void Dysplay(){
  for(int i = 0; i <= lim; i++){
    for(int j = 0; j<= lim; j++){
      printf("%03d", matriz[i][j]);
    }
  }
}

int main(){
  Generacion();
  SumCol();
  Dysplay();
}