/*
Una importante cadena de venta de autopartes, que posee 3 sucursales ubicadas en CABA,
Córdoba y Santa Fe desea obtener un sistema que le permita procesar las ventas realizadas en
cada sucursal.

Actualmente, cada sucursal posee un sistema que se encarga de registrar las ventas que se
realizan.

Por cada venta, el mencionado sistema guarda los datos de la factura en un vector cuya
estructura se describe a continuación:

Número de factura, número entero largo
Fecha:
    Día: número entero corto
    Mes: número entero corto
    Año: número entero
Nombre del cliente: cadena
CUIT del cliente: número entero largo
Total: número real
Items:
    id: número entero corto
    descripción: cadena
    cantidad: número entero corto
    precio unitario: número real

Los items son a lo sumo 15.

El desarrollador del sistema nos indica que por un error en la última actualización, el sistema
dejó de registrar el Total de la factura.

El dueño de la cadena de autopartes, necesita a fin de mes, un listado con el total de las ventas
diaria realizadas por las 3 sucursales, ordenado por monto total de venta diaria ascendente.

Sucursal1{
    fecha{
        facturas{
            items
        }
    }
}



Ejemplo:
Si los datos de entrada son:
Sucursal  Día  Total
1           1     10
1           2     20
1           3     30

Sucursal    Día Total
2           1   50
2           2   60


El listado a fin de mes debería ser:
Dia     Monto
2       80
1       60
3       30
Se pide:
1. Definir las eestructuras necesarias para representar una factura

typedef struct{
    long int nroFactura;
    ST_Fecha fecha;
    string nombreCliente;
    long int cuitCliente;
    float total;
    ST_Items items;
} ST_Factura;
    
    ST_Factura facturas[n] = { ST_Items items[15] = {itemsFactura} }

2. Definir las estructuras necesarias para poder generar el listado solicitado
    sucursal[30] = { totalesXdia }

3. Implementar las función necesarias para generar el listado


Estrategia

recibir vector de facturas
calcular total por Día
imprimir listado por sucursal
sumar totales por sucursal
imprimir listado por mayor venta


1) Recorrer vector facturas de cada sucursal y calcular total de cada facturas

2) FacturasSucursal1y2 = apareo'(FacturasSucursal1, FacturasSucursal2)

3) FacturasResultante = apareo'(FacturasSucursal1y2, FacturasSucursal3)

4) vectorFinal = corteDeControl'(FacturasResultante)

5) ordenar vectorFinal por monto e imprimirlo
*/

#include <iostream>
using namespace std;

//Punto 1
#define MAX_ITEMS 15
#define CANT_FACTURAS 100
#define CANT_DIAS 31

typedef struct
{
    short int dia;
    short int mes;
    int anio;
} ST_Fecha;

//***********Items de la Factura*************
typedef struct
{
    short int id;
    string descripcion;
    short int cantidad;
    float precioUnitario;
} ST_Items;

//***********Factura*************
typedef struct
{
    long int nroFactura;
    ST_Fecha fecha;
    string nombreCliente;
    long int cuitCliente;
    float total;
    ST_Items items[MAX_ITEMS];
} ST_Factura;
//FIN PUNTO 1

typedef struct
{
    ST_Fecha fecha;
    float montoDiario;
} ST_FinMeS;

int convertirFecha(ST_Fecha fecha);
void calcularTotalDeFactura(ST_Factura factura[], int cantFacturas, int cantItems);
void burbujeoMejor(ST_FinMeS arr[], int n);
void ordenarXFecha(ST_Factura arr[], int n);
void apareo(ST_Factura vecA[], int n, ST_Factura vecB[], int m, ST_Factura vecC[], int &k);
void corteDeControl(ST_Factura facturas[], int cantFacturas, ST_FinMeS vectorFinal[CANT_DIAS]);
void imprimirVectorConFormato(ST_FinMeS facturas[], int n);

