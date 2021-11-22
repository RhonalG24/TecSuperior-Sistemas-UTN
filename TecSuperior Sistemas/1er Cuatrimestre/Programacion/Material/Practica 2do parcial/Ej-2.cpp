/*
Ejercicio 2
1) Aldo Hel es un heladero de gran trayectoria y dueño de HelAldo, y nos ha pedido ayuda para
tener algo de estadísticas sobre su negocio. Actualmente tiene solamente dos sucursales en
las cuales se venden los mismos 50 gustos de helado. 

De cada gusto sabemos:
● Nombre (Texto)
● Código de gusto (Entero de 1 a 50)



Cada sucursal tiene su Listado de pedidos que se realiza registrando la cantidad de helado
que se vendió en cada venta, en este listado se registra qué gusto y cuántos gramos se
vendieron:
● Hora de venta: Horario en formato HHMMSS
● Código de gusto: Entero de 1 a 50
● Cantidad de gramos: Entero

define struct{
    int horaVenta;
    short int codigoGusto;
    int gramos;
} Pedido;

Para centralizar la operatoria Aldo le pide al encargado de cada sucursal que al terminar el
día envíen sus listados. Ejemplo:
SUCURSAL 1
HORA    COD.GUSTO
121403  12
121403  3
130112  12
GR
100
150
200

Para ayudar a Aldo necesitamos:
SUCURSAL 2
HORA COD. GUSTO
111001
3
164510
11
173114
24
GR
98
110
112

a. Realizar el procedimiento que reciba los listados de las dos sucursales y genere el
conjunto de consumo consolidado, ordenado por horario de venta en forma
ascendente.
void combinar(Pedido sucursal1[], Pedido sucursal2[], int cantPedidos, Pedido consumoConsolidado[], int &totalPedidos)

Realizar la codificación del procedimiento que reciba el conjunto consolidado de consumo de
ambas sucursales y el conjunto de Gustos, e informe:


b. Facturación total, sabiendo que el helado vendido en el primer turno (hasta las
18hs.) tiene un precio de $300 por Kg. y luego de $400 por Kg.

c. Imprimir el listado de Gustos y su consumo total en kilogramos, ordenado por
consumo en forma descendente:
GUSTO
CONSUMO TOTAL(kg)

Consideraciones:
● El listado de cada sucursal está cargado y ordenado por Hora de venta en forma
ascendente
● El conjunto de Gustos está completo y ordenado por código (de 1 a 50) en forma
ascendente
Restricciones:
- Los listados de cada sucursal solo pueden ser recorridos secuencialmente una vez
cada uno
- Sobre el conjunto de Gustos no se pueden hacer búsquedas secuenciales
*/

#include <iostream>
using namespace std;
#define CANT_PEDIDOS 100
#define CANT_GUSTOS 50
// #define CANT_PEDIDOS 6
// #define CANT_GUSTOS 4

typedef struct
{
    string nombre;
    short int codigoGusto;
} Gusto;

typedef struct
{
    int horaVenta;
    short int codigoGusto;
    int gramos;
} Pedido;

typedef struct
{
    Gusto gusto;
    float kilogramos;
} Consumo;

float convertirGrAKg(int gramos);
float verificarHora(Pedido vector[], int posicion);
int obtenerPosicion(Pedido vector[], int posicion);
void combinar(Pedido sucursal1[], Pedido sucursal2[], int cantPedidos, Pedido consumoConsolidado[], int &totalPedidos);
void ordenarXKilogramo(Consumo arr[], int n);
void imprimirListado(Consumo vector[], int n);
void corteDeControl(Pedido consumoConsolidado[], int totalPedidos, Gusto gustos[], Consumo listadoFinal[CANT_GUSTOS]);
// void corteDeControl(Pedido consumoConsolidado[], int totalPedidos, Gusto gustos[], float listadoFinal[CANT_GUSTOS]);
// void ordenarVectorXKilogramo(float arr[], int n);
// void imprimirListado(float vector[], Gusto gustos[], int n);

int main()
{
    Gusto gustos[CANT_GUSTOS];
    Pedido sucursal1[CANT_PEDIDOS];
    Pedido sucursal2[CANT_PEDIDOS];

    // Gusto gustos[CANT_GUSTOS] = {
    //     {"vainilla", 1},
    //     {"banana", 2},
    //     {"fresa", 3},
    //     {"chocolate", 4},
    // };
    // Pedido sucursal1[CANT_PEDIDOS] = {
    //     {102010, 4, 300},
    //     {102510, 4, 300},
    //     {202010, 2, 300},
    //     {212010, 3, 300},
    //     {222610, 3, 300},
    //     {231010, 1, 300},
    // };
    // Pedido sucursal2[CANT_PEDIDOS] = {
    //     {12010, 1, 300},
    //     {32510, 4, 300},
    //     {42010, 3, 300},
    //     {102010, 4, 300},
    //     {112610, 3, 300},
    //     {151010, 1, 300},
    // };

    int totalPedidos = CANT_PEDIDOS * 2;
    Pedido consumoConsolidado[totalPedidos];

    //Ambos vectores ya vienen ordenados por hora de venta
    combinar(sucursal1, sucursal2, CANT_PEDIDOS, consumoConsolidado, totalPedidos);
    // for (int i = 0; i < totalPedidos; i++)
    // {
    //     cout << consumoConsolidado[i].codigoGusto << "\t\t" << consumoConsolidado[i].gramos << "\t\t" << consumoConsolidado[i].horaVenta << endl;
    // }

    Consumo listadoFinal[CANT_GUSTOS];
    listadoFinal->kilogramos = {0};
    // float listadoFinal[CANT_GUSTOS];

    corteDeControl(consumoConsolidado, totalPedidos, gustos, listadoFinal);

    return 0;
}

