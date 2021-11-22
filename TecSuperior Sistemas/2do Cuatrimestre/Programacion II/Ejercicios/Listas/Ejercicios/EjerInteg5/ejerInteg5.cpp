/*Ejercicio 5
Una facultad requiere de una pieza de software que le permita gestionar a los alumnos
inscriptos.
La universidad cuenta actualmente con 1000 alumnos, de cada uno posee los siguientes
datos:
● Legajo, 7 caracteres
● Carrera: 1 caracter
● Nombre, 30 caracteres
● Apellido, 30 caracteres
● Email, 30 caracteres
● Teléfono, 10 caracteres

El legajo es un número entero entre 1000 y 2000.

Las carreras están nomencladas según el siguiente listado
● K, ingeniería en sistemas
● C, ingeniería civil
● P ingeniería electrónica
● D ingeniería mecánica

Los datos antes mencionados se encuentran almacenados en el archivo ​ alumnes.dat
Los datos de las carreras se encuentran almacenados en el archivo ​ carreras.txt, donde
además del código se encuentra el nombre y descripción de la carrera.

Por otra parte, la facultad posee las notas de cada materia de los alumnos en distintos
archivos, uno por cada materia. El nombre de cada archivo indica la materia.
Estos archivos poseen el número, fecha de cada parcial y el legajo de cada alumno. Tener en
cuenta que estos archivos se encuentran desordenados y que sólo hay 2 parciales por cada
alumno.

Se pide:

1. Imprimir el archivo de notas de forma ordenada, utilizando el legajo como criterio.
Restricción: sólo puede ser recorrido secuencialmente 1 vez.
2. Calcular y guardar el promedio de las notas de los alumnos, ordenado por legajo de
forma ascendente. Restricción: sólo posee 8000 bytes de espacio en disco.

Estrategia
archivos alumnes.dat y carreras.txt, archivo nombreMateria.dat

para imprimir lo del 1, recorrer el archivos de notas y guardar en una lista ordenada por legajo


para el segundo, guardar en otra lista solo el promedio y legajo del alumno dado que solo hay 8mil bytes disponibles (legajo: 4bytes, promedio: 4bytes * 1000 alumnos)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char carrera;
    char nombre[31];
    char apellido[31];
    char email[31];
    char telefono[11];
} Alumno;

typedef struct
{
    int nroParcial;
    int fechaParcial;
    int legajo;
} Nota;

typedef struct
{
    float promedio;
    int legajo;
} Promedio;

typedef struct nodo
{
    Nota dato;
    struct nodo *ste;
} STR_NODO;

typedef struct nodoPromedio
{
    Promedio dato;
    struct nodoPromedio *ste;
} STR_NODO_PROMEDIO;

int main()
{
    STR_NODO *list;
    create(&list);

    FILE *ptrNotasDat = abrirArchivo("IngenieriaCivil.dat", "rb");

    Nota nota;

    fread(&nota, sizeof(Nota), 1, ptrNotasDat);
    while (!feof(ptrNotasDat))
    {
        insertOrdered(&list, nota);
        fread(&nota, sizeof(Nota), 1, ptrNotasDat);
    }

    printList(list);

    fclose(ptrNotasDat);

    return 0;
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

////////////////////////        Listas

void create(STR_NODO **list)
{
    *list = NULL;
}

bool isEmpty(STR_NODO *lista)
{
    return lista == NULL;
}

STR_NODO *insertInFront(STR_NODO **list, Nota dato)
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

STR_NODO *insertAtEnd(STR_NODO **list, Nota dato)
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
STR_NODO *insertOrdered(STR_NODO **list, Nota dato)
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

/**
 *Busca y devuelve el nodo que contiene el valor pasado por parametro 
 * NULL si no lo encuentra
 */
STR_NODO *search(STR_NODO *list, Nota dato)
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
Nota deleteFirst(STR_NODO **list)
{
    STR_NODO *nodoAux = *list;
    *list = (*list)->ste;
    Nota dato = nodoAux->dato;
    free(nodoAux);
    return dato;
}

/**
 * Elimina el nodo contenedor del dato pasado*/
Nota deleteNodo(STR_NODO **list, Nota dato)
{
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux && listAux->dato.legajo != dato.legajo)
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
    Nota dato;
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
STR_NODO *insertWithoutDuplicates(STR_NODO **list, Nota dato)
{
    STR_NODO *nodo = search(*list, dato);
    if (nodo == NULL)
    {
        nodo = insertOrdered(list, dato);
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

void guardarPromedios(STR_NODO *list, STR_NODO_PROMEDIO *listPromedio)
{
    listPromedio->dato.legajo = list->dato.legajo;
    Promedio promedio;
    promedio.promedio = 0;
    while (list != NULL)
    {
        promedio.promedio = list->dato.nroParcial;
        printf("Dato: %d\n", list->dato);
        list = list->ste;
    }
    return;
}

/**
 * Inserta en determinada posicion
 */
STR_NODO *insertAt(STR_NODO **list, Nota dato, int pos)
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