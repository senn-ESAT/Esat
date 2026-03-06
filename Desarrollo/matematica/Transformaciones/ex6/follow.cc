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
#include "../../2D/MathLib.h"

const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int kNPoints = 5;
esat::Vec3 circle[kNPoints];

void DrawCircle(esat::Mat3 m) {
  esat::Vec2 tr_circle[kNPoints];
  for (int i = 0; i < kNPoints; ++i) {
    esat::Vec3 tmp = esat::Mat3TransformVec3(m, circle[i]);
    tr_circle[i] = {tmp.x, tmp.y};
  }
  esat::DrawSetStrokeColor(0,0,0,0);
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawSolidPath(&tr_circle[0].x, kNPoints);
}

esat::Mat3 BasicTransform(esat::Vec2 mouse){
  esat::Mat3 m = esat::Mat3Identity();
  // escalar y por lo tanto el radio
  m = esat::Mat3Multiply(esat::Mat3Scale(70.0f, 70.0f), m);
  // rotar la figura por un valor velocidad
  m = esat::Mat3Multiply(esat::Mat3Rotate(6.28f), m);
  // translate es el punto de origen
  m = esat::Mat3Multiply(esat::Mat3Translate(mouse.x, mouse.y ), m);
  return m;
}

void initCircle(){
  float angleC = 6.28f / (float) kNPoints;
  for (int i = 0; i < kNPoints; ++i) {
    circle[i] = {cosf(angleC * i), sinf(angleC * i), 1.0f};
  }
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::Vec2 mousePosition;
  
  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  initCircle();

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);    
    
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    esat::Mat3 m = BasicTransform(mousePosition);

    DrawCircle(m);
    // for(int i = 0; i < kNPoints; i++){
      
    // }

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}