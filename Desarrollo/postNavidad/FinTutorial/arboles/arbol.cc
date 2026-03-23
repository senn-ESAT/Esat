#include <stdio.h>
#include <stdlib.h>
#include "barbol.cc"

Tbarbol *barbol1,*buscar;


int main(){

  printf("crear\n");
  crear_barbol(&barbol1);
  //Creación arbol binario.

  printf("insertar\n");
  barbol1=insertar_barbol(3,insertar_barbol(7,nullptr,nullptr),insertar_barbol(10,nullptr,nullptr));
  barbol1=insertar_barbol(15,barbol1,insertar_barbol(9,insertar_barbol(8,nullptr,nullptr),insertar_barbol(10,nullptr,nullptr)));
  //o bien
  //barbol2=insertar_barbol(20,insertar_barbol(12,nullptr,nullptr),insertar_barbol(13,nullptr,nullptr));
  //y luego barbol1=inserta_barbol(15,barbol1,barbol2);


  printf("\n------------ ARBOL GENERADO ----------------\n");
  MostrarArbol( barbol1, 0);
  printf("--------------------------------------------\n\n\n");

  return 0;
}