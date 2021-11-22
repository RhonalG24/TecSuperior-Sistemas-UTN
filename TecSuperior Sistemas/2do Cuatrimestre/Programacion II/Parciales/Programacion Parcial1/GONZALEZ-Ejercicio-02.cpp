/* EJERCICIO 2
    Desarrollar validaTelefono
telefono valido: + <cod_pais> - <cod_area> - <nro_telefono>
    los cod_* y nro_telefono deben ser digitos
    entre cod_area y nro_telefono deben tener maximo 8 digitos
Entrada:
    string cadena

Salida
    bool esNroTelefono // cantidad de no vocales que posee la cadena de caracteres

Estrategia:
    inicializar esNroTelefono en false
    Verificar si el primer caracter es '+'
    partir la cadena por '-' y verificar las condiciones
        si cumple las condiciones
            esNroTelefono = true

    retorna esNroTelefono
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validaTelefono(char *cadena);

int main()
{
    if (validaTelefono("+54-11-123458"))
    {
        printf("Es numero.\n");
    }
    else
    {
        printf("No es numero.\n");
    };

    return 0;
}
bool validaTelefono(char *cadena)
{
    bool esNroTelefono = false;
    int length = strlen(cadena);

    int codPais;
    int codArea;
    int nroTelefono;

    char buffer[length] = {0};
    char aux[length] = {0};
    int cantDigitos = 0;

    strcpy(buffer, cadena);

    if (buffer[0] == '+')
    {
        buffer[0] = '0';
        // strtok(buffer, "+"); //lo descarto
        codPais = atoi(strtok(buffer, "-"));
        if (codPais) //verifico que es de tipo numerico
        {
            strcpy(aux, strtok(NULL, "-"));
            // aux = strtok(NULL, "-");
            cantDigitos = strlen(aux); //cuento los caracteres que tiene
            codArea = atoi(aux);       //lo convierto a numero

            if (codArea)
            { //si es tipo numerico
                strcpy(aux, strtok(NULL, "-"));
                //aux = strtok(NULL, "-");
                cantDigitos += strlen(aux);
                nroTelefono = atoi(aux);

                if (nroTelefono && (cantDigitos <= 8))
                {
                    esNroTelefono = true;
                }
            }
        }
    }

    return esNroTelefono;
}