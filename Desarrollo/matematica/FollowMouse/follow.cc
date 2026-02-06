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

const unsigned int ScreenX = 800;
const unsigned int ScreenY = 600;
const int speed = 4;

mm::Vec2 calculoMouse(){
  mm::Vec2 mouse;
  mouse.x = (float)esat::MousePositionX();
  mouse.y = (float)esat::MousePositionY();
  return mouse;
}

mm::Vec2 moveSquare(mm::Vec2 s, mm::Vec2 m){
  mm::Vec2 moovement;
  moovement = subVec2(m, s);
  moovement = normalize(moovement);
  moovement = scaleV2(moovement, speed);
  return moovement;
}

void drawSquare(mm::Vec2 v){
  float lados[10] = {v.x,v.y, v.x+20,v.y, v.x+20,v.y+20, v.x,v.y+20, v.x,v.y};
  esat::DrawSetStrokeColor(255,255,255);
  esat::DrawSetFillColor(255,255,255);
  esat::DrawSolidPath(lados, 5);
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  mm::Vec2 centro = {ScreenX/2, ScreenY/2}, mouse, dir, squatre = {10, 10};
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);
      esat::DrawSetStrokeColor(255,255,255);

      mouse = calculoMouse();
      dir = subVec2(mouse, squatre);
      mm::Vec2Print(dir);
      dir = normalize(dir);
      mm::Vec2Print(dir);

      squatre = sumVec2(squatre, dir);
      
      drawSquare(squatre);

      esat::DrawEnd();
      esat::WindowFrame();
      do {
        current_time = esat::Time();
      } while((current_time - last_time) <= 1000.0 / fps);
    }
  esat::WindowDestroy();
  return 0;
}