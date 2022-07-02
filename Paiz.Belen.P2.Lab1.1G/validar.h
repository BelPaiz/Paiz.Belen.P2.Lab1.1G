#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED


//numeros enteros

int pidoValidoNumero(int* pNumero, char mensaje[]);
int validarNumero(char numero[]);
int convertirCharAInt(char num[], int* pnumero);
int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo);
int validaConvierteChar_Int(char num[], int* pNumero);

//Cadenas de letras

int validarLetras(char letras[]);
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);
