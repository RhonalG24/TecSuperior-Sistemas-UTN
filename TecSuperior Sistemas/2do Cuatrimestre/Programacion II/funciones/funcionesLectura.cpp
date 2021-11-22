#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void discardChars()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

/**
 * Usa scanf para leer string
 * Usa discardChars()
 */
void leerString(const char *msg, int limite, char *variable)
{

    printf("%s", msg);
    scanf(" %[^\n]s", variable);
    discardChars();

    while (strlen(variable) > limite)
    {
        printf("\nDebe contener como máximo %d carácteres.\n\n", limite);
        printf("%s", msg);
        scanf(" %[^\n]s", variable);
        discardChars();
    }
    return;
}

/**
 * Usa fgets para leer string
 * No usar
 */
void leerString(const char *msg, int limite, char *variable)
{
    printf("%s", msg);
    fgets(variable, limite, stdin);
    return;
};

/**
 * Lee cualquier tipo excepto cadenas
 * Usa discardChars()
 * Nota: debes agregar & a la variable.
 */
void leer(const char *msg, const char *formato, void *variable)
{
    printf(msg);
    scanf(formato, variable);
    discardChars();
    return;
}

char leerLetra(char const *msg)
{
    char letra;
    printf("%s\n", msg);
    scanf(" %c", &letra);
    return letra;
}

int contarPalabras(const char *cadena)
{
    // char aux[80]; //una forma
    // char *aux = (char*) malloc(sizeof(char)*80); //otra forma
    int cantPalabras = 0;

    char *aux = (char *)malloc(sizeof(char) * (strlen(cadena) + 1));
    strcpy(aux, cadena);

    char *palabra;
    palabra = strtok(aux, " ");
    while (palabra != NULL)
    {
        cantPalabras++;
        palabra = strtok(NULL, " ");
    }

    free(aux); //libero la memoria

    return cantPalabras;
};

int contarLetras(char palabra[])
{
    int cant = 0;
    while (palabra[cant] != '\0')
    {
        cant++;
    }
    return cant;
}

int cuentaNoVocales(char *cadena)
{
    int cantNoVocales = 0;
    int pos = 0;

    while (*(cadena + pos) != '\0')
    {
        switch (*(cadena + pos))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            cantNoVocales++;
            break;
        }
        pos++;
    }

    return cantNoVocales;
}

bool esPalindromo(char vector[])
{
    int longitud = contarLetras(vector);
    for (int i = 0; i < longitud / 2; i++)
    {
        if (*(vector + i) != *(vector + (longitud - (i + 1))))
        {
            return 0;
        }
    }
    return 1;
}