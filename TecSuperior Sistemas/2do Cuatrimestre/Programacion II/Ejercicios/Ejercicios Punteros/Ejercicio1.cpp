/*
1) Declarar una variable entera, un vector de caracteres de diez posiciones y una variable con
soporte de decimales y ...
a)  Asignarle valores.
b)  Imprimir el valor de cada una.
c)  Imprimir la dirección de memoria de cada una.
*/

#include <stdio.h>
using namespace std;

int main()
{
    int enteros = 10;
    char caracteres[10] = "Hola";
    float decimales = 2.5;

    int *ptrInt = NULL;
    char *ptrChar = NULL;
    float *ptrFloat = NULL;

    ptrInt = &enteros;
    ptrChar = caracteres;
    ptrFloat = &decimales;

    printf("Enteros vale = %d - dir. en memoria = %p\n", *ptrInt, ptrInt);

    printf("Caracteres vale = %s - dir. en memoria = %p\n", caracteres, *caracteres);

    printf("Decimales vale = %f - dir. en memoria = %p\n", *ptrFloat, ptrFloat);
}

/*
2) Declarar una variable que sea puntero a un número entero y luego ...
a)
Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c)
Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.
3) Declarar un puntero miPuntero de char[10], asignar dinámicamente espacio en memoria, asignarle
el valor “hola” y luego ...
a)
Imprimir por pantalla el puntero con el formateador %s.
b) Imprimir la dirección de memoria del puntero.
c)
Imprimir el valor del puntero.
d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
Analice el resultado y concluya.
4) Declarar un struct que defina una variable del tipo vector de caracteres, llamada nombre, y otra
que sea del tipo entero, llamada edad y ...
a)
En la función main, asigne el valor “Kokumo” y “30” para nombre y edad respectivamente.
b) Luego, invoque una función que reciba el struct por parámetro y que imprima el valor de
ambas variables del struct.
c)
Dentro de esa misma función, cambie los valores de las variables en cuestión y muestre
nuevamente sendos valores.
d) De regreso en el main, e inmediatamente después de la llamada a la función, imprima los
valores del struct; analice qué valores se imprimieron en pantalla.
5) Repita el ejercicio anterior pero pasando la referencia del struct y estudie los valores impresos por
pantalla; concluya qué ocurrió.Cadenas
1)
Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
NEUQUEN → verdadero
CHUBUT → falso
2) Repita el ejercicio 1 utilizando funciones de la biblioteca <string.h>
3) Dada una cadena, cuya longitud máxima es de 15 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena forma una dirección de ip válida.
Ejemplo:
192.168.1.23 → verdadero
192.168.1.z → falso
10.250.244.255 → verdadero
4) Dada una cadena que representa un número, cuya longitud máxima es de 80 caracteres,
desarrollar la función formatearNumero que reciba dos cadenas. La primera será la
cadena que representa el número mientras que la segunda será la que indique la
preferencia para el separador de miles y decimales (locale). Ejemplo:
Entrada: “1.050.214,56”, “AR” → “1.050.214, 56”
Entrada: “1,050,214.56”, “AR” → “1.050.214, 56”
Entrada: “1.050.214, 56”, “EN” → “1,050,214. 56”
5) Dada una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, devolver la cadena inversa.
a) ¿De qué forma se modifica el ejercicio si se desea modificar la cadena recibida?
6) Utilizando la función gets , leer de la entrada estándar una línea de longitud máxima 80
caracteres. Utilizando sólo sintaxis de punteros determinar:
a) ¿Cuántas palabras conforman la línea leída?
b) ¿Cuál es la palabra de longitud máxima y cuántos caracteres posee?
c) Repita el punto a) y b) utilizando la funciones strtok y strlen
7) Utilizando la función gets , leer de la entrada estándar una línea de longitud máxima 80
caracteres. Se pide generar y devolver la cadena que surge como producto de la
concatenación de aquellas palabras que terminan en una consonante y la siguientecomienza con una vocal. Ejemplo:
Canción Elefante Lavarropas Avión → CanciónElefante LavarropasAvión
Pájaro Auto Flor Ventana → Pájaro Auto Flor Ventana
8) Utilizando la función gets , leer de la entrada estándar dos líneas de longitud máxima 80
caracteres cada una. Se pide generar y devolver la cadena que surge como producto de
la intersección de las palabras de ambas líneas. Ejemplo:
línea 1: El fútbol es un deporte que se juega con una pelota redonda.
línea 2: El rugby es un deporte que se juega con una pelota ovalada.
salida: El es un deporte que se juega con una pelota.
9) Utilizando sintaxis de punteros, desarrollar la función comienzaEn que reciba dos
cadenas de caracteres, cuya longitud máxima será de 80 caracteres, y devuelva la
primer posición de la primer cadena donde comienza la segunda cadena. Ejemplo:
Entrada: “Hola mundo...mundo”, “mundo” → 5
Entrada: “Hola mundo...mundo”, “ola” → 1
Entrada: “Hola mundo...mundo”, “chau” → -1
10) Se desea sumar enteros largos, con un número de dígitos que supera el máximo de los
enteros largos. Cada número puede tener hasta 80 dígitos. Codifique una función que
permita realizar dicha suma.
*/