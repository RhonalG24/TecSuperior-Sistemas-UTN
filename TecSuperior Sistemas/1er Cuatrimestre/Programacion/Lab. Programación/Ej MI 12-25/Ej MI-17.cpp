#include <iostream>
using namespace std;

int main()
{
    float sueldo;
    int sueldo1 = 0; //menos $1.520.
    int sueldo2 = 0; //entre $1.520 y $2.780
    int sueldo3 = 0; //entre $2.780 y $5.999
    int sueldo4 = 0; //$5.999 o m�s.

    cout << "Ingrese el sueldo (0 para salir): " << endl;
    cin >> sueldo;

    while (sueldo > 0)
    {
        if (sueldo >= 5999)
        {
            sueldo4++;
        }
        else if (sueldo >= 2780)
        {
            sueldo3++;
        }
        else if (sueldo >= 1520)
        {
            sueldo2++;
        }
        else
        {
            sueldo1++;
        }
        cout << "Ingrese el siguiente sueldo � 0 para salir: " << endl;
        cin >> sueldo;
    }

    cout << sueldo1 << " empleados ganan menos de $1.520." << endl;
    cout << sueldo2 << " empleados ganan entre $1.520 y $2.780." << endl;
    cout << sueldo3 << " empleados ganan entre $2.780 y $5.999." << endl;
    cout << sueldo4 << " empleados ganan $5.999 o m�s." << endl;

    return 0;
}