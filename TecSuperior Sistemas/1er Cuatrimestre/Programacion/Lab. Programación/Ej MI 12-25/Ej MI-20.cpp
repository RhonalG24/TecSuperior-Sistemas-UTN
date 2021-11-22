#include <iostream>
using namespace std;

int main()
{
    float num;
    float numMayor;
    const int CANT_VALORES = 10;

    cout << "1) Ingrese un número: " << endl;
    cin >> num;

    numMayor = num;

    for (int i = 1; i < CANT_VALORES; i++)
    {
        cout << i + 1 << ") Ingrese un número: " << endl;
        cin >> num;

        if (num > numMayor)
        {
            numMayor = num;
        }
    }
    cout << "El mayor número ingresado fue " << numMayor << endl;
}