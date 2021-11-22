#include <iostream>
#include <stdio.h>

void pedirNumeros(int &numeroAlto, int &numeroBajo, int &promedio, int &cantNumeros)
{
    int numero;
    char opcion;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    numeroAlto = numero;
    numeroBajo = numero;

    printf("¿Desea ingresar otro número? 's' para si ó 'e' para terminar: ");
    scanf("%s", &opcion);
    fflush(stdin);

    while (opcion != 'e')
    {
        printf("Ingrese un número: ");
        scanf("%d", &numero);
        fflush(stdin);

        cantNumeros++;

        if (numero > numeroAlto)
        {
            numeroAlto = numero;
        }

        if (numero < numeroBajo)
        {
            numeroBajo = numero;
        }

        promedio += numero;

        printf("¿Desea ingrese otro número? Si no, ingrese 'e': ");
        scanf("%s", &opcion);
        fflush(stdin);
    }
    return;
}