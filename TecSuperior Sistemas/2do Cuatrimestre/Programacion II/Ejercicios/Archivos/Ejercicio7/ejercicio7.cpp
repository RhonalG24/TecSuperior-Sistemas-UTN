/*
    Ej. 7: Dado el archivo binario generado en el ejercicio 6, desarrolle un programa que solicitando por
teclado un código de materia permita seleccionar todos los registros que se anotaron para rendirla y los
grabe en otro archivo (MATFINALES.DAT), con el mismo diseño.
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

void buscarMateria();
int main()
{
    Boleta alumno;
    int codigoMateria;
    printf("Ingrese el codigo de materia a buscar: ");
    scanf("%d", &codigoMateria);
    fflush(stdin);

    FILE *ptrArchivoBin = NULL;
    FILE *ptrArchivoFinalesBin = NULL;

    // ptrArchivoBin = fopen("../Ejercicio_6/diaFinalesBin.dat", "rb");
    ptrArchivoBin = fopen("../Ejercicio-6-11-funciones/Ej6/diaFinalesBin.dat", "rb");

    if (ptrArchivoBin == NULL)
    {
        printf("Archivo NO encontrado!\n");
        return -1;
    }
    else
    {
        printf("Archivo encontrado!\n");
    }

    ptrArchivoFinalesBin = fopen("matFinales.dat", "wb");
    if (ptrArchivoFinalesBin == NULL)
    {
        printf("Archivo matFinales.dat no encontrado\n");
        return -1;
    }

    fread(&alumno, sizeof(alumno), 1, ptrArchivoBin);
    while (!feof(ptrArchivoBin))
    {
        if (alumno.codMateria == codigoMateria)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%s\n", alumno.legajo, alumno.codMateria, alumno.diaExamen, alumno.mesExamen, alumno.anioExamen, alumno.nombreApellido);
            fwrite(&alumno, sizeof(alumno), 1, ptrArchivoFinalesBin);
        }
        fread(&alumno, sizeof(alumno), 1, ptrArchivoBin);
    }

    fclose(ptrArchivoBin);
    fclose(ptrArchivoFinalesBin);
    return 0;
}