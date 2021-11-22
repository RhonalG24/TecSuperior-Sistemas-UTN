/* 1)
Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
NEUQUEN → verdadero
CHUBUT → falso
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int contarLetras(char palabra[]);
bool esPalindromo(char vector[]);

int main()
{
    // char *miCadena = (char *)malloc(sizeof(char) * 81);
    // miCadena = "NEUQUEN";
    // char cadena[81] = "NEUQUEN";
    char cadena[81] = "CHUBUT";

    if (esPalindromo(cadena))
    {
        printf("Es Palindromo.\n\n");
    }
    else
    {
        printf("No es palindromo.\n\n");
    }

    // free(miCadena);
    return 0;
}

int contarLetras(char palabra[])
{
    int cant = 0;

    while (palabra[cant] != '\0')
    {
        cant++;
    }

    return cant;
}

bool esPalindromo(char vector[])
{
    int longitud = contarLetras(vector);
    for (int i = 0; i < longitud / 2; i++)
    {
        if (*(vector + i) != *(vector + (longitud - (i + 1))))
        {
            return 0;
        }
    }
    return 1;
}