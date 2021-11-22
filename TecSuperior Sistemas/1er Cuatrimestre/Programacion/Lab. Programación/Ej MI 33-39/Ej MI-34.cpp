#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
int calcularFactorial(int num);

int main()
{
    int num = pedirNumero("Ingrese un numero:");
    int factorial = calcularFactorial(num);

    cout << "El factorial de " << num << " es: " << factorial << endl;

    return 0;
}

int pedirNumero(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

int calcularFactorial(int num)
{
    int factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}