int main()
{
    ST_Factura FacturasSucursal1[CANT_FACTURAS];
    ST_Factura FacturasSucursal2[CANT_FACTURAS];
    ST_Factura FacturasSucursal3[CANT_FACTURAS];

    // ST_Factura FacturasSucursal1[CANT_FACTURAS] = {
    //     {0001, {03, 05, 2021}, "Raul", 20546563, 0, {{01, "pala", 5, 150}, {02, "pol", 4, 50}}},
    //     {0002, {03, 05, 2021}, "Rhonal", 20546565, 0, {{01, "pala", 10, 150}, {02, "pol", 6, 50}}},
    //     {0003, {02, 05, 2021}, "teto", 20546567, 0, {{01, "pala", 1, 150}, {02, "pol", 1, 50}}},
    //     {0004, {05, 05, 2021}, "jacky", 20546569, 0, {{01, "pala", 2, 150}, {02, "pol", 2, 50}}},
    //     {0005, {20, 05, 2021}, "stefy", 20546571, 0, {{01, "pala", 10, 150}, {02, "pol", 2, 50}}},
    //     {0006, {16, 05, 2021}, "clau", 20546573, 0, {{01, "pala", 1, 150}, {02, "pol", 4, 50}}}};

    // ST_Factura FacturasSucursal2[CANT_FACTURAS] = {
    //     {0001, {06, 05, 2021}, "Raul", 20546563, 0, {{01, "pala", 5, 150}, {02, "pol", 4, 50}}},
    //     {0002, {8, 05, 2021}, "Rhonal", 20546565, 0, {{01, "pala", 10, 150}, {02, "pol", 6, 50}}},
    //     {0003, {06, 05, 2021}, "teto", 20546567, 0, {{01, "pala", 1, 150}, {02, "pol", 1, 50}}},
    //     {0004, {01, 05, 2021}, "jacky", 20546569, 0, {{01, "pala", 2, 150}, {02, "pol", 2, 50}}},
    //     {0005, {14, 05, 2021}, "stefy", 20546571, 0, {{01, "pala", 10, 150}, {02, "pol", 2, 50}}},
    //     {0006, {21, 05, 2021}, "clau", 20546573, 0, {{01, "pala", 1, 150}, {02, "pol", 4, 50}}}};

    // ST_Factura FacturasSucursal3[CANT_FACTURAS] = {
    //     {0001, {04, 05, 2021}, "Raul", 20546563, 0, {{01, "pala", 5, 150}, {02, "pol", 4, 50}}},
    //     {0002, {06, 05, 2021}, "Rhonal", 20546565, 0, {{01, "pala", 10, 150}, {02, "pol", 6, 50}}},
    //     {0003, {22, 05, 2021}, "teto", 20546567, 0, {{01, "pala", 1, 150}, {02, "pol", 1, 50}}},
    //     {0004, {25, 05, 2021}, "jacky", 20546569, 0, {{01, "pala", 2, 150}, {02, "pol", 2, 50}}},
    //     {0005, {30, 05, 2021}, "stefy", 20546571, 0, {{01, "pala", 10, 150}, {02, "pol", 2, 50}}},
    //     {0006, {12, 05, 2021}, "clau", 20546573, 0, {{01, "pala", 1, 150}, {02, "pol", 4, 50}}}};

    // 1) Recorrer vector facturas de cada sucursal y calcular total de cada facturas
    calcularTotalDeFactura(FacturasSucursal1, CANT_FACTURAS, MAX_ITEMS);
    calcularTotalDeFactura(FacturasSucursal2, CANT_FACTURAS, MAX_ITEMS);
    calcularTotalDeFactura(FacturasSucursal3, CANT_FACTURAS, MAX_ITEMS);

    // 2) FacturasSucursal1y2 = apareo'(FacturasSucursal1, FacturasSucursal2)

    ordenarXFecha(FacturasSucursal1, CANT_FACTURAS);
    ordenarXFecha(FacturasSucursal2, CANT_FACTURAS);
    ordenarXFecha(FacturasSucursal3, CANT_FACTURAS);

    int cantFacturas1y2 = CANT_FACTURAS + CANT_FACTURAS;

    ST_Factura FacturasSucursal1y2[cantFacturas1y2];
    apareo(FacturasSucursal1, CANT_FACTURAS, FacturasSucursal2, CANT_FACTURAS, FacturasSucursal1y2, cantFacturas1y2);

    // 3) FacturasResultante = apareo'(FacturasSucursal1y2, FacturasSucursal3)
    int cantFacturasResultante = cantFacturas1y2 + CANT_FACTURAS;

    ST_Factura FacturasResultante[cantFacturasResultante];
    apareo(FacturasSucursal1y2, cantFacturas1y2, FacturasSucursal3, CANT_FACTURAS, FacturasResultante, cantFacturasResultante);

    // 4) vectorFinal = corteDeControl'(FacturasResultante)

    ST_FinMeS vectorFinal[CANT_DIAS];
    corteDeControl(FacturasResultante, cantFacturasResultante, vectorFinal);

    // 5) ordenar vectorFinal por monto e imprimirlo
    burbujeoMejor(vectorFinal, CANT_DIAS);
    imprimirVectorConFormato(vectorFinal, CANT_DIAS);

    return 0;
}

