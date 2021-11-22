/*
Ejercicio 1
Desarrollar una aplicación que permita ingresar números enteros. Se deben procesar todos los números hasta que se ingrese
un 0.

Sólo contemplando aquellos números que no sean primos, informar si la secuencia de números está ordenada, y en tal caso,
informar si es ascendente o descendente.

Nota: Un número primo es aquel que sólo es divisible por 1 y por si mismo.

Punto mínimos que debe contener este ejercicio:
c. Desarrollar la función bool esNumeroPrimo(int) utilizando lenguaje C/C++
d. Desarrollar el diagrama de flujo del programa principal.
*/

#include <iostream>
using namespace std;

void leer(string mensaje, int &numero);

void leer(string mensaje, int &numero)
{
    cout << mensaje;
    cin >> numero;
    cout << endl;
    return;
}

bool esNumeroPrimo(int numero);

bool esNumeroPrimo(int numero)
{
    bool primo = true;

    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            primo = false;
            return primo;
        }
    }
    return primo;
}

void definirOrden(int numero, int numeroAnterior, string &orden)
{
    string ordenActual;
    if (orden != "desordenado")
    {

        if (numero >= numeroAnterior)
        {
            ordenActual = "ascendente";
        }
        if (numero < numeroAnterior)
        {
            ordenActual = "descendente";
        }
        if (orden == "sinOrden")
        {
            orden = ordenActual;
        }
        if (orden != ordenActual)
        {
            orden = "desordenado";
        }
    }
}

int main()
{
    int numero, numeroAnterior;
    bool primo = false, ordenado = false, primerNumeroNoPrimo = false;

    string orden = "sinOrden";

    leer("Ingrese un número entero (o 0 para salir):", numero);
    while (numero != 0)
    {

        while (primerNumeroNoPrimo == false && numero != 0)
        {
            primo = esNumeroPrimo(numero);
            if (!primo)
            {
                primerNumeroNoPrimo = true;
                numeroAnterior = numero;
            }
            leer("Ingrese un número entero (o 0 para salir):", numero);
        }

        if (primerNumeroNoPrimo == false)
        {
            cout << "Sólo se ingresaron número primos." << endl
                 << endl;
            return 0;
        }

        primo = esNumeroPrimo(numero);

        if (!primo)
        {
            definirOrden(numero, numeroAnterior, orden);
            numeroAnterior = numero;
        }

        leer("Ingrese un número entero (o 0 para salir):", numero);
    }

    if (orden == "desordenado")
    {
        cout << "La secuencia está desordenada." << endl
             << endl;
    }
    else
    {

        cout << "La secuencia está ordenada y el orden es " << orden << endl
             << endl;
    }

    return 0;
}
