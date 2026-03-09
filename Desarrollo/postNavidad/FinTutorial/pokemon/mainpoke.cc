#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include <esat/window.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/draw.h>
#include <esat/time.h>

#include "coliciones.cc"
#include "map.cc"
#include "player.cc"
#include "pokedex.cc"



const int ScreenX = 800, ScreenY = 600, fps = 30, nPokemons = 8;
double current_time, last_time;

void initSprites(esat::SpriteHandle **backgroundS, esat::SpriteHandle **playerS, esat::SpriteHandle **pokemonS){
  esat::SpriteHandle playerSheet, pokeSheet;
  playerSheet = esat::SpriteFromFile("./img/red.png");
  pokeSheet = esat::SpriteFromFile("./img/pokemon.png");

  (*playerS) = (esat::SpriteHandle*)malloc(12*sizeof(esat::SpriteHandle));          // el player tiene 4 dire con 3 sprites de animacion
  (*pokemonS) = (esat::SpriteHandle*)malloc(nPokemons*sizeof(esat::SpriteHandle));  // 8 pokemons diferentes
  (*backgroundS) = (esat::SpriteHandle*)malloc(3*sizeof(esat::SpriteHandle));       // pasto, agua, pasto alto

  int i = 0;
  for(int y = 0; y < 4; y++){
    for(int x = 0; x < 3; x++){
      // player
      (*playerS)[i] = esat::SubSprite(playerSheet, x*17, y*25,  17, 25);
      
      if((y*3)+x < nPokemons){
        (*pokemonS)[i] = esat::SubSprite(pokeSheet, x*122, y*122,  122, 122);
      }
      i++;
    }
  }
  (*backgroundS)[0] = esat::SpriteFromFile("./img/grass.png");
  (*backgroundS)[1] = esat::SpriteFromFile("./img/water.png");
  (*backgroundS)[2] = esat::SpriteFromFile("./img/tallGrass.png");
  (*backgroundS)[3] = esat::SpriteFromFile("./img/battle.jpg");


  // posibles mas cargas para decoraciones
  esat::SpriteRelease(pokeSheet);
  esat::SpriteRelease(playerSheet);
}

void saveFile(Player p1, Pokedex *pdx){
  FILE *f = fopen("save.dat", "wb");
  // en caso de que ya tenga limpiamos la lista
  while(p1.catched != NULL){
    Pokedex *found = BuscarEnLista(pdx, p1.catched->idCatched);
    fwrite(&found->id, sizeof(int), 1, f);
    p1.catched = p1.catched->prox;
  }
  
  fclose(f);
}

void readFile(Pokedex *pdex){
  FILE *f = fopen("save.dat", "rb");
  if(f != NULL){
    int i = 0, valor;
    while(!feof(f)){
      fread(&valor, sizeof(valor), 1, f);
      Pokedex *found = BuscarEnLista(pdex, valor);

      esat::DrawSetTextSize(10);
      esat::DrawSetFillColor(255,255,255);
      esat::DrawText(50 + (150*i), 400, found->name);
      i++;
    }
  }
}

void end(){
  esat::DrawEnd();  	
  esat::WindowFrame();
  do {
    current_time = esat::Time();
  } while((current_time - last_time) <= 1000.0 / fps);
}

//////////////////////////////////////////////////////|
// P = Pause                                          |
// R = reset pokemons capturados                      |
// I = caja de billi | D = proximo | S = anterior     |
// S = salvar                                         |
// L = ver pokemons salvados                          |
// WASD = movimiento                                  |
//////////////////////////////////////////////////////|

