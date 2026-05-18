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

const int pFlecha = 8;
esat::Vec2 pentagon[5];

float points[16] = {
0.0f, 0.4f,
0.65f, 0.4f,
0.65f, 0.25f,
1.0f, 0.5f,
0.65f, 0.75f,
0.65f, 0.6f,
0.0f, 0.6f,
0.0f, 0.4f };

void centerPoints(){
  for(int i = 0; i < pFlecha*2; i++){
    if(i%2 == 0){
      points[i] -= 0;     // x de la base
    }else{
      points[i] -= 0.5f;  // y central
    }
  }
}

void initPenta(){
  float angle = 6.28/5;
  for(int i = 0; i < 5; i++){
    pentagon[i] = {cosf(angle*i), sinf(angle*i)};
  }
}

esat::Mat3 pentaMat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  
  temp = esat::Mat3Multiply(esat::Mat3Scale(150, 150), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 arrowMat(esat::Vec2 pos, float angle){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  
  temp = esat::Mat3Multiply(esat::Mat3Rotate(0.001f*esat::Time()), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(150*0.75f, 150*0.75f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(150, 0), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(angle), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

void drawPenta(esat::Mat3 mat){
  esat::Vec2 lines[5];
  for(int i = 0; i < 5; i++){
    lines[i] = esat::Mat3TransformVec2(mat, pentagon[i]);
  }

  for(int i = 0; i < 5; i++){
    if(i == 4){
      esat::DrawLine(lines[i].x, lines[i].y, lines[0].x, lines[0].y);
    }else{
      esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
    }
  }
}

void drawArrow(esat::Mat3 mat){
  esat::Vec2 lines[pFlecha];
  for(int i = 0; i < pFlecha*2; i+=2){
    esat::Vec2 temp = {points[i],points[i+1] };
    lines[i/2] = esat::Mat3TransformVec2(mat, temp);
  }

  for(int i = 0; i < pFlecha; i++){
    if(i == pFlecha-1){
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

  initPenta();
  centerPoints();
  
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

    esat::Mat3 m = pentaMat(mousePosition);
    drawPenta(m);

    for(int i = 0; i < 5; i++){
      float angle = 6.28/5;

      esat::Mat3 arr = arrowMat(mousePosition, angle * i);
      drawArrow(arr);
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