/*
Ej. 22: Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de los
siguientes archivos:
Un archivo “Destinos.dat”, con información de la distancia a cada uno de los destinos y con
el siguiente diseño de registro:
    a.1) número de destino (3 dígitos)
    a.2) distancia en kilómetros (float)
También se dispone de otro archivo “Viajes.dat”, con los viajes realizados por cada camión y con el
siguiente diseño de registro:
    b.1) patente del camión (6 caracteres, no son más de 200 camiones) 
    b.2) número de destino 
    b.3) número de chofer (1..150)
Se pide desarrollar la metodología necesaria para realizar un programa que informe:
    1. Cantidad de viajes realizados a cada destino
    2. Número de chofer con menor cantidad de km recorridos
    3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
*/

/*
Datos:
    Destinos.dat : distancia a cada uno de los destinos
        a.1) número de destino (3 dígitos)
        a.2) distancia en kilómetros (float)
    Viajes.dat : viajes realizados por cada camión
        b.1) patente del camión (6 caracteres, no son más de 200 camiones) 
        b.2) número de destino 
        b.3) número de chofer (1..150)

    Salida: 
        1. Cantidad de viajes realizados a cada destino
        2. Número de chofer con menor cantidad de km recorridos
        3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
    
    Estrategia
        Abrir archivos (r)
        pasar Destinos.dat a un array
        
        array de registrosDestino[999] (el indice es el nro de destino [0-999], y un acumulador de viajes a dicho destino)
        array de chofer (indice es el numero de chofer, inicializo en 0, acumulo los kilometrajes)
        array de camiones (guardo patente y si fue al destino 116)
        
        Por cada viaje
            float kilometraje;
            1) cant de viaje al destino
                kilometraje = Accedo al array de destinos por PUP para buscar el kilometraje
                Accedo al array de registrosDestino por PUP (nroDestino-1) y aumento el contador
            2) Accedo al array de choferes por PUP y acumulo el kilometraje 
            3) Accedo al array de camiones, busco la patente y cambio a true si el destino es 116
        
        Imprimo listado de viajes con cantViajes (registrosDestino)
        Busco el chofer con menos km y lo muestro
        Imprimo listado de choferes que fueron al destino 116
            
            
        Cerrar archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nro;
    float distancia; //km
} Destino;

typedef struct
{
    char patenteCamion[199];
    int nroDestino;
    int nroChofer; //1-150
} Viaje;

typedef struct
{
    float distancia;
    int cantViajes;
} Registro_Destinos;

typedef struct
{
    char patenteCamion[199];
    bool destino116;
} Registro_Camiones;

int main()
{

    return 0;
}