int esat::main(int argc, char **argv){
  esat::WindowInit(ScreenX, ScreenY);
  esat::DrawSetTextFont("./font/pokemon-generation-1-regular.ttf");
  WindowSetMouseVisibility(true);
  srand(time(NULL));

  esat::SpriteHandle *backgroundS = nullptr, *playerS = nullptr, *pokemonS = nullptr; 
  Player player;
  Pokedex *pokedex;
  Tile *tiles;

  pokedex = nullptr;

  initPlayer(&player);
  
  initSprites(&backgroundS, &playerS, &pokemonS);

  initPokedex(&pokedex, "Bulbasaur", 0);
  initPokedex(&pokedex, "Caterpie", 1);
  initPokedex(&pokedex, "Pidgey", 2);
  initPokedex(&pokedex, "Charmender", 3);
  initPokedex(&pokedex, "Geodude", 4);
  initPokedex(&pokedex, "Pikachu", 5);
  initPokedex(&pokedex, "Sqirtle", 6);
  initPokedex(&pokedex, "Weedle", 7);

  loadMaps(&tiles);
  
  int page = 0, randomPoke = 0;
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    switch(page){
      case 0:
        moverPlayer(&player, tiles);
    
        drawMap(tiles, backgroundS);
        drawPlayer(player, playerS);
    
        playerFrame(&player);
        if(esat::IsKeyDown('P') || esat::IsKeyDown('p')){
          page = 1;
        }
        if(esat::IsKeyDown('i') || esat::IsKeyDown('I')){
          page = 2;
        }
        isPlayerOnTallGrass(&player, tiles);
        if(player.onFightArea){
          if(rand()%100 == 0){
            player.onFightArea = false;
            page = 3;
            randomPoke = rand()%nPokemons;
          }
        }
      break;
      case 1:
        esat::DrawSetFillColor(255,0,255);
        esat::DrawSetTextSize(40);
        esat::DrawText((ScreenX/2)-90, 100, "PAUSE");

        esat::DrawSetTextSize(20);
        esat::DrawSetFillColor(255,255,255);
        esat::DrawText((ScreenX/2)-240, 200, "PRESS S TO SAVE POKEMON");
        esat::DrawText((ScreenX/2)-240, 250, "PRESS L TO READ SAVED POKEMONS");
                
        if(esat::IsKeyDown('s') || esat::IsKeyDown('S')){
          saveFile(player, pokedex);
        }        
        if(esat::IsKeyPressed('l') || esat::IsKeyPressed('L')){
          readFile(pokedex);
        }
        if(esat::IsKeyDown('P') || esat::IsKeyDown('p')){
          page = 0;
        }
      break;
      case 2:
        if((esat::IsKeyDown('d') || esat::IsKeyDown('D')) && player.catched->prox != nullptr){
          player.catched = player.catched->prox;
        }
        else if((esat::IsKeyDown('a') || esat::IsKeyDown('A')) && player.catched->prev != nullptr){
          player.catched = player.catched->prev;
        }

        //Pokedex *found = BuscarEnLista(pokedex, player.catched->idCatched);

        // esat::DrawSprite(pokemonS[found->id], 200, 100);
        // esat::DrawText(200, 250, found->name);
        if(esat::IsKeyDown('p') || esat::IsKeyDown('P')){
          page = 0;
        }
        //free(found);
      break;
      case 3:
        Pokedex *wild = BuscarEnLista(pokedex, randomPoke);
        esat::DrawSprite(backgroundS[3], 0, 0);
        esat::DrawSetFillColor(0,0,0);
        esat::DrawSprite(pokemonS[wild->id], 500, 130);

        esat::DrawText(80, 90, wild->name);
        esat::DrawText(480, 470, "PRESS X TO ESCAPE");
        esat::DrawText(480, 430, "PRESS Z TO CAPTURE");


        if(esat::IsKeyDown('z') || esat::IsKeyDown('Z')){
          // capturar pokemon
        }
        else if(esat::IsKeyDown('x') || esat::IsKeyDown('X')){
          page = 0;
        }
      break;

    }
    if(esat::IsKeyDown('r') || esat::IsKeyDown('R')){
      CatchedRefresh(&player.catched);
    }
    end();
  }
  esat::WindowDestroy();
  free(pokedex);
  free(tiles);
  free(backgroundS);
  free(playerS);
  free(pokemonS);
  return 0;
}