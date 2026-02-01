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

const int kNPoints = 30;
float g_circle[kNPoints * 2];


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  float angle = 6.28f / (float) kNPoints;
  for (int i = 0; i < kNPoints; ++i) {
    g_circle[i * 2] = cosf(angle * i) * 180.0f + 400.0f; //x
    g_circle[i * 2 + 1] = sinf(angle * i) * 180.0f + 300.0f; //y
  }

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
         esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(120, 120, 120);

    esat::DrawSetStrokeColor(0, 0, 0, 255);
    esat::DrawSetFillColor(255, 255, 0, 255);
    esat::DrawSolidPath(g_circle, kNPoints);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}