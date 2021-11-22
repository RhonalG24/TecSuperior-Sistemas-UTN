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

/**
 * Uso: 
 * char letra;
    letra = leerLetra("Ingrese una letra (o '.' para salir): \n");
 */
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