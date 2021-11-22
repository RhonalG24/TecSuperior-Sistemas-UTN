/*
2) Implementar un sistema que solicite indefinidamente números por pantalla hasta que se
ingrese un valor de corte e...
a) Imprimir el número más alto.
b) Imprimir el número más bajo.
c) Imprimir el promedio.

Agregado: Que se permita continuar luego del corte. 
Agregado: Que al final de los resultados de TODO. 
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#include "pedirNumeros.h"
#define CANT_VUELTAS 10

int main()
{

    char opcion;
    int numero, vuelta = 0;
    int numeroAlto[CANT_VUELTAS] = {0}, numeroBajo[CANT_VUELTAS] = {0}, promedio[CANT_VUELTAS] = {0}, cantNumeros[CANT_VUELTAS] = {0};
    bool continuar = true;

    while (continuar)
    {
        pedirNumeros(numeroAlto[vuelta], numeroBajo[vuelta], promedio[vuelta], cantNumeros[vuelta]);

        printf("El numero más alto fue %d\n", numeroAlto[vuelta]);
        printf("El numero más bajo fue %d\n", numeroBajo[vuelta]);
        if (promedio[vuelta] != 0)
        {
            promedio[vuelta] /= cantNumeros[vuelta];
            printf("El promedio fue %d\n\n", promedio[vuelta]);
        }

        printf("Desea volver a ingresar números? 1 para sí, 0 para no: ");
        scanf("%d", &continuar);
        fflush(stdin);
        vuelta++;
    }

    for (int i = 0; i < vuelta; i++)
    {
        printf("Resultados de la vuelta %d:\n", &i);
        printf("Número más alto: %d\n", &numeroAlto[i]);
        printf("Número más bajo: %d\n", &numeroBajo[i]);
        printf("Promedio: %d\n\n", &promedio[i]);
    }

    return 0;
}