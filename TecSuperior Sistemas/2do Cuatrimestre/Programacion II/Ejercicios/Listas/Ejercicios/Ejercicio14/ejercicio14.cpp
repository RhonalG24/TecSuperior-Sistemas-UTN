/*
Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere otra cola COLAB por apareo del campo ARRIBO del registro (define orden creciente en ambas). Nota: COLA y COLB dejan de ser útiles
después​ ​ del​ ​ apareo.
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

/**
 * Apareo de colas
 * Destruye las colas A y B
 */
void apareo(STR_QUEUE *queueA, STR_QUEUE *queueB, STR_QUEUE *queueAB)
{

    while (!isEmpty(*queueA) && !isEmpty(*queueB))
    {
        if (queueA->fte->dato < queueB->fte->dato)
        {
            add(queueAB, remove(queueA));
        }
        else
        {
            add(queueAB, remove(queueB));
        }
    }

    while (!isEmpty(*queueA))
    {
        add(queueAB, remove(queueA));
    }

    while (!isEmpty(*queueB))
    {
        add(queueAB, remove(queueB));
    }

    return;
}

// void apareo(STR_QUEUE *queueA, STR_QUEUE *queueB, STR_QUEUE *queueC)
// {
//     int valA, valB;
//     if (!isEmpty(*queueA))
//     {
//         valA = remove(queueA);
//     }
//     if (!isEmpty(*queueB))
//     {
//         valB = remove(queueB);
//     }

//     while (!isEmpty(*queueA) && !isEmpty(*queueB))
//     {
//         if (valA <= valB)
//         {
//             add(queueC, valA);
//             valA = remove(queueA);
//         }
//         else
//         {
//             add(queueC, valB);
//             valB = remove(queueB);
//         }
//     }

//     if (isEmpty(*queueA))
//     {
//         add(queueC, valA);
//     }
//     while (!isEmpty(*queueA))
//     {
//         add(queueC, remove(queueA));
//     }

//     if (isEmpty(*queueB))
//     {
//         add(queueC, valB);
//     }
//     while (!isEmpty(*queueB))
//     {
//         add(queueC, valB);
//         add(queueC, remove(queueB));
//     }
// }

int main()
{
    STR_QUEUE queueA = create();
    STR_QUEUE queueB = create();
    STR_QUEUE queueAB = create();

    add(&queueA, 1);
    add(&queueA, 3);
    add(&queueA, 7);
    add(&queueA, 11);

    add(&queueB, 2);
    add(&queueB, 4);
    add(&queueB, 5);
    add(&queueB, 10);

    apareo(&queueA, &queueB, &queueAB);

    print(&queueAB);
    print(&queueA);
    print(&queueB);

    // printf("La cola %s esta vacía", isEmpty(queue) ? "" : "NO ");

    return 0;
}

/**
 * Pasa el contenido de la cola pasada por parametro a una nueva.
 * En funcion: *newQueue = pasarCola(&queue)
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
// // para copiar a otra cola mientras se saca de la original
// while(!isEmpty(*queue)){
// // add(&newQueue, remove(queue));
// }
