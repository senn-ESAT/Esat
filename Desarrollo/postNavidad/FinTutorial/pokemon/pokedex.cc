struct Pokedex{
  int id;
  char* name;
  Pokedex *pre, *prox;
};

void initPokedex(Pokedex **pedia, char* name, int id){
  Pokedex *temp;

  temp = (Pokedex*)malloc(1 * sizeof(Pokedex));

  temp->id = id;
  temp->name = name;
  temp->prox = *pedia;
  temp->pre = nullptr;

  // Si la lista no estaba vacía
  if(*pedia != nullptr){
    (*pedia)->pre = temp;
  }
  
  *pedia = temp;
}

Pokedex* BuscarEnLista(Pokedex *lista, int id){
  Pokedex *loop = nullptr;
  for(loop = lista; loop != nullptr; loop = loop->prox){
    if(loop->id == id){
      return loop;
    }
  }
  return nullptr;
}