/*
8. Ingresar un valor entero N (< 25). A continuación ingresar un conjunto GG de N elementos.
Imprimir el arreglo en orden inverso generando tres estrategias para imprimir los elementos a
razón
de: a) Uno por línea, b) Diez por línea, c) Cinco por línea con identificación

pedir N (< 25)
crear arr GG[N]
llenarArr()
imprimirArr() orden inverso
    -UNO por línea
    -DiezPorLinea
    -5PorLineaConID
*/

#include <iostream>
using namespace std;
#define MAX_DIMENSION 25

int pedirInt(string mensaje);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
void pedirVector(int vector[], int dimension);
// void imprimirInverso(int vector[], int dimension);
// void imprimirInverso1xLinea(int vector[], int dimension);
// void imprimirInverso10xLinea(int vector[], int dimension);
// void imprimirInverso5xLineaConID(int vector[], int dimension);

void imprimirInversoLimiteXLineaConID(int vector[], int dimension, int limiteXLinea);

int main()
{
    int N = pedirInt("Indique la cantidad de elementos que ingresará (<25): ");
    verificarCondicion(N, MAX_DIMENSION, "La cantidad de elementos a ingresar debe ser menor a 25", "Indique la cantidad de elementos que ingresará (<25): ");

    int GG[N] = {0};

    pedirVector(GG, N);

    cout << "Uno por linea: " << endl
         << endl;
    // imprimirInverso1xLinea(GG, N);
    imprimirInversoLimiteXLineaConID(GG, N, 1);

    cout << "10 por línea: " << endl
         << endl;
    // imprimirInverso10xLinea(GG, N);
    imprimirInversoLimiteXLineaConID(GG, N, 10);

    cout << "5 por linea con ID: " << endl;
    // imprimirInverso5xLineaConID(GG, N);
    imprimirInversoLimiteXLineaConID(GG, N, 5);

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

// void imprimirInverso(int vector[], int dimension)
// {
//     for (int i = dimension - 1; i >= 0; i--)
//     {
//         cout << i << ") " << vector[i] << endl;
//     }
//     cout << endl;
//     return;
// }

// void imprimirInverso1xLinea(int vector[], int dimension)
// {
//     for (int i = dimension - 1; i >= 0; i--)
//     {
//         cout << i << ") " << vector[i] << endl;
//     }
//     cout << endl;
//     return;
// }

// void imprimirInverso10xLinea(int vector[], int dimension)
// {
//     int lineas = dimension / 10;
//     for (int l = 0; l <= lineas; l++)
//     {
//         if (dimension < 10)
//         {
//             for (int i = dimension - 1; i >= 0; i--)
//             {
//                 cout << i << ") " << vector[i] << ", ";
//             }
//             cout << endl;
//         }
//         else
//         {
//             for (int i = dimension - 1; i >= dimension - 10; i--)
//             {
//                 cout << i << ") " << vector[i] << ", ";
//             }
//             cout << endl;
//         }
//         dimension -= 10;
//     }
//     cout << endl;
//     return;
// }

// void imprimirInverso5xLineaConID(int vector[], int dimension)
// {
//     int lineas = dimension / 5;
//     for (int l = 0; l <= lineas; l++)
//     {
//         if (dimension < 5)
//         {
//             for (int i = dimension - 1; i >= 0; i--)
//             {
//                 cout << i << ") " << vector[i] << ", ";
//             }
//             cout << endl;
//         }
//         else
//         {
//             for (int i = dimension - 1; i >= dimension - 5; i--)
//             {
//                 cout << i << ") " << vector[i] << ", ";
//             }
//             cout << endl;
//         }
//         dimension -= 5;
//     }
//     cout << endl;
//     return;
// }

void imprimirInversoLimiteXLineaConID(int vector[], int dimension, int limiteXLinea)
{
    int lineas = dimension / limiteXLinea;
    for (int l = 0; l <= lineas; l++)
    {
        if (dimension < limiteXLinea)
        {
            for (int i = dimension - 1; i >= 0; i--)
            {
                cout << "[" << i << "] = " << vector[i] << ", ";
            }
            cout << endl;
        }
        else
        {
            for (int i = dimension - 1; i >= dimension - limiteXLinea; i--)
            {
                cout << "[" << i << "] = " << vector[i] << ", ";
            }
            cout << endl;
        }
        dimension -= limiteXLinea;
    }
    cout << endl;
    return;
}