#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"
#include "MathLib.h"

struct Ship{
  mm::Vec2 pos, speed;
  float angulo = 0.0f;
};

const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;

Ship Nave = {ScreenX/2, ScreenY/2};

float puntosNave[6];

void InitCircle(){
  float angle_a = Nave.angulo;
  float angle_b = -160.0f + angle_a;
  float angle_c = 160.0f + angle_a;

  puntosNave[0] = sinf(angle_a)*10+Nave.pos.x;
  puntosNave[1] = cosf(angle_a)*10+Nave.pos.y;
  puntosNave[2] = sinf(angle_b)*20+Nave.pos.x;
  puntosNave[3] = cosf(angle_b)*20+Nave.pos.y;
  puntosNave[4] = sinf(angle_c)*20+Nave.pos.x;
  puntosNave[5] = cosf(angle_c)*20+Nave.pos.y;
}

void DrawCircle(){
  esat::DrawSetStrokeColor(255, 255, 255);
  esat::DrawSolidPath(puntosNave, 6);
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
    
    InitCircle();
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