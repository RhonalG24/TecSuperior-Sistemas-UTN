/*
23.Dado un arreglo de enteros (Max = 1000) y otro entero (DATO) se pide desarrollar:
a) Una rutina que indique si DATO es o no un elemento del arreglo.
b) Una rutina que indique si DATO es o no un elemento del arreglo y si lo es devuelva la posición
de la primera aparición del mismo (Búsqueda Secuencial).
c) Una rutina que devuelva todas las posiciones en las cuales aparece DATO en el arreglo.
d) Una rutina que devuelva la posición de la primera y de la última aparición de DATO en el
arreglo.

generarArr()
pedirInt()

dato en Arr

rand()%(HASTA-DESDE+1)+DESDE
*/

#include <iostream>
using namespace std;
#define MAX_DIMENSION 1000
// #define RAND_MAX 5
#include <ctime> //para generar números aleatorios

int pedirInt(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
// void pedirVector(int vector[], int dimension);

void generarVectorRandom(int vector[], int dimension, int valorMaximo);
void imprimirVector(int vector[], int dimension);
void determinarPertenencia(int vector[], int dimension, int valor);

void buscarEnVector(int vector[], int dimension, int valor, int &posicion);
void buscarPosicionesEnVector(int vector[], int dimension, int valor, int posiciones[], int &repeticiones);
void buscarPrimeraYUltimaPosicionEnVector(int vector[], int dimension, int valor, int posiciones[], int &repeticiones, int &primeraPos, int &ultimaPos);

int main()
{
    srand(time(NULL)); //para generar números aleatorios

    int dimension = pedirInt("Ingrese la cantidad de elementos que desea generar en el vector (max = 1000):");
    verificarCondicion(dimension, MAX_DIMENSION, "El valor maximo aceptado es 1000.", "Ingrese la cantidad de elementos que desea generar en el vector (max = 1000):");

    int vector[dimension] = {0};
    generarVectorRandom(vector, dimension, 5);

    imprimirVector(vector, dimension);

    int dato = pedirInt("Ingrese el dato que desea buscar en el vector: ");

    // a)
    determinarPertenencia(vector, dimension, dato);

    // b)
    int primeraPosicion;
    buscarEnVector(vector, dimension, dato, primeraPosicion);
    cout << "El dato se encontró por primera vez en la posicion " << primeraPosicion << " del vector." << endl
         << endl;

    // c)
    int posiciones[dimension] = {0};
    int cantPosiciones;
    buscarPosicionesEnVector(vector, dimension, dato, posiciones, cantPosiciones);
    cout << "Las posiciones fueron las siguientes: " << endl
         << endl;
    imprimirVector(posiciones, cantPosiciones);

    // d)
    int ultimaPosicion;
    buscarPrimeraYUltimaPosicionEnVector(vector, dimension, dato, posiciones, cantPosiciones, primeraPosicion, ultimaPosicion);
    cout << "Primera posicion = " << primeraPosicion << " y la última posicion = " << ultimaPosicion << endl
         << endl;
    return 0;
}

int pedirInt(string mensaje)
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

void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor)
{
    while (valor >= condicion)
    {
        mostrarAlerta(mensajeAlerta);
        valor = pedirInt(mensajeValor);
    }
    return;
}

void pedirVector(int vector[], int dimension)
{

    for (int i = 0; i < dimension; i++)
    {
        cout << i + 1 << ") ";
        vector[i] = pedirInt("Ingrese un valor: ");
    }
    return;
}

void generarVectorRandom(int vector[], int dimension, int valorMaximo)
{
    for (int i = 0; i < dimension; i++)
    {
        vector[i] = rand() % (valorMaximo - 0 + 1) + 0; //rand()%(HASTA-DESDE+1)+DESDE
    }
    return;
}

void imprimirVector(int vector[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        cout << "[" << i << "] = " << vector[i] << ", " << endl;
    }

    cout << endl;
    return;
}

void determinarPertenencia(int vector[], int dimension, int valor)
{

    for (int i = 0; i < dimension; i++)
    {
        if (valor == vector[i])
        {
            cout << "El valor está en el vector." << endl;
            return;
        }
    }
    cout << "El valor no se encuentra en el vector." << endl;
    return;
}

void buscarEnVector(int vector[], int dimension, int valor, int &posicion)
{
    posicion = -1;
    for (int i = 0; i < dimension; i++)
    {
        if (vector[i] == valor)
        {
            posicion = i;
            return;
        }
    }
    return;
}

void buscarPosicionesEnVector(int vector[], int dimension, int valor, int posiciones[], int &repeticiones)
{
    repeticiones = 0;
    for (int i = 0; i < dimension; i++)
    {
        if (vector[i] == valor)
        {
            posiciones[repeticiones] = i;
            repeticiones++;
        }
    }
    return;
}

void buscarPrimeraYUltimaPosicionEnVector(int vector[], int dimension, int valor, int posiciones[], int &repeticiones, int &primeraPos, int &ultimaPos)
{
    repeticiones = 0;
    for (int i = 0; i < dimension; i++)
    {
        if (vector[i] == valor)
        {
            posiciones[repeticiones] = i;
            repeticiones++;
        }
    }
    primeraPos = posiciones[0];
    ultimaPos = posiciones[repeticiones - 1];
    return;
}