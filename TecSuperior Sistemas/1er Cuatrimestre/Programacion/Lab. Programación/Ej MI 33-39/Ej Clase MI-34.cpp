#include <iostream>
using namespace std;

int factorial(int numero)
{
    int factorial = 1;

    for (int i = numero; i >= 1; i--)
    {
        factorial *= i;
    }

    return factorial;
}

int leerNumero(string mensaje)
{ //funcionc
    int numero;
    cout << mensaje << endl;
    cin >> numero;
    return numero;
}

//Una forma más genérica
void leerNumero(int &valor, string mensaje)
{ //procedimiento
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void imprimir(int numero, int fact)
{
    cout << "!" << numero << " = " << factorial << endl;
    return;
}

int main()
{

    int numero = leerNumero("Ingrese el numero para calcular el factorial:");

    leerNumero(numero, "Ingrese un numero"); //sobreescribe al anterior

    int fact = factorial(numero);

    imprimir(numero, fact);
    // imprimir factorial

    system("pause");
    return 0;
}