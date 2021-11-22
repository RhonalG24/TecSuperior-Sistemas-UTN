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

bool isEmpty(STR_QUEUE queue);
STR_QUEUE create();
void crearVectorDeColas(STR_QUEUE *queue, int cantColas);
void add(STR_QUEUE *queue, int valor);
int remove(STR_QUEUE *queue);
void print(STR_QUEUE *queue);
void printDatos(STR_QUEUE *queue);
int contarNodos(STR_QUEUE *queue);
STR_QUEUE pasarCola(STR_QUEUE *queue);
STR_QUEUE ordenar(STR_QUEUE *original);
STR_QUEUE pasarAlFinalColas(STR_QUEUE *queueA, STR_QUEUE *queueB);
void apareo(STR_QUEUE *queueA, STR_QUEUE *queueB, STR_QUEUE *queueAB);

int main()
{
    STR_QUEUE queue = create();

    add(&queue, 1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 4);

    print(&queue);

    printf("La cola %s esta vacía", isEmpty(queue) ? "" : "NO ");

    return 0;
}

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

/**
 * Crea un vector de colas
 * Se le ingresa la cantidad de colas a crear
 */
void crearVectorDeColas(STR_QUEUE *queue, int cantColas)
{

    for (int i = 0; i < cantColas; i++)
    {
        queue[i] = create();
    }
    return;
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
 * Imprime datos con estructura de una cola 
 */
void printDatos(STR_QUEUE *queue)
{
    Alumno alumno;
    while (!isEmpty(*queue))
    {
        alumno = remove(queue);
        printf("%d\t%s\n", alumno.legajo, alumno.apellidoNombre);
    }
}

/*imprimir dato con estructura
void print(STR_QUEUE *queue) {
    while(!isEmpty(*queue)) {
        STR_DATO dato = remove(queue);
        printf("%d\t%s\n", dato.legajo, dato.apellido);
    }
}*/

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