/*
20. Ingresar por plano, fila y columna todos los elementos de una matriz MATRIDIM de M planos,
filas y columnas. Desarrollar un programa que:
a) Imprima la matriz MATRIDIM por columnas, fila, plano.
b) Calcule e imprima el valor promedio de la matriz.
c) Determine e imprima el mayor valor y en que lugar del la matriz se encuentra.
d) Genere e imprima una matriz MATCSUMCOL donde cada elemento sea la suma de la columna
homóloga.
e) Genere e imprima una matriz MATMAXFIL donde cada elemento sea el valor máximo de cada
fila.
*/

#include <iostream>
using namespace std;
#define MAX_PLANOS 5
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

typedef struct
{
    int valor;
    int coordI;
    int coordJ;
    int coordK;
} Valor;

// ^
// |
// f p
//  c  -->
void cargarMatriz3Dim(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas, Valor &valorMayor);
void imprimirMatriz3DCFP(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas);
void leer(string mensaje, int &num);
float calculaValorPromedioMatriz(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas);

int main()
{
    int dimension;
    Valor valorMayor;
    leer("Indique la dimensión de la matriz 3D: ", dimension);

    int MATRIDIM[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS] = {0};

    cargarMatriz3Dim(MATRIDIM, dimension, dimension, dimension, valorMayor);

    //Parte a) Imprima la matriz MATRIDIM por columnas, fila, plano.
    imprimirMatriz3DCFP(MATRIDIM, dimension, dimension, dimension);

    // b) Calcule e imprima el valor promedio de la matriz.
    int promedio = calculaValorPromedioMatriz(MATRIDIM, dimension, dimension, dimension);
    cout << "Promedio: " << promedio << endl;

    // c) Determine e imprima el mayor valor y en que lugar del la matriz se encuentra.
    cout << "El valor mayor de la matriz es: " << valorMayor.valor
         << ". Se encontró en la posición (" << valorMayor.coordI << "," << valorMayor.coordJ << "," << valorMayor.coordK << ")"
         << endl;
    return 0;
}

void leer(string mensaje, int &num)
{
    cout << mensaje;
    cin >> num;
    cout << endl;
    return;
}

void cargarMatriz3Dim(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas, Valor &valorMayor)
{
    bool primerValor = true;

    for (int i = 0; i < planos; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            for (int k = 0; k < columnas; k++)
            {
                cout << "Ingrese un valor: ";
                cin >> matriz[i][j][k];
                cout << endl;
                if (primerValor == true || valorMayor.valor < matriz[i][j][k])
                {
                    primerValor = false;
                    valorMayor.valor = matriz[i][j][k];
                    valorMayor.coordI = i;
                    valorMayor.coordJ = j;
                    valorMayor.coordK = k;
                }
            }
        }
    }
    return;
}

//columnas, fila, plano.
/**
 * Imprime una matriz 3D por columna, fila y plano
 */
void imprimirMatriz3DCFP(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas)
{

    for (int k = 0; k < columnas; k++)
    {
        for (int j = 0; j < filas; j++)
        {
            for (int i = 0; i < planos; i++)
            {
                cout << matriz[i][j][k] << endl;
            }
        }
    }
    return;
}

//b)
float calculaValorPromedioMatriz(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas)
{
    float promedio = 0;
    int valores = 0;

    for (int i = 0; i < planos; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            for (int k = 0; k < columnas; k++)
            {
                promedio += matriz[i][j][k];
                valores++;
            }
        }
    }

    if (promedio != 0)
    {
        promedio /= valores;
    }

    return promedio;
}

//c) Determine e imprima el mayor valor y en que lugar del la matriz se encuentra.

// d) Genere e imprima una matriz MATCSUMCOL donde cada elemento sea la suma de la columna
// homóloga.
void generarMATCSUMCOL(int matriz[MAX_PLANOS][MAX_FILAS][MAX_COLUMNAS], int planos, int filas, int columnas, int matrizColumnas[MAX_COLUMNAS][MAX_FILAS])
{
    int suma;
    matrizColumnas = {0};
    for (int k = 0; k < columnas; k++)
    {
        for (int i = 0; i < planos; i++)
        {
            suma = 0;
            for (int j = 0; j < filas; j++)
            {
                suma += matriz[i][j][k];
            }
            matrizColumnas[i][k] = suma;
        }
    }
}

// e) Genere e imprima una matriz MATMAXFIL donde cada elemento sea el valor máximo de cada
// fila.