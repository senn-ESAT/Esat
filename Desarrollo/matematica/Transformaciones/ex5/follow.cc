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
#include "../../2D/MathLib.h"


const unsigned int kWindowWidth = 800;
const unsigned int kWindowHeight = 600;

const int kNPoints = 5;
esat::Vec3 g_circle[kNPoints];
esat::Vec3 puntos[10] = {0};

void de2a3(){
  int row = 0;

  float points[10] = {
    0.0f, 0.0f,
    0.0f, 0.75f,
    0.125f, 1.0f,
    0.25f, 0.75f,
    0.25f, 0.0f,
  };

  for(int i = 0; i < kNPoints*2; i+=2){
    puntos[row].x = points[i];
    puntos[row].y = points[i+1];
    puntos[row].z = 1;
    row++;
  }
}

// esto es un modo simplificado para normalisar
void homogeneizar(){
  // el 8 es el valor mas alto de el array
  float r = 1.0f / 0.7f;
  for(int i = 0; i < kNPoints; i++){
    puntos[i].x *= r;
    puntos[i].y *= r;
    // en la z no hace falta porque es un punto
  }
}

// calcula los puntos
// void InitCircle() {
//   float angle = 6.28f / (float) kNPoints;
//   for (int i = 0; i < kNPoints; ++i) {
//     g_circle[i] = { cosf(angle * i), sinf(angle * i), 1.0f };
//   }
// }

esat::Mat3 OuterCircle(float rot, esat::Vec2 mouse){
  esat::Mat3 m = esat::Mat3Identity();
  // escalar y por lo tanto el radio
  if((int)rot%2 == 0){
    m = esat::Mat3Multiply(esat::Mat3Translate(0, 2.0f), m);
  }
  else{
    m = esat::Mat3Multiply(esat::Mat3Translate(0, -3.0f), m);
  }
  m = esat::Mat3Multiply(esat::Mat3Scale(70.0f, 70.0f), m);
  // rotar la figura por un valor velocidad
  m = esat::Mat3Multiply(esat::Mat3Rotate(6.28f/(float)8*rot), m);
  // translate es el punto de origen
  m = esat::Mat3Multiply(esat::Mat3Translate(mouse.x, mouse.y ), m);
  return m;
}

void DrawCircle(esat::Mat3 m) {
  esat::Vec2 tr_circle[kNPoints];
  for (int i = 0; i < kNPoints; ++i) {
    esat::Vec3 tmp = esat::Mat3TransformVec3(m, puntos[i]);
    tr_circle[i] = { tmp.x, tmp.y };
  }
  esat::DrawSetStrokeColor(0,0,0,0);
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawPath(&tr_circle[0].x, kNPoints);
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
  //InitCircle();

  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);    
    
    esat::Vec2 mousePosition;
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    for(int i = 0; i < 10; i++){
      esat::Mat3 m = OuterCircle(i, mousePosition);
      DrawCircle(m);
    }
    /*
    esata decentrado porque el que esta al reves no inicia en el centro pero desde el primer punto
    me bastaria hacer un segundo draw con col cosos al reves
    */
    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}