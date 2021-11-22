/*
Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere una única cola COLAB a partir de ellas. (Primero los
nodos​ ​ de​ ​ COLA​ ​ y ​ ​ luego​ ​ los​ ​ de​ ​ COLB).
*/

// mientras no se acabe a
//     metemos en c
// int valor = remove(&colaA);
// add(&colaC, valor);

// mientras no se acabe b
//     metemos en c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    nodo *ste;
} STR_NODO;

typedef struct queue
{
    STR_NODO *fte;
    STR_NODO *fin;
} STR_QUEUE;

bool isEmpty(STR_QUEUE queue)
{
    return queue.fte == NULL && queue.fin == NULL;
}

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

int remove(STR_QUEUE *queue)
{
    STR_NODO *aux = queue->fte;
    int valor = queue->fte->dato;
    queue->fte = queue->fte->ste;

    if (queue->fte == NULL)
    {
        queue->fin = NULL;
    }

    free(aux);
    return valor;
}

void print(STR_QUEUE *queue)
{
    while (!isEmpty(*queue))
    {
        printf("%d\n", remove(queue));
    }
}

/**
 * Pasa el contenido de la cola pasada por parametro a una nueva.
 * En funcion: *newQueue = pasarCola(&queue)
 * Destruye la cola
 */
STR_QUEUE pasarCola(STR_QUEUE *queue)
{
    STR_QUEUE newQueue = create();
    int value;
    while (!isEmpty(*queue))
    {
        value = remove(queue);
        add(&newQueue, value);
    }
    return newQueue;
}

/**
 * Pasa los valores de cola A y luego los de cola b a una cola C
 * En el main: colaC = pasarAlFinalColas(&colaA, &colaB)
 * No destruye las colas A y B
 * */
STR_QUEUE pasarAlFinalColas(STR_QUEUE *queueA, STR_QUEUE *queueB)
{
    STR_QUEUE newQueue = create();
    STR_QUEUE queueAux = create();
    int value;

    while (!isEmpty(*queueA))
    {
        value = remove(queueA);
        add(&newQueue, value);
        add(&queueAux, value);
    }
    *queueA = pasarCola(&queueAux);

    while (!isEmpty(*queueB))
    {
        value = remove(queueB);
        add(&newQueue, value);
        add(&queueAux, value);
    }
    *queueB = pasarCola(&queueAux);

    return newQueue;
}

int main()
{
    STR_QUEUE queueA = create();
    STR_QUEUE queueB = create();

    add(&queueA, 1);
    add(&queueA, 2);
    add(&queueA, 3);
    add(&queueB, 4);
    add(&queueB, 5);
    add(&queueB, 6);

    STR_QUEUE queueC;

    queueC = pasarAlFinalColas(&queueA, &queueB);

    print(&queueC);

    // printf("La cola %sesta vacía.\n", isEmpty(queueC) ? "" : "NO ");

    // print(&queueB);
    // print(&queueA);

    return 0;
}

// // para copiar a otra cola mientras se saca de la original
// while(!isEmpty(*queue)){
// // add(&newQueue, remove(queue));
// }
