/*
17. Ingresar dos valores, M (< 30) y N (< 25) y a continuación por filas todos los componentes de
una matriz matriza de M filas y N columnas. Desarrollar un programa que:
a) Imprima la matriz matriza por columnas.
b) Calcule e imprima el valor promedio de los componentes de la matriz.
c) Genere e imprima un vector vecSumCol donde cada componente sea la suma de la columna
homóloga.
d) Genere e imprima un vector VECMAXFIL donde cada componente sea el valor máximo de cada
fila.

ST
Ingresar M y n
crear matriz
llenar matriz
imprimir matriz
calcular valor promedio de los componentes de la matriz
general vector vecSumCol
imprimir vecSumCol
generar VECMAXFIL
imprimir VECMAXFIL

*/

#include <iostream>
using namespace std;

#define MAX_FILAS 29
#define MAX_COLUMNAS 24

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &dato, int condicion, string mensaje);

void pedirVector(float vector[], int dimension);
void imprimirVector(float vector[], int dimension);

/**
 * Carga la matriz por filas
 */
void pedirMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);
/**
 * Imprime la matriz por columnas
 */
void imprimirMatrizPorColumna(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);

float calcularPromedioMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);

void sumarColumnas(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, float vectorSuma[]);
void determinarValorMaximoPorFila(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, float vectorValoresMaximos[]);

int main()
{
    int filas = pedirNumeros("Ingrese la cantidad de filas de la matriz (< 30): ");
    verificarCondicion(filas, MAX_FILAS, "Ingrese la cantidad de filas de la matriz (< 30): ");
    int columnas = pedirNumeros("Ingrese la cantidad de columnas de la matriz (< 25): ");
    verificarCondicion(columnas, MAX_COLUMNAS, "Ingrese la cantidad de columnas de la matriz (< 25): ");

    int matriza[MAX_FILAS][MAX_COLUMNAS] = {0};
    pedirMatriz(matriza, filas, columnas);
    //Parte A
    imprimirMatrizPorColumna(matriza, filas, columnas);

    //Parte B
    float promedio = calcularPromedioMatriz(matriza, filas, columnas);
    cout << "El promedio de los valores ingresados es " << promedio << endl;

    //Parte C
    float vecSumCol[columnas] = {0};
    sumarColumnas(matriza, filas, columnas, vecSumCol);
    imprimirVector(vecSumCol, columnas);

    //Parte D
    float vecMaxFil[filas] = {0};
    determinarValorMaximoPorFila(matriza, filas, columnas, vecMaxFil);
    imprimirVector(vecMaxFil, filas);

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

void pedirMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingrese un valor:" << endl;
            cin >> matriz[i][j];
            cout << endl;
        }
    }
}

void imprimirMatrizPorColumna(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            cout << "[" << i << "]"
                 << "[" << j << "] = " << matriz[i][j] << endl;
        }
    }
}

float calcularPromedioMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    float suma = 0;
    float promedio = 0.0;
    int totalComponentes = filas * columnas;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma += matriz[i][j];
        }
    }
    if (totalComponentes != 0)
    {
        promedio = suma / totalComponentes;
    }
    return promedio;
}

void sumarColumnas(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, float vectorSuma[])
{
    int suma = 0;
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            suma += matriz[i][j];
        }
        vectorSuma[j] = suma;
        suma = 0;
    }
}

void determinarValorMaximoPorFila(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, float vectorValoresMaximos[])
{
    int valorMaximo;
    for (int i = 0; i < filas; i++)
    {
        valorMaximo = matriz[i][0];
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] > valorMaximo)
            {
                valorMaximo = matriz[i][j];
            }
            vectorValoresMaximos[i] = valorMaximo;
        }
    }
}