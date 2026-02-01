#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



COORD cxy;
//#define posicion(x,y) {(cxy.X)= (x); (cxy.Y)= (y); SetConsoleCursorPosition((GetStdHandle(STD_OUTPUT_HANDLE)), (cxy) );}


void posicion(int x,int y){
	cxy.X=x;
	cxy.Y=y;
	SetConsoleCursorPosition((GetStdHandle(STD_OUTPUT_HANDLE)), (cxy) );
}

int main()
{
	system("cls");
	posicion(40,10);printf("Texto a posicion 40,10");
	posicion(20,05);printf("Texto a posicion 20,05");
	posicion(50,15);printf("Texto a posicion 50,15");
 return 0;
}