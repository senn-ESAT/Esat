#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <esat/time.h>
#include <esat/draw.h>
#include <esat/window.h>
#include <esat/input.h>
#include <esat/math.h>

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
  int v1 = NULL,v2 = NULL,v3 = NULL;  // vive
  int n1 = NULL,n2 = NULL,n3 = NULL;  // nace
  bool update = false;
};

esat::Vec2 mouse;
Cuadricula *Block = nullptr;
WorldsSetting WS;
int Screen = 800, fps = 10;
double current_time, last_time;

// bool per tile
// de -1 -1 a +1 +1 sumar bool=true si 2-3 range entonces vive si no muere

void generacionBichos(){
  int filas = 0;
  int col = 0;
  int maxNum = WS.nBichos*WS.nBichos;
  Block = (Cuadricula*)malloc(maxNum * sizeof(Cuadricula));
  
  for(int i = 0; i < maxNum; i++){
    bool bicho = false;
    filas = i / WS.nBichos;
    col = i % WS.nBichos;

    if(rand()%2 == 0){bicho = true;}
    Pos position = {col, filas};
    
    (Block+i)->dimension = position;
    (Block+i)->vive = bicho;
    col++;
  }
}

void clickCheck(){
  if(esat::MouseButtonDown(0) == 1){
    WS.update = false;
    mouse.x = (float)esat::MousePositionX();
    mouse.y = (float)esat::MousePositionY();

    int i = 0, j = 0;
    bool pressed, found = false;
    pressed = esat::MouseButtonPressed(0);

    while(i < WS.nBichos && !found){
      // if found col
      if(i*WS.espacioBichos <= mouse.x && (i+1)*WS.espacioBichos > mouse.x){
        while(j < WS.nBichos && !found){
          // if found row
          if(j*WS.espacioBichos <= mouse.y && (j+1)*WS.espacioBichos > mouse.y){
            int position = (j-1)*WS.nBichos+i;
            (Block+position)->vive = !(Block+position)->vive;
            found = true;
          }
          j++;
        }
      }
      i++;
    }
  }
}

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
  }
}

int chechSuroundings(int c, int r){
  int temp = 0;
  for(int i = c-1; i <= c+1; i++){
    for(int j = r-1; j <= r+1; j++){
      //para evitar leer -1 o pasarse de linea
      if(i >= 0 && i < WS.nBichos && j >= 0 && j < WS.nBichos){
        int position = j*WS.nBichos+i;
        if(i != c || j != r){
          if((Block+position)->vive){
            temp++;
          }
        }
      }
    }
  }
  return temp;
}

void updateBichos(){
  if(WS.update){
    int row = 0;
    int col = 0;
    bool *temp = nullptr;
    temp = (bool*)malloc(WS.nBichos * WS.nBichos * sizeof(bool));

    for(int i = 0; i < WS.nBichos*WS.nBichos; i++){
      row = i / WS.nBichos;
      col = i % WS.nBichos;
      int neigbors = chechSuroundings(col, row);
      int position = (row)*WS.nBichos+col;

      if((neigbors == WS.n1 || neigbors == WS.n2 || neigbors == WS.n3) && (Block+position)->vive == false){
        *(temp+position) = true;
      }
      else if((neigbors == WS.v1 || neigbors == WS.v2 || neigbors == WS.v3) && (Block+position)->vive == true){
        *(temp+position) = true;
      }
      else{
        *(temp+position) = false;
      }
      col++;
    }
    
    for(int i = 0; i < WS.nBichos*WS.nBichos; i++){
      (Block+i)->vive = *(temp+i);
    }
    free(temp);
  }
}

void fpsControl(){
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
}

int esat::main(int argc, char **argv) {
  if(argc < 3){
    printf("ERROR: Faltan datos");  
    return 1;
  }
  srand(time(NULL));
  printf("a");

  WS.n1 = WS.n2 = WS.n3 = -1;
  WS.v1 = WS.v2 = WS.v3 = -1;
  printf("a");

  char *nace = nullptr;
  char *vive = nullptr;
  int nace_len = 0;
  int vive_len = 0;
  printf("a");

  int i = 0, newIndex = 0;;
  bool slashFound = false;

  while(argv[1][i] != '\0'){
    if(argv[1][i] != '/'){
       if (!slashFound) {
        nace = (char*)realloc(nace, nace_len + 2);
        nace[nace_len] = argv[1][i];
        nace_len++;
        nace[nace_len] = '\0';
    } else {
        vive = (char*)realloc(vive, vive_len + 2);
        vive[vive_len] = argv[1][i];
        vive_len++;
        vive[vive_len] = '\0';
    }
    }
    else{
      slashFound = true;
      newIndex = i+1;
    }
    i++;
  }

  printf("a");

  int len = strlen(nace);
  printf("-%d-",len);
  if (len > 0) WS.n1 = nace[0] - 48;
  if (len > 1) WS.n2 = nace[1] - 48;
  if (len > 2) WS.n3 = nace[2] - 48;
  printf("a");
  
  len = strlen(vive);
  printf("-%d-",len);
  if (len > 0) WS.v1 = vive[0] - 48;
  if (len > 1) WS.v2 = vive[1] - 48;
  if (len > 2) WS.v3 = vive[2] - 48;

  
  WS.espacioBichos = atoi(*(argv+2));
  WS.nBichos = Screen/WS.espacioBichos;
  
  free(nace);
  nace = nullptr;
  free(vive);
  vive = nullptr;
    
  esat::WindowInit(Screen, Screen);
  WindowSetMouseVisibility(true);

  generacionBichos();
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)){
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);

    clickCheck();
    dibujarBicho();
    updateBichos();
      
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
      WS.update = true;
    }

    esat::DrawEnd();  	
    esat::WindowFrame();
    
    fpsControl();
  }
  esat::WindowDestroy();
  free(Block);
  Block = nullptr;
  
  return 0;
}