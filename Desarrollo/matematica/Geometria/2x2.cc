#include <stdio.h>
#include <stdlib.h>

struct Equacion{
    float x, y, igual;
};

struct Solucion{
    float x,y;
};

Equacion A, B;
Solucion S;

void Imput(Equacion &e){
    printf("\n\nEquacion: \n[x]: ");
    scanf("%f", &e.x);
    printf("[y]: ");
    scanf("%f", &e.y);
    printf("[Equal]: ");
    scanf("%f", &e.igual);
}

void MCM(){
    float x1 = A.x, x2 = B.x;
    //linea arriva multiplicado por valor de x
    A.x*=x2;
    A.y*=x2;
    A.igual*=x2;
    // lo mismo pero no lo mismo porque la revez
    B.x *= x1;
    B.y *= x1;
    B.igual *= x1;
}

void calY(){
    if(B.y == 0){
        printf("No divide por 0");
    }
    else{
        S.y = A.igual/A.y;
    }
}

void Resta(){
    A.x-=B.x;
    A.y-=B.y;
    A.igual-=B.igual;

    printf("Resto %f - %f - %f - %f - %f - %f\n", A.x, A.y, A.igual, B.x, B.y, B.igual);

    calY();
}

void VerificarSigno(){
    if(A.x < 0 && B.x > 0){
        B.x*= (-1);
        B.y*= (-1);
        B.igual*= (-1);
        printf("verificar signo %f - %f - %f - %f - %f - %f\n", A.x, A.y, A.igual, B.x, B.y, B.igual);

        VerificarSigno();
    }
    else{
        Resta();
    }
}


void CalcX(Equacion a2){
    A.x = a2.x;
    A.y = S.y;
    A.igual = a2.igual;

    if(A.x == 0){
        printf("No divide por 0");

    }
    else{
        S.x = A.igual/=A.x;
    }    
}

void Dysplay(){
    printf("Solution: [X]: %.0f  [Y]:%.0f", S.x, S.y);
}

int main(){
    Equacion memA;
    Imput(A);
    memA = A;
    Imput(B);

    MCM();

    VerificarSigno();

    CalcX(memA);
    Dysplay();

    return 0;
}