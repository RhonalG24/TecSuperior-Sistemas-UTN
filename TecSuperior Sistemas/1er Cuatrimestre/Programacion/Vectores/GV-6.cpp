/*
6. Ingresar un valor entero N (< 40). A continuación ingresar un conjunto VALOR de N elementos.
Determinar e imprimir el valor máximo y la posición del mismo dentro del conjunto. Si el máximo
no es único, imprimir todas las posiciones en que se encuentra.

Estrategia
Ingresar N
cargar vector VALOR
Determinar valorMaximo y posición(es)

*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void pedirVector(float vector[], int dimension);
void determinarValorMaximo(float vector[], int dimension, float &valorMaximo, int posiciones[], int &cantValoresMaximos);
void imprimirVector(int vector[], int dimension);

int main()
{
    int dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    while (dimension > 39)
    {
        mostrarAlerta("El número debe ser menor a 40.");
        dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    }

    float valor[dimension] = {0};
    int posiciones[dimension] = {0};
    float valorMaximo;
    int cantValoresMaximos = 0;

    pedirVector(valor, dimension);
    determinarValorMaximo(valor, dimension, valorMaximo, posiciones, cantValoresMaximos);

    cout << "El valor máximo fue: " << valorMaximo << ". Apareció en las posiciones ";
    imprimirVector(posiciones, cantValoresMaximos);
    cout << endl;

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

void pedirVector(float vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << "Ingrese un número:" << endl;
        cin >> vector[i];
        cout << endl;
    }
    return;
}

void determinarValorMaximo(float vector[], int dimension, float &valorMaximo, int posiciones[], int &cantValoresMaximos)
{
    valorMaximo = vector[0];
    posiciones[0] = 1;

    for (int i = 1; i < dimension; i++)
    {
        if (vector[i] == valorMaximo)
        {
            cantValoresMaximos++;
            posiciones[cantValoresMaximos - 1] = i;
        }
        if (vector[i] > valorMaximo)
        {
            valorMaximo = vector[i];
            cantValoresMaximos = 1;
            posiciones[cantValoresMaximos - 1] = i;
        }
    }
    return;
}

void imprimirVector(int vector[], int dimension)
{

    for (int i = 0; i < dimension; i++)
    {
        cout << vector[i] << ", ";
    }
    cout << endl;

    return;
}