/*
9. Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
de​ ​ sus​ ​ nodos​ ​ y ​ ​ la​ ​ retorne.​ ​ Solo​ ​ se​ ​ deben​ ​ usar​ ​ pilas.​ ​ (Definir​ ​ parámetros​ ​ y ​ ​ codificar).

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

int leer(const char *msg)
{
    int valor;
    printf(msg);
    scanf("%d", &valor);
    return valor;
}

void llenarPila(STR_NODO **pila)
{
    int num = leer("Ingrese un numero (0 para salir): \n");
    while (num != 0)
    {
        push(pila, num);
        num = leer("Ingrese un numero (0 para salir): \n");
    }
    return;
}

void vaciarPila(STR_NODO **pila)
{
    while (!isEmpty(*pila))
    {
        printf("%d\n", pop(pila));
    }
    return;
}

void pasarDePila(STR_NODO **pila, STR_NODO **nvaPila);

void ordenarPila(STR_NODO **pila);

int main()
{

    STR_NODO *pila;
    create(&pila);

    llenarPila(&pila);

    ordenarPila(&pila);
    vaciarPila(&pila);

    // push(&pila, 1);
    // // pop(&pila);
    // while (!isEmpty(pila))
    // {
    //     printf("%d", pop(&pila));
    // }

    return 0;
}

void pasarDePila(STR_NODO **pila, STR_NODO **nvaPila)
{
    int num;
    while (!isEmpty(*pila))
    {
        num = pop(pila);
        push(nvaPila, num);
    }
    return;
}

void ordenarPila(STR_NODO **pila)
{
    STR_NODO *pilaAux;
    create(&pilaAux);

    bool ordenado = false;
    int num, aux;
    while (!ordenado)
    {
        ordenado = true;
        if (!isEmpty(*pila))
        {
            num = pop(pila);
            aux = pop(pila);
        }
        while (!isEmpty(*pila))
        {

            if (num <= aux)
            {
                push(&pilaAux, num);
                num = aux;
                aux = pop(pila);
            }
            else
            {
                ordenado = false;

                push(&pilaAux, aux);
                aux = pop(pila);
            }
        }

        push(&pilaAux, num);
        pasarDePila(&pilaAux, pila);
    }
    return;
}