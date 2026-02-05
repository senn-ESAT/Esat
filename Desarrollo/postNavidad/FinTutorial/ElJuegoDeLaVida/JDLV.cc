#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <esat/time.h>
#include <string.h>
#include <esat/draw.h>
#include <esat/window.h>
#include <esat/input.h>

Balls *Block = nullptr;
int Screen = 800, fps = 10;
double current_time, last_time;
int nBichos = 70, espacionBichos = Screen/nBichos;

int esat::main(int argc, char **argv) {
  if(argc == 4){
    srand(time(NULL));

    // *argv+0 nombre del programa
    // no se que le pasan

    esat::WindowInit(Screen, Screen);
    WindowSetMouseVisibility(true);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0,0,0);
      

      
      esat::DrawEnd();  	
      esat::WindowFrame();
      
      fpsControl();
    }
    esat::WindowDestroy();
    free(Block);
    Block = nullptr;
  }
  else{
    printf("ERROR: Faltan datos");  
  }
  return 0;
}