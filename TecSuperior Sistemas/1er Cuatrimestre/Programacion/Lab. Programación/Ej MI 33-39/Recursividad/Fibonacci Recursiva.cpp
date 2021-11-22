#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
int calcularFibonacci(int cantValores);

int main()
{
    int contador = 0;
    int cantNumeros = pedirNumero("Ingrese cual valor de la serie quiere ver:");
    int fibonacci = calcularFibonacci(cantNumeros);
    cout << "El valor numero " << cantNumeros << " de la serie es: " << fibonacci << endl;

    return 0;
}

int pedirNumero(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

int calcularFibonacci(int cantValores)
{
    if (cantValores < 3)
    {
        return 1;
    }
    else
    {
        int resultado = 1;

        resultado = calcularFibonacci(cantValores - 1) + calcularFibonacci(cantValores - 2);

        return resultado;
    }
}