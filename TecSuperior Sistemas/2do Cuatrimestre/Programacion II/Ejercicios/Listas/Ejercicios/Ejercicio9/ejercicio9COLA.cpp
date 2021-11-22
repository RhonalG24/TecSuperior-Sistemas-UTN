/*
9. Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
de​ ​ sus​ ​ nodos​ ​ y ​ ​ la​ ​ retorne.​ ​ Solo​ ​ se​ ​ deben​ ​ usar​ ​ colas.​ ​ (Definir​ ​ parámetros​ ​ y ​ ​ codificar).

*/

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

STR_QUEUE ordenar(STR_QUEUE *original)
{
    STR_QUEUE queueOrd = create();
    STR_QUEUE queueCand = create();
    STR_QUEUE queueAux = create();

    int numOriginal;
    int numCand;

    while (!isEmpty(*original))
    {
        numOriginal = remove(original);
        add(&queueCand, numOriginal);

        while (!isEmpty(*original))
        {
            numOriginal = remove(original);
            numCand = remove(&queueCand);

            if (numCand <= numOriginal)
            {
                add(&queueCand, numCand);
                add(&queueAux, numOriginal);
            }
            else
            {
                add(&queueCand, numOriginal);
                add(&queueAux, numCand);
            }
        }
        numCand = remove(&queueCand);
        add(&queueOrd, numCand);

        *original = pasarCola(&queueAux);
    }

    return queueOrd;
}

int main()
{
    STR_QUEUE queueOriginal = create();
    STR_QUEUE queueOrd = create();

    add(&queueOriginal, 5);
    add(&queueOriginal, 9);
    add(&queueOriginal, 2);
    add(&queueOriginal, 15);

    queueOrd = ordenar(&queueOriginal);
    print(&queueOrd);

    // printf("La cola %s esta vacía", isEmpty(queueOrd) ? "" : "NO ");

    return 0;
}
