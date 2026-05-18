#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"
#include "esat/math.h"


const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;

const int nPoints = 7;

float points[nPoints*2] = {
  0.0f, 2.0f,
  - 5.0f, - 8.0f,
  - 8.0f, - 8.0f,
  0.0f, 8.0f,
  8.0f, - 8.0f,
  5.0f, - 8.0f,
  0.0f, 2.0f
};

void normalize(){
  for(int i = 0; i < nPoints*2; i++){
    points[i] = points[i]/8.0f; // 8.0f es el valor mas alto entonces es un modo facil de normalizar
  }
}

esat::Mat3 outerCircle(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Translate(0, 4), temp);

  temp = esat::Mat3Multiply(esat::Mat3Scale(1, 1.2f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(50,50), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation -  (0.0001f *esat::Time())), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 innerCircle(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;

  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Translate(0, -2), temp);

  temp = esat::Mat3Multiply(esat::Mat3Scale(1, 1.2f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(20,20), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation + (0.0001f *esat::Time())), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);
  return temp;
}

void DrawThing(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i = 0; i < nPoints*2; i += 2){
    esat::Vec2 temp = {points[i], points[i+1]};

    lines[i/2] = esat::Mat3TransformVec2(mat, temp);
  }

  for(int i = 0; i < nPoints - 1; i++){
    esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
  }
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  normalize();
  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0); 
    esat::DrawSetStrokeColor(255,255,255);   
    
    esat::Vec2 mousePosition;
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    for(int i = 0; i < 12; i++){
      esat::Mat3 m = outerCircle(mousePosition, (6.28/12)*i);
      DrawThing(m);
    }

    for(int i = 0; i < 5; i++){
      esat::Mat3 m = innerCircle(mousePosition, (6.28/5)*i);
      DrawThing(m);
    }

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}