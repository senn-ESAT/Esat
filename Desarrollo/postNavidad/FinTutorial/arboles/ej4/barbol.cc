struct Tree{
  char *animal, *question;
  Tree *si, *no;
};

const int maxLetters = 20;

void initTree(Tree **animales){
  Tree *temp;
  temp = (Tree*)malloc(1 * sizeof(Tree));
  temp->animal = (char*)malloc(maxLetters * sizeof(char));
  temp->animal = "Pajaro\0";
  temp->si = nullptr;
  temp->no = nullptr;
  temp->question = nullptr;
  *animales = temp;
}

void delEnter(char **text){
  for(int i = 0; i < maxLetters; i++){
    if((*text)[i] == '\n'){
      (*text)[i] = '\0';
    }
  }
}

void addNewBranch(Tree **tree, char *newName, char *question, char sn){
  Tree *newRoot = nullptr, *secondBranch = nullptr, *temp;
  temp = *tree;
  newRoot = (Tree*)malloc(1 * sizeof(Tree));
  secondBranch = (Tree*)malloc(1 * sizeof(Tree));

  newRoot->question = question;
  newRoot->animal = nullptr;

  secondBranch->animal = newName;
  secondBranch->question = nullptr;
  secondBranch->si = nullptr;
  secondBranch->no = nullptr;

  if(sn == 'n' || sn == 'N'){
    newRoot->no = secondBranch;
    newRoot->si = temp;
  }else{
    newRoot->si = secondBranch;
    newRoot->no = temp;
  }
  *tree = newRoot;
}


char Question(Tree **tree){
  char c = 'n';
  if((*tree)->question != nullptr){
    printf("\n");
    fputs((*tree)->question, stdout);
    c = getch();
  }else{
    printf("\nEse animal es un ");
    fputs((*tree)->animal, stdout);
    c = getch();
  }
  return c;
}

void Answere(Tree **tree, char c){
  if(c == 'n' || c == 'N'){
    /*
    Lo siento he fallado, ayúdame a aprender ...
    Cómo se llama el animal que habías pensado? perro
    Qué pregunta distinguiría a un perro de un pájaro?
    Puede volar
    Si el animal fuera un perro, cuál sería la respuesta? n
    */
    if((*tree)->no != nullptr){
      char a = Question(&(*tree)->no);printf("\n");
      Answere(&(*tree)->no, a);
    }else{
      printf("\n--------------------------------\n");
      char *name = nullptr, *pregunta = nullptr, respuesta = NULL;
      name = (char*)malloc(maxLetters * sizeof(char));
      pregunta = (char*)malloc(maxLetters * sizeof(char));

      printf("Lo siento he fallado, ayudame a aprender ...\nComo se llama el animal que habias pensado? ");
      fgets(name, maxLetters, stdin);
      delEnter(&name);

      // sin esto se salta la proxima pregunta porque el enter de la pregunta pasada tambien entra en esta
      // while ((c = getchar()) != '\n' && c != EOF);

      printf("\nQue pregunta distinguiria a un "); fputs(name, stdout);
      printf(" de un "); fputs((*tree)->animal, stdout); printf(" ");
      fgets(pregunta, maxLetters, stdin);
      delEnter(&pregunta);
      
      printf("Si el animal fuera un "); fputs(name, stdout); printf(", cual seria la respuesta? ");

      do{
        respuesta = getch();
      }while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N');

      addNewBranch(&(*tree), name, pregunta, respuesta);
      
      printf("\n--------------------------------\n");
      printf("Gracias por facilitarme esta nueva información.");
    }
  }else{
    if((*tree)->si != nullptr){
      char a = Question(&(*tree)->si);
      Answere(&(*tree)->si, a);
    }
  }
}
