#include <stdio.h>
#include <stdlib.h>
#include "string.h"

using namespace std;

int contarPalabras(const char *cadena)
{
    // char aux[80]; //una forma
    // char *aux = (char*) malloc(sizeof(char)*80); //otra forma
    char *aux = (char *)malloc(sizeof(char) * (strlen(cadena) + 1));
    strcpy(aux, cadena);
    char *palabra;
    palabra = strtok(aux, " ");
    int cantPalabras = 0;
    while (palabra != NULL)
    {
        cantPalabras++;
        palabra = strtok(NULL, " ");
    }
    free(aux);
};

int main()
{
    // int valor1 = 0;
    // int valor2 = 0;
    // int valor3 = 0;

    // printf("Ingrese 3 nros: ");
    // scanf("%d %d %d", &valor1, &valor2, &valor3); //el scanf lee hasta que encuentra un espacio
    // //si quiero leer un texto con espacios no puedo usar el scanf
    // fflush(stdin); //para limpiar el buffer del standard io, sino cuando quieras leer algo de nuevo te va a tomar el \0 que quedo de la anterior lectura y romperá el programa
    // // fflush(stdin);
    // //ahora, el gets lee siempre y unicamente cadenas
    // char texto[20];

    // printf("ingrese texto:");

    // //se pasa solo "texto" y no "&texto" porque los array ya se pasan por referencia

    // //gets(texto); //no hay forma de controlar la cantidad de caracteres que se ingresan, si supera el tamaño del vector te agarra memoria de otro sitio

    // fgets(texto, 20, stdin); //(variable, cantDecaracteres+\0, documentoDondeSeGuardara) ..Es mejor que usar el gets()

    // //puts pone en el standar output
    // puts(texto);

    // char cadena[] = "Hola,mundo,soy,una,cadena,separa,por,comas",
    //      delimitador[] = ",";
    // char *token = strtok(cadena, delimitador);
    // if (token != NULL)
    // {
    //     while (token != NULL)
    //     {
    //         // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
    //         printf("Token: %s\n", token);
    //         token = strtok(NULL, delimitador);
    //     }
    // }

    //----------------------------
    char cadena2[] = "Una cadena con espacios en blanco";

    printf("Cantidad palabras %d\n\n", contarPalabras(cadena2));
    // }

    return 0;
}

/*
#include <stdio.h>
#include <string.h>
 
int main(){
    char cadena[] = "Hola,mundo,soy,una,cadena,separa,por,comas",
    delimitador[] = ",";
    char *token = strtok(cadena, delimitador);
    if(token != NULL){
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            printf("Token: %s\n", token);
            token = strtok(NULL, delimitador);
        }
    }
}
*/