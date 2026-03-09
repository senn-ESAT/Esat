struct Coords{
  float x, y;
};

struct Colision{
  Coords p1, p2;
};
  
bool CheckColision(Colision colision1, Colision colision2){
  if (colision1.p2.x > colision2.p1.x && colision1.p1.x < colision2.p2.x && colision1.p2.y > colision2.p1.y && colision1.p1.y < colision2.p2.y){
    return true;
  }
  else{
    return false;
  }
}

void ShowColision(Colision colision){
  esat::DrawSetStrokeColor(255, 255, 255, 255);
  esat::DrawLine(colision.p1.x, colision.p1.y, colision.p2.x, colision.p1.y);
  esat::DrawLine(colision.p2.x, colision.p1.y, colision.p2.x, colision.p2.y);
  esat::DrawLine(colision.p2.x, colision.p2.y, colision.p1.x, colision.p2.y);
  esat::DrawLine(colision.p1.x, colision.p2.y, colision.p1.x, colision.p1.y);
}