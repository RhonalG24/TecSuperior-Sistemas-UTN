/*
Ejercicio 1
Se conoce como cuadrado mágico en las matemáticas recreacionales a las matrices formadas por
números enteros positivos que cumplen con la particularidad que la sumatoria de cada fila, columna
y diagonales dan el mismo número.

4 9 2
3 5 7
8 1 6

Tendrá como “constante mágica” al número 15
Realizar un programa que permita al usuario realizar la carga por filas de la matriz de NxN deseada y
luego imprimirla por pantalla junto con su constante mágica, en caso que la matriz no forme un
cuadrado mágico imprimir “No es mágico”
*/

#include <iostream>
using namespace std;

#define MAX_FILAS 30
#define MAX_COLUMNAS 30

void leer(string mensaje, int &valor);
void cargarMatrizCuadrada(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension);
void imprimirMatrizCuadrada(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension);
void cuadradoMagico(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension);

int main()
{
    int dimension;
    leer("Ingrese un número para la dimension de la matriz: ", dimension);
    int matriz[MAX_FILAS][MAX_COLUMNAS] = {0};

    cargarMatrizCuadrada(matriz, dimension);
    imprimirMatrizCuadrada(matriz, dimension);
    cuadradoMagico(matriz, dimension);

    return 0;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void cargarMatrizCuadrada(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << "Fila " << i + 1 << ":" << endl;
        for (int j = 0; j < dimension; j++)
        {
            leer("Ingrese un número: ", matriz[i][j]);
        }
    }
    return;
}

void imprimirMatrizCuadrada(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    return;
}

void cuadradoMagico(int matriz[MAX_FILAS][MAX_COLUMNAS], int dimension)
{
    int sumatoria = 0;
    int numeroMagico;

    //recorre la diagonal principal
    for (int i = 0; i < dimension; i++)
    {

        sumatoria += matriz[i][i];
    }
    numeroMagico = sumatoria;
    sumatoria = 0;

    //recorre la diagonal secundaria
    for (int i = 0; i < dimension; i++)
    {
        sumatoria += matriz[i][dimension - i - 1];
    }
    if (sumatoria != numeroMagico)
    {
        cout << "No es mágico." << endl;
        return;
    }
    sumatoria = 0;

    //recorre por filas
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            sumatoria += matriz[i][j];
        }
        if (sumatoria != numeroMagico)
        {
            cout << "No es mágico." << endl;
            return;
        }
        sumatoria = 0;
    }

    //recorre por columnas
    for (int j = 0; j < dimension; j++)
    {
        for (int i = 0; i < dimension; i++)
        {
            sumatoria += matriz[i][j];
        }
        if (sumatoria != numeroMagico)
        {
            cout << "No es mágico." << endl;
            return;
        }
        sumatoria = 0;
    }

    cout << "Constante mágica: " << numeroMagico << endl;
    return;
}
