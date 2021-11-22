/*Ejercicio 2:

Desarrollar una función que reciba una lista, y devuelva un booleano: TRUE si todos los nodos son distintos, y FALSE si existe alguno duplicado.
Tener en cuenta que:
La lista que se ingresa como parámetro no está ordenada.
Los nodos iguales son aquellos que contienen el mismo valor en dato.
Un nodo se puede repetir N cantidad de veces.

Estrategia
    Creo un nodo para guardar la posicion actual de la lista original
    posiciono la lista original en el siguiente nodo

    mientras la lista original tenga nodos{
        creo una lista auxiliar para recorrer. Inicia en el siguiente valor porque se actualizo la lista previamente
        creo la variable dato que contiene el valor a comparar con el resto de los valores en la lista
        
        mientras la lista auxiliar tenga nodos y el dato sea distinto a los datos de la lista auxiliar{
            me muevo dentro de la lista auxiliar al siguiente nodo
        }

        si salio del while porque no hay mas nodos{
            el nodo a comparar sera ahora el que contiene la lista original, nodo que se habia desplazado ya previamente.
            posiciono la lista original en el siguiente nodo

        } siNo, si salio porque encontro un valor repetido{
            retorna false
        }
    }
    
    retorna true si recorrio toda la lista original sin que se repitieran valores

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    nodo *siguiente;
} STR_NODO;

void create(STR_NODO **list);
STR_NODO *insertInFront(STR_NODO **list, int dato);
void clearList(STR_NODO **list);

//Funcion del ejercicio
bool nodosDistintos(STR_NODO *list);

int main()
{
    STR_NODO *list;
    create(&list);

    insertInFront(&list, 4);
    insertInFront(&list, 5);
    insertInFront(&list, 4);
    insertInFront(&list, 7);

    if (nodosDistintos(list))
    {
        printf("Los nodos son distintos.\n");
    }
    else
    {
        printf("Hay al menos un nodo que se repite.\n");
    }

    clearList(&list);

    return 0;
}

void create(STR_NODO **list)
{
    *list = NULL;
}

STR_NODO *insertInFront(STR_NODO **list, int dato)
{
    //creacion del nodo
    STR_NODO *nodo = (STR_NODO *)(malloc)(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->siguiente = NULL;

    //insertamos el nuevo nodo en la lista
    nodo->siguiente = *list;
    *list = nodo;
    return nodo;
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
        *list = (*list)->siguiente;
        free(nodoAux);
    }
    return;
}

//Funcion del ejercicio
bool nodosDistintos(STR_NODO *list)
{
    STR_NODO *nodoAux;        //creo nodo para guardar la posicion actual en la lista
    nodoAux = list;           //guardo el nodo actual de la lista
    list = (list)->siguiente; //posiciono la lista en el siguiente nodo

    while (list != NULL) //mientras la lista original tenga nodos
    {
        STR_NODO *listAux = list;                        //creo una lista auxiliar que comienza en el nodo siguiente al guardado
        int dato = nodoAux->dato;                        //guardo el valor del nodo actual para comparar
        while (listAux != NULL && listAux->dato != dato) ///mientras la lista auxiliar tenga nodos y el dato no este repetido
        {
            listAux = listAux->siguiente; //me posiciono en el siguiente nodo de la lista
        }

        if (listAux == NULL) //si salio del while porque se termino la lista
        {
            nodoAux = list;           //guardo el nodo actual de la lista
            list = (list)->siguiente; //posiciono la lista en el siguiente nodo
        }
        else if (dato == listAux->dato)
        { //si salio del while por un dato repetido
            return false;
        }
    }

    return true;
}