#include <stdio.h>

FILE *f;
char cadena[255] = {"\0"};

int main(){
    printf("cadena?\n");
    fgets(cadena, 255, stdin);
    f = fopen("./a.txt", "a");
    fputs(cadena, f);
    fclose(f);

    return 0;
}