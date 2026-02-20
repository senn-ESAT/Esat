#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <esat/math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int ScreenX = 800, ScreenY = 600;
esat::Vec3 puto2[10];

void initMat(){
  float angle = 6.28f / 10;
  for(int i = 0; i < 10; i++){
    puto2[i] = {cosf(angle*i), sinf(angle*i), 1};
  }
}

esat::Mat3 updatePutos(){
  esat::Mat3 m = esat::Mat3Identity();
  m = esat::Mat3Multiply(esat::Mat3Scale(180.0f, 180.0f), m);
  m = esat::Mat3Multiply(esat::Mat3Rotate(0.01f), m);
  m = esat::Mat3Multiply(esat::Mat3Translate(200.0f, 200.0f), m);
  return m;
}

void drawPutos(esat::Mat3 a){
  esat::Vec2 t[10];
  for(int i = 0; i < 10; i++){
    esat::Vec3 temp;
    temp = esat::Mat3TransformVec3(a, puto2[i]);
    t[i] = {temp.x, temp.y};
  }
  esat::DrawPath(&t[0].x, 10);
}

/*
Matric es como las specs de los puntos
para que sea la misma forma tengo que 
aplicare una matri para todos los puntos
*/

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);
  
  initMat();
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    esat::DrawSetStrokeColor(255, 255, 255);
    
    esat::Mat3 puto; 
    puto = updatePutos();
    drawPutos(puto);
    
    esat::DrawEnd();
    esat::WindowFrame();
    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}