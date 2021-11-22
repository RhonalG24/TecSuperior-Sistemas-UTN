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

void discardChars();
void leerString(const char *msg, char *variable, int limite);
void leer(const char *msg, const char *formato, void *variable);

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

void llenarBoletas(Boleta boletas[], int cantBoletas)
{
    Boleta aux;
    cantBoletas = 0;

    printf("Ingrese el nombre y apellido del alumno:\n");
    fgets(aux.nombreApellido, 26, stdin);
    while (aux.nombreApellido[0] != '\0')
    {

        fflush(stdin);

        printf("Ingrese el numero de legajo:\n");
        scanf("%d", &aux.legajo);

        printf("Ingrese el codigo de materia:\n");
        scanf("%d", &aux.codMateria);

        printf("Ingrese el dia, mes y año del examen:\n");
        scanf("%d %d %d", &aux.diaExamen, &aux.mesExamen, &aux.anioExamen);
        fflush(stdin);

        //lleno el vector de boletas
        boletas[cantBoletas] = aux;

        cantBoletas++;

        printf("Ingrese el nombre y apellido del alumno:\n");
        fgets(aux.nombreApellido, 26, stdin);
    }
    return;
}

int main()
{
    Boleta boleta;

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

    leerString("Ingrese el nombre y apellido del alumno:\n", boleta.nombreApellido, 26);
    // printf("Ingrese el nombre y apellido del alumno:\n");
    // fgets(boleta.nombreApellido, 26, stdin);

    while (strcmp(boleta.nombreApellido, " ") != 0)
    {
        leer("Ingrese el numero de legajo:\n", "%d", &(boleta.legajo));
        // printf("Ingrese el numero de legajo:\n");
        // // scanf("%d", &aux.legajo);
        // scanf("%d", &boleta.legajo);

        // fflush(stdin);

        leer("Ingrese el codigo de materia:\n", "%d", &(boleta.codMateria));
        // leer("Ingrese el codigo de materia:\n", boleta.codMateria);
        // printf("Ingrese el codigo de materia:\n");
        // scanf("%d", &boleta.codMateria);

        // printf("Ingrese el dia, mes y año del examen:\n");
        // scanf("%d %d %d", &boleta.diaExamen, &boleta.mesExamen, &boleta.anioExamen);

        // fflush(stdin);
        leer("Ingrese el dia del examen:\n", "%d", &(boleta.diaExamen));

        leer("Ingrese el mes del examen:\n", "%d", &(boleta.mesExamen));

        leer("Ingrese el año del examen:\n", "%d", &(boleta.anioExamen));

        fprintf(ptrArchivo, "%d\t%d\t%d\t%d\t%d\t%s\n", boleta.legajo, boleta.codMateria, boleta.diaExamen, boleta.mesExamen, boleta.anioExamen, boleta.nombreApellido);
        fwrite(&boleta, sizeof(boleta), 1, ptrArchivoBin);

        leerString("Ingrese el nombre y apellido del alumno:\n", boleta.nombreApellido, 26);

        // printf("Ingrese el nombre y apellido del alumno:\n");
        // fgets(boleta.nombreApellido, 26, stdin);
    }
    fclose(ptrArchivo);
    fclose(ptrArchivoBin);
    return 0;
}

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

void leerString(const char *msg, char *variable, int limite)
{

    printf("%s", msg);
    scanf("%[^\n]s", variable);
    discardChars();

    while (strlen(variable) > limite)
    {
        printf("\nDebe contener como máximo %d carácteres.\n\n", limite);
        printf("%s", msg);
        scanf("%[^\n]s", variable);
        discardChars();
    }
    return;
}

/**
 * Lee cualquier tipo excepto cadenas
 */
void leer(const char *msg, const char *formato, void *variable)
{
    printf(msg);
    scanf(formato, variable);
    discardChars();
    return;
}