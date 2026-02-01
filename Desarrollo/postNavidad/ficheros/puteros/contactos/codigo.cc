#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

FILE *f;

struct Contacts{
  int id;
  char name[20] = {"\0"};
  char surName1[20] = {"\0"};
  char surName2[20] = {"\0"};
  char phone[11] = {"\0"};
  char mail[30] = {"\0"};
};

void delEnter(char *text, int size){
  for(int i = 0; i < size; i++){
    if(text[i] == '\n'){
      text[i] = '\0';
    }
  }
}

Contacts insertContact(){
  Contacts contactIns;

  printf("\nName: ");
  fgets(contactIns.name, sizeof(contactIns.name), stdin);
  printf("Surname1: ");
  fgets(contactIns.surName1, sizeof(contactIns.surName1), stdin);
  printf("Surname2: ");
  fgets(contactIns.surName2, sizeof(contactIns.surName2), stdin);
  printf("Phone: ");
  fgets(contactIns.phone, sizeof(contactIns.phone),stdin);
  printf("Mail: ");
  fgets(contactIns.mail, sizeof(contactIns.mail), stdin);

  delEnter(contactIns.name, strlen(contactIns.name));
  delEnter(contactIns.surName1, strlen(contactIns.surName1));
  delEnter(contactIns.surName2, strlen(contactIns.surName2));
  delEnter(contactIns.phone, strlen(contactIns.phone));
  delEnter(contactIns.mail, strlen(contactIns.mail));

  return contactIns;
}

int getID() {
  Contacts last;

  if (fseek(f, -sizeof(Contacts), SEEK_END) != 0){
    return 0;
  }

  fread(&last, sizeof(Contacts), 1, f);
  return last.id + 1;
}

void waiting(){
  printf(" Press any key to continue...");
  while(!getch()){}
}

void newContact(){
  Contacts contact; 
  
  f = fopen("contacts.dat", "ab+");
  contact = insertContact();
  contact.id = getID();

  fwrite(&contact, sizeof(contact), 1, f);

  fclose(f);
  
  printf("\nDone!");
  waiting();
}

void showList(){
  system("cls");
  
  f = fopen("contacts.dat", "rb+");
  
  if (f != NULL){
    Contacts list; 
    while(fread(&list, sizeof(list), 1, f)){
      printf("\n[ID]: %d", list.id); 
      printf("[NAME]: "); fputs(list.name, stdout);
      printf("[SURNAME1]: "); fputs(list.surName1, stdout);
      printf("[SURNAME2]: "); fputs(list.surName2, stdout);
      printf("[PHONE]: "); fputs(list.phone, stdout);
      printf("[MAIL]: "); fputs(list.mail, stdout);
    }
    fclose(f);
  }
  else{
    printf("404");
  }
}

void delContact(){
  system("cls");
  
  showList();
  f = fopen("contacts.dat", "rb+");
  
  if(f != NULL){
    FILE *temp;
    char delName[20] = {"\0"};
    
    printf("\n\nContact name to delete: ");
    fgets(delName, sizeof(delName), stdin);
    delEnter(delName, strlen(delName));
    
    temp = fopen("temp.dat", "ab+");
    
    bool found = false;
    Contacts search; 
    while(fread(&search, sizeof(search), 1, f)){
      
      if(strcmp(search.name, delName) == 0){
        found = true;
      }
      else{
        if(found){
          search.id--;
        }
        fwrite(&search, sizeof(search), 1, temp);
      }
        
    }
    fclose(f);
    fclose(temp);
    
    if(found){
      remove("contacts.dat");
      rename("temp.dat", "contacts.dat");
      printf("\nDone!");
    }
    else{
      printf("\nContact not found!");
    }
  printf(" %d ", found);
  }
  else{
    printf("\nNo contacts found!");
  }
  waiting();
}

void edit(){
  Contacts modified;
  system("cls");

  char modId[10] = {"\0"};
  bool valid = true;
  int ID;
  showList();

  f = fopen("contacts.dat", "rb+");
  if(f != NULL){
    printf("\n\nContact ID to modify: "); 
    
    fgets(modId, sizeof(modId), stdin);
    delEnter(modId, strlen(modId));

    for(int i = 0; i < strlen(modId); i++){
      if(modId[i] < 48 || modId[i] > 57){
        valid = false;
        printf("\nInput not valid.");
      }
    }
  
    if(valid){
      ID = atoi(modId);
      Contacts contGot; bool searchContinue = true;

      while(fread(&contGot, sizeof(contGot), 1, f) && searchContinue){

        if(contGot.id == ID){
          modified = insertContact();
          modified.id = ID;
          fseek(f, -1*sizeof(contGot), SEEK_CUR);
          fwrite(&modified, sizeof(modified), 1, f);
          fseek(f, -1*sizeof(contGot), SEEK_CUR);
          searchContinue = false;
        }
      }
    
      fclose(f);
    
      if(searchContinue){
        printf("\nContact not found.");
      }
      else{
        printf("\nDone!");
      }
    }
  }
  else{
    printf("\nNo contacts found!");
  }

  waiting();
}

int main(){
  system("CLS");
  int menu = 0;

  while(menu != 5){
    system("cls");

    printf("1 ... New contact\n2 ... Delete contact\n3 ... Modify contact\n4 ... Show list\n5 ... Quit\n");
    menu = getch()-48;

    switch(menu){
      case 1:
        newContact();
      break;
      case 2:
        delContact();
      break;
      case 3:
        edit();
      break;
      case 4:
        showList();
        waiting();
      break;
    }
  }

  return 0;
}