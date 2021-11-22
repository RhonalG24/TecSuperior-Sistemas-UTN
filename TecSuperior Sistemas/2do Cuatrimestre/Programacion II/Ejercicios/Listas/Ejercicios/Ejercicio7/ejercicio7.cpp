/*
Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por
un punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si
no lo son. Los conjuntos deben ingresarse por teclado. (Definir parámetros y
codificar).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char dato;
    struct nodo *ste;
} STR_NODO;

void create(STR_NODO **head)
{
    *head = NULL;
}

void push(STR_NODO **head, char dato)
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

char leerLetra(char const *msg)
{
    char letra;
    printf("%s\n", msg);
    scanf(" %c", &letra);
    return letra;
}

bool inversa(STR_NODO **pila)
{
    char letra;
    char elemento;

    letra = leerLetra("Ingrese una letra (o '.' para salir): \n");

    while (letra != '.')
    {
        push(pila, letra);
        letra = leerLetra("Ingrese una letra (o '.' para salir): \n");
    }

    letra = leerLetra("Ingrese una letra (o '.' para salir): \n");
    elemento = pop(pila);

    while (*pila != NULL && elemento == letra)
    {
        letra = leerLetra("Ingrese una letra (o '.' para salir): \n");
        elemento = pop(pila);
    }

    return letra == elemento;
}

int main()
{

    STR_NODO *pila;
    create(&pila);

    if (inversa(&pila))
    {
        printf("Es inversa.\n");
    }
    else
    {
        printf("No es inversa.\n");
    }

    return 0;
}