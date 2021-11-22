#include <iostream>
using namespace std;

int pedirNumero(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

int calcularMCD(int valorA, int valorB)
{
    int resto = valorA % valorB;

    while (resto > 0)
    {
        valorA = valorB;
        valorB = resto;
        resto = valorA % valorB;
    }

    return valorB;
}

int main()
{
    int num1, num2, mcd;

    num1 = pedirNumero("Ingrese el primer numero: ");
    num2 = pedirNumero("Ingrese el segundo numero: ");

    mcd = calcularMCD(num1, num2);

    cout << "El MCD entre " << num1 << " y " << num2 << " es: " << mcd << endl;

    return 0;
}