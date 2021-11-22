#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct materia
{
    char codigo[5];
    int alumnos;
};
struct alumno
{
    char codigo[5];
    char legajo[7];
    int nota;
};

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);

int main(int argc, char const *argv[])
{ //Armo vector de 11 posiciones
    int notas[11] = {0};
    //Recorro el archivo

    // abro el archivo
    FILE *ptrAlumno = abrirArchivo("ALUMNOS.DAT", "rb");
    alumno alumno;
    fread(&alumno, sizeof(alumno), 1, ptrAlumno);

    // leo el primer registro.
    // entro a un while (!EOF)
    while (!feof(ptrAlumno))
    {
        // saco del buffer la nota y la sumo al vector.
        int pos = alumno.nota;
        notas[pos]++;
        // vuelvo a leer.
        fread(&alumno, sizeof(alumno), 1, ptrAlumno);
    }
    //Según la nota, accedo al array de notas, y le agrego una unidad.
    //Recorro el vector para mostrar sus valores.
    for (int i = 0; i < 11; i++)
    {
        printf("La cantidad de alumnos con nota %d es:  %d\n", i, notas[i]);
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
    else
    {
        printf("Archivo %s encontrado!\n", nombreArchivo);
    }

    return ptrArchivo;
}