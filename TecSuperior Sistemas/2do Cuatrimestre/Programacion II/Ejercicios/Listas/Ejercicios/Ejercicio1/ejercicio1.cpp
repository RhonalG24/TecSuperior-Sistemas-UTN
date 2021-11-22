/*
Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros nodos de la pila y deje el valor I como primero. (Definir parámetros y codificar). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **head)
{
    *head = NULL;
}

int main()
{

    STR_NODO *head;
    create(&head);

    return 0;
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

int main()
{
    STR_NODO *pila;
    create(&pila);
    // push(&pila, 1);
    // push(&pila, 2);

    int valor = 0;
    printf("Ingrese el valor I:\n");
    scanf("%d", &valor);

    pop(&pila);
    pop(&pila);
    push(&pila, valor);
    //para vaciar la pila (recorerla)
    //mientras que la pila no este vacia
    while (!isEmpty(pila))
    {
        printf("%d", pop(&pila));
    }

    return 0;
}