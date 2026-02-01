#include <stdio.h>
#include  <stdlib.h>
#include <string.h>

struct Year{
  char year[5] = {"2026"};  // the year
  int maches = 0;         // thew amount of matches with the numbers
};

FILE *f1, *f2;
char numbers[6][5] = {"\0"};
// sizeof devuelve el numero de bits, no ella grandeza de un array como creia
// divideindolo por el mismo sizeof devielve ahora si la dimension del array
char LEN (sizeof(numbers) / sizeof(numbers[0]));

void inBin(){
  f1 = fopen("resultados.txt", "r");
  f2 = fopen("TablaResultados.dat", "wb");
  
  while(!feof(f1)){
    char ch = fgetc(f1);

    fwrite(&ch, sizeof(ch), 1, f2);
  }
  fclose(f1);
  fclose(f2);
}

void delEnter(char *text, int strl){
  for(int i=0; i<strl; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

bool noRepetition(char *num){
  for(int i = 0; i < LEN; i++){
    if(strcmp(num, numbers[i]) == 0){
      return false;
    }
  } 
  return true;
}

void gestionNumbers(){
  int nIn = 0;
  while(nIn < LEN){
    char in[5];
    printf("Insertar numero [1-49]");
    fgets(in, sizeof(in), stdin);
    delEnter(in, strlen(in));
    int value = atoi(in);


    if(value >= 1 && value <= 49 && noRepetition(in)){
      strcpy(numbers[nIn], in);
      nIn++;
    }
  }
}

int main(){
  char valor;
  
  /* 85-2026*/
  Year winnerYear;  // the year with most maches
  Year thisYear;    // the current year in the loop

  
  inBin();
  gestionNumbers();

  f1 = fopen("TablaResultados.dat", "rb");

  // 2026;15;16;23;27;37;39;13;2;;
  // 0   1  2  3  4  5  6  7  8 9 10 \n 
  char info[11][5] = {"\0"};
  int coma = 0, letra = 0;;
  while(fread(&valor, sizeof(valor), 1, f1)){
    if(valor != ';'){
      info[coma][letra] = valor;
    }
    else{
      info[coma][letra+1] = '\0';
      coma++;
      letra = -1;
    }

    
    // coma == 1 para verificar solo cuando se completa la carga del año y lo mira solo una ves
    if(strcmp(thisYear.year, info[0]) != 0 && coma == 1){
      if(thisYear.maches > winnerYear.maches){
        winnerYear = thisYear;
      }
      thisYear.maches = 0;
      strcpy(thisYear.year, info[0]);
    }
    
    if(valor == '\n'){
      //control if numbers are equal
      for(int i = 0; i < LEN; i++){
        for(int j = 1; j < 9; j++){
          if(strcmp(numbers[i], info[j]) == 0){
            thisYear.maches += 1;
          }
        }
      }

      for(int a = 0; a < 11; a++){
        for(int b = 0; b < 5; b++){
          info[a][b] = '\0';
        }
      }
      
      coma = 0;
      letra = -1;
    }
    letra++;
  }

  printf("\nThe year with most matches is: "); fputs(winnerYear.year, stdout);
  printf(" with %d matches", winnerYear.maches);

  return 0;
}