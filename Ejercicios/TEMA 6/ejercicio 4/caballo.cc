#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int dimT = 10;
int table[dimT][dimT] = {0}, positionY, positionX, movidas = 0;

void Spawn(){
  srand(time(NULL));
  positionX = (rand() % dimT);
  positionY = (rand() % dimT);
}

bool Movimiento() {
  // arriba-izquierda
  if (positionX - 2 >= 0 && positionY - 1 >= 0 && table[positionX - 2][positionY - 1] == 0) {
    positionX -= 2;
    positionY -= 1;
    return true;
  }
  // arriba-derecha
  if (positionX - 2 >= 0 && positionY + 1 < dimT && table[positionX - 2][positionY + 1] == 0) {
    positionX -= 2;
    positionY += 1;
    return true;
  }
  // izquierda-arriba
  if (positionX - 1 >= 0 && positionY - 2 >= 0 && table[positionX - 1][positionY - 2] == 0) {
    positionX -= 1;
    positionY -= 2;
    return true;
  }
  // derecha-arriba
  if (positionX - 1 >= 0 && positionY + 2 < dimT && table[positionX - 1][positionY + 2] == 0) {
    positionX -= 1;
    positionY += 2;
    return true;
  }
  // izquierda-abajo
  if (positionX + 1 < dimT && positionY - 2 >= 0 && table[positionX + 1][positionY - 2] == 0) {
    positionX += 1;
    positionY -= 2;
    return true;
  }
  // derecha-abajo
  if (positionX + 1 < dimT && positionY + 2 < dimT && table[positionX + 1][positionY + 2] == 0) {
    positionX += 1;
    positionY += 2;
    return true;
  }
  // abajo-izquierda
  if(positionX + 2 < dimT && positionY - 1 >= 0 && table[positionX + 2][positionY - 1] == 0) {
    positionX += 2;
    positionY -= 1;
    return true;
  }
  // abajo-derecha
  if (positionX + 2 < dimT && positionY + 1 < dimT && table[positionX + 2][positionY + 1] == 0) {
    positionX += 2;
    positionY += 1;
    return true;
  }
  return false;
}

void Juego(){
  do{
    movidas++;
    table[positionX][positionY] = movidas;
  }while (Movimiento());
}

void Pantalla(){
  for(int i = 0; i < dimT; i++){
    for(int j = 0; j < dimT; j++){
      printf(" %03d ", table[i][j]);
    }
    printf("\n");
  }
  printf("Tablero rellenado: %d %", movidas);
}

int main(){
  Spawn();
  Juego();
  Pantalla();
}