#include <iostream>
using namespace std;

int main()
{
    float num;
    int cantValores = 0;

    cout << "Ingrese un número (O un número negativo para salir): " << endl;
    cin >> num;

    while (num >= 0)
    {
        cantValores++;
        cout << "El número ingresado fue " << num << endl;
        cout << "Ingrese otro número (O un número negativo para salir): " << endl;
        cin >> num;
    }

    cout << "Ingresó un total de " << cantValores << " valores." << endl;
    return 0;
}