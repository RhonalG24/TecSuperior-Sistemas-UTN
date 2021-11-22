/*
3. Ingresar un valor entero N (< 20). A continuación ingresar un conjunto VEC de N componentes.
A partir de este conjunto generar otro FACT en el que cada elemento sea el factorial del elemento
homólogo de VEC. Finalmente imprimir ambos vectores a razón de un valor de cada uno por
renglón
*/

#include <iostream>
using namespace std;

#define MAX_DIMENSION 19

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &dato, int condicion, string mensaje);
int calcularFactorial(int num);

void pedirVector(int vector[], int dimension);
void imprimirVector(int vector[], int dimension);

void crearVectorFactorial(int vector[], int vectorFactorial[], int dimension);
void imprimirDosVectores(int vector[], int vector2[], int dimension, string mensajeEntreVectores);

int main()
{
    int dimension = pedirNumeros("Indique cuantos valores ingresará ( < 20): ");
    verificarCondicion(dimension, MAX_DIMENSION, "Indique cuantos valores ingresará ( < 20): ");

    int vec[dimension] = {0};
    pedirVector(vec, dimension);

    int fact[dimension] = {0};
    crearVectorFactorial(vec, fact, dimension);

    imprimirDosVectores(vec, fact, dimension, "! = ");

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

void crearVectorFactorial(int vector[], int vectorFactorial[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        vectorFactorial[i] = calcularFactorial(vector[i]);
    }
    return;
}

int calcularFactorial(int num)
{
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

void imprimirDosVectores(int vector[], int vector2[], int dimension, string mensajeEntreVectores)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << vector[i] << mensajeEntreVectores << vector2[i] << endl;
    }
    return;
}