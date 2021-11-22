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
void leerString(const char *msg, char *variable, int limite);
void leer(const char *msg, const char *formato, void *variable);
void discardChars();

Alumno leerAlumno();
void escribirEnBinario(const Alumno *alumno, FILE *ptrArchivo);
Novedades leerAlumnoNovedad();
void escribirEnBinario(const Novedades *alumno, FILE *ptrArchivo);

int main()
{

    FILE *ptrAlumnosDat = abrirArchivo("ALUMNOS.dat", "rb");
    FILE *ptrNovedadesDat = abrirArchivo("NOVEDADES.dat", "rb");

    Alumno alumno;
    Novedades novedades;
    char opcion;
    do
    {
        alumno = leerAlumno();
        escribirEnBinario(&alumno, ptrAlumnosDat);
        leer("Desea registrar otro alumno? (s/n)\n", "%c", &opcion);
    } while (opcion == 's');

    do
    {
        novedades = leerAlumnoNovedad();
        escribirEnBinario(&novedades, ptrNovedadesDat);
        leer("Desea registrar otro alumno? (s/n)\n", "%c", &opcion);
    } while (opcion == 's');

    fclose(ptrAlumnosDat);
    fclose(ptrNovedadesDat);
    return 0;
}

Alumno leerAlumno()
{
    Alumno alumno;
    leer("Ingrese el legajo:\n", "%d", &alumno.legajo);
    leerString("Ingrese el nombre:\n", alumno.apellidoNombre, 31);
    leerString("Ingrese el domicilio:\n", alumno.domicilio, 21);
    leer("Ingrese el codigo postal:\n", "%d", &alumno.codPostal);
    leer("Ingrese el telefono:\n", "%d", &alumno.telefono);
    leer("Ingrese el año de ingreso:\n", "%d", &alumno.anioIngreso);
    return alumno;
}

Novedades leerAlumnoNovedad()
{
    Novedades novedades;
    leer("Ingrese el legajo:\n", "%d", &novedades.legajo);
    leerString("Ingrese el nombre:\n", novedades.apellidoNombre, 31);
    leerString("Ingrese el domicilio:\n", novedades.domicilio, 21);
    leer("Ingrese el codigo postal:\n", "%d", &novedades.codPostal);
    leer("Ingrese el telefono:\n", "%d", &novedades.telefono);
    leer("Ingrese el año de ingreso:\n", "%d", &novedades.anioIngreso);
    leer("Ingrese el codigo de operacio: (A,B o M)", "%c", &novedades.codOperacion);
    return novedades;
}

void escribirEnBinario(const Alumno *alumno, FILE *ptrArchivo)
{
    fwrite(alumno, sizeof(alumno), 1, ptrArchivo);
    return;
}

void escribirEnBinario(const Novedades *alumno, FILE *ptrArchivo)
{
    fwrite(alumno, sizeof(alumno), 1, ptrArchivo);
    return;
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

/**
 * Usa fgets para leer string
 * No usar
 */
void leerString(const char *msg, char *variable, int limite)
{
    printf("%s", msg);
    fgets(variable, limite, stdin);
    return;
};

/**
 * Lee cualquier tipo excepto cadenas
 * Usa discardChars()
 * Nota: debes agregar & a la variable.
 */
void leer(const char *msg, const char *formato, void *variable)
{
    printf(msg);
    scanf(formato, variable);
    discardChars();
    return;
}

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}