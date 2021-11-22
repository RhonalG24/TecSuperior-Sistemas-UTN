// Dados N valores informar el mayor, el menor y en qu� posici�n del conjunto fueron ingresados.

#include <iostream>
using namespace std;

int main()
{
    int cantValores;
    float num, num1;
    float ingresoMayor;
    float ingresoMenor;
    float numMayor;
    float numMenor;

    cout << "Cuantos valores ingresaras?" << endl;
    cin >> cantValores;
    cout << "Ingrese un numero:" << endl;
    cin >> num1;

    numMayor = num1;
    numMenor = num1;
    ingresoMayor = 1;
    ingresoMenor = 1;

    for (int i = 2; i <= cantValores; i++)
    {
        cout << "Ingrese otro numero: " << endl;
        cin >> num;
        if (num > numMayor)
        {
            numMayor = num;
            ingresoMayor = i;
        }
        else if (num < numMenor || num == 1)
        {
            numMenor = num;
            ingresoMenor = i;
        }
    }

    cout << "El mayor numero fue " << numMayor << " y fue introducido en la posicion " << ingresoMayor << endl;
    cout << "El menor numero fue " << numMenor << " y fue introducido en la posicion " << ingresoMenor << endl;
    return 0;
}