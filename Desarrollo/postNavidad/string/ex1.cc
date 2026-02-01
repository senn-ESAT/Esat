#include <stdio.h>
#include <string.h>

char words[20][20];

void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int main() {
  int count = 0;
  bool stay = true;

  while (count < 20 && stay) {
    fgets(words[count], 20, stdin);
    delEnter(words[count]);    

    if (strcmp(words[count], "salir") == 0) {
      stay = false;
    }

    count++;
  }

  for (int i = 0; i < count; i++) {
    int len = strlen(words[i]);
    for (int j = len - 1; j >= 0; j--) {
      putchar(words[i][j]);
    }
    printf("\n");
  }

  return 0;
}
