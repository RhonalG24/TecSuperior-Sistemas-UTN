#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n = 10;
    int *ptrNro = NULL;

    int vector[10];

    char palabra[] = {'H', 'o', 'l', 'a', '\0'};
    char palabra2[] = "Hola"; // char palabra[] = {'H','o','l','a','\0'};
    char *ptrPalabra = palabra;
    printf("%s arranca en la posicion %p", palabra, palabra);

    ptrNro = &n;

    scanf("%d", &n);

    printf("n = %d\n", n);
    printf("Dir. en memoria de n = %p\n", &n);
    printf("Ptro a N = %p, y N vale = %d\n", ptrNro, *ptrNro);

    *ptrNro = 20; //modifica el valor de la variable a la que apunta
    printf("n = %d\n", n);
    return 0;
}