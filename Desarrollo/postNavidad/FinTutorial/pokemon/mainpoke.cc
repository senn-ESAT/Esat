#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/sprite.h>

#include "player.cc"

struct Pokedex{
  int id, sprite; // el nombre se saca despues en base al id con un switch
};

const int ScreenX = 800, ScreenY = 600, fps = 30, nPokemons = 8; 
double current_time, last_time;

void initSprites(esat::SpriteHandle **backgroundS, esat::SpriteHandle **playerS, esat::SpriteHandle **pokemonS){
  esat::SpriteHandle playerSheet, pokeSheet;
  playerSheet = esat::SpriteFromFile("./img/red.png");
  pokeSheet = esat::SpriteFromFile("./img/pokemon.png");

  (*playerS) = (esat::SpriteHandle*)malloc(12*sizeof(esat::SpriteHandle));          // el player tiene 4 dire con 3 sprites de animacion
  (*pokemonS) = (esat::SpriteHandle*)malloc(nPokemons*sizeof(esat::SpriteHandle));  // 8 pokemons diferentes
  (*backgroundS) = (esat::SpriteHandle*)malloc(2*sizeof(esat::SpriteHandle));       // pasto, agua

  int i = 0;
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 4; y++){
      // player
      (*playerS)[i] = esat::SubSprite(playerSheet, y*28, x*28,  28, 31);
      i++;
    }
    
    // pokemon
    // if(i < 8){
    //   (*pokemonS)[i] = esat::SubSprite(pokeSheet, 121, 121, (i/3)*121, (i/3)*121);
    // }

  }
  (*backgroundS)[0] = esat::SpriteFromFile("./img/grass.png");
  (*backgroundS)[1] = esat::SpriteFromFile("./img/water.png");
  // posibles mas cargas para decoraciones
  esat::SpriteRelease(pokeSheet);
  esat::SpriteRelease(playerSheet);
}

void initPokedex(Pokedex **pedia){
  for(int i = 0; i < nPokemons; i++){
    (*pedia)->id = i;
    (*pedia)->sprite = i;
  }
}

void loadMaps(FILE **file){
  *file = fopen("map.dat", "rb");
}

void drawMap(FILE *map, esat::SpriteHandle *tiles){
  int value, row = 0, col = 0;
  while(fread(&value, sizeof(value), 1, map)){
    printf("it reads");
    if(col%28){
      row++;
      col = 0;
    }

    //esat::DrawSprite(tiles[value], 28*col, 28*row);
    col++;
  }
}

void freeSprties(){

}

void end(){
  esat::DrawEnd();  	
  esat::WindowFrame();
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
  FILE *map;

  initSprites(&backgroundS, &playerS, &pokemonS);printf("[SPRITES LOADED]");
  //initPokedex(&pokedex);
  initPlayer(&player);
  loadMaps(&map); printf("[MAP LOADED SUCCESSFULY]");
  //drawMap(map, backgroundS);printf("[DRAWMAP]");

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    esat::DrawSprite(backgroundS[0], 0,0);

    moverPlayer(&player);
    drawPlayer(player, playerS);

    playerFrame(&player);
    end();
  }
  esat::WindowDestroy();
  freeSprties();
  return 0;
}