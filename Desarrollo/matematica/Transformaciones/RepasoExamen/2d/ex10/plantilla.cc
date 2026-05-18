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

float points[20] = {
0.0f, 0.0f, 
0.45f, 0.0f,
0.8f, 0.35f, 
0.9f, 0.35f,
1.0f, 0.25f, 
1.0f, 0.35f,
0.9f, 0.45f, 
0.8f, 0.45f,
0.45f, 0.1f, 
0.0f, 0.1f
};

esat::Mat3 initMat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(100, 100), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

void DrawThing(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i = 0; i < nPoints*2; i+= 2){
    esat::Vec2 temp = {points[i], points[i]};
    lines[i/2] = esat::Mat3TransformVec2(mat, temp);
  }
  printf("\n--------------------------");
  for(int i = 0; i < nPoints; i++){
    printf("\n[%f] - [%f]", lines[i].x, lines[i].y);
    if(i == nPoints-1){
      esat::DrawLine(lines[i].x, lines[i].y, lines[0].x, lines[0].y);
    }else{
      esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
    }
  }
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

    esat::Mat3 m = initMat(mousePosition);
    DrawThing(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}