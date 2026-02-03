#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <esat/time.h>

// click genera nueva forma
// -> <-
// z -- x ++
// s salva
// [space] rota antiorario

// salva objetos, posicion y angulo 

struct form{
  int points;    // 3 = triangle 4 = square
  int speed;
  float x, y;   // coords
  char r = 0;
  char g = 0;
  char b = 0;
};
const int ScreenX = 800, ScreenY = 600;

form *block = nullptr;

float radius = 10.0f;   // radio 
float angle = 0.0f;   
const int Speed = 4;  // 4 px every frame
int nObject = 0;


void NewObject(){
  int shape = 3 + rand()%2;
  float x = (float)esat::MousePositionX();
  float y = (float)esat::MousePositionY();
  int speed = 2 + rand()%4;
  char red = rand()%255;
  char green = rand()%255;
  char blue = rand()%255;


  form newObj = {shape, speed, x, y, red, green, blue};
  block = (form*)realloc(block, (nObject+1)*sizeof(form));
  *(block+nObject) = newObj;
  nObject++;
}

void updatePosition(int index){
  (block+index)->y += (block+index)->speed;
  if((block+index)->y >= ScreenY){
    (block+index)->y = 0.0f;
  }
}


void drawObject(int index){
  float *g_circle;
  g_circle = (float*)malloc(2*(block+index)->points*(sizeof(float)));

  float angle_a = angle;
  float angle_b = 6.28f / (float) (block+index)->points;
  float sin_a = sinf(angle_a);  // 0.0f
  float sin_b = sinf(angle_b);
  float cos_a = cosf(angle_a);  // 1.0f
  float cos_b = cosf(angle_b);
  for(int i = 0; i < (block+index)->points; ++i){
    float sin_a_b = sin_a * cos_b + cos_a * sin_b;
    float cos_a_b = cos_a * cos_b - sin_a * sin_b;
    *(g_circle+i*2) = cos_a_b * radius + (block+index)->x;
    *(g_circle+i*2+1) = sin_a_b * radius + (block+index)->y;
    sin_a = sin_a_b;
    cos_a = cos_a_b;
  }
  esat::DrawSetStrokeColor((block+index)->r, (block+index)->g, (block+index)->b);
  esat::DrawSetFillColor((block+index)->r, (block+index)->g, (block+index)->b);

  esat::DrawSolidPath(g_circle, (block+index)->points);
  free(g_circle);
  g_circle = nullptr;
}

double current_time = 0.0;
double last_time = 0.0;
double fps = 24.0;

int esat::main(int argc, char **argv) {
  srand(time(NULL));
  esat::WindowInit(ScreenX, ScreenY);
  WindowSetMouseVisibility(true);
  
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    if(esat::MouseButtonDown(0) == 1){
      NewObject();
    }
    
    for(int i = 0; i < nObject; i++){
      updatePosition(i);
      drawObject(i);
      if(IsKeyPressed('x') || IsKeyPressed('X')){
        radius += 0.1f;
      }
      if(IsKeyPressed('z') || IsKeyPressed('Z')){
        if(radius > 8.0f){
          radius -= 0.01f;
        }
      }
      if(IsKeyPressed(' ')){
        angle += 0.1f;
      }
    }
      
    esat::DrawEnd();  	
  	esat::WindowFrame();

    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  free(block);
  block = nullptr;
  return 0;
}