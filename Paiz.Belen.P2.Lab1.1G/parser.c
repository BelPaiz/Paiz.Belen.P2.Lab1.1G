#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "movie.h"


int parser_MoviesFromText(FILE* pFile, LinkedList* pArrayListMovies)
{
    int todoOk = 0;
    char buffer[3][50];
    char falsa[3][50];
    eMovie* unMovie = NULL;

    if(pFile != NULL && pArrayListMovies != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", falsa[0], falsa[1], falsa[2], falsa[3]);
        while(!feof(pFile))
        {
            todoOk = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(todoOk!=4)
            {
                printf("Hubo un problema para leer el pasajero\n");
                exit(1);
            }
            else
            {
                unMovie = Movie_newStr(buffer[0], buffer[1], buffer[2], buffer[3]);
               // Movie_mostrarDinamico(unMovie);

                if( unMovie != NULL)
                {
                    todoOk = ll_add(pArrayListMovies, unMovie);
                }
            }
        }
    }
    return todoOk;
}
