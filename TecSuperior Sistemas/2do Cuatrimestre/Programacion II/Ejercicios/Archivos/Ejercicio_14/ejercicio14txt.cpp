/*
Ej. 14: Una empresa de cable desea actualizar el archivo de series que emite por sus distintos canales,
con material nuevo. Para ello posee los siguientes archivos:
a) un archivo maestro de series, Series.dat, con un registro con los datos de cada series, ordenado
ascendente por Id_Serie, con el siguiente diseño:
a.1) Id_Serie ( 9 dígitos )
a.2) Título de la serie (20 caracteres)
a.3) Genero ( 10 caracteres)

b) otro archivo de novedades de series, NovSeries.dat, con el mismo diseño y orden que el archivo
anterior, que contiene las novedades a incorporar.

Se pide desarrollar la metodología necesaria para escribir un algoritmo que Grabe un archivo maestro de
series actualizado, ActSeries.dat, con el mismo diseño y orden que los anteriores.

archivo maestro de series, Series.dat ordenado ascendente por Id_Serie
novedades de series, NovSeries.dat  mismo diseño y orden
series actualizado, ActSeries.dat, con el mismo diseño y orden
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id_Serie;
    char titulo[21];
    char genero[11];
} Serie;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);

int main()
{
    Serie serie;
    Serie novSerie;

    FILE *ptrSeries = abrirArchivo("Series.dat", "r");
    FILE *ptrNovSeries = abrirArchivo("NovSeries.dat", "r");
    FILE *ptrActSeries = abrirArchivo("ActSeries.dat", "w");

    fflush(ptrSeries);
    fflush(ptrNovSeries);
    fflush(ptrActSeries);

    fflush(stdin);

    fread(&serie, sizeof(serie), 1, ptrActSeries);
    fread(&novSerie, sizeof(novSerie), 1, ptrNovSeries);
    while (!feof(ptrSeries) && !feof(ptrNovSeries))
    {
        if (serie.id_Serie == novSerie.id_Serie)
        {
            fprintf(ptrActSeries, "%d %s %s\n", novSerie.id_Serie, novSerie.titulo, novSerie.genero);
            // fwrite(&novSerie, sizeof(Serie), 1, ptrActSeries);
            fflush(ptrNovSeries);

            fflush(stdin);

            fread(&serie, sizeof(serie), 1, ptrSeries);
            fread(&novSerie, sizeof(novSerie), 1, ptrNovSeries);
        }
        else if (serie.id_Serie > novSerie.id_Serie)
        {
            fprintf(ptrActSeries, "%d %s %s\n", novSerie.id_Serie, novSerie.titulo, novSerie.genero);
            fflush(ptrNovSeries);

            fflush(stdin);

            // fwrite(&novSerie, sizeof(Serie), 1, ptrActSeries);
            fread(&novSerie, sizeof(novSerie), 1, ptrNovSeries);
        }
        else
        {
            fprintf(ptrActSeries, "%d %s %s\n", serie.id_Serie, serie.titulo, serie.genero);
            fflush(ptrSeries);

            fflush(stdin);

            // fwrite(&serie, sizeof(Serie), 1, ptrActSeries);
            fread(&serie, sizeof(serie), 1, ptrSeries);
        }
    }

    while (!feof(ptrSeries))
    {
        fprintf(ptrActSeries, "%d %s %s\n", serie.id_Serie, serie.titulo, serie.genero);
        fflush(ptrSeries);

        fflush(stdin);

        // fwrite(&serie, sizeof(Serie), 1, ptrActSeries);
        fread(&serie, sizeof(serie), 1, ptrSeries);
    }
    while (!feof(ptrNovSeries))
    {
        fprintf(ptrActSeries, "%d %s %s\n", novSerie.id_Serie, novSerie.titulo, novSerie.genero);
        fflush(ptrNovSeries);

        fflush(stdin);

        // fwrite(&novSerie, sizeof(Serie), 1, ptrActSeries);
        fread(&novSerie, sizeof(novSerie), 1, ptrNovSeries);
    }

    fflush(ptrSeries);
    fflush(ptrNovSeries);
    fflush(ptrActSeries);

    fclose(ptrSeries);
    fclose(ptrNovSeries);
    fclose(ptrActSeries);

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