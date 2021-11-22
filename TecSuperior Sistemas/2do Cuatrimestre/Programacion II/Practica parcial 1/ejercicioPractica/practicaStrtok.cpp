
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char cadena[50] = {"esta,es,mi,cadena"};
    char copia[50];
    strcpy(copia, cadena);

    // printf("%s\n", cadena);
    printf("%s\n", strtok(copia, ","));
    printf("%s\n", strtok(NULL, ","));

    printf("%s\n", strtok(NULL, ","));

    printf("%s\n", strtok(NULL, ","));

    // printf("%s\n", strtok(NULL, ","));

    return 0;
}