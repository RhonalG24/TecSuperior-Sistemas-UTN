/*
8. Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y
Nombre de alumnos y los imprima en orden inverso al de ingreso. (Definir
parámetros​ ​ y ​ ​ codificar).

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

    push(&pila, 1);
    // pop(&pila);
    while (!isEmpty(pila))
    {
        printf("%d", pop(&pila));
    }

    return 0;
}