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

const int nPoints = 5;

esat::Vec2 pentagono[nPoints];

void MakePentagon(){
  float angle = 6.28/nPoints;
  for(int i = 0; i < nPoints; i++){
    pentagono[i] = {cosf(angle * i), sinf(angle * i)};
  }
}

esat::Mat3 bigP(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(50,50) , temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation) , temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 smallP(esat::Vec2 pos, float offset, float direction, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  float scale = 20;

  temp = esat::Mat3Multiply(esat::Mat3Scale(-1, 1), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(scale,scale) , temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(offset+scale, 0), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(direction + rotation), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

void drawShape(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i = 0; i < nPoints; i++){
    lines[i] = esat::Mat3TransformVec2(mat, pentagono[i]);
  }

  for(int i = 0; i < nPoints - 1; i++){
    esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
  }
  esat::DrawLine(lines[0].x, lines[0].y, lines[nPoints - 1].x, lines[nPoints - 1].y);
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  MakePentagon();
  
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

    float magicRotation = 0.0001f * esat::Time(); 

    esat::Mat3 m = bigP(mousePosition, magicRotation);
    drawShape(m);

    for(int i = 0; i < nPoints; i++){
      m = smallP(mousePosition, 50, ((6.28/nPoints)* i), magicRotation);
      drawShape(m);
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