#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <esat/math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "MathLib.h"

struct Shape{
  float x;
  float y;
  float radius;
};

const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;
const int knPoints = 30;
float g_circle[knPoints*2];

void DrawCircle(){
  esat::DrawSetStrokeColor(0, 0, 0, 255);
  esat::DrawSetFillColor(255, 0, 0, 150);
  esat::DrawSolidPath(g_circle, knPoints);
}

void InitCircle(float posx, float posy){
  float angle_a = -1.57f;
  float angle_b = 6.28f / (float) knPoints;
  float sin_a = sinf(angle_a);  // 0.0f
  float sin_b = sinf(angle_b);
  float cos_a = cosf(angle_a);  // 1.0f
  float cos_b = cosf(angle_b);

  for(int i = 0; i< knPoints; ++i){
    float sin_a_b = sin_a * cos_b + cos_a * sin_b;
    float cos_a_b = cos_a * cos_b - sin_a * sin_b;
    g_circle[i*2] = cos_a_b * 80.0f + posx;
    g_circle[i*2 + 1] = sin_a_b * 80.0f + posy;
    sin_a = sin_a_b;
    cos_a = cos_a_b;
  }
  DrawCircle();
}

mm::Vec2 calculoMouse(){
  mm::Vec2 mouse;
  mouse.x = (float)esat::MousePositionX();
  mouse.y = (float)esat::MousePositionY();
  return mouse;
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  
  mm::Vec2 mouse; 
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    mouse = calculoMouse();
    
    InitCircle(ScreenX/2, ScreenY/2);
    DrawCircle(); 
    InitCircle(mouse.x, mouse.y);
    DrawCircle();

    esat::DrawEnd();
    esat::WindowFrame();

    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}