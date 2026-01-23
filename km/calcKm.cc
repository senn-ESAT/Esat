#include <stdio.h>
#include <string.h>

FILE *f1, *f2;
char start[255] = {"\0"}, stop[255] = {"\0"};

void inBin(){
  f1 = fopen("TablaKM.txt", "r");
  f2 = fopen("TablaBin.dat", "wb");
  
  while(!feof(f1)){
    char ch = fgetc(f1);

    fwrite(&ch, sizeof(ch), 1, f2);
  }
  fclose(f1);
  fclose(f2);
}

void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

void gestionString(){
  printf("Salida: ");
  fgets(start, 255, stdin);
  printf("Destino: ");
  fgets(stop, 255, stdin);
  delEnter(start);
  delEnter(stop);
}

int main(){
  char valor;
  bool searching = true;

  char info[3][255] = {"\0"};

  inBin();
  gestionString();

  f1 = fopen("TablaBin.dat", "rb");
  fputs(start, stdout);
  fputs(stop, stdout);

  int coma = 0, letra = 0;
  while(fread(&valor, sizeof(valor), 1, f1) && searching){
    if(valor != ';' && coma <3){
      info[coma][letra] = valor;
    }
    else{
      coma++;
      letra = -1;
    }
    
    if(coma == 3 && strcmp(strupr(info[0]), strupr(start)) == 0 && strcmp(strupr(info[1]), strupr(stop)) == 0){
      printf("Distancia entre "); fputs(start, stdout);
      printf(" y "); fputs(stop, stdout);
      printf(" es: "); fputs(info[2], stdout);
      searching = false;
    }
    
    if(coma == 4 || valor == '\n'){
      for(int a = 0; a < 3; a++){
        for(int b = 0; b < 255; b++){
          info[a][b] = '\0';
        }
      }
      
      coma = 0;
      letra = -1;
    }
    letra++;
  }

  return 0;
}