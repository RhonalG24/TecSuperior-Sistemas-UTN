/*
    Ej. 3 : Dado el siguiente dibujo de un registro, especifique la nomenclatura para acceder al registro y cada
    uno de sus campos, y las operaciones que se pueden realizar a nivel registro y a nivel campos. Defina otro
    registro del mismo tipo de datos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char apellidoNombre[25];
    float nota;
} Alumno;

int main()
{
    Alumno estudiante;

    estudiante.legajo;
    estudiante.apellidoNombre;
    estudiante.nota;
    return 0;
}