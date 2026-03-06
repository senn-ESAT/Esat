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

const int kNPoints = 30;
esat::Vec3 circle[kNPoints];

void initCircle(){
  float angleC = 6.28f / (float) kNPoints;
  for (int i = 0; i < kNPoints; ++i) {
    circle[i] = {cosf(angleC * i), sinf(angleC * i), 1.0f};
  }
}

void DrawCircle(esat::Mat3 m) {
  esat::Vec2 tr_circle[kNPoints];
  for (int i = 0; i < kNPoints; ++i) {
    esat::Vec3 tmp = esat::Mat3TransformVec3(m, circle[i]);
    tr_circle[i] = {tmp.x, tmp.y};
  }
  esat::DrawSetStrokeColor(0,0,0,0);
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawPath(&tr_circle[0].x, kNPoints);
}

esat::Mat3 OrbitTrasform(esat::Vec2 mouse, int i){
  esat::Mat3 m = esat::Mat3Identity();
  m = esat::Mat3Multiply(esat::Mat3Scale(100.0f, 30.0f), m);
  float angle = esat::Time()*0.001f;
  m = esat::Mat3Multiply(esat::Mat3Rotate(6.28f/3 * i + angle), m);
  m = esat::Mat3Multiply(esat::Mat3Translate(mouse.x, mouse.y ), m);
  return m;
}

esat::Mat3 NeutronTrasform(esat::Mat3 base, int speed){
  esat::Mat3 m = esat::Mat3Identity();
  m = esat::Mat3Multiply(esat::Mat3Scale(1 / 100.0f * 10, 1 / 30.0f * 10), m);

  float angle = esat::Time()*0.0005f * speed;// efecto pendulo si float angle = cosf(esat::Time()*0.005f);
  m = esat::Mat3Multiply(esat::Mat3Translate(cosf(angle), sinf(angle)), m);
  m = esat::Mat3Multiply(base, m);
  return m;
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  initCircle();

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);    
    
    esat::Vec2 mousePosition = {(float)esat::MousePositionX(), (float)esat::MousePositionY()};
    for(int i = 0; i < 3; i++){
      esat::Mat3 m = OrbitTrasform(mousePosition, i);
      DrawCircle(m);
      DrawCircle(NeutronTrasform(m, i+1));
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