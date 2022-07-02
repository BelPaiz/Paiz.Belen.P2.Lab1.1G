#include "LinkedList.h"
#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[100];
    char genero[100];
    int duracion;
}eMovie;

#endif // MOVIE_H_INCLUDED

void Movie_mostrar(eMovie unMovie);
void Movie_mostrarDinamico(eMovie* pMovie);

//constructores

eMovie* Movie_new();
eMovie* Movie_new_Param(int idPeli, char* titulo, char* genero, int duracion);
eMovie* Movie_newStr(char* idPeli, char* titulo, char* genero, char* duracion);

//setters

int Movie_SetIdPeli(eMovie* emp, int idMovie);
int Movie_SetTitulo(eMovie* emp, char* titulo);
int Movie_SetGenero(eMovie* emp, char* genero);
int Movie_Setduracion(eMovie* emp, int duracion);

//getters

int Movie_GetIdPeli(eMovie* emp, int* idMovie);
int Movie_GetTitulo(eMovie* emp, char* titulo);
int Movie_GetGenero(eMovie* emp, char* genero);
int Movie_Getduracion(eMovie* emp, int* duracion);


//destructor

void Movie_Delete(eMovie* emp);

void* Movie_AsignarTiempos(void* pElement);
int Movie_menuGenero();
int Movie_ComparaGenero1(void* pElement);
int Movie_ComparaGenero2(void* pElement);
int Movie_ComparaGenero3(void* pElement);
int Movie_ComparaGenero4(void* pElement);
int Movie_ComparaGenero5(void* pElement);
int Movie_ComparaGenero6(void* pElement);
int Movie_ComparaGenero7(void* pElement);
int Movie_ComparaGenero8(void* pElement);
int Movie_ComparaGenero9(void* pElement);
int Movie_ComparaGenero10(void* pElement);
int Movie_ComparaGenerosEntreSi(void* pElement1, void* pElement2);
int Movie_CompareDuracion(void* pElement1, void* pElement2);

