/*

    Variable
        int miVariable = 10

        miVariable >> 10
        &miVariable >> 0x1231546

    Punteros
        ptrMiVariable
        0x1231546 //puntero a miVariable
        0x6542131 //propia direccion en memoria

        int *ptrMiVariable = &miVariable

        ptrMiVariable >> 0x1231546
        *ptrMiVariable >> 10
        &ptrMiVariable >> 0x6542131

    Puntero doble
        ptrAlPtrMiVariable
        0x6542131 //valor.. direccion de memoria de la variable a la que apunta
        5w4658464 //propia direccion en memoria

        int **ptrAlPtrMiVariable = &ptrMiVariable
        ptrAlPtrMiVariable = 0x6542131 = &ptrMiVariable
        *ptrAlPtrMiVariable = 0x1231546 = &miVariable
        **ptrAlPtrMiVariable >> 10
        &ptrAlPtrMiVariable >> 5w4658464

*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int miVariable = 10;
    int *ptrMiVariable = &miVariable;
    int **ptrPtrMiVariable = &ptrMiVariable;

    printf("%p \n", &miVariable);
    printf("%p \n", ptrMiVariable);
    printf("%p \n", *ptrPtrMiVariable);
    printf("%p \n", &(**ptrPtrMiVariable));

    printf("%p \n", miVariable);
    printf("%p \n", *ptrMiVariable);
    printf("%p \n", **ptrPtrMiVariable);

    return 0;
}

/*
en funciones
    funcion normal
        void concatenar(string stringA, string stringB)

        concatenar("hola", miOtroString)

        create(STR_NODO **ptrAPtr)
        create(&ptr)

    
*/