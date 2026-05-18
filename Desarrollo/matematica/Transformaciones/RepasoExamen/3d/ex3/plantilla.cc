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

const int nPoints = 20;

esat::Vec3 estrella[nPoints];

void initStrella(){
  float angle = 6.28/(nPoints/2);

  for(int i = 0; i < nPoints/2; i++){
    if(i%2 == 0){
      estrella[i] = {cosf(angle*i), sinf(angle*i), 1};
      estrella[i + (nPoints/2)] = {cosf(angle*i), sinf(angle*i), -1};
    }else{
      estrella[i] = {cosf(angle*i)*0.5f, sinf(angle*i)*0.5f, 1};
      estrella[i + (nPoints/2)] = {cosf(angle*i)*0.5f, sinf(angle*i)*0.5f, -1};
    }
  }
}

esat::Mat4 updateMet(esat::Vec2 pos){
  esat::Mat4 temp;
  temp = esat::Mat4Identity();

  temp = esat::Mat4Multiply(esat::Mat4Translate(0,0,4), temp);
  temp = esat::Mat4Multiply(esat::Mat4Scale(50, 50, 15), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateX(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateY(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateZ(0.001f*esat::Time()), temp);
  temp = esat::Mat4Multiply(esat::Mat4Translate(pos.x, pos.y, 0), temp);

  return temp;
}

esat::Mat4 updateSon(esat::Mat4 mat){
  esat::Mat4 temp;
  temp = esat::Mat4Identity();

  temp = esat::Mat4Multiply(esat::Mat4Translate(10, 0,0), temp);
  temp = esat::Mat4Multiply(esat::Mat4RotateZ(0.01f*esat::Time()), temp);

  temp = esat::Mat4Multiply(esat::Mat4Scale(0.5f, 0.5f, 1), temp);
  temp = esat::Mat4Multiply(mat, temp);

  return temp;
}


void DrawThing(esat::Mat4 mat){
  esat::Vec3 lineas[nPoints];
  for(int i = 0; i < nPoints; i++){
    lineas[i] = esat::Mat4TransformVec3(mat, estrella[i]);
  }

  // 0->9
  // 10->19;
  // 0->10/1->11 etc...

  for(int i = 0; i < nPoints-1; i++){
    if(i < nPoints/2){
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[i+nPoints/2].x, lineas[i+nPoints/2].y);
    }
    if(i != nPoints/2 -1){
      esat::DrawLine(lineas[i].x, lineas[i].y, lineas[i+1].x, lineas[i+1].y);
    }
    
  }
    esat::DrawLine(lineas[0].x, lineas[0].y, lineas[nPoints/2-1].x, lineas[nPoints/2-1].y);
    esat::DrawLine(lineas[nPoints/2].x, lineas[nPoints/2].y, lineas[nPoints-1].x, lineas[nPoints-1].y);
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  initStrella();
  
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

    esat::Mat4 m = updateMet(mousePosition);
    DrawThing(m);

    m = updateSon(m);
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