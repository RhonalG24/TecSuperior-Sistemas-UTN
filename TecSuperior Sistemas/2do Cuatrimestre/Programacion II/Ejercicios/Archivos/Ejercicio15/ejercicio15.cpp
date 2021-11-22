/*
Ej. 15: El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el
depósito, para realizar las compras del mes.

Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el local, con el siguiente diseño:
a.1) Código de libro ( 4 dígitos )
a.3) Autor (20 caracteres)
a.6) Stock en el local (char)
a.2) Título del libro (30 caracteres)
a.4) Editorial (20 caracteres)
a.7) Genero ( 10 caracteres)

b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el depósito, con el siguiente diseño:
b.1) Código de libro ( 4 dígitos )
b.2) Stock en depósito (unsigned char)

Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por
código de libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en
ambos lugares, con el siguiente formato:

Libros faltantes
Código  Observación
9999    Falta en depósito
9999    Falta en local
9999    Falta en local y en depósito
Total de libros en falta: 9999999


StockEnLocal.dat, ordenado por código del libro
StockEnDeposito.dat, ordenado por código del libro

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char autor[21];
    char stock[7];
    char titulo[31];
    char editorial[21];
    char genero[11];
} LibroLocal;

typedef struct
{
    int codigo;
    char stock[7];
} LibroDeposito;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);

int main()
{
    LibroLocal local;
    LibroDeposito deposito;

    // int cantLocal;
    // int cantTotal;

    FILE *ptrLocal = abrirArchivo("StockEnLocal.dat", "rb");
    FILE *ptrDeposito = abrirArchivo("StockEnDeposito.dat", "rb");

    // printf("Cuantos libros desea tener en el local?\n");
    // scanf("%d", &cantLocal);

    // printf("Cuantos libros desea tener en total?\n");
    // scanf("%d", &cantTotal);

    printf("Libros faltantes.\nCódigo\tObservación\n");

    fread(&local, sizeof(local), 1, ptrLocal);
    fread(&deposito, sizeof(deposito), 1, ptrDeposito);
    while (!feof(ptrLocal) && !feof(ptrDeposito))
    {
        if (local.codigo < deposito.codigo)
        {
            if ((int)local.stock == 0)
            {
                printf("%s\tFalta en local\n", local.stock);
            }
        }
        else if (local.codigo == deposito.codigo)
        {
            /* code */
        }
        else
        {
        }
    }

    fclose(ptrLocal);
    fclose(ptrDeposito);
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