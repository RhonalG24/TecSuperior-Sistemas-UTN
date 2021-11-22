/*
Ejercicio 1: 

Realizar una función que reciba una lista, y que:

Que devuelva una cola con los mismos nodos de la lista en ella.
Que imprima por pantalla la cantidad de nodos de la lista.
Que imprima por pantalla el promedio de sus valores.

Estrategia:

    Creo la cola
    creo un nodo auxiliar (nodoAux) que ira guardando el nodo antes de eliminarlo de la lista

    creo las variables auxiliares (promedio y cantNodos) para hacer las cuentas
    guardo en cantNodo la cantidad de nodos usando la funcion count() para listas

    mientras la lista tenga nodos{
        nodoAux sera igual al nodo actual de la lista
        ubico la lista en el siguiente nodo
        agrego el nodoAux a la cola
        acumulo el valor en la variable promedio
        libero el nodoAux para ir eliminando la lista
    }

    imprimo la cantidad de nodos y el promedio de los valores
    retorno la cola
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    nodo *siguiente;
} STR_NODO;

typedef struct queue
{
    STR_NODO *fte;
    STR_NODO *fin;
} STR_QUEUE;

void create(STR_NODO **list);
int count(STR_NODO *listaAux);
STR_NODO *insertInFront(STR_NODO **list, int dato);

STR_QUEUE create();
void add(STR_QUEUE *queue, int valor);

//Funcion del ejercicio
STR_QUEUE pasarListaACola(STR_NODO **list);

int main()
{
    STR_NODO *list;
    create(&list);

    insertInFront(&list, 4);
    insertInFront(&list, 8);
    insertInFront(&list, 12);

    STR_QUEUE queue = create();
    queue = pasarListaACola(&list);

    return 0;
}

void create(STR_NODO **list)
{
    *list = NULL;
}

int count(STR_NODO *listaAux)
{
    int cant = 0;
    while (listaAux != NULL)
    {
        listaAux = listaAux->siguiente;
        cant++;
    }

    return cant;
}

STR_NODO *insertInFront(STR_NODO **list, int dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->siguiente = NULL;

    //insertamos el nuevo nodo en la lista
    nodo->siguiente = *list;
    *list = nodo;
    return nodo;
}

//Funciones de COLAS

STR_QUEUE create()
{
    STR_QUEUE queue;
    queue.fte = NULL;
    queue.fin = NULL;
    return queue;
}

void add(STR_QUEUE *queue, int valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    if (queue->fte == NULL)
    {
        queue->fte = nodo;
    }
    else
    {
        queue->fin->siguiente = nodo;
    }
    queue->fin = nodo;
}

//Funcion del ejercicio

STR_QUEUE pasarListaACola(STR_NODO **list)
{
    STR_QUEUE queue = create();
    STR_NODO *nodoAux;
    int promedio = 0;
    int cantNodos = count(*list); //cuento la cantidad de nodos en la lista

    while (*list != NULL)
    {
        nodoAux = *list;
        *list = (*list)->siguiente;
        add(&queue, nodoAux->dato); //paso a la cola
        promedio += nodoAux->dato;  //acumulo los valores
        free(nodoAux);
    }

    printf("La lista tiene %d nodos.\n", cantNodos); //imprimo la cantidad de nodos

    if (cantNodos != 0) //si la cantidad de nodos sea distinta de 0 para poder realizar la division
    {
        promedio = promedio / cantNodos;
        printf("El promedio de los valores es: %d\n", promedio);
    }
    else
    {
        printf("No se puede dividir entre 0.\n");
    }
    return queue;
}
