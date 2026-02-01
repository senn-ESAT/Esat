#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"

const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int knPoints = 6;
float g_circle[knPoints*2];

void InitCircle(){
  float angle_a = -1.57f;
  float angle_b = 6.28f / (float) knPoints;
  float sin_a = sinf(angle_a);  // 0.0f
  float sin_b = sinf(angle_b);
  float cos_a = cosf(angle_a);  // 1.0f
  float cos_b = cosf(angle_b);

  for(int i = 0; i< knPoints; ++i){
    float sin_a_b = sin_a * cos_b + cos_a * sin_b;
    float cos_a_b = cos_a * cos_b - sin_a * sin_b;
    g_circle[i*2] = cos_a_b * 180.0f + 400.0f;
    g_circle[i*2 + 1] = sin_a_b * 180.0f + 300.0f;
    sin_a = sin_a_b;
    cos_a = cos_a_b;
  }
}

void DrawCircle(){
  esat::DrawSetStrokeColor(255, 0, 0, 255);
  esat::DrawSetFillColor(255, 0, 0, 255);
  esat::DrawSolidPath(g_circle, knPoints);
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  InitCircle();

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
    esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);

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