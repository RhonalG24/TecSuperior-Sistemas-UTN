/*
Ej. MI-39: ​ Desarrollar un procedimiento tal que dada una hora (HHMMSS) 
y un tiempo también en formato HHMMSS
devuelva la nueva hora que surge de sumar el tiempo a la hora inicial, 
considere también si cambió el día.
*/

#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
void descomponerTiempo(int tiempo, int &hora, int &minutos, int &segundos);
int componerTiempo(int horas, int minutos, int segundos);
void sumarTiempo(int horaInicial, int tiempo, int &suma, bool &nuevoDia);

int main()
{
    bool nuevoDia = false;
    int suma;
    int horaInicial = pedirNumero("Ingrese la hora inicial en formato HHMMSS: ");
    int tiempo = pedirNumero("Ingrese un tiempo en formato HHMMSS: ");

    sumarTiempo(horaInicial, tiempo, suma, nuevoDia);

    cout << "La nueva hora es " << suma << endl;

    if (nuevoDia)
    {
        cout << "El dia cambió." << endl;
    }

    return 0;
}

int pedirNumero(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

void descomponerTiempo(int tiempo, int &hora, int &minutos, int &segundos)
{
    hora = tiempo / 10000; //hhmmss
    minutos = (tiempo / 100) % 100;
    segundos = tiempo % 100;
    return;
}

int componerTiempo(int horas, int minutos, int segundos)
{
    return horas * 10000 + minutos * 100 + segundos;
}

void sumarTiempo(int horaInicial, int tiempo, int &suma, bool &nuevoDia)
{
    int horasIniciales, horasASumar;
    int minutosIniciales, minutosASumar;
    int segundosIniciales, segundosASumar;

    descomponerTiempo(horaInicial, horasIniciales, minutosIniciales, segundosIniciales);
    descomponerTiempo(tiempo, horasASumar, minutosASumar, segundosASumar);

    int horasTotales = horasIniciales + horasASumar;
    int minutosTotales = minutosIniciales + minutosASumar;
    int segundosTotales = segundosIniciales + segundosASumar;

    if (segundosTotales >= 60)
    {
        segundosTotales -= 60;
        minutosTotales++;
    }
    if (minutosTotales >= 60)
    {
        minutosTotales -= 60;
        horasTotales++;
    }
    if (horasTotales >= 24)
    {
        horasTotales -= 24;
        nuevoDia = true;
    }

    suma = componerTiempo(horasTotales, minutosTotales, segundosTotales);
    return;
}