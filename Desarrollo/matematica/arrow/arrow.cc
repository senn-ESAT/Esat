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

esat::Vec2 subVec2(esat::Vec2 v1, esat::Vec2 v2){
  esat::Vec2 temp = {{v1.x - v2.x}, {v1.y - v2.y}};
  return temp;
}

esat::Vec2 sumVec2(esat::Vec2 v1, esat::Vec2 v2){
  esat::Vec2 temp = {{v1.x + v2.x}, {v1.y + v2.y}};
  return temp;
}

esat::Vec2 calculoMouse(){
  esat::Vec2 mouse;
  mouse.x = esat::MousePositionX();
  mouse.y =  esat::MousePositionY();
  return mouse;
}

  esat::Vec2 perp2D1(esat::Vec2 v){
    esat::Vec2 temp = {{-v.y}, {v.x}};
    return temp;
  }

  esat::Vec2 perp2D2(esat::Vec2 v){
    esat::Vec2 temp = {{v.y}, {-v.x}};
    return temp;
  }

esat::Vec2 scaleV2(esat::Vec2 v1, float n){
  esat::Vec2 temp = {{v1.x * n}, {v1.y *n}};
  return temp;
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  esat::Vec2 centro = {ScreenX/2, ScreenY/2}, mouse, primaria, dir, lateralL, lateralR;
  float flecha[10];
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);
      esat::DrawSetStrokeColor(255,255,255);

      mouse = calculoMouse();
      dir = subVec2(mouse, centro);
      primaria = sumVec2(centro, scaleV2(dir, 0.75f));
      esat::DrawLine(centro.x, centro.y, primaria.x, primaria.y);
      dir = subVec2(mouse, primaria);

      flecha[0] = primaria.x; flecha[1] = primaria.y; 
      flecha[2] = sumVec2(primaria, perp2D1(dir)).x; flecha[3] = sumVec2(primaria, perp2D1(dir)).y,
      flecha[4] = mouse.x; flecha[5] = mouse.y;
      flecha[6] = sumVec2(primaria, perp2D2(dir)).x; flecha[7] = sumVec2(primaria, perp2D2(dir)).y;
      flecha[8] = primaria.x; flecha[9] = primaria.y;

      esat::DrawPath(flecha, 5);

      esat::DrawEnd();
      esat::WindowFrame();

      do {
        current_time = esat::Time();
      } while((current_time - last_time) <= 1000.0 / fps);
    }
  esat::WindowDestroy();
  return 0;
}