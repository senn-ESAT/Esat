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

const int nPoints = 36;

esat::Vec2 circle[nPoints];
esat::Vec2 ellipse[nPoints];

void initCircle(){
  float angle = 6.28/nPoints;

  for(int i = 0; i < nPoints; i ++){
    circle[i] = {cosf(angle * i), sinf(angle * i)};
  }
}

esat::Mat3 circleMat(esat::Vec2 pos){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(20, 20), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 ellipseMat(esat::Vec2 pos, float angle){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(4, 1.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(30, 30), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(angle), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y), temp);

  return temp;
}

esat::Mat3 atomMat(esat::Vec2 pos, esat::Mat3 oiginal){
                          // punto origen + posicion elipse + desplazamiento * dimesion eliplse * extrude

  float movement = 0.001f * esat::Time();
  
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(0.25f / 2, 0.75f / 2), temp);  // revertir extrude de ellipse
  temp = esat::Mat3Multiply(esat::Mat3Translate(cosf(movement), sinf(movement)), temp);

  temp = esat::Mat3Multiply(oiginal, temp);

  return temp;
}

void drawCircle(esat::Mat3 mat){
  esat::Vec2 lines[nPoints];
  for(int i = 0; i < nPoints; i++){
    lines[i] = esat::Mat3TransformVec2(mat, circle[i]);
  }
  for(int i = 0; i < nPoints - 1; i++){
    esat::DrawLine(lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
  }
  esat::DrawLine(lines[0].x, lines[0].y, lines[nPoints-1].x, lines[nPoints-1].y);
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  initCircle();

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

    esat::Mat3 m = circleMat(mousePosition);
    drawCircle(m);

    for(int i = 0; i < 3; i++){
      m = ellipseMat(mousePosition, ((6.28/3)*i));
      drawCircle(m);

      m = atomMat(mousePosition, m);
      drawCircle(m);
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