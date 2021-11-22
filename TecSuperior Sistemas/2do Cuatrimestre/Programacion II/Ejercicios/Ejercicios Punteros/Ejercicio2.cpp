/*
2) Declarar una variable que sea puntero a un número entero y luego ...
a)
Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c)
Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 10;

    int *ptrNumero = NULL;

    ptrNumero = &numero;

    printf("Direccion de numero = %p\n", ptrNumero);
    printf("Direccion del puntero = %p\n", &ptrNumero);
    printf("Valor de numero = %d\n", *ptrNumero);

    ptrNumero = (int *)malloc(sizeof(int));

    printf("Direccion de numero = %p\n", ptrNumero);
    printf("Valor del puntero = %p\n", &ptrNumero);
    printf("Valor que se encuentra en el espacio = %d\n", *ptrNumero);

    free(ptrNumero);

    printf("Direccion de numero = %p\n", ptrNumero);
    printf("Valor del puntero = %p\n", &ptrNumero);
    printf("Valor que se encuentra en el espacio = %d\n", *ptrNumero);

    return 0;
}