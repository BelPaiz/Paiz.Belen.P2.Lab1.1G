#include "LinkedList.h"


#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
int controller_menuInico();
void controller_confirmarSalida(char* x);
int controller_loadFromTextMovies(char* path, LinkedList* pArrayListMovies, int*pFlag);
int controller_imprimirMovies(LinkedList* pArrayMovies, int flag);
LinkedList* controller_AsignarTiempor(LinkedList* pArrayMovies, int* pFlag);
LinkedList* controller_FiltrarGenero(LinkedList* pArrayMovies);
int controller_sort(LinkedList* pArrayMovies, int pFlag);
int controller_MovieSaveAsText(char* path, LinkedList* pArrayListMovie, int flag);
