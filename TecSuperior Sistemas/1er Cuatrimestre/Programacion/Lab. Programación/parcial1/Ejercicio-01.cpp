/*
Realizar una función o procedimiento según crea conveniente que pueda calcular la edad de una persona
recibiendo su fecha de nacimiento.
    
*/

#include <iostream>
using namespace std;

void convertirFecha(int fecha, int &anio, int &mes, int &dia);
void calcularEdad(int fechaActual, int fechaNacimiento, int &edad);

void calcularEdad(int fechaActual, int fechaNacimiento, int &edad)
{
    int diaActual, mesActual, anioActual;
    int diaNac, mesNac, anioNac;

    convertirFecha(fechaActual, anioActual, mesActual, diaActual);
    convertirFecha(fechaNacimiento, anioNac, mesNac, diaNac);

    edad = anioActual - anioNac;

    if (mesActual < mesNac)
    {
        edad--;
    }
    else
    {
        if (mesActual == mesNac)
        {
            if (diaActual < diaNac)
            {
                edad--;
            }
        }
    }

    return;
}

void convertirFecha(int fecha, int &anio, int &mes, int &dia)
{
    anio = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = fecha % 100;
    return;
}
