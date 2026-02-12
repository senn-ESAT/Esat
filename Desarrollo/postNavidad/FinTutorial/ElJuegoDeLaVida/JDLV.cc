#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <esat/time.h>
#include <esat/draw.h>
#include <esat/window.h>
#include <esat/input.h>

struct Pos{
      //x    y
  int  col, row;
};

struct Cuadricula{
  Pos dimension;
  bool vive;
};

struct WorldsSetting{
  float espacioBichos;
  int nBichos;
  int v1 = NULL,v2 = NULL,v3 = NULL;
  int m1 = NULL,m2 = NULL,m3 = NULL;
};

struct Mouse{
  float x, y;
};

Mouse mouse;
Cuadricula *Block = nullptr;
int Screen = 800, fps = 10;
WorldsSetting WS;
double current_time, last_time;

// bool per tile
// de -1 -1 a +1 +1 sumar bool=true si 2-3 range entonces vive si no muere
// 

void clickCheck(bool no){
  if(no){
    mouse.x = (float)esat::MousePositionX();
    mouse.y = (float)esat::MousePositionX();
  }
}

void generacionBichos(){
  int filas = 0;
  int col = 0;
  for(int i = 0; i < WS.nBichos*WS.nBichos; i++){
    bool bicho = false;
    if(i%WS.nBichos == 0){filas++; col=0;}
    if(rand()%2 == 0){bicho = true;}
    Pos position = {col, filas};
    
    Block = (Cuadricula*)realloc(Block, (i+1)*sizeof(Cuadricula));
    (Block+i)->dimension = position;
    (Block+i)->vive = bicho;
    col++;
  }
}

// SE rompe TO-DO
void dibujarBicho(){
  float *array = nullptr;
  array = (float*)malloc(10*sizeof(float));
  
  for(int i = 0; i < WS.nBichos*WS.nBichos; i++){
    if((Block+i)->vive == true){
      float startCol = (Block+i)->dimension.col*WS.espacioBichos;
      float startRow = (Block+i)->dimension.row*WS.espacioBichos;
      
      *(array) = startCol;
      *(array+1) = startRow;
      *(array+2) = startCol+WS.espacioBichos;
      *(array+3) = startRow;
      *(array+4) = startCol+WS.espacioBichos;
      *(array+5) = startRow+WS.espacioBichos;
      *(array+6) = startCol;
      *(array+7) = startRow+WS.espacioBichos;
      *(array+8) = startCol;
      *(array+9) = startRow;

      esat::DrawSetFillColor(255,0,0);
      esat::DrawSolidPath(array, 5);
    }
    free(array);
    array = nullptr; 
  }
}

void fpsControl(){
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
}

int esat::main(int argc, char **argv) {
  // if(argc == 3){
    srand(time(NULL));
    WS.espacioBichos = 10;
    WS.nBichos = Screen/WS.espacioBichos;

    // *argv+0 nombre del programa
    // nacimiento/muerte (0-0-0) y nBichos

    // WorldsSetting *VM;
    // WorldsSetting WS;

    // VM = (WorldsSetting*)malloc(VM, sizeof(WorldsSetting));
    // WS.espacioBichos = atoi(*(argv+2)); 

    // int i = 0;
    // bool nacimiento = true;
    // for(int i = 0; i < strlen(*(argv+1))){
    //   if(*(argv+1)[i] == '/'){nacimiento == false};
    //   if(nacimiento){
    //     WS.v1
    //   }
      
    // }
    
    esat::WindowInit(Screen, Screen);
    WindowSetMouseVisibility(true);

    generacionBichos();
    bool si;
    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)){
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0,0,0);
      //si = MouseButtonPressed(0);
      printf("a");
      //clickCheck(si);
      dibujarBicho();
      printf("b");

      esat::DrawEnd();  	
      esat::WindowFrame();
      
      fpsControl();
    }
    esat::WindowDestroy();
    free(Block);
    Block = nullptr;
  // }
  // else{
  //   printf("ERROR: Faltan datos");  
  // }
  return 0;
}