#include <stdio.h>
#include <string.h>

void delEnter(char text[255]){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

// palindromos?
int main(){
  char palabra[20] = {"\0"};
  fgets(palabra, 20, stdin);
  delEnter(palabra);

  int iniP = 0;
  int finP = strlen(palabra) - 1; //posicion es -1 de la palabra porque 0
  bool pal = true;

  while (iniP < finP && pal){
    if(palabra[iniP] != palabra[finP]){
      pal = false;
    }
    iniP++;
    finP--;
  }

  if(pal)
    printf("ES PALINDROMO");
  else
    printf("NO ES");
  

  return 0;
}