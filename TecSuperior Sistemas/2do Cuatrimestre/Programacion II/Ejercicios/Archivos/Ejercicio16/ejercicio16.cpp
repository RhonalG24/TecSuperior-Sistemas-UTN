/*
Ej. 16:
    Una aplicación para descargas de Series posee la información en un archivo binario,
    Episodios.dat, con un registro por cada episodio, ordenado ascendente por Id_Serie y Número de
    temporada, con el siguiente diseño:
        1) Id_Serie ( 9 dígitos )
        3) Número de temporada (1..12)
        5) Cantidad de descargas (long)
        2) Título del episodio (20 caracteres)
        4) Número de episodio (unsigned char)
        6) Fecha de última descarga (aaaammdd)
    Se pide desarrollar la metodología necesaria para escribir un algoritmo emita el siguiente listado:

    Listado de Descargas de Series
    Serie: 999999999
    Temporada: 99
    N. de EpisodioTítulo del Episodio
    Cant. descargasFecha de última descarga
    999xxxxxxxxxxxxxx
    9999999dd/mm/aaaa
    999xxxxxxxxxxxxxx
    9999999dd/mm/aaaa
    .....................................................................................
    Cant. Total de Episodios de la Serie: 99999
    Total descargas de la temporada:999999999
    Serie: 999999999
    Temporada: 99
    N. de EpisodioTítulo del Episodio
    Cant. descargasFecha de última descarga
    999xxxxxxxxxxxxxx
    9999999dd/mm/aaaa
    999xxxxxxxxxxxxxx
    9999999dd/mm/aaaa
    .....................................................................................
    *Cant. Total de Episodios de la temporada: 99999
    *Total descargas de la temporada: 999999999
    **Cant. Total de Episodios de la Serie: 99999
    **Total descargas de la Serie: 999999999
    .......................................................................
    *** Total General de series: 9999
*/

/* Datos:
    Episodios.txt, un registro por cada episodio, ordenado ascendente por Id_Serie y Número de
    temporada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int idSerie;
    int numeroTemporada;
    long cantDescargas;
    char titulo[21];
    unsigned char numeroEpisodio;
    int ultimaDescarga; //aaaammdd
} Episodio;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
Episodio leerTXT(FILE *file);

int main()
{
    Episodio episodio;

    FILE *ptrEpisodios = NULL;
    ptrEpisodios = abrirArchivo("Episodios.txt", "r");

    //lectura
    episodio = leerTXT(ptrEpisodios);

    //corte de control

    while (!feof(ptrEpisodios))
    {
        int idSerie = episodio.idSerie;

        while (!feof(ptrEpisodios) && episodio.idSerie == idSerie)
        {

            int nroTemporada = episodio.numeroTemporada;
            while (!feof(ptrEpisodios) && episodio.idSerie == idSerie && nroTemporada == episodio.numeroTemporada)
            {

                // episodio = leer(ptrEpisodios);
            }
        }
    }

    fclose(ptrEpisodios);
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

    return ptrArchivo;
}

Episodio leerTXT(FILE *file)
{
    Episodio episodio;
    char buffer[500];
    if (fgets(buffer, 500, file) == NULL)
    {
        return episodio;
    }

    episodio.idSerie = atoi(strtok(buffer, ","));
    episodio.numeroTemporada = atoi(strtok(NULL, ","));
    episodio.cantDescargas = atoi(strtok(NULL, ","));
    strcpy(episodio.titulo, strtok(NULL, ","));
    episodio.numeroEpisodio = atoi(strtok(NULL, ","));
    episodio.ultimaDescarga = atoi(strtok(NULL, ","));

    return episodio;
}