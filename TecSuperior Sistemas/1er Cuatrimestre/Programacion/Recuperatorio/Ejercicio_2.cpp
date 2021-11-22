/*
Ejercicio 2
Se desea obtener una aplicación que permita convertir números binarios en un números decimales. Para ello la aplicación
deberá permitir el ingreso de números hasta que el usuario ingrese “FIN”. Para indicar el fin de un número binario se
ingresará el número -1.
Ejemplo, si el usuario ingresa: 1|0|0|0|1|-1 debe devolver 17 ya que:
1 x 2 0 + 0 x 2 1 + 0 x 2 2 + 0 x 2 3 + 1 x 2 4 = 1 + 0 + 0 + 0 + 16 = 17
Se pide:
a.
b.
Mostrar cada número decimal obtenido.
Mostrar la posición y el número decimal del menor número decimal obtenido.
*/

#include <iostream>
#include <math.h>
using namespace std;

void leerString(string mensaje, string &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void leerInt(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

int main()
{

    string opcion;
    int numero;
    double digitoDecimal;
    double numeroDecimal = 0;
    int cantNumeros = 0;
    int menorNumeroDecimal = 0;
    int posicion = 0, posicionMenor;

    leerString("Desea ingresar un número binario? ('S' para sí o 'FIN' para salir) ", opcion);

    while (opcion != "FIN")
    {
        posicion++;
        leerInt("Ingrese un numero entre 0 y 1 o -1 para salir", numero);
        while (numero >= 0)
        {

            digitoDecimal = numero * pow((double)2, (double)cantNumeros);
            numeroDecimal += digitoDecimal;
            cantNumeros++;
            leerInt("Ingrese un numero entre 0 y 1 o -1 para salir", numero);
        }
        cout << "El número es: " << numeroDecimal << endl;
        if (numeroDecimal < menorNumeroDecimal || menorNumeroDecimal == 0)
        {
            menorNumeroDecimal = numeroDecimal;
            posicionMenor = posicion;
        }
        numeroDecimal = 0;
        cantNumeros = 0;
        leerString("Desea ingresar un número binario? ('S' para sí o 'FIN' para salir) ", opcion);
    }

    cout << "El menor numero decimal fue " << menorNumeroDecimal << endl
         << "Fue ingresado en la posicion " << posicionMenor << endl
         << endl;

    return 0;
}
