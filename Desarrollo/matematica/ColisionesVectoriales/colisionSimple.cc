#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "esat/window.h"
#include "esat/draw.h"
#include "esat/input.h"
#include "esat/sprite.h"
#include "esat/time.h"
#include "esat/math.h"
#include "../2D/MathLib.h"


const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int kNPoints = 7;
mm::Vec3 puntos[14] = {0};

void de2a3(){
  int row = 0;
  float points[14] = {
    3, 3,
    6, 3,
    7, 0,
    6, -3,
    3, -3,
    0, 0,
    3, 3 
  };

  for(int i = 0; i< kNPoints*2; i+=2){
    puntos[row].x = points[i];
    puntos[row].y = points[i+1];
    puntos[row].z = 1;
    row++;
  }
}

// esto es un modo simplificado para normalisar
void homogeneizar(){
  // el 8 es el valor mas alto de el array
  float r = 1.0f / 8;
  for(int i = 0; i < kNPoints; i++){
    puntos[i].x *= r;
    puntos[i].y *= r;
    // en la z no hace falta porque es un punto
  }
}

esat::Mat3 OuterCircle(float rot){
  esat::Mat3 m = esat::Mat3Identity();
  // escalar y por lo tanto el radio
  m = esat::Mat3Multiply(esat::Mat3Translate(0, 0.0f), m);
  m = esat::Mat3Multiply(esat::Mat3Scale(100.0f, 100.0f), m);
  // rotar la figura por un valor velocidad
  m = esat::Mat3Multiply(esat::Mat3Rotate(6.28f/(float)12*rot), m);
  // translate es el punto de origen
  m = esat::Mat3Multiply(esat::Mat3Translate(kWindowWidth/2, kWindowHeight/2 ), m);
  return m;
}

void DrawCircle(esat::Mat3 m) {
  esat::Vec2 tr_circle[kNPoints];
  esat::Vec3 points[kNPoints];
  for (int i = 0; i < kNPoints; ++i) {
    points[i].x = puntos[i].x;
    points[i].y = puntos[i].y;
    points[i].z = puntos[i].z;
    esat::Vec3 tmp = esat::Mat3TransformVec3(m, points[i]);
    tr_circle[i] = { tmp.x, tmp.y };
  }
  esat::DrawSetStrokeColor(0,0,0,0);
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawPath(&tr_circle[0].x, kNPoints);
}

bool checkColision(esat::Vec2 mouse){
  mm::Vec3 temp[kNPoints];
  for(int i = 0; i < kNPoints; i++){
    
    temp[i] = mm::subVec3(puntos[i], puntos[i+1]);
    //normalize(temp[i]);
    //dor v y mouse
  }
  return true;
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  de2a3();
  homogeneizar();
  
  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);    
    
    esat::Vec2 mousePosition;
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    if(esat::MouseButtonDown(0)){
      if(checkColision(mousePosition)){
       printf("Colision\n");
     }else{
       printf("No colision\n");
     }
    } 
    
    esat::Mat3 m = OuterCircle(0);
    DrawCircle(m);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}