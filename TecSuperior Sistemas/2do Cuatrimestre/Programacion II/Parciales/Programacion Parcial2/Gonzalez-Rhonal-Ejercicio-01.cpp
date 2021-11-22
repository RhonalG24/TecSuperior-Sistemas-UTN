/*
Ejercicio 1
Un corralón recibe en horario de oficina material de construcción que entrega durante los fines de semana.
Diariamente un empleado da de alta los artículos en el sistema respetando el orden de llegada, para lo cual imputa el código
de la ubicación temporal en la playa, código de barra y precio de ventas; la carga queda en memoria.
En una etapa posterior, fuera de horario de oficina, los empleados trasladan a la ubicación definitiva cada uno de estos
artículos recibidos; para asistirse, imprimen la nómina de bultos en el orden inverso al que fueron recibidos, con los tres
datos relevados oportunamente.
Los sábados por la mañana un empleado recibe los pedidos que los clientes realizan telefónicamente; ingresa al sistema el
nombre, dirección, código postal, código del artículo (únicamente puede comprar un sólo tipo) y la cantidad.
Todo queda en memoria hasta que por la tarde, cuando dejan de recibirse llamados, se imprime el listado de clientes en el
mismo orden que fueron recibidos, para realizar el delivery.

a. Desarrollar la estrategia y estructuras para el problema enunciado y para los puntos siguientes:
b. Realizar la carga de un artículo recibido.
c. Realizar la impresión de los artículos.
d. Realizar el alta de un pedido.
e. Realizar la impresión del listado para el delivery

Estrategia
    a) 
    inicio un nodo para una pila
    b) procedimiento cargarMateriales() para cargar los datos dentro de la pila
    c) procedimiento vaciarPila() que vacia la pila mientras imprime, para que se impriman en orden inverso al que se cargaron
    d) inicio un nodo para una cola 
    procedimiento cargarPedidos() para cargar los pedidos en una cola
    e) procedimiento vaciarCola() para ir vaciando la cola mientras imprimo, para que asi queden en el mismo orden con el cual se cargaron

    Estructuras para el b)

    typedef struct{
        int codUbicacion;
        int codBarra;
        float precioVenta;
    } Material;

    typedef struct nodo{
        Material dato;
        struct nodo *ste;
    } STR_NODO;

    Estructuras para el d)
    typedef struct{
        char nombre[21];
        char direccion[21];
        int codPostal;
        int codArticulo;
        int cantidad;
    } Pedido;

    typedef struct nodoPedido
    {
        Pedido pedido;
        struct nodoPedido *ste;
    } STR_NODO_PEDIDO;

    typedef struct queue
    {
        STR_NODO_PEDIDO *fte;
        STR_NODO_PEDIDO *fin;
    } STR_QUEUE;


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codUbicacion;
    int codBarra;
    float precioVenta;
} Material;

typedef struct nodo
{
    Material dato;
    struct nodo *ste;
} STR_NODO;

typedef struct
{
    char nombre[21];
    char direccion[21];
    int codPostal;
    int codArticulo;
    int cantidad;
} Pedido;

typedef struct nodoPedido
{
    Pedido pedido;
    struct nodoPedido *ste;
} STR_NODO_PEDIDO;

typedef struct queue
{
    STR_NODO_PEDIDO *fte;
    STR_NODO_PEDIDO *fin;
} STR_QUEUE;

int leer(const char *msg);
float leerFloat(const char *msg);
void create(STR_NODO **head);
void push(STR_NODO **head, Material dato);
Material pop(STR_NODO **head);
bool isEmpty(STR_NODO *pila);
void cargarMateriales(STR_NODO **pila);
void vaciarPila(STR_NODO **pila);

STR_QUEUE create();
bool isEmpty(STR_QUEUE queue);
void add(STR_QUEUE *queue, Pedido valor);
Pedido remove(STR_QUEUE *queue);
void cargarPedidos(STR_QUEUE *queue);
void vaciarCola(STR_QUEUE *queue);
void discardChars();
void leerString(const char *msg, int limite, char *variable);

int main()
{

    STR_NODO *pila;
    create(&pila);

    // cargarMateriales(&pila);
    // vaciarPila(&pila);

    STR_QUEUE queue = create();
    cargarPedidos(&queue);
    vaciarCola(&queue);

    return 0;
}

int leer(const char *msg)
{
    int valor;
    printf(msg);
    scanf("%d", &valor);
    return valor;
}
float leerFloat(const char *msg)
{
    float valor;
    printf(msg);
    scanf("%f", &valor);
    return valor;
}

//Funciones Pila
void create(STR_NODO **head)
{
    *head = NULL;
}

void push(STR_NODO **head, Material dato)
{
    //declarar el nodo
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    //inicializarlo
    nodo->dato = dato;
    nodo->ste = NULL;

    //hacer la referencia (enlazado)
    nodo->ste = *head;
    *head = nodo;
    return;
}

Material pop(STR_NODO **head)
{
    Material valor = (*head)->dato;
    STR_NODO *aux = *head;
    *head = (*head)->ste;
    //liberar el nodo
    free(aux);
    return valor;
}

bool isEmpty(STR_NODO *pila)
{
    return pila == NULL;
}

void cargarMateriales(STR_NODO **pila)
{
    Material material;

    material.codUbicacion = leer("Ingrese el código de la ubicacion en la playa (0 para salir): \n");
    while (material.codUbicacion != 0)
    {

        material.codBarra = leer("Ingrese el código de barra: \n");
        material.precioVenta = leerFloat("Ingrese el precio de venta: \n");
        push(pila, material);
        material.codUbicacion = leer("Ingrese el código de la ubicacion en la playa (0 para salir): \n");
    }
    return;
}

void vaciarPila(STR_NODO **pila)
{
    Material materialAux;
    while (!isEmpty(*pila))
    {
        materialAux = pop(pila);
        printf("%d\t%d\t%.2f\n", materialAux.codUbicacion, materialAux.codBarra, materialAux.precioVenta);
    }
    return;
}

//Funciones Cola

STR_QUEUE create()
{
    STR_QUEUE queue;
    queue.fte = NULL;
    queue.fin = NULL;
    return queue;
}

bool isEmpty(STR_QUEUE queue)
{
    return queue.fte == NULL && queue.fin == NULL;
}

void add(STR_QUEUE *queue, Pedido valor)
{
    STR_NODO_PEDIDO *nodo = (STR_NODO_PEDIDO *)malloc(sizeof(STR_NODO_PEDIDO));
    nodo->pedido = valor;
    nodo->ste = NULL;

    if (queue->fte == NULL)
    {
        queue->fte = nodo;
    }
    else
    {
        queue->fin->ste = nodo;
    }
    queue->fin = nodo;
}

Pedido remove(STR_QUEUE *queue)
{
    STR_NODO_PEDIDO *aux = queue->fte;
    Pedido valor = queue->fte->pedido;
    queue->fte = queue->fte->ste;

    if (queue->fte == NULL)
    {
        queue->fin = NULL;
    }

    free(aux);
    return valor;
}

void cargarPedidos(STR_QUEUE *queue)
{
    Pedido pedido;
    char stringAux[21];

    pedido.codArticulo = leer("Ingrese el código del articulo (0 para salir): \n");
    while (pedido.codArticulo != 0)
    {
        leerString("Ingrese el nombre del cliente: \n", 21, stringAux);
        strcpy(pedido.nombre, stringAux);
        leerString("Ingrese la direccion: \n", 21, stringAux);
        strcpy(pedido.direccion, stringAux);
        pedido.codPostal = leer("Ingrese el código postal (0 para salir): \n");
        pedido.cantidad = leer("Ingrese la cantidad (0 para salir): \n");

        add(queue, pedido);
        pedido.codArticulo = leer("Ingrese el código del articulo (0 para salir): \n");
    }
    return;
}

/**
 * Imprime datos con estructura de una cola 
 */
void vaciarCola(STR_QUEUE *queue)
{
    Pedido pedido;

    char nombre[21];
    char direccion[21];
    int codPostal;
    int codArticulo;
    int cantidad;
    while (!isEmpty(*queue))
    {
        pedido = remove(queue);
        printf("%s\t%s\t%d\t%d\t%d\n", pedido.nombre, pedido.direccion, pedido.codPostal, pedido.codArticulo, pedido.cantidad);
    }
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
 * Usa discardChars()
 */
void leerString(const char *msg, int limite, char *variable)
{

    printf("%s", msg);
    scanf(" %[^\n]s", variable);
    discardChars();

    while (strlen(variable) > limite)
    {
        printf("\nDebe contener como máximo %d carácteres.\n\n", limite);
        printf("%s", msg);
        scanf(" %[^\n]s", variable);
        discardChars();
    }
    return;
}
