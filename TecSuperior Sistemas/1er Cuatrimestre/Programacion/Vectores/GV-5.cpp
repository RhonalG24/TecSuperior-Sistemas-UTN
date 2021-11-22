/*
5. Ingresar un valor entero N (< 30). A continuación ingresar un conjunto UNO y luego otro
conjunto DOS, ambos de N componentes. Generar e imprimir otro conjunto TRES intercalando los
valores de posición impar de DOS y los valores de posición par de UNO.
*/

#include <iostream>
using namespace std;

#define MAX_DIMENSION 29

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &dato, int condicion, string mensaje);

void pedirVector(int vector[], int dimension);
void imprimirVector(int vector[], int dimension);

void imprimirDosVectoresIntercalados(int vector1[], int vector2[], int vector3[], int dimension);

int main()
{
    int dimension = pedirNumeros("Indique la cantidad de valores que  ingresará (< 30): ");
    verificarCondicion(dimension, MAX_DIMENSION, "Indique la cantidad de valores que  ingresará (< 30): ");

    int uno[dimension] = {0};
    int dos[dimension] = {0};
    int tres[dimension] = {0};
    pedirVector(uno, dimension);

    cout << "Ahora ingresará el segundo vector" << endl
         << endl;
    pedirVector(dos, dimension);

    imprimirDosVectoresIntercalados(uno, dos, tres, dimension);
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

void imprimirDosVectoresIntercalados(int vector1[], int vector2[], int vector3[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        if (i % 2 == 0)
        {
            vector3[i] = vector1[i];
        }
        else
        {
            vector3[i] = vector2[i];
        }
    }
    imprimirVector(vector3, dimension);
    return;
}