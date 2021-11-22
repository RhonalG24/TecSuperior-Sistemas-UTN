#include <stdio.h>

void pedirNumeros(int numeros[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("\n%d) Ingrese un número: ", i + 1);
        scanf("%d", &numeros[i]);
        fflush(stdin);
    }
}

void mostrarNumeros(int numeros[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("%d) %d\n", i, numeros[i]);
    }
}