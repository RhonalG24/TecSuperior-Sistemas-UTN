/*Ejercicio 3
    Una empresa ferroviaria desea procesar los archivos históricos de venta de pasajes de 2
    estaciones que producto de una remodelación fueron unificadas.
    Para esto cuenta con 2 archivos binarios, uno por cada estación, donde cada registro
    describe una venta de un pasaje. Cada registro contiene
        ● Número de boleto (long int)
        ● Fecha en formato "DD-MM-YYYY HH:MM:SS"
        ● Id de estación (short int)
        ● Precio (float)

    Los archivos se encuentran ordenados por fecha.
    Se pide:
    
    1. Generar un nuevo archivo de texto, que contenga los registros de los 2 archivos
    binarios, ordenado por fecha. La particularidad es que del campo fecha solo se
    requiere la fecha DD-MM-YYYY
    
    2. A partir del archivo de texto generado en el punto 1, emitir un listado con la siguiente
    forma:
    
    Estación: xxx
    Año: 9999. Mes:99
    Total mensual: 999.99
    Año: 9999. Mes: 99
    Total mensual: 999.99
    
    Estación: yyy
    Año: 9999. Mes:99
    Total mensual: 999.99
    Año: 9999. Mes: 99
    Total mensual: 999.99
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULL_DATE_SIZE 20
#define SHORT_DATE_SIZE 11
typedef struct
{
    int nroBoleto;
    char fecha[FULL_DATE_SIZE];
    int idEstacion;
    float precio;
} Venta;

int main()
{

    return 0;
}
