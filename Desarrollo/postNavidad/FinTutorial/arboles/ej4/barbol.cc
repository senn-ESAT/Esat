struct Tree{
  char *content, *question;
  Tree *si, *no;
};

void initTree(Tree **animales){
  (*animales) = nullptr;
  Tree *anim;
  anim = (Tree*)malloc(1*sizeof(Tree));
  anim->content = (Tree*)malloc();
  anim->content = "perro";
  anim->si = nullptr;
  anim->no = nullptr;
  anim->question = nullptr;
}

void Questions(Tree *tree, char answere){
  printf("Ese animal es un ");
}