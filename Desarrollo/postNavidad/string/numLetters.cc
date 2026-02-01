#include <stdio.h>
#include <string.h>

int main(){
  const int max = 30, iniP = 0;
  char abominio[max] = {"\0"};
  fgets(abominio, max, stdin);
  int ini = 0;
  
  // 48-57 ascii numero de 0 a 9
  // 48 es 0 restas el asci del nuermo a 48 y te sale el numero
  for(int i = 0; i < strlen(abominio); i++){
    int fin = 0;
    int nv = 0;
    // si el caracter es un numero entonces entra
    if(int(abominio[i]) >= 48 && int(abominio[i]) <= 57){
      nv = (int(abominio[i]) - 48);   // calcula que numero es el caracter
      ini = i+1;                      // ini es i+1 porque i es el numero
      int j = ini;                    // j es para el bucle de adelante que encuentra el fin de la palabra
      // mientras que no sea el fin de el array y no sea un numero sigue
      while(abominio[j] != '\0' && int(abominio[j]) < 48 || int(abominio[j]) > 57){
        fin = j;
        j++;
      }
    }

    // el for repite las paralbras y el while escribe las letras
    for(int j = 0; j < nv; j++){  
      int nl = 0; // contador de letras
      while(ini + nl < fin){
        printf("%c", abominio[ini+nl]);
        nl++;
      }
    }
  }
  return 0;
}