/*
Ejercicio 2:

Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de los siguientes archivos:

Un archivo “Destinos.dat”, con información de la distancia a cada uno de los destinos y con
el siguiente diseño de registro:
    Número de destino (3 dígitos).
    Distancia en kilómetros (float).

También se dispone de otro archivo “Viajes.dat”, con los viajes realizados por cada camión y con el siguiente diseño de registro:

    Patente del camión (6 caracteres, no son más de 200 camiones).
    Número de destino.
    Número de chofer (1..150).

Se pide desarrollar la metodología necesaria para realizar un programa que informe:

1. Cantidad de viajes realizados a cada destino
2. Número de chofer con menor cantidad de km recorridos
3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.

*/

/*
Datos:
    Destinos.dat : distancia a cada uno de los destinos
        Número de destino (3 dígitos)
        Distancia en kilómetros (float)
    Viajes.dat : viajes realizados por cada camión
        Patente del camión (6 caracteres, no son más de 200 camiones) 
        Número de destino 
        Número de chofer (1..150)

    Salida: 
        1. Cantidad de viajes realizados a cada destino
        2. Número de chofer con menor cantidad de km recorridos
        3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
    
    Estrategia
        Abrir archivos ("rb")
        pasar Destinos.dat a un array
        
        array de registrosDestino[999] (el indice es el nro de destino [0-999], y un acumulador de viajes a dicho destino)
        array de chofer (indice es el numero de chofer, inicializo en 0, acumulo los kilometrajes)
        array de camiones[200] (guardo patente y si fue al destino 116)
        
        Por cada viaje
            float kilometraje;
            1) cant de viaje al destino
                kilometraje = Accedo al array de regDestinos por PUP para buscar el kilometraje
                Accedo al array de regDestinos por PUP (nroDestino-1) y aumento el contador
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
#define MAX_DESTINO 999
#define MAX_CAMIONES 200
#define MAX_CHOFERES 150

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

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
void generarArray(Registro_Destinos *regDestinos, FILE *ptrDestinosDat);
int buscarPatente(Registro_Camiones *vec, int cant, char *valor);
void registrarCamion(Registro_Camiones *vec, const Viaje viaje, int &cantCamiones);
void imprimirViajes(Registro_Destinos *regDestinos);
void imprimirChoferMenorKm(float *chofer);

int main()
{
    // Abrir archivos ("rb")
    FILE *ptrDestinosDat = abrirArchivo("Destinos.dat", "rb");
    FILE *ptrViajesDat = abrirArchivo("Viajes.dat", "rb");

    //     array de registrosDestino[999] (el indice es el nro de destino [0-999], y un acumulador de viajes a dicho destino)
    Registro_Destinos regDestinos[MAX_DESTINO];
    //     pasar Destinos.dat a un array
    generarArray(regDestinos, ptrDestinosDat);
    //     array de chofer (indice es el numero de chofer, inicializo en 0, acumulo los kilometrajes)
    float chofer[MAX_CHOFERES] = {0};

    //     array de camiones[200] (guardo patente y si fue al destino 116)
    Registro_Camiones camiones[MAX_CAMIONES];
    camiones->destino116 = false;

    Viaje viaje;
    float kilometraje;
    int cantCamiones = 0;
    //     Por cada viaje
    fread(&viaje, sizeof(Viaje), 1, ptrViajesDat);
    while (!feof(ptrViajesDat))
    {

        kilometraje = regDestinos[viaje.nroDestino - 1].distancia; //guardo la distancia

        // 1) cant de viaje al destino
        regDestinos[viaje.nroDestino - 1].cantViajes++; // Accedo al array de regDestinos por PUP (nroDestino-1) y aumento el contador

        // 2) Accedo al array de choferes por PUP y acumulo el kilometraje
        chofer[viaje.nroChofer - 1] += kilometraje;

        // 3) Accedo al array de camiones, busco la patente y cambio a true si el destino es 116
        int pos = buscarPatente(camiones, MAX_CAMIONES, viaje.patenteCamion);
        if (pos == -1)
        { //si no esta en el array de camiones, se registra
            registrarCamion(camiones, viaje, cantCamiones);
        }
        else if (viaje.nroDestino == 116)
        { //si esta, se verifica si el viaje fue al destino 116
            camiones[pos].destino116 = true;
        }
        fread(&viaje, sizeof(Viaje), 1, ptrViajesDat);
    }
    // 1. Cantidad de viajes realizados a cada destino
    imprimirViajes(regDestinos);
    // 2. Número de chofer con menor cantidad de km recorridos
    imprimirChoferMenorKm(chofer);
    // 3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.

    //     Imprimo listado de choferes que fueron al destino 116

    //No me dio tiempo de hacer la funcion pero funcionaria asi..
    //imprimirCamiones116(camiones); //funcion que imprime los camiones que tengan destino116 == true

    fclose(ptrDestinosDat);
    fclose(ptrViajesDat);

    return 0;
}

FILE *abrirArchivo(const char *nombreArchivo, const char *modo)
{
    FILE *ptrArchivo = fopen(nombreArchivo, modo);
    if (ptrArchivo == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s", nombreArchivo);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Archivo %s encontrado!\n", nombreArchivo);
    }

    return ptrArchivo;
}

void generarArray(Registro_Destinos *regDestinos, FILE *ptrDestinosDat)
{
    Destino destino;

    regDestinos->cantViajes = {0};
    int pos; //nroDestino

    fread(&destino, sizeof(Destino), 1, ptrDestinosDat);
    while (!feof(ptrDestinosDat))
    {
        pos = destino.nro;
        regDestinos[pos - 1].distancia = destino.distancia;

        fread(&destino, sizeof(Destino), 1, ptrDestinosDat);
    }
    return;
}

int buscarPatente(Registro_Camiones *vec, int cant, char *valor)
{
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(vec[i].patenteCamion, valor) == 0)
        {
            return i;
        }
    }
    //Si no salió todavía, no estaba en el vector
    return -1;
}

void registrarCamion(Registro_Camiones *vec, const Viaje viaje, int &cantCamiones)
{
    strcpy(vec[cantCamiones].patenteCamion, viaje.patenteCamion);
    cantCamiones++;
    return;
}

void imprimirViajes(Registro_Destinos *regDestinos)
{

    for (int i = 0; i < MAX_DESTINO; i++)
    {
        printf("Destino %d - %d viajes.\n", i + 1, regDestinos[i].cantViajes);
    }
    return;
}

void imprimirChoferMenorKm(float *chofer)
{

    int choferMenorRecorrido;
    float menorKm = 999999;
    for (int i = 0; i < MAX_CHOFERES; i++)
    {
        if (chofer[i] > 0 && chofer[i] < menorKm)
        {
            choferMenorRecorrido = i;
            menorKm = chofer[i];
        }
    }

    printf("El chofer con menor kilometraje recorrido fue el nro %d\n", choferMenorRecorrido + 1);
    return;
}