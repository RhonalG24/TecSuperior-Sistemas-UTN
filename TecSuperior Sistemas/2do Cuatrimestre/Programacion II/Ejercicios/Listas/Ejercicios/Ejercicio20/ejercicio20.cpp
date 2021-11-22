/* 20. Dadas dos listas LISTA y LISTB (nodo = registro + puntero), desarrollar y codificar un procedimiento que genere una única lista LISTC a partir de ellas. (Primero los nodos de LISTA y luego los de LISTB). */
#include <iostream>
#include <stdio.h>

typedef struct nodo
{
    int dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **list)
{
    *list = NULL;
}

void push(STR_NODO **list, int dato)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;
    nodo->ste = *list;
    *list = nodo;
}
int main(int argc, char const *argv[])
{
    struct nodo *listA;
    create(&listA);
    push(&listA, 5);
    push(&listA, 4);
    push(&listA, 125);
    push(&listA, 7);
    push(&listA, 43);
    push(&listA, 12);

    struct nodo *listB;
    create(&listB);
    push(&listB, 321);
    push(&listB, 421);
    push(&listB, 521);
    push(&listB, 621);
    push(&listB, 721);

    struct nodo *listC;

    create(&listC);
    struct nodo *listaAux = listB;

    while (listaAux != NULL)
    {
        push(&listC, listaAux->dato);
        listaAux = listaAux->ste;
    }

    listaAux = listA;

    while (listaAux != NULL)
    {
        push(&listC, listaAux->dato);
        listaAux = listaAux->ste;
    }

    listaAux = listC;

    while (listaAux != NULL)
    {
        printf("%d", listaAux->dato);
        listaAux = listaAux->ste;
    }
    return 0;
}