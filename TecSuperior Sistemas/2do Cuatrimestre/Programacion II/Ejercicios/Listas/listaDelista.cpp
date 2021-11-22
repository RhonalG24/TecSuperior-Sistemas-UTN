#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    struct nodo *ste;
} STR_NODO;

typedef struct list
{
    int idLista;
    struct nodo **nodo;
    struct list *steLista;
} STR_LIST;

void create(STR_NODO **list);
STR_NODO *insertInFront(STR_NODO **list, int dato);
STR_NODO *insertAtEnd(STR_NODO **list, int dato);
STR_NODO *insertOrdered(STR_NODO **list, int dato);
STR_NODO *search(STR_NODO *list, int dato);
int deleteFirst(STR_NODO **list);
int deleteNodo(STR_NODO **list, int dato);
void clearList(STR_NODO **list);
void sortList(STR_NODO **list);
STR_NODO *insertWithoutDuplicates(STR_NODO **list, int dato);
void printList(STR_NODO *list);
STR_NODO *insertAt(STR_NODO **list, int dato, int pos);
STR_NODO *readAt(STR_NODO **list, int pos);
bool isEmpty(STR_NODO *lista);
int count(STR_NODO *listaAux);
void apareoLista(STR_NODO **listA, STR_NODO **listB, STR_NODO **listC);

STR_LIST *insertOrderedList(STR_LIST **list, int id);
STR_LIST *searchList(STR_LIST *list, int id);
STR_LIST *insertWithoutDuplicatesList(STR_LIST **list, int id);

int main()
{
    STR_NODO *list;
    create(&list);

    return 0;
}

void create(STR_NODO **list)
{
    *list = NULL;
}

bool isEmpty(STR_NODO *lista)
{
    return lista == NULL;
}

STR_NODO *insertInFront(STR_NODO **list, int dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    //insertamos el nuevo nodo en la lista
    nodo->ste = *list;
    *list = nodo;
    return nodo;
}

STR_NODO *insertAtEnd(STR_NODO **list, int dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    //avanza hasta encontrar el ultimo nodo de la lista
    STR_NODO *listAux = *list;
    while (listAux != NULL && listAux->ste != NULL)
    {
        listAux = listAux->ste;
    }
    //contemplamos el caso en el que la lista este vacia
    if (listAux == NULL)
    {
        *list = nodo;
    }
    else
    {
        //insertamos el nuevo nodo al final de la lista
        listAux->ste = nodo;
    }

    return nodo;
}

/**
 * Inserta un nodo respetando el orden de los datos
*/
STR_NODO *insertOrdered(STR_NODO **list, int dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    //avanza hasta encontrar el nodo mayor respecto del nuevo
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux != NULL && dato < listAux->dato)
    {
        nodoAnt = listAux;
        listAux = listAux->ste;
    }

    if (nodoAnt == NULL)
    {
        *list = nodo;
    }
    else
    {
        nodoAnt->ste = nodo;
    }

    nodo->ste = listAux;

    return nodo;
}

STR_LIST *insertOrderedList(STR_LIST **list, int id)
{
    //creacion del nodo
    STR_LIST *nodo = (STR_LIST *)(malloc)(sizeof(STR_LIST));
    nodo->idLista = id;
    nodo->steLista = NULL;

    //avanza hasta encontrar el nodo mayor respecto del nuevo
    STR_LIST *listAux = *list;
    STR_LIST *nodoAnt = NULL;
    while (listAux != NULL && id < listAux->idLista)
    {
        nodoAnt = listAux;
        listAux = listAux->steLista;
    }

    if (nodoAnt == NULL)
    {
        *list = nodo;
    }
    else
    {
        nodoAnt->steLista = nodo;
    }

    nodo->steLista = listAux;

    return nodo;
}

/**
 *Busca y devuelve el nodo que contiene el valor pasado por parametro 
 * NULL si no lo encuentra
 */
STR_NODO *search(STR_NODO *list, int dato)
{
    STR_NODO *listAux = list;
    while (listAux && listAux->dato != dato)
    {
        listAux = listAux->ste;
    }
    return listAux;
}

