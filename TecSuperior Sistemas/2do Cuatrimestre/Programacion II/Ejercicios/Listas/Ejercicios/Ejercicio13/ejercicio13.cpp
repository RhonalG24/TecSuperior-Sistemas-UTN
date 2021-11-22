/*-
Dada una cola (nodo = registro + puntero), imprimirla en orden natural si tiene más
de​ ​ 100​ ​ nodos,​ ​ caso​ ​ contrario​ ​ imprimirla​ ​ en​ ​ orden​ ​ inverso.

if (contarNodos(&COLA) > 100){
    while(!isEmpty(COLA)){
        int valor = remove(&COLA);
        add(&COLAUX, valor)
        print(valor)
    }
} else {
    while(!isEmpty(COLA)){
        int valor = remove(&COLA);
        add(&COLAUX, valor);
        push(&pila, valor);
    }
    imprimir(&pila);
}
while(!isEmpty(COLAUX)){    
    add(&COLA, remove(&COLAUX))     
}
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

STR_QUEUE pasarCola(STR_QUEUE *queue);
STR_QUEUE ordenar(STR_QUEUE *original);
STR_QUEUE pasarAlFinalColas(STR_QUEUE *queueA, STR_QUEUE *queueB);

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

void push(STR_NODO **head, int dato)
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

int pop(STR_NODO **head)
{
    int valor = (*head)->dato;
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
void vaciarPila(STR_NODO **pila)
{
    while (!isEmpty(*pila))
    {
        printf("%d\n", pop(pila));
    }
    return;
}

void create(STR_NODO **head)
{
    *head = NULL;
}

int main()
{
    STR_QUEUE queue = create();
    STR_QUEUE queueAux = create();
    STR_NODO *pila;
    create(&pila);

    int valor;

    add(&queue, 1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 4);
    // add(&queue, 5);
    // add(&queue, 6);

    // print(&queue);

    if (contarNodos(&queue) > 5)
    {
        while (!isEmpty(queue))
        {
            valor = remove(&queue);
            add(&queueAux, valor);
            printf("%d\n", valor);
        }
    }
    else
    {
        while (!isEmpty(queue))
        {
            int valor = remove(&queue);
            add(&queueAux, valor);
            push(&pila, valor);
        }
        vaciarPila(&pila);
    }

    while (!isEmpty(queueAux))
    {
        add(&queue, remove(&queueAux));
    }
    // printf("La cola %s esta vacía", isEmpty(queue) ? "" : "NO ");

    return 0;
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
// // para copiar a otra cola mientras se saca de la original
// while(!isEmpty(*queue)){
// // add(&newQueue, remove(queue));
// }

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