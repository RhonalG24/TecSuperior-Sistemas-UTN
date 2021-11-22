/*
1. Ingresar un valor N (< 25). Generar un arreglo de N componentes en el cual las mismas
contengan los primeros números naturales pares e imprimirlo.

Strategy

pedir N
generarArreglo(N)
imprimir arreglo
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void generarArreglo(int cantComponentes, int vector[]);
void imprimirArreglo(int cantComponentes, int vector[]);

int main()
{
    int cantComponentes = pedirNumeros("Ingrese la cantidad de números pares que desea imprimir: ");
    while (cantComponentes > 24)
    {
        mostrarAlerta("El número debe ser menor a 25.");
        cantComponentes = pedirNumeros("Ingrese la cantidad de números pares que desea imprimir: ");
    }

    int vector[cantComponentes] = {0};

    generarArreglo(cantComponentes, vector);

    imprimirArreglo(cantComponentes, vector);

    return 0;
}

int pedirNumeros(string mensaje)
{
    int numero;
    cout << mensaje;
    cin >> numero;
    cout << endl;
    return numero;
}

void mostrarAlerta(string mensaje)
{
    cout << mensaje << endl;
}

void generarArreglo(int cantComponentes, int vector[])
{
    for (int i = 0; i < cantComponentes; i++)
    {
        vector[i] = 2 * (i + 1);
    }
    return;
}

void imprimirArreglo(int cantComponentes, int vector[])
{
    for (int i = 0; i < cantComponentes; i++)
    {
        cout << vector[i] << ", ";
    }
    cout << endl;
}