/*
    ej 35 TOP-DOWN
    - ingresar numero
    - calcular factorial del numero
    - si es multiplo de 3 lo cuento
    - si es multiplo de 5 lo cuento
    - si es multiplo de 3 y 5 lo cuento
    - mostrar resultados
*/

#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
int calcularFactorial(int num);
bool esMultiploDe(int num, int multiplo);

int main()
{
    int num = pedirNumero("Ingrese un numero entero ( o 0 para salir): ");
    int factorial = 1;
    bool esMultiploDe3;
    bool esMultiploDe5;
    bool esMultiploDe3y5;
    int multiploDe3 = 0, multiploDe5 = 0, multiploDe3y5 = 0;

    while (num != 0)
    {

        if (esMultiploDe3 = esMultiploDe(num, 3))
        {
            multiploDe3++;
            cout << "Este numero es multiplo de 3" << endl;
        }
        if (esMultiploDe5 = esMultiploDe(num, 5))
        {
            multiploDe5++;
            cout << "Este numero es multiplo de 5" << endl;
        }
        if (esMultiploDe3 && esMultiploDe5)
        {
            multiploDe3y5++;
            cout << "Este numero es multiplo de 3 y tambien de 5" << endl;
        }
        if (num > 0)
        {
            factorial = calcularFactorial(num);
            cout << "Su factorial es " << factorial << endl;
        }
        else
        {
            cout << "No se puede calcular el factorial de este numero. " << endl;
        }

        cout << endl;

        num = pedirNumero("Ingrese otro numero entero ( o 0 para salir): ");
    }
    cout << "Se ingresaron: " << endl
         << multiploDe3 << " multiplos de 3," << endl
         << multiploDe5 << " multiplos de 5 y" << endl
         << multiploDe3y5 << " multiplos de 3 y 5." << endl;
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

bool esMultiploDe(int num, int multiplo)
{
    return num % multiplo == 0;
    // bool esMultiplo = (num % multiplo == 0) ? true : false;
    // return esMultiplo;
    /*bool esMultiplo = false;
    if (num % multiplo == 0)
    {
        esMultiplo = true;
        return esMultiplo;
    }*/
}