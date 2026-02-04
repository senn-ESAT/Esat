#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <esat/time.h>
#include <string.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/window.h>
#include <esat/input.h>

struct Balls{
  float x;
  float y;
  float speed;
  bool color;
  int dir; // 4 dirs --> UpR, UpL, DownL, DownR 
};

Balls *Block = nullptr;
esat::SpriteHandle green, blue, ball1, ball2;
int ScreenX, ScreenY, nBalls, fps = 24, halfsec = fps/2;
double current_time, last_time;

void loadSprites(){
  green = esat::SpriteFromFile("./img/verde.png");
  blue = esat::SpriteFromFile("./img/azul.png");
  ball1 = esat::SpriteFromFile("./img/bola1.png");
  ball2 = esat::SpriteFromFile("./img/bola2.png");
}

void ballsGeneration(){
  for(int i = 0; i < nBalls; i++){
    bool color = false;
    if(rand()%2 == 0){
      color = true;
    }
    Balls newBall = {
      (float)(rand()%ScreenX),
      (float)(rand()%ScreenY),
      2.0f+(float)(rand()%6),
      color,
      rand()%4,
    };
    
    Block = (Balls*)realloc(Block, (i+1)*sizeof(Balls));
    *(Block+i) = newBall;
  }
}

void freeSprites(){
  esat::SpriteRelease(blue);
  esat::SpriteRelease(green);
  esat::SpriteRelease(ball1);
  esat::SpriteRelease(ball2);
}

void drawBalls(int index, esat::SpriteHandle image){
  if((Block+index)->color){
    esat::DrawSprite(green, (Block+index)->x, (Block+index)->y);
  }
  else{
    esat::DrawSprite(blue, (Block+index)->x, (Block+index)->y);
  }
  esat::DrawSprite(image, (Block+index)->x, (Block+index)->y);
}

void moveBalls(int index){
  switch((Block+index)->dir){
    case 0: // UpR
      (Block+index)->x += (Block+index)->speed;
      (Block+index)->y -= (Block+index)->speed;

      // if colision right
      if((Block+index)->x+esat::SpriteWidth(ball1) > ScreenX){
        (Block+index)->dir = 1;
      }
      // if colision top
      else if((Block+index)->y < 0){
        (Block+index)->dir = 2;
      }
    break;
    case 1: // UpL
      (Block+index)->x -= (Block+index)->speed;
      (Block+index)->y -= (Block+index)->speed;

      // if colision left
      if((Block+index)->x < 0.0f){
        (Block+index)->dir = 0.0f;
      }
      // if colision top
      else if((Block+index)->y < 0.0f){
        (Block+index)->dir = 3;
      }
    break;    
    case 2: //DownR
      (Block+index)->x += (Block+index)->speed;
      (Block+index)->y += (Block+index)->speed;

      // if colision right
      if((Block+index)->x+esat::SpriteWidth(ball1) > ScreenX){  
        (Block+index)->dir = 3;
      }
      // if colision bottom
      else if((Block+index)->y+esat::SpriteHeight(ball1) > ScreenY){
        (Block+index)->dir = 0.0f;
      }
    break;    
    case 3: //DownL
      (Block+index)->x -= (Block+index)->speed;
      (Block+index)->y += (Block+index)->speed;

      // if colision left
      if((Block+index)->x < 0.0f){
        (Block+index)->dir = 2;
      }
      // if colision bottom
      else if((Block+index)->y+esat::SpriteHeight(ball1) > ScreenY){
        (Block+index)->dir = 1;
      }
    break;
  }
}

void fpsControl(){
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
  animation ++;
  if(animation%fps == 0){
    animation = 0;
  }
}

int esat::main(int argc, char **argv) {
  if(argc == 4){
    srand(time(NULL));

    //*argv+0 nombre del programa 
    //*argv+1 cadena ScreenX
    //*argv+2 cadena ScreenY
    //*argv+3 cadena nBalls

    ScreenX = atoi(*(argv+1)); 
    ScreenY = atoi(*(argv+2));
    nBalls = atoi(*(argv+3));

    esat::WindowInit(ScreenX, ScreenY);
    WindowSetMouseVisibility(true);
    
    loadSprites();
    ballsGeneration();
    int animation = 0;
    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
      last_time = esat::Time();
      esat::DrawBegin();
      esat::DrawClear(0,0,0);
      
      for(int i = 0; i < nBalls; i++){
        if(animation - halfsec < 0){
          drawBalls(i, ball1);
        }
        else{
          drawBalls(i, ball2);
        }
        moveBalls(i);
      }
      
      esat::DrawEnd();  	
      esat::WindowFrame();
      
      fpsControl();
    }
    esat::WindowDestroy();
    freeSprites();
    free(Block);
    Block = nullptr;
  }
  else{
    printf("ERROR: Faltan datos");  
  }
  return 0;
}