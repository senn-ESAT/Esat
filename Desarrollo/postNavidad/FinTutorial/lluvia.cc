#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// click genera nueva forma
// -> <-
// z -- x ++
// s salva
// [space] rota antiorario

// salva objetos, posicion y angulo 

struct form{
  int points;    // 3 = triangle 4 = square
  float x, y;   // coords
  char r = 0;
  char g = 0;
  char b = 0;
};

form *block = nullptr;

float radius = 10.0f;   // radio 
float angle = 0.0f;   
const int Speed = 4;  // 4 px every frame
int nObject = 0;


void NewObject(){
  int shape = 3 + rand()%2;
  float x = (float)esat::MousePositionX();
  float y = (float)esat::MousePositionY();
  char red = rand()%255;
  char green = rand()%255;
  char blue = rand()%255;

  printf("\n[lados]: %d[x]: %f[y]: %f[r]: %d[g]: %d [b]: %d\n", shape, x, y, red, green, blue);

  form newObj = {shape, x, y, red, green, blue};
  block = (form*)realloc(block, (nObject+1)*sizeof(form));
  *(block+nObject) = newObj;
  nObject++;
}

void drawObject(int index){
  float *g_circle;
  printf("preload ");
  g_circle = (float*)malloc((block+index)->points*(sizeof(float)));

  float angle_a = angle;
  float angle_b = 6.28f / (float) (block+index)->points;
  float sin_a = sinf(angle_a);  // 0.0f
  float sin_b = sinf(angle_b);
  float cos_a = cosf(angle_a);  // 1.0f
  float cos_b = cosf(angle_b);
  printf("[presalvado] ");
  for(int i = 0; i < (block+index)->points; ++i){
    float sin_a_b = sin_a * cos_b + cos_a * sin_b;
    float cos_a_b = cos_a * cos_b - sin_a * sin_b;
    *(g_circle+i*2) = cos_a_b * radius + (block+index)->x;
    *(g_circle+i*2+1) = sin_a_b * radius + (block+index)->y;
    sin_a = sin_a_b;
    cos_a = cos_a_b;
  }
  printf("[predibujp] ");
  //esat::DrawSetStrokeColor((block+index)->r, (block+index)->g, (block+index)->b, 255);
  esat::DrawSetFillColor(255, 0, 0, 255);
  esat::DrawSolidPath(g_circle, (block+index)->points);
  printf("[cierre] ");
  // free(g_circle);
  // g_circle = nullptr;
  printf("free ");
}

int esat::main(int argc, char **argv) {
  srand(time(NULL));
  esat::WindowInit(800,600);
  WindowSetMouseVisibility(true);
  
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    printf("inicio - ");
    if(esat::MouseButtonDown(0) == 1){
      printf("NEW - ");
      NewObject();
    }
    
    if(nObject > 0){
      printf("dibujo - ");
      for(int i = 0; i < nObject; i++){
        printf(" no: %d i: %d ",nObject, i);
        //updatePosition();
        drawObject(i);
      }
    }
      
    esat::DrawEnd();  	
  	esat::WindowFrame();
    printf("end\n");  
  }
  esat::WindowDestroy();
  free(block);
  block = nullptr;
  return 0;
}