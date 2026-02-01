void delEnter(char *text){
  for(int i=0; i<255; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

int stringLength(char *text){
  int count = 0;
  bool end = true;
  while(end){
    if(text[count] != '\0'){
      count++;
    }
    else{
      end = false;
    }
  }
  return count;
}

//same lenth
bool strEqualStr(char *str1, char *str2){
  int l1 = stringLength(str1);
  int l2 = stringLength(str2);
  if(l1 != l2){
    return false;
  }

  for(int i = 0; i < l1; i++){
    if(str1[i] != str2[i]){
      return false;
    }
  }
  return true;
}

// to do string contain