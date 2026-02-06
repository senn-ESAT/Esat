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
#include "./2D/example_demo.cc"

const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;

esat::Vec2 calculoPrimaria(){
  esat::Vec2 mouse;
  mouse.x = esat::MousePositionX();
  mouse.y =  esat::MousePositionY();
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  esat::Vec2 centro = {ScreenX/2, ScreenY/2}, mouse, primaria;
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);

      mouse = calculoPrimaria();
      primaria = MM::subVec2(mouse, centro);

      esat::DrawEnd();
      esat::WindowFrame();

      do {
        current_time = esat::Time();
      } while((current_time - last_time) <= 1000.0 / fps);
    }
  esat::WindowDestroy();
  return 0;
}