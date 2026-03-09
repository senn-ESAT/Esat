struct Tile{
  int type = 0;       //mover tilesize adentro de tile, menos globales
  Colision colision;
};

const int tileSize = 32, mapRow = 19, mapCol = 25;

void loadMaps(Tile **tiles){
  FILE *file;
  file = fopen("./map.dat", "r");
  if(file == NULL){
    printf("error al cargar el mapa");
  }
  else{
    char value;
    int counter = 0, col = 0, row = 0;
    *tiles = (Tile*)malloc((mapCol*mapRow) * sizeof(Tile));
    while(counter < mapCol * mapRow && fread(&value, sizeof(char), 1, file)){
      if(value != '\n'){
        (*tiles)[counter].type = value - '0';
        (*tiles)[counter].colision.p1 = {(float)tileSize*col, (float)tileSize*row};
        (*tiles)[counter].colision.p2 = {(*tiles)[counter].colision.p1.x + tileSize, (*tiles)[counter].colision.p1.y + tileSize};
        counter++;
        col++;
      }
      else{
        row++;
        col=0;
      }
    }
  }
  fclose(file);
}

void drawMap(Tile *map, esat::SpriteHandle *tiles){
  int row = 0, col = 0;
  for(int i = 0; i < mapRow*mapCol; i++){
    esat::DrawSprite(tiles[map[i].type], map[i].colision.p1.x, map[i].colision.p1.y);
    ShowColision(map[i].colision);
  }
}