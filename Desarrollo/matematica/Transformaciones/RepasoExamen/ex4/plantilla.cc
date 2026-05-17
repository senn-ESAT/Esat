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

float points[14] = {    // LOS HDP DE LOS PUNTOS NO ESTAN CENTRADOS
20.0f, 10.0f,
15.0f, 0.0f,
12.0f, 0.0f,
20.0f, 16.0f, // punto central
28.0f, 0.0f,
25.0f, 0.0f,
20.0f, 10.0f,
};

void normalize(){
  for(int i = 0; i < nPoints*2; i++){
    // center le restamos el punto central asìel punto central es 0,0
    if(i%2 == 0){
      points[i] -= 20.0f;
    }else{
      points[i] -= 8.0f;
    }
    points[i] = points[i]/28.0f;
  }
}

esat::Mat3 outerCircle(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Translate(0, 1), temp);

  temp = esat::Mat3Multiply(esat::Mat3Scale(150, 150), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 innerCircle(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Translate(0, -1), temp);

  temp = esat::Mat3Multiply(esat::Mat3Scale(50, 50), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

void drawShape(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i = 0; i < nPoints*2; i+=2){
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

    for(int i = 0; i < 7; i++){
      esat::Mat3 m = outerCircle(mousePosition, (6.28/7)*i);
      drawShape(m);
    }

    for(int i = 0; i < 5; i++){
      esat::Mat3 m = innerCircle(mousePosition, (6.28/5)*i);
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