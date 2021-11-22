#include <iostream>
using namespace std;

int main()
{
    int tipoInfraccion;
    float valorMulta;
    float multaTotalL = 0;
    float multaTotalM = 0;
    float multaTotalG = 0;
    string motivoInfraccion;
    int cantInfraccionG = 0;
    char gravedadInfraccion;
    int totalL = 0;
    int totalM = 0;
    int totalG = 0;
    int CANTIDAD_FRACCIONES = 20;

    for (int i = 0; i < CANTIDAD_FRACCIONES; i++)
    {
        cout << "Ingrese el tipo de infracción (1, 2, 3 o 4): " << endl;
        cin >> tipoInfraccion;
        cout << "Ingrese el motivo de la infracción: " << endl;
        cin >> motivoInfraccion;
        cout << "Ingrese el valor de la multa: " << endl;
        cin >> valorMulta;
        cout << "Ingrese la gravedad de la infracción (L, M o G): " << endl;
        cin >> gravedadInfraccion;

        switch (gravedadInfraccion)
        {
        case 'L':
            totalL++;
            multaTotalL += valorMulta;
            break;
        case 'M':
            totalM++;
            multaTotalM += valorMulta;
            break;
        case 'G':
            totalG++;
            multaTotalG += valorMulta;
            if (tipoInfraccion == 3 || tipoInfraccion == 4)
            {
                cantInfraccionG++;
            }
            break;
        }
    }

    cout << "La fábrica tiene " << totalL << " infraciones de gravedad L lo cual suma una multa de $" << multaTotalL << " ," << endl;
    cout << totalM << " infraciones de gravedad M lo cual suma una multa de $" << multaTotalM << endl;
    cout << "y " << totalG << " infraciones de gravedad G lo cual suma una multa de $" << multaTotalG << endl;

    if (cantInfraccionG > 3)
    {
        cout << "Clausurar fábrica.";
    }

    return 0;
}