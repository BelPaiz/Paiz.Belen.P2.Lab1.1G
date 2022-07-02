#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movie.h"
#include "validar.h"
#include <time.h>

void Movie_mostrar(eMovie unMovie)
{
    printf("%4d      %20s      %10s      %4d\n\n",
           unMovie.id_peli,
           unMovie.titulo,
           unMovie.genero,
           unMovie.duracion);
}
void Movie_mostrarDinamico(eMovie* pMovie)
{
    printf("%4d      %30s      %20s      %4d\n\n",
           pMovie->id_peli,
           pMovie->titulo,
           pMovie->genero,
           pMovie->duracion);
}

//constructores

eMovie* Movie_new()
{
    eMovie* nuevoMovie = (eMovie*) malloc(sizeof(eMovie));
    if(nuevoMovie != NULL)
    {
        nuevoMovie->id_peli = 0;
        strcpy(nuevoMovie->titulo, "");
        strcpy(nuevoMovie->genero, "");
        nuevoMovie->duracion = 0;
    }
    return nuevoMovie;
}
eMovie* Movie_new_Param(int idPeli, char* titulo, char* genero, int duracion)
{
    eMovie* nuevoMovie = Movie_new();

    if(!(Movie_SetIdPeli(nuevoMovie, idPeli) &&
            Movie_SetTitulo(nuevoMovie, titulo) &&
            Movie_SetGenero(nuevoMovie, genero) &&
            Movie_Setduracion(nuevoMovie, duracion)))
    {
        free(nuevoMovie);
        nuevoMovie = NULL;
    }
    return nuevoMovie;
}
eMovie* Movie_newStr(char* idPeli, char* titulo, char* genero, char* duracion)
{
    eMovie* nuevoMovie = Movie_new();
    int idPel;
    int durac;
    validaConvierteChar_Int(idPeli, &idPel);
    validaConvierteChar_Int(duracion, &durac);

    if(!(Movie_SetIdPeli(nuevoMovie, idPel) &&
            Movie_SetTitulo(nuevoMovie, titulo) &&
            Movie_SetGenero(nuevoMovie, genero) &&
            Movie_Setduracion(nuevoMovie, durac)))
    {
        free(nuevoMovie);
        nuevoMovie = NULL;
    }
    return nuevoMovie;
}


//setters

int Movie_SetIdPeli(eMovie* emp, int idMovie)
{
    int todoOk = 0;

    if(emp != NULL && idMovie > 0)
    {
        emp->id_peli = idMovie;
        todoOk = 1;
    }
    return todoOk;
}
int Movie_SetTitulo(eMovie* emp, char* titulo)
{
    int todoOk = 0;

    if(emp != NULL && titulo != NULL && strlen(titulo) < 100 && strlen(titulo) > 2)
    {
        strcpy(emp->titulo, titulo);
        strlwr(emp->titulo);
        emp->titulo[0] = toupper(emp->titulo[0]);
        todoOk = 1;
    }
    return todoOk;
}
int Movie_SetGenero(eMovie* emp, char* genero)
{
    int todoOk = 0;

    if(emp != NULL && genero != NULL && strlen(genero) < 100 && strlen(genero) > 2)
    {
        strcpy(emp->genero, genero);
        strlwr(emp->genero);
        emp->genero[0] = toupper(emp->genero[0]);
        todoOk = 1;
    }
    return todoOk;
}
int Movie_Setduracion(eMovie* emp, int duracion)
{
    int todoOk = 0;

    if(emp != NULL && duracion >= 0)
    {
        emp->duracion = duracion;
        todoOk = 1;
    }
    return todoOk;
}

//getters

int Movie_GetIdPeli(eMovie* emp, int* idMovie)
{
    int todoOk = 0;

    if(emp != NULL && idMovie != NULL)
    {
        *idMovie = emp->id_peli;
        todoOk = 1;
    }
    return todoOk;
}
int Movie_GetTitulo(eMovie* emp, char* titulo)
{
    int todoOk = 0;

    if(emp != NULL && titulo != NULL)
    {
        strcpy(titulo, emp->titulo);
        todoOk = 1;
    }
    return todoOk;
}
int Movie_GetGenero(eMovie* emp, char* genero)
{
    int todoOk = 0;

    if(emp != NULL && genero != NULL)
    {
        strcpy(genero, emp->genero);
        todoOk = 1;
    }
    return todoOk;
}
int Movie_Getduracion(eMovie* emp, int* duracion)
{
    int todoOk = 0;

    if(emp != NULL && duracion > 0)
    {
        *duracion = emp->duracion;
        todoOk = 1;
    }
    return todoOk;
}



//destructor

void Movie_Delete(eMovie* emp)
{
    free(emp);
}

void* Movie_AsignarTiempos(void* pElement)
{
    srand(time(NULL));
    int durac;
    int min = 100;
    int max = 240;
    int idP;
    if(pElement != NULL)
    {
        Movie_GetIdPeli(pElement, &idP);
        for(int i=0; i<=idP;i++)
        {
            srand(rand());
            durac = (rand() % (max - min +1) + min);
        }
        Movie_Setduracion(pElement, durac);
    }
    return pElement;
}

int Movie_ComparaGenero1(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Adventure") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero2(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Drama") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero3(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Comedy") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero4(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Romance") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero5(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Documentary") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero6(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Horror") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero7(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Musical") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero8(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Animation") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero9(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Action") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int Movie_ComparaGenero10(void* pElement)
{
    int todoOk = 0;
    char genero[50];

    if(pElement != NULL)
    {
        Movie_GetGenero(pElement, genero);

        if(stricmp(genero,"Western") == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int Movie_ComparaGenerosEntreSi(void* pElement1, void* pElement2)
{
    int todoOk = 0;

    char genero1[50];
    char genero2[50];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        Movie_GetGenero(pElement1, genero1);
        Movie_GetGenero(pElement2, genero2);
        if(stricmp(genero1, genero2) > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(stricmp(genero1, genero2) < 0)
            {
                todoOk = -1;
            }
        }
    }
    return todoOk;
}

int Movie_CompareDuracion(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    int duracion1;
    int duracion2;
    if(pElement1 != NULL && pElement2 != NULL)
    {
        Movie_Getduracion(pElement1, duracion1);
        Movie_Getduracion(pElement2, duracion2);
        if(duracion1 < duracion2)
        {
            todoOk = 1;
        }
        else
        {
            if(duracion1 > duracion2)
            {
                todoOk = -1;
            }
        }
    }
    return todoOk;
}


