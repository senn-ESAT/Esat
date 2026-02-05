#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <esat/time.h>
#include <esat/draw.h>
#include <esat/window.h>
#include <esat/input.h>

bool *Block = nullptr;
int Screen = 800, fps = 10;
double current_time, last_time;
int nBichos = 70, espacionBichos = Screen/nBichos;

// bool per tile
// de -1 -1 a +1 +1 sumar bool=true si 2-3 range entonces vive si no muere
// 

void clickCheck(){}

void generacionBichos(){
  for(int i = 0; i < nBichos*2; i++){
    bool bicho = false;
    if(rand()%2 == 0){
      bicho = true;
    }
    Block = (bool*)realloc(bool, (i+1)*sizeof(bool));
    *(Block+i) = bicho;
  }
}

void dibujarBicho(){
  for(int i = 0; i < nBichos*2; i++){
    if((Block+i)){
      esat::DrawSetFillColor(255,0,0);
      
    }
  }
}

void fpsControl(){
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
}

int esat::main(int argc, char **argv) {
  if(argc == 4){
    srand(time(NULL));

    // *argv+0 nombre del programa
    // no se que le pasan

    esat::WindowInit(Screen, Screen);
    WindowSetMouseVisibility(true);

    generacionBichos();
    

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0,0,0);
      
      // clickCheck();
      dibujarBicho();

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