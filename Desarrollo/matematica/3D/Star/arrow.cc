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

const int nPoints = 10;

esat::Vec4 points[nPoints*2];// ={
//   //front
//   {0, 0, 1, 1}, // bottom left
//   {0, 1, 1, 1}, // top left
//   {1, 1, 1, 1}, // torp right
//   {1, 0, 1, 1}, // bottom right
//   {0, 0, -1, 1},// bottom left
//   {0, 1, -1, 1},// top left
//   {1, 1, -1, 1},// torp right
//   {1, 0, -1, 1},
// };

// void Modal(){
//   esat::Mat4 m;
//   m = esat:: Mat4RotateX(rotationValue);
//   m = Mat4RotateY(rotationValue);
//   m = Mat4RotateZ(rotationValue);
// }

void initStar(){
  float angle = 6.28f / (float) nPoints;

  for (int i = 0; i < nPoints ; ++i){
    if(i%2 == 0){
      points[i] = { cosf(angle*i), sinf(angle*i), 0.4f, 1.0f};

      points[i + nPoints] = {cosf(angle*i), sinf(angle*i), -0.4f, 1.0f};
    }else{
      points[i] = {cosf(angle*i) * 0.6f, sinf(angle*i) * 0.6f, 0.4f, 1.0f};

      points[i + nPoints] = {cosf(angle*i)*0.6f, sinf(angle*i)* 0.6f, -0.4f, 1.0f};
    }
  }
}

// estrella mini
esat::Mat4 DerivedTransform(esat::Mat4 mat){
 
  esat::Mat4 m = esat::Mat4Identity();
  // Rotate
  m = esat::Mat4Multiply(esat::Mat4Scale(0.5f, 0.5f, 0.5f), m);
  m = esat::Mat4Multiply(esat::Mat4RotateZ(esat::Time() * 0.005f), m);
  m = esat::Mat4Multiply(esat::Mat4Translate(3.0f, 0.0f, 0.0f), m);
  m = esat::Mat4Multiply(esat::Mat4RotateZ(esat::Time() * 0.0005f), m);

  m = esat::Mat4Multiply(mat, m);
  return m;
}

void DrawShape(esat::Mat4 m){
  // Draw -> points
  esat::Vec2 drawingPoints[nPoints*2];

  for(int i = 0;  i < nPoints*2; ++i){
    esat::Vec4 temp;
    temp = esat::Mat4TransformVec4(m, points[i]);
    drawingPoints[i] = {temp.x, temp.y};

    float r = 1.0f/temp.w;

    drawingPoints[i].x = temp.x * r;
    drawingPoints[i].y = temp.y * r;
  }

  esat::DrawSetStrokeColor(255, 255, 255);
  for(int i = 0; i < nPoints; ++i){
    // frente con frente
    esat::DrawLine(drawingPoints[i].x, 
                  drawingPoints[i].y, 
                  drawingPoints[(i+1) % nPoints].x, 
                  drawingPoints[(i+1) % nPoints].y);
                  
    // los del frente con los de atras
    esat::DrawLine(drawingPoints[i].x, 
                  drawingPoints[i].y, 
                  drawingPoints[i+ nPoints].x, 
                  drawingPoints[i+ nPoints].y);

    //atras con atras
    esat::DrawLine(drawingPoints[i + nPoints].x, 
                  drawingPoints[i + nPoints].y, 
                  drawingPoints[(i + 1) % nPoints + nPoints].x, 
                  drawingPoints[(i + 1) % nPoints + nPoints].y);
  }
}

esat::Mat4 CubeTransform(esat::Vec2 mousePosition){
  //               Translate        Scale            Projection                          ??????????
  // final_point = T(t.x, t.y, 0) * S(s.x, s.y, 1) * proj * T(0, 0, z) * 3D(aka model) * LocalPoint

  esat::Mat4 m = esat::Mat4Identity();

  // Rotate
  m = esat::Mat4Multiply(esat::Mat4RotateY(esat::Time() * 0.001f), m);
  // Initial translate
  m = esat::Mat4Multiply(esat::Mat4Translate(0.0f, 0.0f, 4.0f), m);
  // Projection
  m = esat::Mat4Multiply(esat::Mat4Projection(), m);
  // Scale
  m = esat::Mat4Multiply(esat::Mat4Scale(400.0f, 400.0f, 1.0f), m);
  // Tanslate
  m = esat::Mat4Multiply(esat::Mat4Translate(mousePosition.x, mousePosition.y, 0.0f), m);

  return m;
}


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0, last_time = 0.0, fps = 60.0;
  esat::Vec2 mousePosition;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);
  initStar();
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    esat::DrawSetStrokeColor(255,255,255);

    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    esat::Mat4 m = CubeTransform(mousePosition);
    DrawShape(m);

    m = DerivedTransform(m);
    DrawShape(m);



    //               Translate        Scale            Projection                          ??????????
    // final_point = T(t.x, t.y, 0) * S(s.x, s.y, 1) * proj * T(0, 0, z) * 3D(aka model) * LocalPoint

    // esat::Mat4 m = esat::Mat4Identity();


    // // Initial translate
    // m = esat::Mat4Multiply(esat::Mat4Translate(0, 0, 30), m);
    // // Projection
    // m = esat::Mat4Multiply(esat::Mat4Projection(), m);
    // // Scale
    // m = esat::Mat4Multiply(esat::Mat4Scale(50.0f, 50.0f, 0), m);
    // // Rotate
    // // Tanslate
    // m = esat::Mat4Multiply(esat::Mat4Translate(mousePosition.x, mousePosition.y, 1), m);

    // // Draw -> points
    // esat::Vec2 drawingPoints[8];
    // esat::Vec3 prepoint;

    // for(int i = 0;  i < 8; i++){
    //   esat::Vec3 temp;
    //   temp = esat::Mat4TransformVec3(m, points[i]);
    //   drawingPoints[i] = {temp.x, temp.y};

    //   esat::DrawLine(temp.x, temp.y, prepoint.x, prepoint.y);
    //   prepoint = temp;
    // }

    esat::DrawEnd();
    esat::WindowFrame();


    do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}