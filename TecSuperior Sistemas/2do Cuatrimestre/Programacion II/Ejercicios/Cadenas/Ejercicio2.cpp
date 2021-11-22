/*
strtock para el 3 (como el split de JS).. investigar

hacer del 1 al 3 por lo menos

del punteros hacer hasta el 5 al menos con strcpy

2) Repita el ejercicio 1 utilizando funciones de la biblioteca <string.h>
    1)
    Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
    punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
    NEUQUEN → verdadero
    CHUBUT → falso
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool determinarPalindromo(char cadena[]);

int main()
{
    char cadena[81] = "NEUQUEN";
    // char cadena[81] = "CHUBUT";

    if (determinarPalindromo(cadena))
    {
        printf("Es palindromo.\n\n");
    }
    else
    {
        printf("No es palindromo.\n\n");
    };

    return 0;
}

bool determinarPalindromo(char cadena[])
{
    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i] != cadena[strlen(cadena) - (i + 1)])
        {
            return 0;
        }
    }
    return 1;
};