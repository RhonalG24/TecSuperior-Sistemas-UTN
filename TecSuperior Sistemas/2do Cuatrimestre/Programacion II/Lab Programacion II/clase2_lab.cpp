/*
PUNTEROS

Variable que contiene una direcci´on de memoria


*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int miVariable = 45;

    //Con & en el argumeto le pasamos la direccion en memoria de la variable
    //pasameUnPuntero(&miVariable) return 0;
    //o directamente &miVariable

    //para declarar puntero
    int *miPuntero = NULL;

    //int *miPtr es distinto a *miPtr

    //con *miPtr obtengo el contenido de la direccion

    int *otroPuntero = &miVariable;

    int miArray[3];

    int *miArrayPrimerPosicion = NULL;
    miArrayPrimerPosicion = miArray; //obtengo el puntero a la primera posicion del array = 0x7ffd231c7830
    int *ptrSegundaPosicion = NULL;
    ptrSegundaPosicion = miArray + 1; //obtengo la segunda posicion de array = 0x7ffd231c7834

    cout << miArrayPrimerPosicion << endl;

    cout << ptrSegundaPosicion << endl;

    printf("%p\n", miArrayPrimerPosicion);      //imprime la primera posicion
    printf("%d\n", *miArrayPrimerPosicion);     //imprime el contenido de la primera posicion
    printf("%d\n", *miArrayPrimerPosicion + 1); //imprime el contenido de la segunda posicion

    // puntero constante: (señalo siempre al mismo sitio, el carro señalado puede cambiar)
    //char *const valor;

    //puntero a constante: (el carro no lo puedo cambiar pero si puedo cambiar hacia donde señala) restringe el uso que se le da al puntero
    //no puede cambiarle el valor
    //const char *valor

    /* CADENAS */

    /*  Vector de Caracteres
            Para declararlo: 3 maneras distintas

            1.- char palabra[] = "hola mundo"; //Asigna automaticamente la longitud del vector. Son 11 posiciones, el ultimo es '\0' que significa Final del string

            2.- char palabra[11] = "hola mundo";

            3.- char *palabra = "hola mundo";
 
        */
}