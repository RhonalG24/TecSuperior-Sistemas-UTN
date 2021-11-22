/*
pedir 10 numeros
ordenarlos
mostrar

consola
burbujeo
*/

#include <iostream>
using namespace std;

#include "consola.h"
#include "burbujeoMejorado.h"

#define CANT_NUMEROS 10

int main()
{
    int numeros[CANT_NUMEROS] = {0};
    pedirNumeros(numeros, CANT_NUMEROS);
    burbujeoMejor(numeros, CANT_NUMEROS);
    mostrarNumeros(numeros, CANT_NUMEROS);

    return 0;
}