/*
    Archivos Binarios
    Ej. 6: Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el mes de mayo.
    Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código de materia,
    día, mes y año del examen. Los datos finalizan con un nombre y apellido nulo.
    Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por teclado, genere
    un archivo binario de inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente
    diseño:
        a.1 Nro. de legajo (8 dígitos)
        a.2 Código de materia (6 dígitos)
        a.3 Día del examen (1..31)
        a.4 Mes del examen (1..12)
        a.5 Año del examen (4 dígitos) 
        a.6 Nombre-Apellido (25caract)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_BOLETAS 100

typedef struct
{
    int legajo;
    int codMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    char nombreApellido[26];
} Boleta;

void llenarBoletas(Boleta boletas[], int cantBoletas)
{
    Boleta aux;
    cantBoletas = 0;

    // printf("Ingrese el nombre y apellido del alumno:\n");
    // fgets(aux.nombreApellido, 26, stdin);
    // scanf("%s", &aux.nombreApellido);
    // fgets(aux.nombreApellido, 26, stdin);
    // // fflush(stdin);
    printf("Ingrese el numero de legajo:\n");
    scanf("%d", &aux.legajo);

    // while (strcmp(aux.nombreApellido, "") != 0)
    while (aux.legajo > 0)
    {
        printf("Ingrese el nombre y apellido del alumno:\n");
        scanf("%100s", aux.nombreApellido);
        fflush(stdin);
        // printf("Ingrese el numero de legajo:\n");
        // scanf("%d", &aux.legajo);
        // fflush(stdin);

        printf("Ingrese el codigo de materia:\n");
        scanf("%d", &aux.codMateria);
        // fflush(stdin);

        printf("Ingrese el dia, mes y año del examen:\n");
        scanf("%d %d %d", &aux.diaExamen, &aux.mesExamen, &aux.anioExamen);
        fflush(stdin);

        //lleno el vector de boletas
        boletas[cantBoletas] = aux;
        // fflush(stdin);

        cantBoletas++;
        // printf("Ingrese el nombre y apellido del alumno:\n");
        // // scanf("%100s", aux.nombreApellido);

        // fgets(aux.nombreApellido, 26, stdin);
        // // fflush(stdin);
        printf("Ingrese el numero de legajo:\n");
        scanf("%d", &aux.legajo);
    }
    return;
}

int main()
{
    // Boleta boletas[CANT_BOLETAS];
    Boleta boleta;

    // int cantBoletas = 0;

    FILE *ptrArchivo = NULL;
    FILE *ptrArchivoBin = NULL;

    ptrArchivo = fopen("diaFinales.txt", "w");
    if (ptrArchivo == NULL)
    {
        return -1;
    }
    ptrArchivoBin = fopen("diaFinalesBin.dat", "wb");
    if (ptrArchivoBin == NULL)
    {
        return -1;
    }

    // Boleta aux;
    // cantBoletas = 0;

    // printf("Ingrese el nombre y apellido del alumno:\n");
    // fgets(aux.nombreApellido, 26, stdin);
    // scanf("%s", &aux.nombreApellido);
    // fgets(aux.nombreApellido, 26, stdin);
    // // fflush(stdin);
    printf("Ingrese el numero de legajo:\n");
    // scanf("%d", &aux.legajo);
    scanf("%d", &boleta.legajo);

    // while (strcmp(aux.nombreApellido, "") != 0)
    // while (aux.legajo > 0)
    while (boleta.legajo > 0)
    {
        printf("Ingrese el nombre y apellido del alumno:\n");
        // scanf("%100s", aux.nombreApellido);
        scanf("%100s", boleta.nombreApellido);

        fflush(stdin);
        // printf("Ingrese el numero de legajo:\n");
        // scanf("%d", &aux.legajo);
        // fflush(stdin);

        printf("Ingrese el codigo de materia:\n");
        // scanf("%d", &aux.codMateria);
        scanf("%d", &boleta.codMateria);

        // fflush(stdin);

        printf("Ingrese el dia, mes y año del examen:\n");
        // scanf("%d %d %d", &aux.diaExamen, &aux.mesExamen, &aux.anioExamen);
        scanf("%d %d %d", &boleta.diaExamen, &boleta.mesExamen, &boleta.anioExamen);

        fflush(stdin);

        //lleno el vector de boletas
        // boletas[cantBoletas] = aux;
        // fflush(stdin);

        // cantBoletas++;
        // printf("Ingrese el nombre y apellido del alumno:\n");
        // // scanf("%100s", aux.nombreApellido);

        // fgets(aux.nombreApellido, 26, stdin);
        // // fflush(stdin);

        // llenarBoletas(boletas, cantBoletas);
        // for (int i = 0; i < cantBoletas - 1; i++)
        // {
        //     fprintf(ptrArchivo, "%d\t%d\t%d\t%d\t%d\t%s\n", boletas[i].legajo, boletas[i].codMateria, boletas[i].diaExamen, boletas[i].mesExamen, boletas[i].anioExamen, boletas[i].nombreApellido);
        // }
        fprintf(ptrArchivo, "%d\t%d\t%d\t%d\t%d\t%s\n", boleta.legajo, boleta.codMateria, boleta.diaExamen, boleta.mesExamen, boleta.anioExamen, boleta.nombreApellido);
        fwrite(&boleta, sizeof(boleta), 1, ptrArchivoBin);
        printf("Ingrese el numero de legajo:\n");
        // scanf("%d", &aux.legajo);
        scanf("%d", &boleta.legajo);
    }
    fclose(ptrArchivo);
    fclose(ptrArchivoBin);
    return 0;
}
