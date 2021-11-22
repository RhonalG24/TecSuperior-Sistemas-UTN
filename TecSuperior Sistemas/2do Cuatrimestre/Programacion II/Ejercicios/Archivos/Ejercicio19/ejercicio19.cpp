/*
Ej. 19: Dado un archivo de productos codificados de 1 a 100, sin ningún orden, con el siguiente diseño:
    código de producto (1..100)
    precio unitario (single)
y un conjunto de pedidos, y de cada uno se conoce: código de producto, y cantidad de unidades pedidas
(long). Los pedidos finalizan con un código de producto igual a 0.
Se pide:
     informar de cada pedido código de producto, unidades, precio unitario e importe
     al final del proceso:
        o informar los códigos de productos que no fueron vendidos
        o grabar un archivo de texto con el siguiente listado
Listado de Facturación por producto

Código de Producto Total facturado
               999        99999.99

Datos:
    Archivo de productos codificados del 1 al 100, desordenado
        código de producto (1..100)
        precio unitario (single)
    conjunto de pedidos. (Los pedidos finalizan con un código de producto igual a 0)
        código de producto,  
        cantidad de unidades pedidas (long)

Salida: 
    informar por cada pedido: código de producto, unidades, precio unitario e importe
    informar los productos no vendidos
    generar archivo de texto
        codProducto Total Facturado

Estrategia

    1. Abrir archivo de productos modo lectura
    2. Abrir archivo de texto en modo escritura 
    3. Ingresar pedidos


    cerrar archivos



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codProducto;    //1-100
    int precioUnitario; //(single)
} Producto;

typedef struct
{
    int codProducto; //1-100
    int cantPedida;  //(long)
} Pedidos;

typedef struct
{
    int precioUnitario; //(single)
    int cantVendida;
    int importe;
} ProductoFinal;

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
    FILE *ptrProductosDat = abrirArchivo("PRODUCTOS.dat", "rb");
    FILE *ptrPedidosDat = abrirArchivo("PEDIDOS.dat", "rb");
    FILE *ptrListadoTxt = abrirArchivo("LISTADO.txt", "w");

    ProductoFinal productos[100];
    productos->importe = {0};
    Producto producto;
    Pedidos pedido;

    fread(&producto, sizeof(Producto), 1, ptrProductosDat);
    while (!feof(ptrProductosDat))
    {
        productos[producto.codProducto - 1].precioUnitario = producto.precioUnitario;
        fread(&producto, sizeof(Producto), 1, ptrProductosDat);
    }

    fread(&pedido, sizeof(Pedidos), 1, ptrPedidosDat);
    while (!feof(ptrPedidosDat))
    {
        int codigoProducto = pedido.codProducto;

        while ()
    }

    fclose(ptrProductosDat);
    fclose(ptrPedidosDat);
    fclose(ptrListadoTxt);

    return 0;
}

// ---- COMIENZO --------
// STRUCT {float precio, int cantidadVendido}
// Armo array del STRUCT con 100 posiciones.
// PASO los datos de ListaDePrecios a un array con PUP con precio y cantidad vendida en 0.
// ABRO PARA LECTURA Ventas
// LEO PRIMER REGISTRO.
// CORTE DE CONTROL
// CALCULO IMPORTE (Busco el precio y multiplico por la cantidad)

// ACUMULO EN EL ARRAY LA CANTIDAD PARA ESE PRODUCTO.

// MUESTRO pedido código de producto, unidades, precio unitario e importe

/* ---------- */

// Informar los códigos de productos que no fueron vendidos

// recorro el array, y muestro los que tienen cantidadVendido == 0.

// Grabo un archivo de texto con el siguiente listado
// recorro el array, y voy grabando a un archivo codigo + (precio * cantidad)