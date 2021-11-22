/*
    Ej. 4 Dados los siguientes dibujos que corresponden a distintos tipos de registros realice su declaración
    en C++, y especifique la nomenclatura para acceder al registro y cada uno de sus campos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char dia;
    char mes;
    short int anio;
} FechaNaci;

typedef struct
{
    char nombre[20];
    FechaNaci fechaNacimiento;
} Persona;

//***********************

typedef struct
{
    char apellido[20];
    char nombre[20];
} NombreLargo;

typedef struct
{
    int nota1;
    int nota2;
    int nota3;
} Calificaciones;

typedef struct
{
    int legajo;
    NombreLargo apellidoNombre;
    Calificaciones calificaciones;
} Persona2;

int main()
{

    return 0;
}