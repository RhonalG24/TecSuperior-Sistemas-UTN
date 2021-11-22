/*
Ejercicio 2
Dado una estructura del tipo:
    Valor
    PosicionSiguiente

Siguiendo los mismos lineamientos de los vistos para listas, pero utilizando un vector de MAX_ELEMENTOS posiciones,
realice el diagrama e implemente las operaciones:

a. insertarOrdenado,
b. insertarAlFrente
c. borrarPrimero
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENTOS 20

typedef struct
{
    int valor;
    int posicionSig;
} PseudoLista;

int main()
{
    PseudoLista lista[MAX_ELEMENTOS];
    return 0;
}

void insertarAlFrente(PseudoLista *lista, int dato)
{
    for (int i = MAX_ELEMENTOS - 1; i > 0; i--)
    { //para desplazar todos los valores un espacio hacia adelante.
        lista[i + 1].valor = lista[i].valor;
        lista[i + 1].posicionSig = lista[i].posicionSig;
    }
    lista[0].valor = dato;
    lista[0].posicionSig = 1;
}

int borrarPrimero(PseudoLista *lista)
{
    int dato = lista[0].valor;

    for (int i = 0; i < MAX_ELEMENTOS - 1; i++)
    { //para desplazar todos los valores un espacio hacia atras.
        lista[i].valor = lista[i + 1].valor;
        lista[i].posicionSig = i + 1;
    }

    return dato;
}
void insertarOrdenado(PseudoLista *lista, int valor)
{
    PseudoLista *listaAux;
    int count = 0;
    while (count != MAX_ELEMENTOS - 1 && valor < lista[count].valor)
    {

        count++;
    }
}
