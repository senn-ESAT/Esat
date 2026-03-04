#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/sprite.h>

struct Pokedex{
  int id, sprite; // el nombre se saca despues en base al id con un switch
};

struct Player{
  float x, y;
  int dir;
  int *catched;
};

const int ScreenX = 800, ScreenY = 600, fps = 30, nPokemons = 8; 
double current_time, last_time;

void initSprites(esat::SpriteHandle **backgroundS, esat::SpriteHandle **playerS, esat::SpriteHandle **pokemonS){
  esat::SpriteHandle playerSheet, bgSheet, pokeSheet;
  pokeSheet = esat::SpriteFromFile("./img/pokemon.png");
  playerSheet = esat::SpriteFromFile("./img/red.png");
  //bgSheet = esat::SpriteFromFile("./img/tiles.png"); // cambiars

  (*playerS) = (esat::SpriteHandle*)malloc(12*sizeof(esat::SpriteHandle));    // el player tiene 4 dire con 3 sprites de animacion
  //(*backgroundS) = (esat::SpriteHandle*)malloc(3*sizeof(esat::SpriteHandle)); // piso, pasto, agua
  (*pokemonS) = (esat::SpriteHandle*)malloc(nPokemons*sizeof(esat::SpriteHandle));   // 8 pokemons diferentes

  for(int i = 0; i < 12; i++){
    // player
    (*playerS)[i] = esat::SubSprite(playerSheet, 28, 31, 0, i*28);
    
    // pokemon
    if(i < 8){
      (*pokemonS)[i] = esat::SubSprite(pokeSheet, 121, 121, (i/3)*121, (i/3)*121);
    }

    // background
    // if(i < 3){
    //   (*pokemonS)[i] = esat::SubSprite(pokeSheet, 121, 121, (i/3)*121, (i/3)*121);
    // }
  }
  // posibles mas cargas para decoraciones
}

void initPokedex(Pokedex **pedia){
  for(int i = 0; i < nPokemons; i++){
    (*pedia)->id = i;
    (*pedia)->sprite = i;
  }
}

void initPlayer(Player *player){
  player->dir = 1;
  player->x = ScreenX/2;
  player->y = ScreenY/2;
}

void loadMaps(){

}

void freeSprties(){

}

void fpsControl(){
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
}

int esat::main(int argc, char **argv) {
  esat::WindowInit(ScreenX, ScreenY);
  WindowSetMouseVisibility(true);
  srand(time(NULL));
  esat::SpriteHandle *backgroundS = nullptr, *playerS = nullptr, *pokemonS = nullptr; 
  Player player;
  Pokedex *pokedex;

  initSprites(&backgroundS, &playerS, &pokemonS);
  initPokedex(&pokedex);
  initPlayer(&player);
  loadMaps();


  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);


    
    esat::DrawEnd();  	
  	esat::WindowFrame();

    fpsControl();
  }
  esat::WindowDestroy();
  freeSprties();
  return 0;
}