/*
Ej. 1 : Se conoce de cada alumno de un curso los siguientes datos: legajo (8dígitos) y las notas de 2
parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe un
archivo de texto CURSO.TXT con una línea por cada alumno, con el número de legajo y su promedio
(real).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
} Alumno;

FILE *openFile(char *filename, char *mode)
{
    FILE *archivo = fopen(filename, mode);
    if (archivo == NULL)
    {
        exit(EXIT_FAILURE);
    }
    return archivo;
}

int main()
{
    Alumno alumno;

    FILE *ptrArchivo = openFile("CURSO.txt", "w");

    fprintf(ptrArchivo, "Legajo\t\t promedio\n");

    printf("Ingrese el legajo del alumno o un numero negativo para terminar: ");
    scanf("%d", &alumno.legajo);
    fflush(stdin);

    while (alumno.legajo > 0)
    {
        printf("Ingrese la primera nota del alumno: ");
        scanf("%d", &alumno.nota1);
        fflush(stdin);
        printf("Ingrese la segunda nota del alumno: ");
        scanf("%d", &alumno.nota2);
        fflush(stdin);

        alumno.promedio = ((float)(alumno.nota1 + alumno.nota2) / 2);

        fprintf(ptrArchivo, "%d\t\t\t%.2f\n", alumno.legajo, alumno.promedio);

        printf("Ingrese legajo del siguiente alumno o un numero negativo para terminar: ");
        scanf("%d", &alumno.legajo);
        fflush(stdin);
    }
    fflush(ptrArchivo);
    fclose(ptrArchivo);
    return 0;
}