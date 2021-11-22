/*
9. Ingresar un valor entero N (< 40). A continuación ingresar un conjunto A y luego otro conjunto B
ambos de N elementos. Generar un arreglo C donde cada elemento se forme de la siguiente
forma: C[1] = A[1]+B[N] C[2] = A[2]+B[N-1]
*/

#include <iostream>
using namespace std;
#define MAX_DIMENSION 40

int pedirInt(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
void pedirVector(int vector[], int dimension);
void generarVectorC(int vector[], int dimension, int vectorA[], int vectorB[]);
void imprimirVector(int vector[], int dimension);

int main()
{
    int N = pedirInt("Indique la cantidad de elementos que ingresará (<40): ");
    verificarCondicion(N, MAX_DIMENSION, "La cantidad de elementos a ingresar debe ser menor a 25", "Indique la cantidad de elementos que ingresará (<40): ");

    int A[N] = {0};
    int B[N] = {0};

    cout << "Vector A: " << endl
         << endl;
    pedirVector(A, N);

    cout << "Vector B: " << endl
         << endl;
    pedirVector(B, N);

    int C[N] = {0};
    generarVectorC(C, N, A, B);

    cout << "Vector C: " << endl
         << endl;
    imprimirVector(C, N);

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

void generarVectorC(int vector[], int dimension, int vectorA[], int vectorB[])
{
    for (int i = 0; i < dimension; i++)
    {
        vector[i] = vectorA[i] + vectorB[dimension - i - 1];
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