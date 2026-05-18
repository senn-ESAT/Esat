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

const int nPoints = 8;

esat::Vec3 points[nPoints] = {
  {-1.0f, -1.0f, 1.0f,},
  {-1.0f, 1.0f, 1.0f,},
  {1.0f, 1.0f, 1.0f,},
  {1.0f, -1.0f, 1.0f,},

  {-1.0f, -1.0f, -1.0f,},
  {-1.0f, 1.0f, -1.0f,},
  {1.0f, 1.0f, -1.0f,},
  {1.0f, -1.0f, -1.0f},
};

esat::Mat4 initMat(esat::Vec2 mouse){
  esat::Mat4 temp;
  temp = esat::Mat4Identity();

  temp = esat::Mat4Multiply(esat::Mat4Scale(100, 100, 100), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateY(0.001f * esat::Time()),temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateX(0.001f * esat::Time()),temp);
  temp = esat::Mat4Multiply(esat::Mat4Translate(mouse.x, mouse.y, 0), temp);

  return temp;
}

void drawCube(esat::Mat4 mat){
  esat::Vec3 lines[nPoints];
  for(int i = 0; i < nPoints; i++){
    lines[i] = esat::Mat4TransformVec3(mat, points[i]);
  }

  for(int i = 0; i < nPoints-1; i++){
    if(i != (nPoints/2)-1){
      esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
    }
    if(i < nPoints/2){
      esat::DrawLine(lines[i].x, lines[i].y, lines[i+4].x, lines[i+4].y);
    }
  }
  esat::DrawLine(lines[0].x, lines[0].y, lines[3].x, lines[3].y);
  esat::DrawLine(lines[4].x, lines[4].y, lines[7].x, lines[7].y);
}



int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
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

    esat::Mat4 m = initMat(mousePosition);
    drawCube(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}