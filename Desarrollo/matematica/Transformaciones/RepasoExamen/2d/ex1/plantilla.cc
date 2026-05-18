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

const int nPoints = 10;

esat::Vec2 PuntosCirculo[nPoints] = {0};

void initPuntos(){
  float radPerPoint = (6.28f) / nPoints;
  for (int i = 0; i < nPoints; i++){
    float angle = radPerPoint * i;
    PuntosCirculo[i] = {cosf(angle) , sinf(angle)};
  }
}

esat::Mat3 initMat(esat::Vec2 mouse){
  esat::Mat3 temp;

  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(100.0f, 100.0f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(mouse.x, mouse.y), temp);

  return temp;
}

void drawCircle(esat::Mat3 m){
  float lines[nPoints*2];
  for(int i = 0; i < nPoints; i++){
    esat::Vec2 temp;
    temp = esat::Mat3TransformVec2(m, PuntosCirculo[i]);

    lines[i*2] = temp.x;
    lines[i*2 + 1] = temp.y;

  }
  esat::DrawPath(lines, 10);
  esat::DrawLine(lines[0], lines[1], lines[nPoints * 2 - 2], lines[nPoints * 2-1]);
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  initPuntos();

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);
  
  esat::Mat3 circleMat;
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    esat::DrawSetStrokeColor(255, 255, 255, 255);
    
    esat::Vec2 mousePosition;
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();
    
    circleMat = initMat(mousePosition);

    drawCircle(circleMat);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}