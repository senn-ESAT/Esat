struct Position{
  float x, y;
};

struct Player{
  int dir = 0, frame = 0;
  int *idCatched;
  Position pos;
  bool isMoving;
  double lastFrame = 0.0f;
};

void initPlayer(Player *player){
  player->dir = 1;
  player->pos.x = 400;
  player->pos.y = 300;
  // no tiene pokemons en el momenot
}

void playerFrame(Player *p1){
  if(p1->lastFrame + 200.0f < esat::Time()){
    if(p1->isMoving){
      p1->frame++;
      if(p1->frame > 2){
        p1->frame = 0;
      }
    }
    p1->lastFrame = esat::Time();
  }
}

void moverPlayer(Player *p1){
  if(esat::IsKeyPressed('d') || esat::IsKeyPressed('D')){
    p1->pos.x += 4.0f; 
    p1->isMoving = true;
    p1->dir = 0;
  }else if(esat::IsKeyPressed('a') || esat::IsKeyPressed('A')){
    p1->pos.x -= 4.0f; 
    p1->isMoving = true;
    p1->dir = 1;
  }else if(esat::IsKeyPressed('w') || esat::IsKeyPressed('W')){
    p1->pos.y -= 4.0f; 
    p1->isMoving = true;
    p1->dir = 2;
  }else if(esat::IsKeyPressed('s') || esat::IsKeyPressed('S')){
    p1->pos.y += 4.0f; 
    p1->isMoving = true;
    p1->dir = 3;
  }
  else{p1->isMoving = false;}
}

void drawPlayer(Player p1, esat::SpriteHandle *playerIMG){
  int pose = (p1.dir*3) + p1.frame;
  esat::DrawSprite(playerIMG[pose], p1.pos.x, p1.pos.y);
}