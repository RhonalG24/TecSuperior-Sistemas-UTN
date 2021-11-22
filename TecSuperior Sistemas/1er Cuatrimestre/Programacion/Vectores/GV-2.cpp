/*
2. Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. Si el último
elemento del conjunto tiene un valor menor que 10 imprimir los negativos y en caso contrario los
demás.

strategy
pedir N
mientras N > 29
    alerta
    pedir N
FinMientras

pedir valores del vector
si vector[N] < 10
    for(int i = 0; i < N; i++)
        si(vector[i] < 0)
            imprimir
        FinSi
SiNo
    for(int i = 0; i < N; i++)
        if(vector[i] > 0)
            imprimir
        FinSi
FinSi
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void pedirVector(float vector[], int dimension);
void imprimirVector(float vector[], int dimension);

int main()
{
    int dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    while (dimension > 29)
    {
        mostrarAlerta("El número debe ser menor a 30.");
        dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    }
    float vector[dimension] = {0};
    pedirVector(vector, dimension);
    imprimirVector(vector, dimension);
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
void imprimirVector(float vector[], int dimension)
{
    if (vector[dimension - 1] < 10)
    {
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i] < 0)
            {
                cout << vector[i] << ", ";
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i] > 0)
            {
                cout << vector[i] << ", ";
            }
        }
        cout << endl;
    }

    //     for (int i = 0; i < dimension; i++)
    //     {
    //         cout << vector[i] << ", ";
    //     }
    //     cout << endl;

    return;
}