struct tbbarbol{
  int info, repetition = 0;
  tbbarbol *Rchild, *Lchild;
};

tbbarbol* crear_barbol(){
  return nullptr;
}

tbbarbol* buscar_barbol(tbbarbol *barbol, int num){
  tbbarbol *temp = nullptr;
  if(barbol->Rchild != nullptr && temp == nullptr){
    temp = buscar_barbol(barbol->Rchild, num);
  }
  
  if(barbol->Lchild != nullptr && temp == nullptr){
    temp = buscar_barbol(barbol->Lchild, num);
  }

  if(barbol->info == num && temp == nullptr){
    temp = barbol;
  }
  return temp;
}

void insertar_barbol(tbbarbol **insert, int num){
  tbbarbol *temp;
  temp = (tbbarbol*) malloc(1*sizeof(tbbarbol));

  temp->info = num;
  temp->Lchild = nullptr;
  temp->Rchild = nullptr;
  temp->repetition = 1;

  
  // si primera
  if(*insert == nullptr){
    *insert = temp;
  }else{

    //check repetitions
    if((*insert)->info == temp->info){
      (*insert)->repetition++;
    }
    
    if((*insert)->info > temp->info){
      if((*insert)->Lchild == nullptr){ // si vacio entonces salvar
        (*insert)->Lchild = temp;
      }
      else{
        insertar_barbol(&(*insert)->Lchild, num);
      }
    }else if((*insert)->info < temp->info){  // si menor
      if((*insert)->Rchild == nullptr){
        (*insert)->Rchild = temp;
      }
      else{
        insertar_barbol(&(*insert)->Rchild, num);
      }
    }
  }
}

void MostrarArbol(tbbarbol *barbol, int offset){

  if(barbol->Rchild != nullptr){
    MostrarArbol(barbol->Rchild, offset+3);
  }

  for(int i = 0; i < offset; i++){
    printf(" ");
  }
  printf("%03d (%02d)\n", barbol->info, barbol->repetition);
  
  if(barbol->Lchild != nullptr){
    MostrarArbol(barbol->Lchild, offset+3);
  }
}

void inorden(tbbarbol *barbol){

  if(barbol->Lchild != nullptr){
    inorden(barbol->Lchild);
  }
  
  printf("%d ", barbol->info);
  if(barbol->Rchild != nullptr){
    inorden(barbol->Rchild);
  }
  
}

void preorden(tbbarbol *barbol){
  printf("%d ", barbol->info);

  if(barbol->Lchild != nullptr){
    preorden(barbol->Lchild);
  }

  if(barbol->Rchild != nullptr){
    preorden(barbol->Rchild);
  }
}

void postorden(tbbarbol *barbol){
  if(barbol->Lchild != nullptr){
    postorden(barbol->Lchild);
  }

  if(barbol->Rchild != nullptr){
    postorden(barbol->Rchild);
  }

  printf("%d ", barbol->info);
}

