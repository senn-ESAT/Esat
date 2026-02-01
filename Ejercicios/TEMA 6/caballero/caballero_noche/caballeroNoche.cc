#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

COORD cxy;
const int ancho=80, alto=26;

int px = ancho/2, py = alto, np = 5, round = 0;
int map[ancho][alto] = {0};
char tecla_pulsada;

void posicion(int x,int y){
	cxy.X=x;
	cxy.Y=y;
	SetConsoleCursorPosition((GetStdHandle(STD_OUTPUT_HANDLE)), (cxy) );
}

int arbol(){
  int r;
  r = (rand() % 100);
  if(r%2 == 0){
    return 1;
  }
  return 0;
}

void MapGen(){
  for(int i=0; i<ancho; i++){
    for(int j = 0; j<alto-1; j++){
      map[i][j] = arbol();
    }
  }
}

bool Proximidad(int x, int y){
  for(int i = 0; i<5; i++){
    for(int j = 0; j<5; j++){
      if(px-2+i == x && y == py-3+j){
        return true;
      }
    }
  }
  return false;
}

void LoadMap(){
  printf("\n");
  bool cercania=false;
  for(int i=0; i<ancho; i++){
    for(int j = 0; j<alto; j++){
      //si cerca de player carga digamos un 5*5
      cercania = Proximidad(i, j);
      if(map[i][j] == 1 && cercania){
        posicion(i, j);printf("*");
      }
      else{
        posicion(i, j);printf(" ");
      }
    }
  }
}
// el -1 es para que aparezca en la linea vacia del array
// para que el mapa elimine el viejo caballero
void LoadPlayer(){
  posicion(px, py-1);printf("O");
  round++;
}

//ascii
int InputVer(char in){
  if(in == 111)//o
    return 1;
  if(in == 112)//p
    return 2;
  if(in == 113)//q
    return 3;
  return 0;
}

void Izquierda(){
  if(px>0 && map[px-1][py-1] == 0)
    px--;
}

void Derecha(){
  if(px<ancho-1 && map[px+1][py-1] == 0)
    px++;
}
//pocicion -2 porque el caballero ya esta en -1
void Arriba(){
  if(map[px][py-2] == 0){
    py--;
  }
}
//va para un switch entonce si true continua le juego
bool Gana(){
  if(py <= 0){
    return false;
  }
  return true;
}

void Pocion(){
  for(int i = 0; i<3;i++){
    for(int j = 0; j<3; j++){
      map[px-1+i][py-2+j] = 0;
    }
  }
}

void Juego(){
  while(Gana() && tecla_pulsada != 27){
    LoadMap();//genera mapa
    LoadPlayer();//genera caballero sobre mapa
    posicion(0,27);printf("Pociciones restantes: %d", np);

    tecla_pulsada=getch();
    int mov = 0;
    
    if(tecla_pulsada == 32 && np>0){// 32 == "space"
      Pocion();
      np--;
    }
    else{
      mov = InputVer(tecla_pulsada);
      switch(mov){
        case 1:
          Izquierda();
        break;
        case 2:
          Derecha();
        break;
        case 3:
          Arriba();
        break;
      }
    }
  }
}

void Stats(){
  posicion(0, alto+1);printf("Pociones restantes: %d \nMovimiento ejecutados: %d", np, round);
}

int main(){
  system("cls");
  srand(time(NULL));
  MapGen();
  Juego();
  Stats();
}