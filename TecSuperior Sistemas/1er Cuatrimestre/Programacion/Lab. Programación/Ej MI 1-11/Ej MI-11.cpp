/*
Ej. MI-11 Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
❖ ‘menor’ si la edad es menor o igual a 12
❖ ‘cadete’ si la edad está comprendida entre 13 y 18
❖ ‘juvenil’ si la edad es mayor que 18 y no supera los 26
❖ ‘mayor’ en el caso que no cumpla ninguna de las condiciones anteriores
*/

#include <iostream>
using namespace std;

int main()
{
    int edad;
    string mensaje;

    cout << "Ingrese la edad del socio: " << endl;
    cin >> edad;

    if (edad <= 12)
    {
        mensaje = "El socio es menor.";
    }
    else if (edad <= 18)
    {
        mensaje = "El socio es cadete.";
    }
    else if (edad <= 26)
    {
        mensaje = "El socio es juvenil.";
    }
    else
    {
        mensaje = "El socio es mayor.";
    }
    cout << mensaje << endl;
    return 0;
}