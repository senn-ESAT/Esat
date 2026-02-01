#include <stdio.h>

void delEnter(char text[255]){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int main() {
  char text[80];
  fgets(text, 80, stdin);
  delEnter(text);

  int iniP = 0;

  for (int i = 0; i<80; i++) {
    if (text[i] == ' ' || text[i] == '\0') {
      int finP = i - 1;

      while (iniP < finP) {
        char tmp = text[iniP];
        text[iniP] = text[finP];
        text[finP] = tmp;
        iniP++;
        finP--;
      }
      iniP = i + 1;
    }
  }

  fputs(text, stdout);
  return 0;
}