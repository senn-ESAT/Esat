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

esat::Vec3 points[8] ={
  {0, 0, 0},       // bottom left
  {0, 0.6f, 0},    // top left
  {0.5f, 0.6f, 0}, // torp right
  {0.5f, 0, 0},    // bottom right
  {0.4f, 0.5f, 0}, // repeat
  {0.4f, 1, 0},
  {1, 1, 0},
  {1, 0.4f, 0}
};
void Modal(){
  esat::Mat4 m;
  m = esat:: Mat4RotateX(rotationValue);
  m = Mat4RotateY(rotationValue);
  m = Mat4RotateZ(rotationValue);
}

int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;

  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);

  esat::Vec2 mousePosition;
  float rotationValue = 0.0f;
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0, 0, 0);
      esat::DrawSetStrokeColor(255,255,255);

      mousePosition.x = esat::MousePositionX();
      mousePosition.y = esat::MousePositionY();

      //               Translate        Scale            Projection                          ??????????
      // final_point = T(t.x, t.y, 0) * S(s.x, s.y, 1) * proj * T(0, 0, z) * 3D(aka model) * LocalPoint

      esat::Mat4 m = esat::Mat4Identity();


      // Initial translate
      m = esat::Mat4Multiply(esat::Mat4Translate(0, 0, 30), m);
      // Projection
      m = esat::Mat4Multiply(esat::Mat4Projection(), m);
      // Scale
      m = esat::Mat4Multiply(esat::Mat4Scale(50.0f, 50.0f, 0), m);
      // Rotate
      // Tanslate
      m = esat::Mat4Multiply(esat::Mat4Translate(mousePosition.x, mousePosition.y, 1), m);

      // Draw -> points
      esat::Vec2 drawingPoints[8];

      for(int i = 0;  i < 8; i++){
        esat::Vec3 temp;
        temp = esat::Mat4TransformVec3(m, points[i]);
        drawingPoints[i] = {temp.x, temp.y};

        esat::DrawLine();
      }

      esat::DrawEnd();
      esat::WindowFrame();

      do {
        current_time = esat::Time();
      } while((current_time - last_time) <= 1000.0 / fps);
      rotationValue += 0.0001f;
    }
  esat::WindowDestroy();
  return 0;
}