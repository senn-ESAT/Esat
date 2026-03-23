struct tbbarbol{
  int content;
  tbbarbol *Rchild, *Lchild;
};

void crear_barbol(tbbarbol **init){
  *init = nullptr;
}

void insertar_barbol(tbbarbol **insert, int num){
  tbbarbol *temp;
  temp = (tbbarbol*) malloc(1*sizeof(tbbarbol));

  temp->content = num;
  temp->Lchild = nullptr;
  temp->Rchild = nullptr;

  if((*insert)->content > temp->content){
    if((*insert)->Lchild != nullptr){
      insertar_barbol(insertar_barbol((*)))
    }
  }
}