#include <stdio.h>
#include <conio.h> 
#include<windows.h>

//función getch() devuelve la tecla pulsada sin ECO en pantalla.
//función getche() devuelve la tecla pulsada con ECO en pantalla.


char tecla_pulsada;


int main(){

	tecla_pulsada=getch(); //Con la pulsación no se produce ECO en pantalla y no se muestra el carácter
	printf("Ha pulado el caracter: %d",tecla_pulsada);

    
	return 0;
}