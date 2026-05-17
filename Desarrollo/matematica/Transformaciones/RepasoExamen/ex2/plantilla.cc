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

esat::Vec2 points[nPoints];

void initPoints(){
  float radPP = 6.28 / nPoints;

  for(int i = 0; i < nPoints; i++){
    points[i] = {cosf(radPP*i), sinf(radPP*i)};
    printf("\n[%f] - [%f]",points[i].x,points[i].y);
  }
}

esat::Mat3 MatMaker(esat::Vec2 pos, float scale, float rotate){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(scale, scale), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(rotate * esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);
  return temp;
}

void DrawCircle(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];

  for(int i = 0; i < nPoints; i++){
    lines[i] = esat::Mat3TransformVec2(mat, points[i]);
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
  initPoints();
  
  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);    
    esat::DrawSetStrokeColor(255,255,255);
    
    esat::Vec2 pos;
    pos.x = 150; 
    pos.y = 200;

    esat::Mat3 m = MatMaker(pos, 100, 0.001);
    DrawCircle(m);

    pos.x = 600; 
    pos.y = 300;

    m = MatMaker(pos, 175, -0.001);
    DrawCircle(m);

    pos.x = 310; 
    pos.y = 400;

    m = MatMaker(pos,45, 0.001);
    DrawCircle(m);

    pos.x = 310; 
    pos.y = 270;

    m = MatMaker(pos, 60, -0.001);
    DrawCircle(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}