/*
Dado el archivo binario generado en el ejercicio 7, desarrollar la codificación en C o C++ que
graba un archivo de texto, LISTADO.TXT, de los alumnos inscriptos de acuerdo al siguiente diseño.

Legajo      Nombre y Apellido   Fecha   Código de materia
99999999 xxxxxxxxxxxxxxxxxxxx dd/mm/aa  999999
99999999 xxxxxxxxxxxxxxxxxxxx dd/mm/aa  999999

Realice la estrategia de resolución, la representación gráfica del algoritmo, y dibuje el diseño del registro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    int codMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    char nombreApellido[26];
} Boleta;

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

int main()
{
    FILE *ptrArchivoFinalesBin = NULL;
    FILE *ptrArchivoListado = NULL;
    Boleta alumno;

    // ptrArchivoFinalesBin = fopen("../Ejercicio7/matFinales.dat", "rb");

    // if (ptrArchivoFinalesBin == NULL)
    // {
    //     printf("Archivo matFinales NO encontrado.\n");
    //     return -1;
    // }
    // else
    // {
    //     printf("\nArchivo matFinales encontrado!\n");
    // }

    ptrArchivoFinalesBin = abrirArchivo("../Ejercicio7/matFinales.dat", "rb");

    // ptrArchivoListado = fopen("Listado.txt", "w");
    // if (ptrArchivoListado == NULL)
    // {
    //     printf("Archivo Listado.txt no encontrado.\n");
    //     return -1;
    // }
    // else
    // {
    //     printf("\nArchivo Listado.txt encontrado!\n");
    // }
    ptrArchivoListado = abrirArchivo("Listado.txt", "w");

    fprintf(ptrArchivoListado, "Legajo\tNombre y Apellido\tFecha\tCódigo de materia\n");

    fread(&alumno, sizeof(alumno), 1, ptrArchivoFinalesBin);
    while (!feof(ptrArchivoFinalesBin))
    {
        fprintf(ptrArchivoListado, "%d\t%s\t%d/%d/%d\t%d\n", alumno.legajo, alumno.nombreApellido, alumno.diaExamen, alumno.mesExamen, alumno.anioExamen, alumno.codMateria);
        fread(&alumno, sizeof(alumno), 1, ptrArchivoFinalesBin);
    }

    // Legajo      Nombre y Apellido   Fecha   Código de materia

    fclose(ptrArchivoFinalesBin);
    fclose(ptrArchivoListado);
}