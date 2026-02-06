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

const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;
  struct Vec2 {
    float x, y;
  };
esat::Vec2 calculoPrimaria(){
  esat::Vec2 mouse;
  mouse.x = esat::MousePositionX();
  mouse.y =  esat::MousePositionY();
  return mouse;
}

  Vec2 subVec2(Vec2 v1, Vec2 v2){
    Vec2 temp = {{v1.x - v2.x}, {v1.y - v2.y}};
    return temp;
  }


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  Vec2 centro = {ScreenX/2, ScreenY/2}, mouse, primaria;
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);
      esat::DrawSetStrokeColor(255,255,255);

      mouse = calculoPrimaria();
      //primaria = subVec2(mouse, centro);
      esat::DrawLine(centro.x, centro.y, mouse.x, mouse.y);

      esat::DrawEnd();
      esat::WindowFrame();

      do {
        current_time = esat::Time();
      } while((current_time - last_time) <= 1000.0 / fps);
    }
  esat::WindowDestroy();
  return 0;
}