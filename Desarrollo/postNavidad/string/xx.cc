#include <stdio.h>

//--------string.h--------------
void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int stringLength(char *text){
  int count = 0;
  bool end = true;
  while(end){
    if(text[count] != '\0'){
      count++;
    }
    else{
      end = false;
    }
  }
  return count;
}

bool findWord(char *text, char *word, int pos){
  int i = 0;
  while(word[i] != '\0'){
    if(text[pos + i] != word[i]){
      return false;
    }
    i++;
  }
  return true;
}

int main(){
  char frase[255];
  char censura[255];

  // Leer frase
  fgets(frase, 254, stdin);
  delEnter(frase);

  // Leer palabra a censurar
  fgets(censura, 254, stdin);
  delEnter(censura);

  int lenFrase = stringLength(frase);
  int lenCensura = stringLength(censura);
  
  for(int i = 0; i <= lenFrase - lenCensura; i++){
    if(findWord(frase, censura, i)){
      for(int j = 0; j < lenCensura; j++){
        frase[i + j] = 'x';
      }
    }
  }

  fputs(frase, stdout);
  return 0;
}