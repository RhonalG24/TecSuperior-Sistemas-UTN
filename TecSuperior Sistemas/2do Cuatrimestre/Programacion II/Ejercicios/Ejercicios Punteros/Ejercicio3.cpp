/*3) Declarar un puntero miPuntero de char[10], asignar dinámicamente espacio en memoria, asignarle
el valor “hola” y luego ...
a) Imprimir por pantalla el puntero con el formateador %s.
b) Imprimir la dirección de memoria del puntero.
c) Imprimir el valor del puntero.
d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
Analice el resultado y concluya.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char *miPuntero[10];
    // char miChar[10] = "hola";
    char *miPuntero = (char *)malloc(sizeof(char) * 10);
    miPuntero = "hola";
    // miPuntero = "hola";

    //a) Imprimir por pantalla el puntero con el formateador %s.
    printf("puntero con el formateador s = %s\n", miPuntero);

    //b) Imprimir la dirección de memoria del puntero.
    printf("dirección de memoria del puntero = %p\n", &miPuntero);

    //c) Imprimir el valor del puntero.
    printf("valor del puntero = %s\n", miPuntero);

    //d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
    printf("dirección de memoria miPuntero[0] = %p\n", &miPuntero[0]);

    //e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
    // Analice el resultado y concluya.
    printf("valor miPuntero[0] = %s\n", &miPuntero[0]);
    miPuntero++;
    printf("Uso miPuntero++\nvalor miPuntero[0] = %s\n", &miPuntero[0]);

    free(miPuntero);
    return 0;
}

/*Cuando en printf usamos %s nos pasa directamente el valor sin desreferenciar (sin necesidad del *) */