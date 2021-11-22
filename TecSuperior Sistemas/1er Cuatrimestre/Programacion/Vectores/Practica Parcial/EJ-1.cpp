/*
Ejercicio 1
Un programador se encuentra trabajando en un proyecto en el cuál le solicitan que desarrolle una
aplicación que permita realizar sumas, restas y producto escalar de vectores. El programador liberó el
código del programa que se adjunta en el archivo ejercicio1.cpp.
A partir del código dado, se pide:
1. Mejore el código aplicando modularización, nombre descriptivos, defines, etc. Debe encontrar como
mínimo 5 funciones/procedimientos.
2. Responda: ¿Por qué el vector "p" necesita ser inicializado y los vectores "s" y "d" no?
Porque en su for para calcular el vector p está haciendo p[h] = p[h] + (v1[h] * v2[h])
Lo cual está sumando a lo que tiene ya guardado en lugar de sobreescribirlo. Por ello hay que 
inicializarlo en 0 para que no tenga basura.
*/

#include <iostream>

using namespace std;

void leer(string mensaje, int &valor);
void llenarVector(int vector[], int dimension);
void mostrarVector(int vector[], int dimension);

void sumarVectores(int vector1[], int vector2[], int dimension, int vectorSuma[]);
void restarVectores(int vector1[], int vector2[], int dimension, int vectorResta[]);
void productoVectores(int vector1[], int vector2[], int dimension, int vectorProducto[]);

int main()
{
    int dimensionV1 = 0;
    int dimensionV2 = 0;

    //N es dimension de v1
    leer("Ingrese la dimension del vector 1: ", dimensionV1);
    int vector1[dimensionV1];

    //m es dimension de v2
    leer("Ingrese la dimension del vector 2: ", dimensionV2);
    int vector2[dimensionV2];

    if (dimensionV1 != dimensionV2)
    {
        // termina el programa
        return 1;
    }

    //llenar el vector1
    cout << "Llene el primer vector:" << endl
         << endl;
    llenarVector(vector1, dimensionV1);

    //llenar el vector2
    cout << "Llene el segundo vector:" << endl
         << endl;
    llenarVector(vector2, dimensionV1);

    int vectorSuma[dimensionV1];       //vector suma
    int vectorDiferencia[dimensionV1]; //vector diferencia

    sumarVectores(vector1, vector2, dimensionV2, vectorSuma);
    cout << "Resultado de la suma de los vectores: " << endl;
    mostrarVector(vectorSuma, dimensionV1);

    restarVectores(vector1, vector2, dimensionV2, vectorDiferencia);
    cout << "Resultado de la resta de los vectores: " << endl;
    mostrarVector(vectorDiferencia, dimensionV1);

    int vectorProducto[dimensionV1] = {0}; //vector producto

    productoVectores(vector1, vector2, dimensionV1, vectorProducto);
    cout << "Resultado del producto escalar: " << endl;
    mostrarVector(vectorProducto, dimensionV1);

    return 0;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
}

void llenarVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        leer("Ingrese un número: ", vector[i]);
    }
}

void sumarVectores(int vector1[], int vector2[], int dimension, int vectorSuma[])
{

    int i = 0;
    while (i < dimension)
    {
        vectorSuma[i] = vector1[i] + vector2[i];
        i++;
    }
    return;
}

void restarVectores(int vector1[], int vector2[], int dimension, int vectorResta[])
{
    int j = 0;
    while (j < dimension)
    {
        vectorResta[j] = vector1[j] - vector2[j];
        j++;
    }
    return;
}
void productoVectores(int vector1[], int vector2[], int dimension, int vectorProducto[])
{
    int h = 0;
    while (h < dimension)
    {
        vectorProducto[h] = vectorProducto[h] + (vector1[h] * vector2[h]);
    }
    return;
}

void mostrarVector(int vector[], int dimension)
{
    for (int h = 0; h < dimension; h++)
    {
        cout << vector[h] << endl;
    }
}