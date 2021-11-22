// Dada una cola (nodo = registro + puntero), desarrollar y codificar una función que
// devuelva​ ​ la​ ​ cantidad​ ​ de​ ​ nodos​ ​ que​ ​ tiene.

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
 */
STR_QUEUE pasarCola(STR_QUEUE *queue)
{
    STR_QUEUE newQueue = create();
    int value;
    while (!isEmpty(*queue))
    {
        value = remove(queue);
        add(&newQueue, value);

        // // para copiar a otra cola mientras se saca de la original
        // while(!isEmpty(*queue)){
        // // add(&newQueue, remove(queue));
        // }
    }
    return newQueue;
}

int contarNodos(STR_QUEUE *queue)
{
    STR_QUEUE newQueue = create();
    int value;
    int cantNodos = 0;
    while (!isEmpty(*queue))
    {
        cantNodos++;
        value = remove(queue);
        add(&newQueue, value);
    }

    *queue = pasarCola(&newQueue);
    return cantNodos;
}

int main()
{
    STR_QUEUE queue = create();

    add(&queue, 1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 4);

    int cantNodos = contarNodos(&queue);
    printf("La cola tiene %d nodos.\n\n", cantNodos);
    print(&queue);

    printf("La cola %sesta vacía.\n", isEmpty(queue) ? "" : "NO ");

    return 0;
}
