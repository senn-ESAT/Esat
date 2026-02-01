#include <stdio.h>

FILE *f;

int main(){
    f=fopen("texto.txt", "w");
    fputs("dgjklgh uksgdfek kl<jsdhfuioe\n siudfytgre\nsdifuygasiefeiujygsfseuy", f);
    fclose(f);
}