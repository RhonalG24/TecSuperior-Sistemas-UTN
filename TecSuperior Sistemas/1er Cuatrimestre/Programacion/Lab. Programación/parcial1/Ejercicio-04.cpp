/*
Realizar una función que reciba dos valores enteros positivos y devuelva la multiplicación de ambos por sumas
sucesivas (sin usar la multiplicación!):
a. Realizar la función utilizando ciclos de iteración
b. Realizar la función utilizando una función recursiva
*/

#include <iostream>
using namespace std;

//funcion a.
int multiplicacion(int num1, int num2)
{
    int producto = 0;

    for (int i = 0; i < num2; i++)
    {
        producto = producto + num1;
    }

    return producto;
}

//funcion b.
int multiplicacionRecursiva(int num1, int num2)
{
    int producto = 0;
    if (num2 <= 1)
    {
        return num1;
    }
    else
    {
        producto = num1 + multiplicacionRecursiva(num1, num2 - 1);
    }
}

int main()
{
    int num1 = 8;
    int num2 = 10;
    cout << multiplicacionRecursiva(num1, num2) << endl;
    return 0;
}