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

const int arrowPoints = 5, squarePoints = 5;


float arrow[arrowPoints*2] = {
  0.0f, 1.0f,
  1.0f, 0.0f,
  0.0f, -3.0f,
  -1.0f, 0.0f,
  0.0f, 1.0f,
};

float square[squarePoints*2] = {
  -1.0f, -1.0f,
  1.0f, -1.0f,
  1.0f, 1.0f,
  -1.0f, 1.0f,
  -1.0f, -1.0f
};

void DrawArrow(esat::Mat3 mat){
  esat::Vec2 drawingShape[arrowPoints];
  for(int i = 0; i < arrowPoints*2; i+=2){
    esat::Vec3 Points;
    esat::Vec3 temp;
    Points.x = arrow[i];
    Points.y = arrow[i+1];
    Points.z = 1;

    temp = esat::Mat3TransformVec3(mat, Points);
    
    drawingShape[i/2] = {temp.x, temp.y};
  }

  esat::DrawSetStrokeColor(255, 255, 255);
  for(int i = 0; i < arrowPoints - 1; i++){
    esat::DrawLine(drawingShape[i].x, drawingShape[i].y,
                   drawingShape[i+1].x, drawingShape[i+1].y);
  }
}

void DrawSquare(esat::Mat3 mat){
  esat::Vec2 drawingShape[5];

  for(int i = 0; i < 10; i+=2){
    esat::Vec3 Points;
    esat::Vec3 temp;
    Points.x = square[i];
    Points.y = square[i+1];
    Points.z = 1;

    temp = esat::Mat3TransformVec3(mat, Points);
    
    drawingShape[i/2] = {temp.x, temp.y};
  }
printf("\n----------------");
  esat::DrawSetStrokeColor(255, 255, 255);

  for(int i = 0; i < squarePoints-1; i++){
    esat::DrawLine(drawingShape[i].x, drawingShape[i].y,
                   drawingShape[i+1].x, drawingShape[i+1].y);
  }
}

// matIdentity
// Scale
// Rotate
// Translate

esat::Mat3 ShiftX(esat::Mat3 mat, float amount){
  mat = esat::Mat3Multiply(esat::Mat3Translate(amount, 0.0f), mat);
  return mat;
}

esat::Mat3 ShiftY(esat::Mat3 mat, float amount){
  mat = esat::Mat3Multiply(esat::Mat3Translate(0.0f, amount), mat);
  return mat;
}

esat::Mat3 Rotate90(esat::Mat3 mat){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  mat = esat::Mat3Multiply(esat::Mat3Rotate(6.28/4), mat);
  return mat;
}

esat::Mat3 romboMat(){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();

  temp = esat::Mat3Multiply(esat::Mat3Scale(10.0f, 10.0f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(0), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(kWindowWidth/2.5, kWindowHeight/2.5), temp);

  return temp;
}

esat::Mat3 MatSquare(){
  esat::Mat3 temp;
  temp = esat::Mat3Identity();
  temp = esat::Mat3Multiply(esat::Mat3Scale(1.0f, 0.5f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Scale(10.0f, 10.0f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Rotate(0.0f), temp);
  temp = esat::Mat3Multiply(esat::Mat3Translate(kWindowWidth/2.5, kWindowHeight/2.5), temp);

  return temp;
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(kWindowWidth, kWindowHeight);
  esat::WindowSetMouseVisibility(true);
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
  esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    
    esat::Mat3 matSquare = MatSquare();
    esat::Mat3 matArrow = romboMat();
    
    for(int j = 0; j < 2; j++){
      esat::Mat3 m = matSquare;
      for(int i = 0; i < 5; i++){
        m = ShiftY(m, 15);
        DrawSquare(m);
        esat::Mat3 m2 = m;
        m2 = ShiftX(m2, 200);
        DrawSquare(m2);
      }

      if(!j){
        matSquare = ShiftX(matSquare, 50);
        matSquare = ShiftY(matSquare, -50);
        matSquare = Rotate90(matSquare);
      }
    }

    DrawArrow(matArrow);

    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}