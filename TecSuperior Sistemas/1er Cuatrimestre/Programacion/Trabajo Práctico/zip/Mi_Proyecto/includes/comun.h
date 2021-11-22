#include <iostream>

using namespace std;

#define CANT_VUELTAS 20

#ifndef COMUN_H
#define COMUN_H

typedef struct
{
    int dia;
    int mes;
    int anio;
} ST_Fecha;

typedef struct
{
    int numeroVuelta;
    int fecha;
    int tiempoMMSS;
    float velocidadMedia;
} ST_Vuelta;

typedef struct
{
    ST_Fecha fecha;
    int vueltaMasRapida;
    int tiempoVueltaMasRapida;
    int vueltaMasLenta;
    int tiempoVueltaMasLenta;
    float velocidadMedia;
    ST_Vuelta vueltas[CANT_VUELTAS];
} ST_Entrenamiento;

#endif /* COMUN_H */

void mostrar(string mensaje);
ST_Fecha convertirFecha(int fecha);
