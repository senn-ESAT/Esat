#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"

/*

h = radio
cateto c = bucle entre -radio y +radio adelate y atrs
co = calculado

calcular punto?
circulo?

*/

const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int circlePoints = 30;
float g_circle[circlePoints*2];


void InitCircle(){
  
}
/*
  coordsCirculo[i * 2] = cosf(angle * i) * 100.0f + 150.0f; //x
  coordsCirculo[i * 2 + 1] = sinf(angle * i) * 100.0f + 150.0f; //y
*/
float catetos[circlePoints*2];
vois calculoTriangulo(){
  float h = 100.0f; // radio
  float cc = 0;   // y
  float co = h;   // x
  float change = (h*2)/(float)circlePoints;  // movimiento en x

  for(int i = 0; i < circlePoints; ++i){
    if(i >= circlePoints/2){
      catetos[i*2] = cc + (change*i);
      catetos[i*2 + 1] = (h*h) - (cc*cc);
    }
    else{
      catetos[i*2] = cc - (change*i);
      catetos[i*2 + 1] = (h*h) - (cc*cc);
    }
  }

}

void DrawCircle(){
  esat::DrawSetStrokeColor(255, 0, 0, 255);
  esat::DrawSetFillColor(255, 0, 0, 255);
  esat::DrawSolidPath(g_circle, circlePoints);
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  calculoTriangulo();
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






