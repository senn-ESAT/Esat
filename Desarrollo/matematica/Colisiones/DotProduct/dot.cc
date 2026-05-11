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

struct Ship{
  mm::Vec2 pos;
  mm::Vec2 speed;
  float angulo = 0.0f;
  float *puntosNave;
};

struct Asteroids{
  float size;
  int nPoints;
  mm::Vec2 pos, speed;
  esat::Vec3 *points;
  // TO-DO colision areas
};

const int ScreenX = 800, ScreenY = 600;
Ship ship;
Asteroids aste;

float* ShipShape(float angle_a, float angle_b, float angle_c, mm::Vec2 pos, float *puntosNave){
  puntosNave[0] = sinf(angle_a)*10+pos.x;   // a
  puntosNave[1] = cosf(angle_a)*10+pos.y;
  puntosNave[2] = sinf(angle_b)*7+pos.x;    // b
  puntosNave[3] = cosf(angle_b)*7+pos.y;
  puntosNave[4] = sinf(angle_c)*7+pos.x;    // c
  puntosNave[5] = cosf(angle_c)*7+pos.y;
  puntosNave[6] = sinf(angle_a)*10+pos.x;   // d (a)
  puntosNave[7] = cosf(angle_a)*10+pos.y;

  return puntosNave;
}

void initShip(){
  float angle_a = ship.angulo;
  float angle_b = angle_a - 2.4f;
  float angle_c = angle_a + 2.4f;

  ship.puntosNave = ShipShape(angle_a, angle_b, angle_c, ship.pos, ship.puntosNave);
}

esat::Vec3* asteroidsShape(){
  esat::Vec3 *vertices;
  vertices = (esat::Vec3*)malloc(10 * sizeof(esat::Vec3));
        *(vertices)     = {-0.20f,  -0.40f, 1.0f}; //A
        *(vertices + 1) = { 0.00f,  -0.60f, 1.0f}; //B
        *(vertices + 2) = { 0.20f,  -0.40f, 1.0f}; //C
        *(vertices + 3) = { 0.40f,  -0.60f, 1.0f}; //D
        *(vertices + 4) = { 0.60f,  -0.40f, 1.0f}; //E
        *(vertices + 5) = { 0.40f,  -0.16f, 1.0f}; //F
        *(vertices + 6) = { 0.52f,   0.00f, 1.0f}; //G
        *(vertices + 7) = { 0.40f,   0.20f, 1.0f}; //H
        *(vertices + 8) = { 0.00f,   0.20f, 1.0f}; //I
        *(vertices + 9) = {-0.20f,   0.00f, 1.0f}; //J
  return vertices;
}

void Controls(){
  //speed
  float current_speed = mm::magnitudeV2(ship.speed);
  if(esat::IsKeyPressed('w') || esat::IsKeyPressed('W')
    || esat::IsSpecialKeyPressed(esat::kSpecialKey_Up)){
    if(current_speed > 8){
      ship.speed = mm::normalize(ship.speed);
      ship.speed = mm::scaleV2(ship.speed, 8);
    }else{
      mm::Vec2 thrust = {sinf(ship.angulo), cosf(ship.angulo)}; // ship direction
      thrust = mm::scaleV2(thrust, 0.065f);                       // add acceleration
      ship.speed = mm::sumVec2(ship.speed, thrust);             // add thrust to current speed
    }
  }

  //direction
  if(esat::IsKeyPressed('a') || esat::IsKeyPressed('A') 
    || esat::IsSpecialKeyPressed(esat::kSpecialKey_Left)){
    ship.angulo += 0.07f;
  }else if(esat::IsKeyPressed('d') || esat::IsKeyPressed('D')
        || esat::IsSpecialKeyPressed(esat::kSpecialKey_Right)){
    ship.angulo -= 0.07f;
  }

  if(esat::IsKeyDown('g') || esat::IsKeyDown('G')){
    ship.pos = {(float)(rand()%800), (float)(rand()%600)};
  }
}

void Move(){
  ship.pos = mm::sumVec2(ship.pos, ship.speed);
}



void SpawnShip(){
  ship.pos = {ScreenX/2, ScreenY/2};
  ship.speed = {0.0f, 0.0f};
  ship.angulo = 0.0f;
  ship.puntosNave = (float*)malloc(8*sizeof(float));
}

float dotCalculator(esat::Vec2 A, esat::Vec2 B){
  return((A.x * B.x) + (A.y * B.y));
}

