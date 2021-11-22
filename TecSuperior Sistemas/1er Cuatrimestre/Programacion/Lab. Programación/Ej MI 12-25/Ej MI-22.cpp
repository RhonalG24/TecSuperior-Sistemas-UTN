// Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre = ‘FIN’,
//informar el nombre de la persona con mayor edad y el de la más joven.

#include <iostream>
using namespace std;

int main()
{

    string nombre;
    int fechaNac;
    int fechaMayor = 0;
    int fechaMenor = 0;
    string personaMayor;
    string personaMenor;

    cout << "Ingrese el nombre de la persona (o FIN para salir): " << endl;
    cin >> nombre;

    while (nombre != "FIN")
    {
        cout << "Ingrese la fecha de nacimiento en formato AAAAMMDD: " << endl;
        cin >> fechaNac;

        if (fechaNac > fechaMenor || fechaMenor == 0)
        {
            personaMenor = nombre;
            fechaMenor = fechaNac;
        }

        if (fechaNac < fechaMayor || fechaMayor == 0)
        {
            personaMayor = nombre;
            fechaMayor = fechaNac;
        }

        cout << "Ingrese el nombre de otra persona (o FIN para salir): " << endl;
        cin >> nombre;
    }

    if (fechaMayor == 0 || fechaMenor == 0)
    {
        cout << "No se ingresaron personas." << endl;
    }
    else
    {
        cout << "La persona con mayor edad es " << personaMayor << endl;
        cout << "La persona con menor edad es " << personaMenor << endl;
    }

    return 0;
}