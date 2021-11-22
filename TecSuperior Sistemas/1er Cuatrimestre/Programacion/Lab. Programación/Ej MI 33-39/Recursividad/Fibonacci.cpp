#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
int calcularFibonacci(int cantValores);

int main()
{
    int cantNumeros = pedirNumero("Ingrese cual valor de la serie quiere ver:");

    //calcularFibonacci
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
    int resultado = 1;
    int aux = 0;
    int resultadoAnterior = 1;

    for (int i = 1; i < cantValores; i++)
    {
        resultado = resultadoAnterior + aux;
        aux = resultadoAnterior;
        resultadoAnterior = resultado;
    }

    return resultado;
}