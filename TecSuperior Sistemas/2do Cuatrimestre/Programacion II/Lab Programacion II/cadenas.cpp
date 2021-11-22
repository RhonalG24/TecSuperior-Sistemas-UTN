#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarLetras(char palabra[])
{
    int cant = 0;

    while (palabra[cant] != '\0')
    {
        cant++;
    }

    return cant;
}

int main()
{
    char palabra[100] = "hola"; //alamcena 99 letras porque el último es '\0'
    printf("La palabra %s tiene %d letras .\n Con strlen = %d\n", palabra, contarLetras(palabra), strlen(palabra));
    return 0;
}
