/* Ej. MI-6 Dadas dos fechas informar cual es la más reciente. Determine cuáles serían los datos de entrada y las leyendas a informar 
de acuerdo al proceso solicitado.
 */

#include <iostream>
using namespace std;

int main()
{
    int fechaActual, fechaA, fechaB;

    cout << "Ingrese la fecha actual: " << endl;
    cin >> fechaActual;
    cout << "Ingrese la primera fecha: " << endl;
    cin >> fechaA;
    cout << "Ingrese la segunda fecha: " << endl;
    cin >> fechaB;

    if (fechaActual - fechaA < fechaActual - fechaB)
    {
        cout << "La fecha más reciente es " << fechaA << endl;
    }
    else
    {
        cout << "La fecha más reciente es " << fechaB << endl;
    }
    return 0;
}