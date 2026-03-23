struct Tbarbol{
  int content;
  Tbarbol *Rchild, *Lchild;
};

void crear_barbol(Tbarbol **tbar){
  *tbar = nullptr;
}

Tbarbol* insertar_barbol(int num, Tbarbol *TL, Tbarbol *TR){
  Tbarbol *temp;
  temp = (Tbarbol*)malloc(1*sizeof(Tbarbol));
  temp->content = num; 
  temp->Lchild = TL;
  temp->Rchild = TR;
  return temp;
}

void MostrarArbol(Tbarbol *barbol, int offset){

  if(barbol->Rchild != nullptr){
    MostrarArbol(barbol->Rchild, offset+3);
  }

  for(int i = 0; i < offset; i++){
    printf(" ");
  }
  printf("%03d\n", barbol->content);
  
  if(barbol->Lchild != nullptr){
    MostrarArbol(barbol->Lchild, offset+3);
  }
}