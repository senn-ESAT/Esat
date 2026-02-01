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

const int PuntoCirculo = 30;
float coordsCirculo[PuntoCirculo * 2];

void circulo(){
  float angle = 6.28f / (float) PuntoCirculo;
  for (int i = 0; i < PuntoCirculo; ++i) {
    coordsCirculo[i * 2] = cosf(angle * i) * 100.0f + 150.0f; //x
    coordsCirculo[i * 2 + 1] = sinf(angle * i) * 100.0f + 150.0f; //y
  }
}

const int PuntoTriangulo = 3;
float coordsTriangulo[PuntoTriangulo * 2];

void triangulo(){
  float angle = 6.28f / (float) PuntoTriangulo;
  for (int i = 0; i < PuntoTriangulo; ++i) {
    coordsTriangulo[i * 2] = cosf(angle * i) * 100.0f + 400.0f; //x
    coordsTriangulo[i * 2 + 1] = sinf(angle * i) * 100.0f + 300.0f; //y
  }
}

const int PuntoCuad = 4;
float coordsCuad[PuntoCuad * 2];

void cuadrado(){
  float angle = 6.28f / (float) PuntoCuad;
  for (int i = 0; i < PuntoCuad; ++i) {
    coordsCuad[i * 2] = cosf(angle * i) * 180.0f + 600.0f; //x
    coordsCuad[i * 2 + 1] = sinf(angle * i) * 180.0f + 400.0f; //y
  }
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);
  
  circulo();
  triangulo();
  cuadrado();
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
  esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(120, 120, 120);
    
    esat::DrawSetStrokeColor(0, 0, 0, 255);
    esat::DrawPath(coordsCirculo, PuntoCirculo);
    esat::DrawPath(coordsTriangulo, PuntoTriangulo);
    esat::DrawPath(coordsCuad, PuntoCuad);

    

    esat::DrawEnd();
    esat::WindowFrame();

    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}