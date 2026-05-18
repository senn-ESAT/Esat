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

esat::Vec2 estrella[10];

void initEstrella(){
  float angle = 6.28/nPoints;

  for(int i = 0; i < nPoints; i++){
    if(i%2 == 0){
      estrella[i] = {cosf(angle*i), sinf(angle*i)};
    }else{
      estrella[i] = {cosf(angle*i)*0.5f, sinf(angle*i)*0.5f};
    }
  }
}

esat::Mat3 initmat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(50,50), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);
  return temp;
}

esat::Mat3 estrelladeforme(esat::Vec2 pos, float rot){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Scale(4, 1), temp);

  temp = esat::Mat3Multiply(esat::Mat3Scale(80,80), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rot), temp);

  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);
  return temp;
}

esat::Mat3 cometa(esat::Vec2 pos, float rot, int speed, int distance){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  float angle = cosf(0.0001f * esat::Time()); 

  temp = esat::Mat3Multiply(esat::Mat3Translate(distance, 0), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(30,30), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(speed + rot),temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;

}


void drawThing(esat::Mat3 mat){
  esat::Vec2 lineas[nPoints];
  for(int i = 0; i < nPoints; i++){
    lineas[i] = esat::Mat3TransformVec2(mat, estrella[i]);
  }

  for(int i = 0; i < nPoints; i++){
    if(i == nPoints-1){
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[0].x, lineas[0].y);
    }else{
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[i+1].x, lineas[i+1].y);
    }
  }
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

    esat::Mat3 m = initmat(mousePosition);
    drawThing(m);

    for(int i = 0; i < 3; i++){
      float angle = 6.28/3;

      esat::Mat3 m = cometa(mousePosition, angle*i, (0.002f*(i + 1))* esat::Time(), 1.5f*i);
      drawThing(m);
    }

    for(int i = 0; i<3; i++){
      float angle = 6.28/3;
      m = estrelladeforme(mousePosition, angle*i);
      drawThing(m);
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