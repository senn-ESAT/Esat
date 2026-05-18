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

const int nPoints = 9;

float figure[nPoints*2] = {
  1.0f, 0.0f,
  1.0f, 3.0f,
  3.0f, 7.0f,
  1.0f, 7.0f,
  0.0f, 5.0f,
  -1.0f, 7.0f,
  -3.0f, 7.0f,
  -1.0f, 3.0f,
  -1.0f, 0.0f 
};
esat::Vec2 points[nPoints];
esat::Vec2 octa[8];

void normalize(){
  for(int i = 0; i < nPoints*2; i+=2){
    points[i/2] = {figure[i]/7, figure[i+1]/7};
  }
}

void initOcta(){
  float angle = 6.28/8;

  for(int i = 0; i < 8; i++){
    octa[i] = {cosf(angle*i), sinf(angle*i)};
  }
}


esat::Mat3 updateMat(esat::Vec2 pos, float angle, float offset){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(100,100), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(0, offset), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(angle), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 updateOcta(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(200,200), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

void drawThing(esat::Mat3 mat){
  esat::Vec2 lineas[nPoints];
  for(int i = 0; i < nPoints; i++){
    lineas[i] = esat::Mat3TransformVec2(mat, points[i]);
  }
  for(int i = 0; i < nPoints; i++){
    if(i != nPoints-1){
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[i+1].x, lineas[i+1].y);
    }else{
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[0].x, lineas[0].y);
    }
  }
}

void DrawOcta(esat::Mat3 mat){
  esat::Vec2 lineas[8];
  for(int i = 0; i < 8; i++){
    lineas[i] = esat::Mat3TransformVec2(mat, octa[i]);
  }
  for(int i = 0; i < 8; i++){
    if(i != 8-1){
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

  normalize();
  initOcta();
  
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

    for(int j = 0; j < 2; j++){
      for(int i = 0; i < 8; i++){
        esat::Mat3 m = updateMat(mousePosition, (6.28/8)*i, 200*j);
        drawThing(m);
      }
    }

    esat::Mat3 o = updateOcta(mousePosition);
    DrawOcta(o);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}