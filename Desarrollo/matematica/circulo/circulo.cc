#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"

struct Shape{
  float x;
  float y;
  float radius;
};


// si le restas 90 grados a un resultado la forma estara girada de 90 grados para la izquierda
//por ejemplo e cuadrado que sale como un rombo si le restas una cierta cantidad de grados te sale el rombo

double current_time = 0.0;
double last_time = 0.0;
double fps = 24.0;

const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int TC = 30, TT = 4, TQ = 5;

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  
  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);
  
  Shape circle= {400.0f, 300.0f, 180.0f};
  Shape triangle= {600.0f, 300.0f, 180.0f};
  Shape square= {400.0f, 400.0f, 180.0f};
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
    esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    float coordC[TC*2];
    float angleC = 6.28f / (float) TC;

    for (int i = 0; i < TC; ++i) {
      coordC[i * 2] = cosf(angleC * i) * circle.radius + circle.x; //x
      coordC[i * 2 + 1] = sinf(angleC * i) * circle.radius + circle.y; //y
    }
          
    esat::DrawSetStrokeColor(255, 0, 0);
    esat::DrawPath(coordC, TC*2);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}