STR_LIST *searchList(STR_LIST *list, int id)
{
    STR_LIST *listAux = list;
    while (listAux && listAux->idLista != id)
    {
        listAux = listAux->steLista;
    }
    return listAux;
}

/**
 * Elimina el primer nodo */
int deleteFirst(STR_NODO **list)
{
    STR_NODO *nodoAux = *list;
    *list = (*list)->ste;
    int dato = nodoAux->dato;
    free(nodoAux);
    return dato;
}

/**
 * Elimina el nodo contenedor del dato pasado*/
int deleteNodo(STR_NODO **list, int dato)
{
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux && listAux->dato != dato)
    {
        nodoAnt = listAux;
        listAux = listAux->ste;
    }

    if (nodoAnt == NULL)
    {
        *list = (*list)->ste;
    }
    else
    {
        nodoAnt->ste = listAux->ste;
    }

    dato = listAux->dato;
    free(listAux);
    return dato;
}

/**
 * Vacia la lista
 */
void clearList(STR_NODO **list)
{
    STR_NODO *nodoAux;
    while (*list != NULL)
    {
        nodoAux = *list;
        *list = (*list)->ste;
        free(nodoAux);
    }
    return;
}

/**
 * ordena una lista
 */
void sortList(STR_NODO **list)
{
    int dato;
    STR_NODO *newList;
    while (*list != NULL)
    {
        dato = deleteFirst(list);
        insertOrdered(&newList, dato);
    }

    *list = newList;
    return;
}

/**
 * Inserta un nodo siempre que no exista previamente en la lista.
 * Inserta respetando el orden
 * Devuelve el puntero al nodo encontrado o insertado
 */
STR_NODO *insertWithoutDuplicates(STR_NODO **list, int dato)
{
    STR_NODO *nodo = search(*list, dato);
    if (nodo == NULL)
    {
        nodo = insertOrdered(list, dato);
    }
    return nodo;
}

STR_LIST *insertWithoutDuplicatesList(STR_LIST **list, int id)
{
    STR_LIST *nodo = searchList(*list, id);
    if (nodo == NULL)
    {
        nodo = insertOrderedList(list, id);
    }
    return nodo;
}

/**
 * Imprime sin perder la referencia al primer elemento
 */
void printList(STR_NODO *list)
{
    while (list != NULL)
    {
        printf("Dato: %d\n", list->dato);
        list = list->ste;
    }
    return;
}

/**
 * Inserta en determinada posicion
 */
STR_NODO *insertAt(STR_NODO **list, int dato, int pos)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;

    for (int i = 0; i < pos && *list != NULL; i++)
    {
        nodoAnt = listAux;
        listAux = listAux->ste;
    }

    if (nodoAnt == NULL)
    {
        *list = nodo;
    }
    else
    {
        nodoAnt->ste = nodo;
    }

    nodo->ste = listAux;
    return nodo;
}

/**
 * Lee el elemento de una posicion determinada
 */
STR_NODO *readAt(STR_NODO **list, int pos)
{
    STR_NODO *listAux = *list;
    STR_NODO *nodo = NULL;
    int i = 0;

    while (i < pos && listAux != NULL)
    {
        nodo = listAux;
        listAux = listAux->ste;
        i++;
    }

    if (i < pos && listAux == NULL)
    {
        return NULL;
    }
    return nodo;
}

int count(STR_NODO *listaAux)
{
    int cant = 0;
    while (listaAux != NULL)
    {
        listaAux = listaAux->ste;
        cant++;
    }

    return cant;
}

/**
 * Llena la lista C con los datos de las listas A y B de manera ordena.
 * Destruye las listas A y C
 */
void apareoLista(STR_NODO **listA, STR_NODO **listB, STR_NODO **listC)
{

    while (*listA != NULL && *listB != NULL)
    {
        insertOrdered(listC, deleteFirst(listA));
        insertOrdered(listC, deleteFirst(listB));
    }

    while (*listA != NULL)
    {
        insertOrdered(listC, deleteFirst(listA));
    }

    while (*listB != NULL)
    {
        insertOrdered(listC, deleteFirst(listB));
    }

    return;
}
