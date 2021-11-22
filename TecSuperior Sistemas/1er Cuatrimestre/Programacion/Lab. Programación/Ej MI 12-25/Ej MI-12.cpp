//Escribir los primeros 100 numeros naturales y la sumatoria de ellos.

#include <iostream>
using namespace std;

int main()
{
    int sumatoria = 0;

    for (int i = 0; i < 100; i++)
    {
        sumatoria = sumatoria + i;
        cout << i << endl;
    }

    cout << "La sumatoria es: " << sumatoria << endl;

    return 0;
}