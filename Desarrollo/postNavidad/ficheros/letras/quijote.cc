#include <stdio.h>
#include <string.h>

FILE *f;

void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int main(){
  int count = 0, index = 0;
  char palabra[20] = {"\0"};
  char palFile[20] = {"\0"};

  f = fopen("./ejercicio.txt", "r");

  printf("Que palabra?\n");
  fgets(palabra, 20, stdin);
  delEnter(palabra);

  do{
    char ch = fgetc(f);

    //if(ch == ' ' || ch == '\n' || ch == ',' || ch == '.' || ch == ';'){
    if(ch < 65){
      if(strcmp(strupr(palabra), strupr(palFile)) == 0){
        count++;
      }

      for(int i = 0; i < sizeof(palFile); i++){
        palFile[i] = '\0';
      }
      index = -1;
    }
    else{
      palFile[index] = ch;
    }
    index++;

  }while(!feof(f));

  printf("Numero: %d", count);
  
  return 0;
}