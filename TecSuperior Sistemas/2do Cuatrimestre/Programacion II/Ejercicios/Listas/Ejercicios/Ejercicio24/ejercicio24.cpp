/*
24. Dado un archivo de registros de alumnos ARCHA sin ningún orden donde cada
registro contiene: a) Apellido y Nombre del alumno (34 caracteres) b) Número de
legajo (6 dígitos) c) División asignada (3 dígitos) Se debe desarrollar el algoritmo y
codificación del programa que imprima el listado de alumnos por división ordenado
por​ ​ división​ ​ y ​ ​ número​ ​ de​ ​ legajo​ ​ crecientes,​ ​ a ​ ​ razón​ ​ de​ ​ 55​ ​ alumnos​ ​ por​ ​ hoja.
*/

/*
abrir archivo

lista por division, recorro el archivo e ingreso en la lista ordenando por legajo
contador de registros = 0
leer archivo
!FEOF{
    contador de registros++
    insertarOrdenado()

    leer archivo
}

para imprimir, 

cerrar archivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char apellidoNombre[35];
    int legajo;
    int division;
} Alumno; //archivo sin orden

typedef struct nodo
{
    Alumno dato;
    struct nodo *ste;
} STR_NODO;

typedef struct division
{
    int division;
    struct nodo **list;
    struct division *ste;
} STR_NODO_DIVISION;

void create(STR_NODO **list);
bool isEmpty(STR_NODO *lista);
STR_NODO *insertInFront(STR_NODO **list, Alumno dato);
STR_NODO *insertAtEnd(STR_NODO **list, Alumno dato);
STR_NODO *insertOrdered(STR_NODO **list, Alumno dato);
STR_NODO_DIVISION *insertOrderedDivision(STR_NODO_DIVISION **list, int dato);
STR_NODO *search(STR_NODO *list, Alumno dato);
STR_NODO_DIVISION *searchDivision(STR_NODO_DIVISION *list, int dato);
void clearList(STR_NODO **list);
void sortList(STR_NODO **list);
STR_NODO_DIVISION *insertWithoutDuplicatesDivision(STR_NODO_DIVISION **list, int dato);
void printList(STR_NODO *list);
STR_NODO *readAt(STR_NODO **list, int pos);
int count(STR_NODO *listaAux);
void apareoLista(STR_NODO **listA, STR_NODO **listB, STR_NODO **listC);
int deleteFirst(STR_NODO_DIVISION **list);

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
void leer(int pos, Alumno *registro, FILE *file);

int main()
{
    STR_NODO_DIVISION **listDivision;
    listDivision = NULL;

    FILE *ptrAlumnosDat = abrirArchivo("ARCHA.DAT", "rb");

    Alumno alumno;

    fread(&alumno, sizeof(Alumno), 1, ptrAlumnosDat);
    while (!feof(ptrAlumnosDat))
    {
        int div = alumno.division;
        STR_NODO_DIVISION *nodoDiv = insertWithoutDuplicatesDivision(listDivision, alumno.division);
        fread(&alumno, sizeof(Alumno), 1, ptrAlumnosDat);
    }

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

STR_NODO *insertInFront(STR_NODO **list, Alumno dato)
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

STR_NODO *insertAtEnd(STR_NODO **list, Alumno dato)
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
STR_NODO *insertOrdered(STR_NODO **list, Alumno dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    //avanza hasta encontrar el nodo mayor respecto del nuevo
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

STR_NODO_DIVISION *insertOrderedDivision(STR_NODO_DIVISION **list, int dato)
{
    //creacion del nodo
    STR_NODO_DIVISION *nodo = (STR_NODO_DIVISION *)(malloc)(sizeof(STR_NODO_DIVISION));
    nodo->division = dato;
    nodo->ste = NULL;

    //avanza hasta encontrar el nodo mayor respecto del nuevo
    STR_NODO_DIVISION *listAux = *list;
    STR_NODO_DIVISION *nodoAnt = NULL;
    while (listAux != NULL && dato < listAux->division)
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
 *Busca y devuelve el nodo que contiene el valor pasado por parametro 
 * NULL si no lo encuentra
 */
STR_NODO *search(STR_NODO *list, Alumno dato)
{
    STR_NODO *listAux = list;
    while (listAux && listAux->dato.legajo != dato.legajo)
    {
        listAux = listAux->ste;
    }
    return listAux;
}

STR_NODO_DIVISION *searchDivision(STR_NODO_DIVISION *list, int dato)
{
    STR_NODO_DIVISION *listAux = list;
    while (listAux != NULL && listAux->division != dato)
    {
        listAux = listAux->ste;
    }
    return listAux;
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

Alumno deleteFirst(STR_NODO **list)
{
    STR_NODO *nodoAux = *list;
    *list = (*list)->ste;
    Alumno dato = nodoAux->dato;
    free(nodoAux);
    return dato;
}

int deleteFirst(STR_NODO_DIVISION **list)
{
    STR_NODO_DIVISION *nodoAux = *list;
    *list = (*list)->ste;
    int dato = nodoAux->division;
    free(nodoAux);
    return dato;
}

/**
 * ordena una lista
 */
void sortList(STR_NODO **list)
{
    Alumno dato;
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
STR_NODO_DIVISION *insertWithoutDuplicatesDivision(STR_NODO_DIVISION **list, int dato)
{
    STR_NODO_DIVISION *nodo = searchDivision(*list, dato);
    if (nodo == NULL)
    {
        nodo = insertOrderedDivision(list, dato);
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

FILE *abrirArchivo(const char *nombreArchivo, const char *modo)
{
    FILE *ptrArchivo = fopen(nombreArchivo, modo);
    if (ptrArchivo == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s", nombreArchivo);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Archivo %s encontrado!\n", nombreArchivo);
    }

    return ptrArchivo;
}

/**
 * Lee el registro en la posicion especificada
 */
void leer(int pos, Alumno *registro, FILE *file)
{
    fseek(file, sizeof(Alumno) * pos, SEEK_SET);
    fread(registro, sizeof(Alumno), 1, file);
    return;
}
