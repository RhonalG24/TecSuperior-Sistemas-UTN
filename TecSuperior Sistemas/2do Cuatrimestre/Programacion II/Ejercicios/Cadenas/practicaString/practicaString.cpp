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

void discardChars();
// void leerString(const char *msg, char *variable, int limite);
void leerString(const char *msg, char *variable, int limite);
void leer(const char *msg, const char *formato, void *variable);

int main()
{
    char nombre[20];
    char apellido[20];
    char vivienda[20];
    int anios;

    // leerString("Ingrese un nombre:\n", nombre, 5);
    // // while ((strcmp(nombre, " ")) != 0)
    // printf("cantChar = %d\n\n", strlen(nombre));
    // while (strlen(nombre) != 1 && strlen(nombre) != 2)

    // {
    //     leer("Ingrese la edad:\n", "%d", &anios);
    //     leerString("Ingrese el apellido:\n", apellido, 5);
    //     leerString("Ingrese la direccion:\n", vivienda, 10);

    //     printf("\n%s cantChar = %d\n\n", nombre, strlen(nombre));
    //     printf("\n%d\n", anios);
    //     printf("\n%s cantChar = %d\n\n", apellido, strlen(apellido));
    //     printf("\n%s cantChar = %d\n\n", vivienda, strlen(vivienda));
    //     leerString("Ingrese un nombre:\n", nombre, 5);
    //     printf("cantChar = %d\n\n", strlen(nombre));
    // }

    Boleta alumno;

    leer("Ingrese el legajo\n", "%d", &alumno.legajo);

    printf("legajo: %d\n", alumno.legajo);

    leerString("Ingrese nombre y apellido:\n", alumno.nombreApellido, 25);
    printf("Nombre: %s\n", alumno.nombreApellido);

    leer("Ingrese el legajo\n", "%d", &alumno.legajo);

    printf("legajo: %d\n", alumno.legajo);
    return 0;
}

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

/**
 * Usa scanf para leer string
 */
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
 * Usa fgets para leer string
 * 
 */
// void leerString(const char *msg, char *variable, int limite)
// {
//     printf("%s", msg);
//     fgets(variable, limite, stdin);

//     return;
// };

void leer(const char *msg, const char *formato, void *variable)
{
    printf(msg);
    scanf(formato, variable);
    discardChars();
    return;
}