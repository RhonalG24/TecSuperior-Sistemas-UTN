/*
Ej. MI-9: Dados un mes y el año correspondiente informar cuántos 
días tiene el mes.
*/

#include <iostream>
using namespace std;

int main()
{
    int mes = 0;
    int anio = 0;
    int dias = 0;

    cout << "Ingrese el mes en número: " << endl;
    cin >> mes;
    cout << "Ingrese el año: " << endl;
    cin >> anio;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dias = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias = 30;
        break;
    case 2:
        if ((anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }

    cout << "El mes " << mes << " del año " << anio << " tiene " << dias << " dias." << endl;
    return 0;
}