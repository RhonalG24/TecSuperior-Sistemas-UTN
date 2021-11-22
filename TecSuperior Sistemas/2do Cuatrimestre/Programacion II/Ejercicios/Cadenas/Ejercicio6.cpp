/*
6) Utilizando la función gets , leer de la entrada estándar una línea de longitud máxima 80
caracteres. Utilizando sólo sintaxis de punteros determinar:
a) ¿Cuántas palabras conforman la línea leída?
b) ¿Cuál es la palabra de longitud máxima y cuántos caracteres posee?
c) Repita el punto a) y b) utilizando la funciones strtok y strlen

USAR FGETS!!!
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

using namespace std;

int contarLetras(char palabra[]);
void mayorPalabra(char texto[]);

int main()
{
    char entrada[81];

    printf("Ingrese un texto de maximo 80 caracteres:\n\n");

    fgets(entrada, 81, stdin);
    // gets(entrada);

    printf("El texto tiene %d caracteres.\n\n", contarLetras(entrada));

    mayorPalabra(entrada);

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

void mayorPalabra(char texto[])
{
    char *token = strtok(texto, " ");

    int cantLetras = 0, mayorCantLetras = 0;
    char palabraMasLarga[81];
    if (token != NULL)
    {
        while (token != NULL)
        {
            cantLetras = contarLetras(token);
            if (cantLetras > mayorCantLetras)
            {
                mayorCantLetras = cantLetras;
                strcpy(palabraMasLarga, token);
            }

            token = strtok(NULL, " ");
        }
    }
    printf("La mayor palabra fue %s", palabraMasLarga);
    return;
}