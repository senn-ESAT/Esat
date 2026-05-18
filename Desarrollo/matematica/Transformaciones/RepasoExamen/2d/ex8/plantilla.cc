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

esat::Vec2 estrella[nPoints];

void initEstrella(){
  float angle = 6.28/nPoints;

  for(int i = 0; i < nPoints; i++){
    if(i%2 == 0){
      estrella[i] = {cosf(angle*i), sinf(angle*i)};
    }else{
      estrella[i] = {cosf(angle*i)/0.5f, sinf(angle*i)/0.5f};
    }
  }
}


esat::Mat3 initMat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(30, 30), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(0.0005f * esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 sonMat(esat::Vec2 pos, esat::Mat3 mat){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(mat, temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(0.5f, 0.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(0.0005f * esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);



  return temp;
}

void drawShape(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i= 0; i < nPoints; i++){
    lines[i] = esat::Mat3TransformVec2(mat, estrella[i]);
  }

  for(int i= 0; i < nPoints -1; i++){
    esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
  }
  esat::DrawLine(lines[0].x, lines[0].y, lines[nPoints-1].x, lines[nPoints-1].y);
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  initEstrella();
  
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

    esat::Mat3 m = initMat(mousePosition);
    drawShape(m);
    float rotationSpeed = 1;
    m = sonMat(mousePosition, m);
    drawShape(m);
    rotationSpeed += 0.5f;
    m = sonMat(mousePosition, m);
    drawShape(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}