float convertirGrAKg(int gramos)
{
    return gramos / 1000.0;
}

void combinar(Pedido sucursal1[], Pedido sucursal2[], int cantPedidos, Pedido consumoConsolidado[], int &totalPedidos)
{
    //contadores para la posicion de los vectores A y B
    int i = 0, j = 0;
    //contador para la posicion del vector resultante
    totalPedidos = 0;

    //mientras pueda comparar valores
    while (i < cantPedidos && j < cantPedidos)
    {

        if (sucursal1[i].horaVenta < sucursal2[j].horaVenta)
        {
            consumoConsolidado[totalPedidos] = sucursal1[i];
            i++; //me muevo en el vector A
        }
        else
        {
            consumoConsolidado[totalPedidos] = sucursal2[j];
            j++;
        }
        totalPedidos++;
    }
    //Para kos valores restantes de los vectores
    while (i < cantPedidos)
    {
        consumoConsolidado[totalPedidos] = sucursal1[i];
        i++;
        totalPedidos++;
    }

    while (j < cantPedidos)
    {
        consumoConsolidado[totalPedidos] = sucursal2[j];
        j++;
        totalPedidos++;
    }
}

float verificarHora(Pedido vector[], int posicion)
{
    if (vector[posicion].horaVenta < 180000)
    {
        return convertirGrAKg(vector[posicion].gramos) * 300;
    }
    else
    {
        return convertirGrAKg(vector[posicion].gramos) * 400;
    }
}
int obtenerPosicion(Pedido vector[], int posicion)
{
    return (vector[posicion].codigoGusto) - 1;
}
// void corteDeControl(Pedido consumoConsolidado[], int totalPedidos, Gusto gustos[], float listadoFinal[CANT_GUSTOS])
// {
//     int i = 0;
//     int key, posicion = 0;
//     float facturacionTotal = 0;
//
//     while (i < totalPedidos)
//     {
//         key = consumoConsolidado[i].horaVenta;
//
//         while (i < totalPedidos && consumoConsolidado[i].horaVenta == key)
//         {
//             facturacionTotal += verificarHora(consumoConsolidado, i);
//
//             posicion = consumoConsolidado[i].codigoGusto - 1.0;
//             listadoFinal[posicion] += convertirGrAKg(consumoConsolidado[i].gramos);
//             // listadoFinal[posicion].gusto.codigoGusto = gustos[posicion].codigoGusto;
//             // listadoFinal[posicion].gusto.nombre = gustos[posicion].nombre;
//             // listadoFinal[posicion].kilogramos += convertirGrAKg(consumoConsolidado[i].gramos);
//             i++;
//         }
//     }
//     cout << "Facturación total: " << facturacionTotal << endl;
//     // ordenarXKilogramo(listadoFinal, CANT_GUSTOS);
//     // imprimirListado(listadoFinal, CANT_GUSTOS);
//     ordenarVectorXKilogramo(listadoFinal, CANT_GUSTOS);
//     imprimirListado(listadoFinal, gustos, CANT_GUSTOS);
//     return;
// }

void corteDeControl(Pedido consumoConsolidado[], int totalPedidos, Gusto gustos[], Consumo listadoFinal[CANT_GUSTOS])
{
    int i = 0;
    int key, posicion = 0;
    float facturacionTotal = 0;

    while (i < totalPedidos)
    {
        key = consumoConsolidado[i].horaVenta;

        while (i < totalPedidos && consumoConsolidado[i].horaVenta == key)
        {
            facturacionTotal += verificarHora(consumoConsolidado, i);

            posicion = obtenerPosicion(consumoConsolidado, i);
            // listadoFinal[posicion] += convertirGrAKg(consumoConsolidado[i].gramos);
            listadoFinal[posicion].gusto = gustos[posicion];
            // listadoFinal[posicion].gusto.codigoGusto = gustos[posicion].codigoGusto;
            // listadoFinal[posicion].gusto.nombre = gustos[posicion].nombre;
            listadoFinal[posicion].kilogramos += convertirGrAKg(consumoConsolidado[i].gramos);
            i++;
        }
    }
    cout << "Facturación total: " << facturacionTotal << endl;
    ordenarXKilogramo(listadoFinal, CANT_GUSTOS);
    imprimirListado(listadoFinal, CANT_GUSTOS);
    return;
}

void ordenarXKilogramo(Consumo arr[], int n)
{
    int i = 0, j;
    Consumo aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].kilogramos < arr[j + 1].kilogramos)
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
// void ordenarVectorXKilogramo(float arr[], int n)
// {
//     int i = 0, j, aux;
//     bool ordenado = false;
//     while (i < n && !ordenado)
//     {
//         ordenado = true; // Arranco asumiendo que si esta ordenado
//         // Los ultimos i elementos ya estan ordenados
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] < arr[j + 1])
//             {
//                 aux = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = aux;
//                 ordenado = false; // Cambio el flag si hice un swap
//             }
//         }
//         i++;
//     }
//     return;
// }

// void imprimirListado(float vector[], Gusto gustos[], int n)
// {
//     cout << "GUSTO \t\t CONSUMO TOTAL (KG)" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << gustos[i].nombre << "\t\t" << vector[i] << endl;
//     }
//     return;
// }

void imprimirListado(Consumo vector[], int n)
{
    cout << "GUSTO \t\t CONSUMO TOTAL (KG)" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vector[i].gusto.nombre << "\t\t" << vector[i].kilogramos << endl;
    }
    return;
}