/*
Ej. MI-3: Dada un número entero de la forma (AAAAMMDD), que representa una fecha valida mostrar el dia, mes y
año que representa.

*/

#include <iostream>
using namespace std;

int main()
{
    int fecha, anioAAAAMMDD, mesAAAAMMDD, diaAAAAMMDD;
    int dia, mes, anio;

    cout << "Introduzca una fecha en formato AAAAMMDD: " << endl;
    cin >> fecha;

    anio = fecha / 10000;        //AAAA
    anioAAAAMMDD = anio * 10000; //AAAA0000

    mes = (fecha - anioAAAAMMDD) / 100; //MM
    mesAAAAMMDD = mes * 100;            //MM00

    dia = fecha - anioAAAAMMDD - mesAAAAMMDD; //000000DD

    cout << "Día: " << dia << endl;
    cout << "Mes: " << mes << endl;
    cout << "Año: " << anio << endl;
}