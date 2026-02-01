#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct AM {
  int alfa;
  char morse[6];
}

AM[36] = {
	{'A', ".-"},
	{'B', "-..."},
	{'C', "-.-."},
	{'D', "-.."},
	{'E', "."},
	{'F', "..-."},
	{'G', "--."},
	{'H', "...."},
	{'I', ".."},
	{'J', ".---"},
	{'K', "-.-"},
	{'L', ".-.."},
	{'M', "--"},
	{'N', "-."},
	{'O', "---"},
	{'P', ".--."},
	{'Q', "--.-"},
	{'R', ".-."},
	{'S', "..."},
	{'T', "-"},
	{'U', "..-"},
	{'V', "...-"},
	{'W', ".--"},
	{'X', "-..-"},
	{'Y', "-.--"},
	{'Z', "--.."},
	{'0', "-----"},
	{'1', ".----"},
	{'2', "..---"},
	{'3', "...--"},
	{'4', "....-"},
	{'5', "....."},
	{'6', "-...."},
	{'7', "--..."},
	{'8', "---.."},
	{'9', "----."}
};

void delEnter(char text[255]){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

void AlfMor(){
  char frase[255];
  while (getchar() != '\n');
  fgets(frase, sizeof(frase), stdin);
  
  for(int i = 0; i < strlen(frase); i++){
    strupr(&frase[i]);
    for(int j = 0; j < 36; j++){
      if(int(frase[i]) == AM[j].alfa){
        fputs(AM[j].morse, stdout);
      }
    }
    if(frase[i] == ' '){
      printf(" ");
    }
  }
}

// WIP
void MorAlf(){
  while (getchar() != '\n');

  char frase[255];
  char PalMorse[6];
  fgets(frase, 255, stdin);
  delEnter(frase);
  int ini = 0, fin = 0;

  for(int i = 0; i < strlen(frase)+1; i++){
    if (frase[i] == ' ' || frase[i] == '\0') {
      fin = i-1;
      for(int j = 0; j <= (fin-ini); j++){
        PalMorse[j] = frase[ini+j];
        if(j == fin-ini)
          PalMorse[j+1] = '\0';
      }

      for(int j = 0; j < 36; j++){
        
      if (strcmp(PalMorse, AM[j].morse) == 0){
          printf("%c", AM[j].alfa);
        }
      }
      ini = i+1;
    }
    if(frase[i] == ' '){
      printf(" ");
    }
  }
}

void MorLive(){
  char letra;
  while(int(letra) != 27){
    letra = getch();
    strupr(&letra);
    for(int i = 0; i < 36; i++){
      if(int(letra) == AM[i].alfa){
        fputs(AM[i].morse, stdout);
      }
    }
    if(letra == ' '){
      printf("  ");
    }
  }
}

int main(){
  int menu = 0;
  system("CLS");
  
  while(menu != 4){
    printf("\n1 ... ALFABETO MORSE\n2 ... MORSE ALFABETO\n3 ... MORSE TECLA\n4 ... SALIR\n");
    scanf("%d", &menu);

    switch(menu){
      case 1:
        system("cls");
        AlfMor();
      break;
      case 2:
        system("cls");
        MorAlf();
      break;
      case 3:
        system("cls");
        MorLive();
      break;
    }
  }

  return 0;
}