float crossCalculator(mm::Vec2 A, mm::Vec2 B){
  return (A.x * B.y) - (A.y * B.x);
}

float PointInTriangle(mm::Vec2 p, mm::Vec2 a, mm::Vec2 b){

    mm::Vec2 ab = mm::subVec2(b, a);
    mm::Vec2 ap = mm::subVec2(p, a);

    //  P
    //  |
    //  |
    //  A------>B

    // si mismo signo del cross product entonces adentro

    float cross = crossCalculator(ab, ap);

    return cross;
}



bool ChechProximity(mm::Vec2 pos1, esat::Vec2 pos2, float offset){

  mm::Vec2 p2 = {pos2.x, pos2.y};
  p2 = mm::subVec2(pos1, p2);

  if((p2.x < offset && p2.x > - offset) && (p2.y < offset && p2.y > - offset)){ // Are they in the same space
    return true;
  }
  return false;
}

esat::Mat3 MatAsteroid(mm::Vec2 pos, float size){
  esat::Mat3 m = esat::Mat3Identity();
  // escalar y por lo tanto el radio
  m = esat::Mat3Multiply(esat::Mat3Scale(size, size), m);
  // rotar la figura por un valor velocidad
  m = esat::Mat3Multiply(esat::Mat3Rotate(0.0f), m);
  // translate es el punto de origen
  m = esat::Mat3Multiply(esat::Mat3Translate(pos.x, pos.y ), m);
  return m;
}

void DrawAsteroid(esat::Mat3 m, esat::Vec3 *points, int nPoint) {
  
//  esat::Vec2 tr_circle[kNPoints];
  esat::Vec2 *tr_circle = nullptr;
  tr_circle = (esat::Vec2*)malloc(nPoint * sizeof(esat::Vec2));

  for (int i = 0; i < nPoint; ++i) {
    esat::Vec3 tmp = esat::Mat3TransformVec3(m, points[i]);    
    tr_circle[i] = { tmp.x, tmp.y };
  }
  esat::DrawSetFillColor(0,0,0,0);
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawSolidPath(&tr_circle[0].x, nPoint);
}

// bool CrossColision(esat::Vec2 vec1, esat::Vec2 vec2){
//   float dotProduct = dotCalculator(vec1, vec2);


// }


int esat::main(int argc, char** argv) {
  srand(time(nullptr));
  double current_time = 0.0;
  double last_time = 0.0;
  double fps = 60.0;
  
  SpawnShip();
  aste.points = asteroidsShape();

  // no normalizo
  aste.size = 40.0f; // size also functions as lives
  aste.pos = {(float)(rand()%300), (float)(rand()%300)};   // random position 
  aste.nPoints = 10;
  
  esat::WindowInit(ScreenX, ScreenY);
  esat::WindowSetMouseVisibility(true);
  
  while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && esat::WindowIsOpened()){
    initShip();
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    esat::DrawSetStrokeColor(255,255,255);
    
    esat::Vec2 mousePosition;
    mousePosition.x = esat::MousePositionX();
    mousePosition.y = esat::MousePositionY();

    esat::DrawPath(ship.puntosNave, 4);

    Controls();
    Move();

    esat::Vec2 ShipPos = {ship.pos.x, ship.pos.y};

    if(ChechProximity(ship.pos, mousePosition, 15)){
      bool stillInside = true;
      float previusCross;
      printf("\nCLOSE -> ");
      int nPoints = 3, i = 0;
      while(stillInside && i < nPoints * 2){
        mm::Vec2 A = {ship.puntosNave[i], ship.puntosNave[i + 1]};     // A -> b -> C
        mm::Vec2 B = {ship.puntosNave[i + 2], ship.puntosNave[i + 3]}; // B -> C -> D(A)
        mm::Vec2 p = {mousePosition.x, mousePosition.y};               // p
        float newCross = PointInTriangle(p, A, B);
        if(i != 0){
          if((newCross < 0 && previusCross < 0) || (newCross > 0 && previusCross > 0)){
            stillInside = true;
          }else{
            stillInside = false;
          }
        }
        previusCross = newCross;
        i+=2;
      }

      if(stillInside){
        printf("COLISION PLAYER");
      }
    }

    esat::Mat3 m = MatAsteroid(aste.pos, aste.size);
    DrawAsteroid(m, aste.points, aste.nPoints);


    esat::DrawEnd();
    esat::WindowFrame();

  	do {
      current_time = esat::Time();
    } while((current_time - last_time) <= 1000.0 / fps);
  }
  esat::WindowDestroy();
  return 0;
}