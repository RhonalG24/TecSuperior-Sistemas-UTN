/*
4. Ingresar un valor entero N (< 25). A continuación ingresar un conjunto VEC de N componentes.
Si la suma de las componentes resulta mayor que cero imprimir las de índice impar, sino los otros
elementos.
*/

#include <iostream>
using namespace std;

#define MAX_DIMENSION 24

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &dato, int condicion, string mensaje);

void pedirVector(int vector[], int dimension);
void imprimirVector(int vector[], int dimension);

int sumarComponentesVector(int vector[], int dimension);

int main()
{
    int dimension = pedirNumeros("Indique la cantidad de valores que  ingresará (< 25): ");
    verificarCondicion(dimension, MAX_DIMENSION, "Indique la cantidad de valores que  ingresará (< 25): ");

    int vec[dimension] = {0};
    pedirVector(vec, dimension);

    int suma = sumarComponentesVector(vec, dimension);
    if (suma > 0)
    {
        for (int i = 0; i < dimension; i += 2)
        {
            cout << vec[i] << ", ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i < dimension; i += 2)
        {
            cout << vec[i] << ", ";
        }
        cout << endl;
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

void pedirVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << i + 1 << ") Ingrese un número:" << endl;
        cin >> vector[i];
        cout << endl;
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

int sumarComponentesVector(int vector[], int dimension)
{
    int suma = 0;
    for (int i = 0; i < dimension; i++)
    {
        suma += vector[i];
    }
    return suma;
}