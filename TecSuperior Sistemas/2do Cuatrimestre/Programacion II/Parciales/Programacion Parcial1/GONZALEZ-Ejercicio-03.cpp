/* EJERCICIO 3
    
Entrada:
    string cadena

Salida
    int cantNoVocales // cantidad de no vocales que posee la cadena de caracteres

Restriccion:
    Solo usar notacion de punteros

    Estrategia:
        recorrer la cadena hasta llegar a fin de cadena
            si el caracter es una vocal{
                no hace nada
            } sino {
                aumento cantNoVocales
            }
        retornar cantNoVocales
*/

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