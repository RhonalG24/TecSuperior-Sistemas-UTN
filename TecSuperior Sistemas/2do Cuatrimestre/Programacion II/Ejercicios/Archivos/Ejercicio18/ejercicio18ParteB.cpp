/*
Ej. 18: Dado el archivo “ALUMNOS.dat” con los datos personales de alumnos ordenado por legajo, con
el siguiente diseño:

    a.1 Legajo (8 dígitos)
    a.2 Apellido y nombre ( 30 caracteres)
    a.3 Domicilio (20 caracteres)
    a.4 Código postal (4 dígitos)
    a.5 Teléfono (10 caracteres)
    a.6 Año de ingreso (4 dígitos)

Y otro archivo con el mismo orden que el mencionado llamado “NOVEDADES.dat”, con las
actualizaciones (altas, bajas, y modificaciones) a ser aplicadas, donde cada registro contiene además de
todos los campos de Alumnos.dat un código de operación (“A”= Alta, “B”= Baja, “M”= Modificación).

    a- Desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado
    “ALUMACTU.dat” con el mismo diseño.
    b- Rehacer el ejercicio considerando que el archivo NOVEDADES es de texto separado por tabs en
    lugar de binario.

    Entrada
    "ALUMNOS.dat" ordenado por legajo
    “NOVEDADES.dat” mismo orden, código de operación (“A”= Alta, “B”= Baja, “M”= Modificación)

    Salida
    "ALUMACTU.dat"  mismo diseño

    Estrategia
        1. Abrir los primeros 2 archivos en modo lectura
        2. Abrir el actualizado en modo escritura
        3. Iniciar ambas estructuras
        4. Hacer corte de control con ambos archivos usando el legajo
                Si codigo es A: Se agrega al arc actualizado
                Si codigo es B: Se elimina en el actualizado
                Si codigo es M: Se actualiza en actualizado
        
        Cerrar los archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char apellidoNombre[31];
    char domicilio[21];
    int codPostal;
    int telefono;
    int anioIngreso;

} Alumno;

typedef struct
{
    int legajo;
    char apellidoNombre[31];
    char domicilio[21];
    int codPostal;
    int telefono;
    int anioIngreso;
    char codOperacion;
} Novedades;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);

void apareoArchivos(FILE *ptrArch1, FILE *ptrArch2, FILE *ptrArchFinal){};

int main()
{
    FILE *ptrAlumnosDat = abrirArchivo("ALUMNOS.dat", "rb");
    FILE *ptrNovedadesDat = abrirArchivo("NOVEDADES.dat", "rb");
    FILE *ptrAlumActDat = abrirArchivo("ALUMACTU.dat", "wb");

    apareoArchivos(ptrAlumnosDat, ptrNovedadesDat, ptrAlumActDat);

    Alumno alumno;
    Novedades novedades;

    fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
    fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);

    while (!feof(ptrNovedadesDat) && !feof(ptrAlumnosDat))
    {
        if (alumno.legajo == novedades.legajo)
        {
            switch (novedades.codOperacion)
            {
            case 'A':
                fwrite(&alumno, sizeof(alumno), 1, ptrAlumActDat);
                fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
                fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
                break;

            case 'B':

                fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
                fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
                break;

            default:
                fwrite(&novedades, sizeof(alumno), 1, ptrAlumActDat);
                fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
                fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
                break;
            }
        }
        else if (alumno.legajo < novedades.legajo)
        {
            fwrite(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
            fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
        }
        else
        {
            fwrite(&novedades, sizeof(alumno), 1, ptrAlumActDat);
            fread(&novedades, sizeof(alumno), 1, ptrNovedadesDat);
        }
    }

    while (!feof(ptrNovedadesDat))
    {
        switch (novedades.codOperacion)
        {
        case 'A':
            fwrite(&novedades, sizeof(alumno), 1, ptrAlumActDat);
            fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
            break;

        case 'B':
            fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
            break;

        default:
            fwrite(&novedades, sizeof(alumno), 1, ptrAlumActDat);
            fread(&novedades, sizeof(novedades), 1, ptrNovedadesDat);
            break;
        }
        fwrite(&novedades, sizeof(alumno), 1, ptrAlumActDat);
    }

    while (!feof(ptrAlumnosDat))
    {
        fwrite(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
        fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
    }

    fclose(ptrAlumnosDat);
    fclose(ptrNovedadesDat);
    fclose(ptrAlumActDat);
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