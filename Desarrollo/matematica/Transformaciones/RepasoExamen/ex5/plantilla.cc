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

const int nPoints = 6;

float points[12] = {
  0.0f, 0.0f,
  0.0f, 0.75f,
  0.125f, 1.0f,
  0.25f, 0.75f, 
  0.25f, 0.0f,
  0.0f, 0.0f
};

esat::Mat3 initMat(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Translate(0, 0.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(160, 160), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation + 0.0001f*esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 initRMat(esat::Vec2 pos, float rotation){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Translate(0, -1.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(160, 160), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotation + 0.0001f*esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}


void drawShape(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
    printf("\n------------------");

  for(int i = 0; i < nPoints*2; i+=2){
    esat::Vec2 temp = {points[i], points[i+1]};
    lines[i/2] = esat::Mat3TransformVec2(mat, temp);
    printf("\n[%f]-[%f]", lines[i/2].x, lines[i/2].y);
  }

  for(int i = 0; i < nPoints - 1; i++){
    esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
  }
}

void centerX(){
  for(int i = 0; i < nPoints*2; i+=2){
    points[i] -= 0.125f;
  }
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  centerX();
  
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

    for(int i = 0; i < 4; i++){
      esat::Mat3 m = initMat(mousePosition, (6.28f/4) * i);
      drawShape(m);
    }
    for(int i = 0; i < 4; i++){
      esat::Mat3 m = initRMat(mousePosition, ((6.28f/4) * i) + (6.28/8));
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