#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabla[9] = {0}, input, player = 0, ganador = 0;

void display(){
  for(int i = 2; i>=0; i--){
    for (int j = 0; j < 3; j++) {
      if(tabla[i*3+j] == 0){printf("   ");}
      if(tabla[i*3+j] == 1){printf(" X ");}
      if(tabla[i*3+j] == 2){printf(" O ");}
    }    
    printf("\n\n");
  }
  printf("\n");
}

void Jugada(){
  /*si mas que 6 rondas entonces todas pas fichas estan en la tabla*/
  int verPlayer = 0;
  if(player > 5){
    do{
      printf("Elimina Casilla: ");
      scanf("%d", &input);
      /* verifica que la ficha eliminada es la del jugador */
      if(tabla[input-1] != 0){
        if(player%2 == 0 && tabla[input-1] == 1){verPlayer = 1;}
        if(player%2 != 0 && tabla[input-1] == 2){verPlayer = 1;}
      }
      /*verifico que el input este bien y saco la ficha*/
    }while(input <= 0 || input > 10 || tabla[input-1] == 0 || verPlayer == 0);
    tabla[input-1] = 0;
    verPlayer = 0;
  }
  /*el jugador elije la pocicion de la jugada*/
  do{
    printf("Casilla Para rellenar: \n");
    /* verifico input */
    scanf("%d", &input);
    if(player%2 == 0 && tabla[input-1] == 1){verPlayer = 1;}
    if(player%2 != 0 && tabla[input-1] == 2){verPlayer = 1;}
    if(tabla[input-1] == 0){verPlayer = 1;}
  }while(input <= 0 || input > 10 || tabla[input-1] != 0 || verPlayer == 0);
  /* 1 = player 1, 2 = player 2 */
  if(player%2 == 0){tabla[input-1] = 1;}
  else{tabla[input-1] = 2;}
}

void action(){
  /* turno */
  if(player%2 == 0){
    printf("Jugador 1 \n");
  }
  else{
    printf("Jugador 2 \n");
  }
  Jugada();
  player++;
}

void AsignacionGanador(int j){
  if(tabla[j] == 1){
    ganador = 1;
  }
  else{ganador = 2;}
}

void VerificaVictoria(){ 
  for(int i = 0; i<9; i++){
    /*verifico si ganador en orizontal*/
    if(i%3 == 0 ){
      if(tabla[i] != 0 && tabla[i] == tabla[i+1] && tabla[i+1] == tabla[i+2]){
        AsignacionGanador(i);
      }
    }
    /*verifico si ganador en vertical*/
    if(i <= 2){
      if(tabla[i] != 0 && tabla[i] == tabla[i+3] && tabla[i+3] == tabla[i+6]){
        AsignacionGanador(i);
      }
    }
    /*verifico si ganador */
    if(i == 0){
      if(tabla[0] != 0 && tabla[0] == tabla[4] && tabla[4] == tabla[8]){
        AsignacionGanador(i);
      }
      if(tabla[2] != 0 && tabla[2] == tabla[4] && tabla[4] == tabla[6]){
        AsignacionGanador(i);
      }
    }
  }
}

void victoria(){
  printf("GANA EL JUGADOR %d\n%d Turnos jugados", ganador, player);
}

int main(){
  /* bloc num para tabla, sacar(obj = 3) y poner */
  do{
    display();
    action();
    VerificaVictoria();
  }while(ganador == 0);
  display();
  victoria();
}