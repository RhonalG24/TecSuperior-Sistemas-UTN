/*
Ej. MI-37: ​ Desarrolle la función
float CalcularPorcentajeDiferencia(int A ,int B)

que recibe dos valores y retorne el siguiente cálculo: (B-A) *100 / (A+B)
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
float CalcularPorcentajeDiferencia(int A, int B);

int main()
{
    int num1 = pedirNumeros("Ingrese el valor A:");
    int num2 = pedirNumeros("ingrese el valor B:");
    // while (num1 + num2 == 0)
    // {
    //     cout << "La suma de ambos no puede ser 0." << endl;
    //     num2 = pedirNumeros("Ingrese el valor B:");
    // }

    cout << "El porcentaje diferencia es: " << CalcularPorcentajeDiferencia(num1, num2) << endl;

    return 0;
}

int pedirNumeros(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

float CalcularPorcentajeDiferencia(int A, int B)
{
    if (A + B == 0)
    {
        cout << "No se puede operar." << endl;
        return 1;
    }
    else
    {
        return ((B - A) * 100) / (A + B);
    }
}