void calcularTotalDeFactura(ST_Factura factura[], int cantFacturas, int cantItems)
{

    for (int i = 0; i < cantFacturas; i++)
    {
        for (int j = 0; j < cantItems; j++)
        {
            factura[i].total += factura[i].items[j].precioUnitario * factura[i].items[j].cantidad;
        }
    }
}

int convertirFecha(ST_Fecha fecha)
{
    return fecha.anio * 10000 + fecha.mes * 100 + fecha.dia;
}

void apareo(ST_Factura vecA[], int n, ST_Factura vecB[], int m, ST_Factura vecC[], int &k)
{
    //contadores para la posicion de los vectores A y B
    int i = 0, j = 0;
    //contador para la posicion del vector resultante
    k = 0;

    //mientras pueda comparar valores
    while (i < n && j < m)
    {

        if (convertirFecha(vecA[i].fecha) < convertirFecha(vecB[j].fecha))
        {
            vecC[k] = vecA[i];
            i++; //me muevo en el vector A
        }
        else
        {
            vecC[k] = vecB[j];
            j++;
        }
        k++;
    }
    //Para kos valores restantes de los vectores
    while (i < n)
    {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while (j < m)
    {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}

void burbujeoMejor(ST_FinMeS arr[], int n)
{
    int i = 0, j;
    ST_FinMeS aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].montoDiario < arr[j + 1].montoDiario) //ordenando de mayor a menor
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false; // Cambio el flag si hice un swap
            }
        }
        i++;
    }
    return;
}

void ordenarXFecha(ST_Factura arr[], int n)
{
    int i = 0, j;
    ST_Factura aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < n - i - 1; j++)
        {
            if (convertirFecha(arr[j].fecha) > convertirFecha(arr[j + 1].fecha)) //ordenando de menor a mayor
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false; // Cambio el flag si hice un swap
            }
        }
        i++;
    }
    return;
}

void corteDeControl(ST_Factura facturas[], int cantFacturas, ST_FinMeS vectorFinal[CANT_DIAS])
{
    int i = 0, j = 0, key;
    ST_FinMeS aux;
    while (i < cantFacturas)
    {
        key = convertirFecha(facturas[i].fecha);
        aux.fecha = facturas[i].fecha;
        aux.montoDiario = 0;
        while (i < cantFacturas && convertirFecha(facturas[i].fecha) == key)
        {
            aux.montoDiario += facturas[i].total;
            i++;
        }
        vectorFinal[j] = aux;
        j++;
    }
    return;
}

void imprimirVectorConFormato(ST_FinMeS facturas[], int n)
{
    cout << "Día\t\tMonto" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << facturas[i].fecha.dia << "/" << facturas[i].fecha.mes << "/" << facturas[i].fecha.anio << "\t" << facturas[i].montoDiario << endl;
    }
    return;
}