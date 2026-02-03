#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <esat/time.h>

struct form{
  int points;     // 3 = triangle 4 = square
  int speed;
  float angle;   
  float x, y;     // coords
  char r = 0;
  char g = 0;
  char b = 0;
};

const int ScreenX = 800, ScreenY = 600;
double current_time = 0.0;
double last_time = 0.0;
double fps = 60.0;
float radius = 10.0f;   // radio 
int nObject = 0;

form *block = nullptr;
FILE *f;

void addingObj(form obj){
  block = (form*)realloc(block, (nObject+1)*sizeof(form));
  *(block+nObject) = obj;
  nObject++;
}

void NewObject(bool triangle){
  int shape;
  if(triangle){
    shape = 3;
  }
  else{
    shape = 4;
  }
  int speed = 2 + rand()%4; // 2-5
  float degrees = 0.0f;
  float x = (float)esat::MousePositionX();
  float y = (float)esat::MousePositionY();
  char red = rand()%255;
  char green = rand()%255;
  char blue = rand()%255;
  
  form newObj = {shape, speed, degrees, x, y, red, green, blue};
  addingObj(newObj);
}

void verifyInputs(int index){
  (block+index)->y += (block+index)->speed;

  if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right)){
    (block+index)->x += (block+index)->speed;
  }
  if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left)){
    (block+index)->x -= (block+index)->speed;
  }
  if(esat::IsKeyPressed(' ')){
    (block+index)->angle += 0.05f;
  }
}

void checkBorderColision(int index){
  if((block+index)->y >= ScreenY){
    if(esat::IsKeyPressed('c') || esat::IsKeyPressed('C')){
      (block+index)->y = ScreenY;  
    }
    else{
      (block+index)->y = 0.0f;
    }
  }

  if((block+index)->x >= ScreenX){
    (block+index)->x = 0.0f;
  }

  if((block+index)->x < 0.0f){
    (block+index)->x = ScreenX;
  }
}

void drawObject(int index){
  float *g_circle;
  g_circle = (float*)malloc(2*(block+index)->points*(sizeof(float)));

  float angle_a = (block+index)->angle;
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

void radioUpdate(){
  if(esat::IsKeyPressed('x') || esat::IsKeyPressed('X')){
    radius += 0.5f;
  }
  if(esat::IsKeyPressed('z') || esat::IsKeyPressed('Z') && radius > 8.0f){
    radius -= 0.5f;
  }
}

void saving(){
  f = fopen("save.dat", "wb");
  for(int i = 0; i < nObject; i++){
    fwrite((block+i), sizeof(form), 1, f);
  }
  fclose(f);
}

void loadFromFile(){
  f = fopen("save.dat", "rb");
  if(f != NULL){
    form valor;
    while(fread(&valor, sizeof(form), 1, f)){
      addingObj(valor);
    }
    fclose(f);
  }
}

int esat::main(int argc, char **argv) {
  srand(time(NULL));
  esat::WindowInit(ScreenX, ScreenY);
  WindowSetMouseVisibility(true);

  loadFromFile();

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);

    if(esat::MouseButtonDown(0) == 1){
      bool tri = true;
      NewObject(tri);
    }
    if(esat::MouseButtonDown(1) == 1){
      bool tri = false;
      NewObject(tri);
    }

    radioUpdate();

    for(int i = 0; i < nObject; i++){
      verifyInputs(i);
      checkBorderColision(i);
      drawObject(i);
    }
    
    esat::DrawEnd();  	
  	esat::WindowFrame();
    
    if(esat::IsKeyPressed('s') || esat::IsKeyPressed('S')){
      saving();
    }

    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  free(block);
  block = nullptr;
  return 0;
}