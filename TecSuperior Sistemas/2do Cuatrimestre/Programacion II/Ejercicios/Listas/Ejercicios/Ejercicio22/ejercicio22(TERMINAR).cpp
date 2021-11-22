/*
. Dadas dos listas LISTA y LISTB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere otra lista LISTC por apareo del campo LEGAJO del
registro (define orden creciente en ambas). Nota: LISTA y LISTB dejan de ser útiles
después​ ​ del​ ​ apareo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;

} Registro;

typedef struct nodo
{
    Registro dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **list)
{
    *list = NULL;
}

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

void leer(const char *msg, const char *formato, void *variable)
{
    printf(msg);
    scanf(formato, variable);
    discardChars();
    return;
}

void leerString(const char *msg, int limite, char *variable)
{

    printf("%s", msg);
    scanf("%[^\n]s", variable);
    discardChars();

    while (strlen(variable) > limite)
    {
        printf("\nDebe contener como máximo %d carácteres.\n\n", limite);
        printf("%s", msg);
        scanf("%[^\n]s", variable);
        discardChars();
    }
    return;
}

STR_NODO *insertInFront(STR_NODO **list, Registro dato);
STR_NODO *insertAtEnd(STR_NODO **list, Registro dato);
STR_NODO *insertOrdered(STR_NODO **list, Registro dato);
STR_NODO *search(STR_NODO *list, Registro dato);
Registro deleteFirst(STR_NODO **list);
Registro deleteNodo(STR_NODO **list, Registro dato);
void clearList(STR_NODO **list);
void sortList(STR_NODO **list);
STR_NODO *insertWithoutDuplicates(STR_NODO **list, Registro dato);
void printList(STR_NODO *list);
STR_NODO *insertAt(STR_NODO **list, Registro dato, int pos);
STR_NODO *readAt(STR_NODO **list, int pos);
void apareoLista(STR_NODO **listA, STR_NODO **listB, STR_NODO **listC);

void llenarLista(STR_NODO **list)
{
    Registro aux;
    leer("Ingrese un numero (-1 para terminar)\n", "%d", &aux.legajo);

    while (aux.legajo != -1)
    {

        insertInFront(list, aux);
        leer("Ingrese un numero (-1 para terminar)\n", "%d", &aux.legajo);
    }
}

int main()
{
    STR_NODO *listA;
    STR_NODO *listB;
    create(&listA);

    llenarLista(&listA);

    create(&listB);
    llenarLista(&listB);

    STR_NODO *listC;
    create(&listC);

    apareoLista(&listA, &listB, &listC);
    printList(listC);

    return 0;
}

STR_NODO *insertInFront(STR_NODO **list, Registro dato)
{
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato.legajo = dato.legajo;
    nodo->ste = NULL;

    nodo->ste = *list;
    *list = nodo;
    return nodo;
}

STR_NODO *insertAtEnd(STR_NODO **list, Registro dato)
{
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato.legajo = dato.legajo;
    nodo->ste = NULL;

    STR_NODO *listAux = *list;
    while (listAux != NULL && listAux->ste != NULL)
    {
        listAux = listAux->ste;
    }

    if (listAux == NULL)
    {
        *list = nodo;
    }
    else
    {
        listAux->ste = nodo;
    }

    return nodo;
}

STR_NODO *insertOrdered(STR_NODO **list, Registro dato)
{
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato.legajo = dato.legajo;
    nodo->ste = NULL;

    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux != NULL && dato.legajo < listAux->dato.legajo)
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

STR_NODO *search(STR_NODO *list, Registro dato)
{
    STR_NODO *listAux = list;
    while (listAux && listAux->dato.legajo != dato.legajo)
    {
        listAux = listAux->ste;
    }
    return listAux;
}

/**
 * Elimina el primer nodo */
Registro deleteFirst(STR_NODO **list)
{
    STR_NODO *nodoAux = *list;
    *list = (*list)->ste;
    Registro dato = nodoAux->dato;
    free(nodoAux);
    return dato;
}

/**
 * Elimina el nodo contenedor del dato.legajo pasado*/
Registro deleteNodo(STR_NODO **list, Registro dato)
{
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux != NULL && listAux->dato.legajo != dato.legajo)
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

void sortList(STR_NODO **list)
{
    Registro dato;
    STR_NODO *newList;
    while (*list != NULL)
    {
        dato = deleteFirst(list);
        insertOrdered(&newList, dato);
    }

    *list = newList;
    return;
}

STR_NODO *insertWithoutDuplicates(STR_NODO **list, Registro dato)
{
    STR_NODO *nodo = search(*list, dato);
    if (nodo == NULL)
    {
        nodo = insertOrdered(list, dato);
    }
    return nodo;
}

void printList(STR_NODO *list)
{
    while (list != NULL)
    {
        printf("dato.legajo: %d\n", list->dato.legajo);
        list = list->ste;
    }
    return;
}

STR_NODO *insertAt(STR_NODO **list, Registro dato, int pos)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato.legajo = dato.legajo;
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