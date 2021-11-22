/*
Sumar dos vectores de dimensión n
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void pedirVector(int vector[], int dimension);
void mostrarVector(int vector[], int dimension);
void sumarVectores(int vector1[], int vector2[], int vectorSuma[], int dimension);

int main()
{

    int dimension = pedirNumeros("Ingrese el tamaño del vector:");
    int vector1[dimension] = {0};
    int vector2[dimension] = {0};
    int vectorSuma[dimension] = {0};
    //pedir datos

    pedirVector(vector1, dimension);
    pedirVector(vector2, dimension);

    //sumar vectores
    sumarVectores(vector1, vector2, vectorSuma, dimension);

    //mostrar Vector
    mostrarVector(vectorSuma, dimension);
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

void pedirVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << "Ingrese un número:" << endl;
        cin >> vector[i];
        cout << endl;
    }
    return;
}

void mostrarVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << "Posición: " << i << " , valor: " << vector[i] << endl;
    }
}

void sumarVectores(int vector1[], int vector2[], int vectorSuma[], int dimension)
{

    for (int i = 0; i < dimension; i++)
    {
        vectorSuma[i] = vector1[i] + vector2[i];
    }

    return;
}