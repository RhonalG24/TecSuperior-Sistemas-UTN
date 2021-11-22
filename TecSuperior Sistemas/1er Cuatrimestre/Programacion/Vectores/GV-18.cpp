/*
18. Ingresar un valor N (< 25) y luego por filas una matriz cuadrada CUADRADA de N filas y
columnas. Desarrollar un programa que determine e imprima:
a) Todos los elementos de la diagonal principal o secundaria según de cual resulte mayor la
sumatoria de elementos.
b) Los elementos del cuarto (N/2 filas y N/2 columnas) cuya sumatoria resulte mayor
(considerando que N fuera par).
c) Los elementos de la triangular superior o inferior dependiendo de cual tenga mayor sumatoria
de elementos.
*/

#include <iostream>
using namespace std;

#define MAX_DIMENSION 24

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &dato, int condicion, string mensaje);

void pedirVector(float vector[], int dimension);
void imprimirVector(float vector[], int dimension);

/**
 * Carga la matriz cuadrada por filas
 */
void pedirMatrizCuadrada(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

/**
 * Suma la diagonal principal de una matriz cuadrada
 */
int sumarDiagonalPrincipal(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

/**
 * Suma la diagonal secundaria de una matriz cuadrada
 */
int sumarDiagonalSecundaria(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

void imprimirDiagonalPrincipal(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);
void imprimirDiagonalSecundaria(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

int sumarCuadrante(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension, int cuadrante);
void imprimirCuadrante(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension, int cuadrante);

int sumaTriangularSuperior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);
int sumaTriangularInferior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

void imprimirTriangularSuperior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);
void imprimirTriangularInferior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension);

int main()
{
    int dimension = pedirNumeros("Ingrese la dimensión de la matriz (< 25): ");
    verificarCondicion(dimension, MAX_DIMENSION, "Ingrese la dimensión de la matriz (< 25): ");

    int cuadrada[dimension][dimension] = {0};
    pedirMatrizCuadrada(cuadrada, dimension);

    int sumaPrincipal = sumarDiagonalPrincipal(cuadrada, dimension);
    int sumaSecundaria = sumarDiagonalSecundaria(cuadrada, dimension);

    if (sumaPrincipal >= sumaSecundaria)
    {
        imprimirDiagonalPrincipal(cuadrada, dimension);
    }
    else
    {
        imprimirDiagonalSecundaria(cuadrada, dimension);
    }

    int cuadrante1 = sumarCuadrante(cuadrada, dimension, 1);
    int cuadrante2 = sumarCuadrante(cuadrada, dimension, 2);
    int cuadrante3 = sumarCuadrante(cuadrada, dimension, 3);
    int cuadrante4 = sumarCuadrante(cuadrada, dimension, 4);

    if (cuadrante1 > cuadrante2 && cuadrante1 > cuadrante3 && cuadrante1 > cuadrante4)
    {
        imprimirCuadrante(cuadrada, dimension, 1);
    }

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
    return;
}

void verificarCondicion(int &dato, int condicion, string mensaje)
{
    while (dato > condicion)
    {
        mostrarAlerta("El número no cumple con la condicion.");
        dato = pedirNumeros(mensaje);
    }
}

void pedirVector(float vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << i + 1 << ") Ingrese un número:" << endl;
        cin >> vector[i];
        cout << endl;
    }
    return;
}

void imprimirVector(float vector[], int dimension)
{

    for (int i = 0; i < dimension; i++)
    {
        cout << vector[i] << ", ";
    }
    cout << endl;

    return;
}

void pedirMatrizCuadrada(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cout << "Ingrese un valor:" << endl;
            cin >> matriz[i][j];
            cout << endl;
        }
    }
    return;
}

int sumarDiagonalPrincipal(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    int suma = 0;
    for (int i = 0; i < dimension; i++)
    {
        suma += matriz[i][i];
    }
    return suma;
}

int sumarDiagonalSecundaria(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    int suma = 0;
    for (int i = 0; i < dimension; i++)
    {
        suma += matriz[i][dimension - 1 - i];
    }
    return suma;
}

void imprimirDiagonalPrincipal(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << matriz[i][i] << ", ";
    }
    cout << endl;
    return;
}

void imprimirDiagonalSecundaria(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << matriz[i][dimension - 1 - i] << ", ";
    }
    cout << endl;
    return;
}

int sumarCuadrante(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension, int cuadrante)
{
    int suma = 0;
    switch (cuadrante)
    {
    case 1:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                suma = +matriz[i][j];
            }
        }
        break;

    case 2:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                suma = +matriz[i][(dimension / 2) + j];
            }
        }
        break;

    case 3:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                suma = +matriz[(dimension / 2) + i][j];
            }
        }
        break;

    case 4:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                suma = +matriz[(dimension / 2) + i][(dimension / 2) + j];
            }
        }
        break;
    }

    return suma;
}

void imprimirCuadrante(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension, int cuadrante)
{
    switch (cuadrante)
    {
    case 1:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                cout << matriz[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        break;

    case 2:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                cout << matriz[i][(dimension / 2) + j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        break;

    case 3:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                cout << matriz[(dimension / 2) + i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        break;

    case 4:
        for (int i = 0; i < dimension / 2; i++)
        {
            for (int j = 0; j < dimension / 2; j++)
            {
                cout << matriz[(dimension / 2) + i][(dimension / 2) + j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        break;
    }

    return;
}

int sumaTriangularSuperior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    int suma = 0;

    for (int i = 0; i < dimension - 1; i++)
    {
        for (int j = i + 1; j < dimension; j++)
        {
            suma += matriz[i][j];
        }
    }
}

int sumaTriangularInferior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    int suma = 0;

    for (int i = 1; i < dimension; i++)
    {
        for (int j = 0; j < i; j++)
        {
            suma += matriz[i][j];
        }
    }
}

void imprimirTriangularSuperior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{

    for (int i = 0; i < dimension - 1; i++)
    {
        for (int j = i + 1; j < dimension; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void imprimirTriangularInferior(int matriz[MAX_DIMENSION][MAX_DIMENSION], int dimension)
{
    for (int i = 1; i < dimension; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}