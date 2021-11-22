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
void leer(const char *msg, const char *fmt, void *val);
void leerString(const char *msg, char *val);
void discardChars();

int main()
{
    Serie serie;
    Serie novSerie;

    FILE *ptrSeries = abrirArchivo("Series.dat", "w");
    FILE *ptrNovSeries = abrirArchivo("NovSeries.dat", "w");

    printf("Ingreso de los datos del archivo Serie.\n");
    leer("Ingrese el id de la serie.\n", "%d", &serie.id_Serie);

    // printf("Ingrese el id de la serie.\n");
    // scanf("%d", &serie.id_Serie);
    // discardChars();
    while (serie.id_Serie != 0)
    {
        leerString("Ingrese el título de la serie.\n", serie.titulo);
        // leer("Ingrese el titulo de la serie.\n", "%s", serie.titulo);
        // printf("Ingrese el titulo de la serie.\n");
        // fgets(serie.titulo, 21, stdin);
        // discardChars();

        leerString("Ingrese el genero de la serie.\n", serie.titulo);
        // leer("Ingrese el genero de la serie.\n", "%s", serie.genero);
        // printf("Ingrese el genero de la serie.\n");
        // fgets(serie.genero, 11, stdin);
        // discardChars();

        fprintf(ptrSeries, "%d %s %s\n", serie.id_Serie, serie.titulo, serie.genero);

        leer("Ingrese el id de la serie.\n", "%d", &serie.id_Serie);

        // printf("Ingrese el id de la serie.\n");
        // scanf("%d", &serie.id_Serie);
        // discardChars();
    }

    printf("Ingreso de los datos del archivo novSerie.\n");
    leer("Ingrese el id de la serie.\n", "%d", &novSerie.id_Serie);

    // printf("Ingrese el id de la serie.\n");
    // scanf("%d", &novSerie.id_Serie);
    // discardChars();
    while (novSerie.id_Serie != 0)
    {
        leerString("Ingrese el título de la serie.\n", novSerie.titulo);
        // leer("Ingrese el titulo de la serie.\n", "%s", novSerie.titulo);

        // printf("Ingrese el titulo de la serie.\n");
        // fgets(novSerie.titulo, 21, stdin);
        // // discardChars();
        leerString("Ingrese el genero de la serie.\n", novSerie.titulo);
        // leer("Ingrese el genero de la serie.\n", "%s", novSerie.genero);

        // printf("Ingrese el genero de la serie.\n");
        // fgets(novSerie.genero, 11, stdin);
        // discardChars();

        fprintf(ptrNovSeries, "%d %s %s\n", novSerie.id_Serie, novSerie.titulo, novSerie.genero);
        leer("Ingrese el id de la serie.\n", "%d", &novSerie.id_Serie);

        // printf("Ingrese el id de la serie.\n");
        // scanf("%d", &novSerie.id_Serie);
        // discardChars();
    }

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

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

void leer(const char *msg, const char *fmt, void *val)
{
    printf(msg);
    scanf(fmt, val);
    discardChars;
}

void leerString(const char *msg, char *val)
{
    printf(msg);
    gets(val);
}

// void leer(Fecha *fecha)
// {
//     int valor;
//     printf("Ingrese el dia:");
//     scanf("%d", &valor);
//     fecha->dia = valor;

//     printf("Ingrese el mes:");
//     scanf("%d", &valor);
//     fecha->mes = valor;

//     printf("Ingrese el anio:");
//     scanf("%d", &valor);
//     fecha->anio = valor;
//     discardChars();
// }
