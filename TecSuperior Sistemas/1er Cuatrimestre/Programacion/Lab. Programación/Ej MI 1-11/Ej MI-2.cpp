//MI-1 Dados dos valores enteros A y B, informar la suma, la resta y el producto.

#include <iostream>
using namespace std;

int main()
{
    int dia, mes, anio;
    int fecha;

    cout << "Ingrese el día: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el año: " << endl;
    cin >> anio;

    fecha = (anio * 10000) + (mes * 100) + dia;

    cout << "Ingresó la fecha: " << fecha << endl;

    return 0;
}