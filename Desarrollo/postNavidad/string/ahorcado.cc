#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int health = 6;
char words[10][11] = {
    "perro",
    "gato",
    "casa",
    "auto",
    "amigo",
    "playa",
    "futbol",
    "mate",
    "ciudad",
    "familia"
};  // the 11th position is \0 so the words are max 10 letters

void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int main(){
  system("cls");
  srand(time(NULL));        // reset del time 
  
  bool win = false;         // check if the player has won
  int word = rand()%10;     // random choise of the word 
  char in[11] = {1, "\0"};
  bool visible[11] = {0};

  visible[0] = true;
  visible[strlen(words[word]) - 1] = true;

  // while the player still have lives and has not won yet 
  while(health > 0 && win == false){
    system("cls");  // clean the console
    printf("[HEALTH]: %d\n", health); // show health
    for(int i = 0; i < strlen(words[word]); i++){
      if(visible[i] == true){
        printf("%c ", words[word][i]);
      }
      else{
        printf("_ ");
      }
    }
    printf("\n");

    fgets(in, sizeof(in), stdin);
    delEnter(in);

    if(strcmp(in, words[word]) == 0){
      win = true;
    }
    else{
      for(int i = 0; i < strlen(words[word]) && i < strlen(in); i++){
        if(words[word][i] == in[i]){
          visible[i] = true;
        }
      }
      health--;
    }
  }

  if(win){
    printf("YOU WIN");
  }
  else{
    printf("YOU LOSE");
  }

  return 0;
}