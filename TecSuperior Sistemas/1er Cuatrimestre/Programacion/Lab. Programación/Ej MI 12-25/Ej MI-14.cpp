#include <iostream>
using namespace std;

int main()
{
    int num;
    float promedioMayores = 0;
    int numMayores = 0;
    int sumaMenores = 0;

    for (int i = 1; i <= 50; i++)
    {
        cout << i << ") Ingrese un número:" << endl;
        cin >> num;

        if (num > 100)
        {
            promedioMayores += num;
            numMayores += 1;
        }
        else if (num < (-10))
        {
            sumaMenores = sumaMenores + num;
        }
    }

    promedioMayores = promedioMayores / numMayores;

    cout << "El promedio de números mayores que 100 es: " << promedioMayores << endl;
    cout << "La suma de los números menores que -10 es: " << sumaMenores << endl;

    return 0;
}