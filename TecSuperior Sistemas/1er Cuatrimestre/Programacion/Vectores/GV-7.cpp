/*
7. Ingresar un valor entero N (< 15). A continuación ingresar un conjunto DATO de N elementos.
Generar otro conjunto de dos componentes MEJORDATO donde el primer elemento sea el mayor
valor de DATO y el segundo el siguiente mayor (puede ser el mismo si está repetido). Imprimir el
conjunto MEJORDATO con identificación.
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void mostrarAlerta(string mensaje);
void pedirVector(float vector[], int dimension);
void determinarDosMayores(float vector[], int dimension, int dosMayores[], int posiciones[]);
void imprimirVector(int vector[], int dimension);

int main()
{
    int dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    while (dimension > 14)
    {
        mostrarAlerta("El número debe ser menor a 15.");
        dimension = pedirNumeros("Ingrese la cantidad de números que desea ingresar: ");
    }

    float DATO[dimension] = {0};
    int MEJOR_DATO[2] = {0};
    int identificaciones[2] = {0};

    pedirVector(DATO, dimension);
    determinarDosMayores(DATO, dimension, MEJOR_DATO, identificaciones);

    cout << "El valor maximo fue " << MEJOR_DATO[0] << " y se ingresó en la posición " << identificaciones[0] + 1 << endl;
    cout << "El segundo valor maximo fue " << MEJOR_DATO[1] << " y se ingresó en la posición " << identificaciones[1] + 1 << endl;
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
        cout << i + 1 << ") Ingrese un número:" << endl;
        cin >> vector[i];
        cout << endl;
    }
    return;
}

void determinarDosMayores(float vector[], int dimension, int dosMayores[], int posiciones[])
{
    if (vector[0] > vector[1])
    {
        dosMayores[0] = vector[0];
        posiciones[0] = 0;
        dosMayores[1] = vector[1];
        posiciones[1] = 1;
    }
    else
    {
        dosMayores[0] = vector[1];
        posiciones[0] = 1;
        dosMayores[1] = vector[0];
        posiciones[1] = 0;
    }

    for (int i = 2; i < dimension; i++)
    {
        if (vector[i] > dosMayores[0])
        {
            dosMayores[1] = dosMayores[0];
            posiciones[1] = posiciones[0];
            dosMayores[0] = vector[i];
            posiciones[0] = i;
        }
        else
        {
            if (vector[i] > dosMayores[1])
            {
                dosMayores[1] = vector[i];
                posiciones[1] = i;
            }
        }
    }
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