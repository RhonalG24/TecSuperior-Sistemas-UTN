/*
Un meteorólogo amateur necesita de nuestra ayuda para procesar los datos que ha relevado. Los datos que
ha registrado son la temperatura (en grados centígrados) y precipitaciones (o sea lluvia en milímetros cúbicos)
por hora.
Realice el programa que le permita cargar los datos registrados durante una semana (7 días) a cada hora (las
24 horas del día) y luego informe:
a. El día y hora con menor temperatura registrada.
b. El día con mayor cantidad de lluvia registrada (la sumatoria de la lluvia de cada hora)
c. La temperatura máxima de la semana

TOP-DOWN main
    pedir datos
    mostrar datos

Estrategia
    para i = 1 hasta 7 con paso 1
        para j = 1 hasta 24 con paso 1
        pedirNumeros() -> temperatura
        pedirNumeros() -> precipitacion

        lluviaTotalDelDia += precipitacion

        if(temperatura > temperaturaMaximaSemana || primeraTemperaturaMaximaSemana == true)
            temperaturaMaximaSemana = temperatura;
            primeraTemperaturaMaximaSemana = false

        if(temperatura < menorTemperatura || primeraTemperatura == true)
            menorTemperatura = temperatura
            diaMenorTemperatura = i;
            horaMenorTemperatura = j;
            primeraTemperatura = false;

        
        FinPara

    if (lluviaTotalDelDia > mayorCantidadLluvia || mayorCantidadLluvia == -1)
        mayorCantidadLluvia = lluviaTotal
        diaMayorLLuvia = i;

    lluviaTotalDelDia = 0;
    FinPara
mostrar El día y hora con menor temperatura registrada.
mostrar El día con mayor cantidad de lluvia registrada (la sumatoria de la lluvia de cada hora)
mostrar La temperatura máxima de la semana
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);

int main()
{
    //Entradas
    int temperatura;
    int precipitacion;
    ///////
    bool primeraTemperaturaMaximaSemana = true;
    bool primeraTemperaturaMenor = true;

    int lluviaTotalDelDia = 0;
    int temperaturaMaximaSemana;
    int menorTemperatura;
    int diaMayorLLuvia;
    int horaMenorTemperatura;
    int diaMenorTemperatura;
    int mayorCantidadLluvia = -1;

    for (int i = 1; i <= 7; i++)
    {
        cout << "Día " << i << endl
             << endl;

        for (int j = 0; j <= 23; j++)
        {
            cout << "Hora " << j << endl
                 << endl;
            temperatura = pedirNumeros("Ingrese la temperatura en grados centígrados: ");
            precipitacion = pedirNumeros("Ingrese la precipitación en cm3: ");
            cout << endl;

            lluviaTotalDelDia += precipitacion;

            if (temperatura > temperaturaMaximaSemana || primeraTemperaturaMaximaSemana == true)
            {
                temperaturaMaximaSemana = temperatura;
                primeraTemperaturaMaximaSemana = false;
            }

            if (temperatura < menorTemperatura || primeraTemperaturaMenor == true)
            {

                menorTemperatura = temperatura;
                diaMenorTemperatura = i;
                horaMenorTemperatura = j;
                primeraTemperaturaMenor = false;
            }
        }
        if (lluviaTotalDelDia > mayorCantidadLluvia || mayorCantidadLluvia == -1)
        {
            mayorCantidadLluvia = lluviaTotalDelDia;
            diaMayorLLuvia = i;
        }

        lluviaTotalDelDia = 0;
    }

    cout << "La menor temperatura se registró el dia " << diaMenorTemperatura << " en la hora " << horaMenorTemperatura << endl;
    cout << "La mayor cantidad de lluvia se dió el día " << diaMayorLLuvia << endl;
    cout << "La temperatura máxima registrada en la semana fue de " << temperaturaMaximaSemana << "°." << endl;

    return 0;
}

int pedirNumeros(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}