struct catched{
  int idCatched;
  catched *prox, *prev;
};

struct Player{
  int dir = 0, frame = 0;
  catched *catched = nullptr;
  Colision colision;
  bool isMoving = false, onFightArea = false;
  double lastFrame = 0.0f;
};

void CatchedRefresh(catched **lista){

  // en caso de que ya tenga limpiamos la lista
  catched *current = *lista;
  catched *next;

  while(current != nullptr){
    next = current->prox;
    free(current);
    current = next;
  }

  *lista = nullptr;

  for(int i = 0; i < 4; i++){
    catched *temp;
  
    temp = (catched*)malloc(1 * sizeof(catched));
  
    temp->idCatched = rand()%8;
    temp->prox = *lista;
    temp->prev = nullptr;
  
    // Si la lista no estaba vacía
    if(*lista != nullptr){
      (*lista)->prev = temp;
    }
    
    *lista = temp;
  }
  printf("Actualizados los pokemons");
}

void initPlayer(Player *player){
  player->dir = 1;
  player->colision.p1 = {400, 300};
  player->colision.p2 = {400+17, 300+25}; //sprites son 17, 25
  CatchedRefresh(&(*player).catched);
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

bool ColisionTile(Player *p1,Tile *tile, int type){
  Tile *loop = nullptr;
  loop = tile;
  for(int i = 0; i < (19*25); i++){
    if(CheckColision(p1->colision, loop[i].colision) && loop[i].type == type){
      return true;
    }
  }
  return false;
}

void moverPlayer(Player *p1, Tile *tiles){
  // RIGHT
  if(esat::IsKeyPressed('d') || esat::IsKeyPressed('D')){
    p1->colision.p2.x += 4.0f;
    if(ColisionTile(p1, tiles, 1)){
      p1->colision.p2.x -= 4.0f;
    }else{
      p1->colision.p1.x += 4.0f;
      p1->isMoving = true;
      p1->dir = 1;
    }
  // LEFT
  }else if(esat::IsKeyPressed('a') || esat::IsKeyPressed('A')){
    p1->colision.p1.x -= 4.0f; 
    if(ColisionTile(p1, tiles, 1)){
      p1->colision.p1.x += 4.0f; 
    }else{
      p1->colision.p2.x -= 4.0f; 
      p1->isMoving = true;
      p1->dir = 3;
    }
  // UP
  }else if(esat::IsKeyPressed('w') || esat::IsKeyPressed('W')){
    p1->colision.p1.y -= 4.0f; 
    if(ColisionTile(p1, tiles, 1)){
      p1->colision.p1.y += 4.0f;
    }else{
        p1->colision.p2.y -= 4.0f; 
        p1->isMoving = true;
        p1->dir = 0;
    }
  // DOWN
  }else if(esat::IsKeyPressed('s') || esat::IsKeyPressed('S')){
    p1->colision.p2.y += 4.0f; 
    if(ColisionTile(p1, tiles, 1)){
      p1->colision.p2.y -= 4.0f; 
    }else{
      p1->colision.p1.y += 4.0f; 
      p1->isMoving = true;
      p1->dir = 2;
    }
  }
  else{p1->isMoving = false;}
}

void isPlayerOnTallGrass(Player *p, Tile *tiles){
  if(ColisionTile(p, tiles, 2)){
    p->onFightArea = true;
  }
  else{
    p->onFightArea = false;
  }
  printf("%d\n", p->onFightArea);
}

void drawPlayer(Player p1, esat::SpriteHandle *playerIMG){
  int pose = (p1.dir*3) + p1.frame;
  esat::DrawSprite(playerIMG[pose], p1.colision.p1.x, p1.colision.p1.y);
  ShowColision(p1.colision);
}