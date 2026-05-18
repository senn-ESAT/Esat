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

const int nPoints = 36;

esat::Vec2 circle[nPoints];

void initCircle(){
  float angle = 6.28f/nPoints;
  for(int i = 0; i < nPoints; i++){
    circle[i] = {cosf(angle*i), sinf(angle*i)};
  }
}

esat::Mat3 updateMat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(20,20),temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y),temp);

  return temp;
}

esat::Mat3 ellipseMat(esat::Vec2 pos, float angle){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(4, 1), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(50, 50), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(angle), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 atomMat(esat::Vec2 pos, float angle, esat::Mat3 mat){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  
  temp = esat::Mat3Multiply(esat::Mat3Scale(0.25f/2.5f, 1/2.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(cosf(esat::Time()*0.001f), sinf(esat::Time()*0.001f)), temp);

  temp = esat::Mat3Multiply(mat, temp);

  return temp;
}

void Drawthing(esat::Mat3 mat){
  esat::Vec2 lineas[nPoints];
  for(int i = 0; i < nPoints; i++){
    lineas[i] = esat::Mat3TransformVec2(mat, circle[i]);
  }
  for(int i = 0; i < nPoints; i++){
    if(i != nPoints-1){
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[i+1].x, lineas[i+1].y);
    }else{
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[0].x, lineas[0].y);
    }
  }
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  initCircle();

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

    esat::Mat3 m = updateMat(mousePosition);
    Drawthing(m);

    for(int i = 0; i < 3; i++){
      float angle = 6.28f/3;
      m = ellipseMat(mousePosition, angle*i);
      Drawthing(m);

      m = atomMat(mousePosition, angle*i, m);
      Drawthing(m);
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