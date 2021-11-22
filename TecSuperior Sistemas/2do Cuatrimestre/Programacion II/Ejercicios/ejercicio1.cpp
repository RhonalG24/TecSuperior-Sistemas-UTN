/*
1) Desarrollar un algoritmo que defina un vector de 10 posiciones y...
a) Asigne a cada una de las posiciones el valor que resulta de: posición_actual x
posición_anterior.
b) Imprimir en pantalla la posición y su valor.
c) Invertir el orden del vector e imprimir por pantalla la posición y su valor.
*/

#include <iostream>
#include "stdio.h"
using namespace std;

void llenarVector(int vector[], int dimension)
{

    vector[0] = 0;
    for (int i = 1; i < dimension; i++)
    {
        vector[i] = i * (i - 1);
    }
    return;
};

void imprimirVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        printf("Posicion: %d Valor: %d \n", i, vector[i]);
    }
}

void invertirVector(int vector[], int dimension)
{
    int aux;
    for (int i = 0; i < dimension / 2; i++)
    {
        aux = vector[i];
        vector[i] = vector[dimension - i];
        vector[dimension - i] = aux;
    }
};

int main()
{
    // printf("HelloWorld\n");
    int dimension = 10;
    int vector[dimension] = {0};

    llenarVector(vector, dimension);

    printf("Vector ordenado:\n");
    imprimirVector(vector, dimension);
    printf("\n");

    invertirVector(vector, dimension);
    printf("Vector invertido:\n");
    imprimirVector(vector, dimension);
    printf("\n");

    return 0;
}
