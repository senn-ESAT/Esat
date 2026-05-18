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

esat::Vec3 star[nPoints];

void initStart(){
  float angle = 6.28/nPoints;

  for(int i = 0; i < nPoints; i++){
    if(i%2 == 0){
      star[i] = {cosf(angle*i), sinf(angle*i), 1};
    }else{
      star[i] = {cosf(angle*i)*0.5f, sinf(angle*i)*0.5f, 1};
    }
  }
}

esat::Mat4 updateMat(esat::Vec2 pos){
  esat::Mat4 temp;
  temp = esat::Mat4Identity();

  temp = esat::Mat4Multiply(esat::Mat4Translate(0,0,4), temp);
  temp = esat::Mat4Multiply(esat::Mat4Scale(100, 100, 1), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateX(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateY(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateZ(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4Translate(pos.x, pos.y, 0), temp);

  return temp;
}

void drawThing(esat::Mat4 mat){
  esat::Vec3 lines[nPoints];
  for(int i = 0; i < nPoints; i++){
    lines[i] = esat::Mat4TransformVec3(mat, star[i]);
  }
  for(int i = 0; i < nPoints; i++){
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

  initStart();
  
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

    esat::Mat4 m = updateMat(mousePosition);
    drawThing(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}