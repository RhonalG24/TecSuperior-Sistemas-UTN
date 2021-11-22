/*
Ejercicio 3
Estás a cargo de la seguridad del casino, y se sabe que hay un ladrón dando vueltas que intenta llevarse el dinero! Para
evitar que este ladrón se lleve el dinero, tiene que haber un guardia en su camino.
Desarrollar una aplicación que permita generar un vector (máximo 15 caracteres) que representa el piso del casino con el
siguiente formato:
Ejemplo de entrada: x x x x G x $ x L
Donde:

x - Espacio vacío
$ - Dinero
G - Guardia
L - Ladron
El piso del casino siempre contendrá un único $, un único G y un único L.
En caso de que no haya un guardia en el camino del ladrón, mostrar el mensaje "ALARMA!!", en caso contrario, se debe
imprimir "OK".
Salida esperada: “ALARMA!!”
Se pide:

a.Desarrollar un módulo que permita identificar la posición del Ladrón, del Guardia y del Dinero

b.Desarrollar una función que en base a la posición del Ladrón, del Guardia y del Dinero emita el mensaje
correspondiente.
*/

#include <iostream>
using namespace std;
#define CANT_PISO 5

typedef struct
{
    int ladron;
    int guardia;
    int dinero;
} Posicion;

void leer(string mensaje, char &var)
{
    cout << mensaje;
    cin >> var;
    cout << endl;
}

void generarPiso(char piso[], int cant)
{
    bool guardia = false, ladron = false, dinero = false;
    cout << "Comienzo de la construcción del piso." << endl
         << endl;
    cout << "Posibles caracteres: \n x - Espacio vacío \n $ - Dinero \n G - Guardia \n L - Ladron" << endl
         << endl;
    for (int i = 0; i < cant; i++)
    {
        leer("Ingrese un caracter:", piso[i]);
        while (piso[i] != 'x' && piso[i] != '$' && piso[i] != 'G' && piso[i] != 'L' || piso[i] == 'G' && guardia || piso[i] == 'L' && ladron || piso[i] == '$' && dinero)
        {
            cout << "Caracter inválido o repetido." << endl
                 << endl;
            leer("Ingrese un caracter:", piso[i]);
        }
        if (piso[i] == 'L')
        {
            ladron = true;
        }
        if (piso[i] == '$')
        {
            dinero = true;
        }
        if (piso[i] == 'G')
        {
            guardia = true;
        }
    }
    cout << endl;
    cout << "Fin de la construcción del piso." << endl
         << endl;
}

void obtenerPosiciones(char piso[], int cant, Posicion &posiciones)
{
    for (int i = 0; i < cant; i++)
    {
        if (piso[i] == 'G')
        {
            posiciones.guardia = i;
        }
        if (piso[i] == 'L')
        {
            posiciones.ladron = i;
        }
        if (piso[i] == '$')
        {
            posiciones.dinero = i;
        }
    }
    return;
}

void generarMensaje(Posicion posiciones)
{
    if (posiciones.guardia > posiciones.dinero && posiciones.guardia > posiciones.ladron || posiciones.guardia < posiciones.ladron && posiciones.guardia < posiciones.dinero)
    {
        cout << "ALARMA!!" << endl;
    }
    else
    {
        cout << "OK" << endl;
    }
}

int main()
{
    char piso[CANT_PISO];
    generarPiso(piso, CANT_PISO);
    Posicion posiciones;
    obtenerPosiciones(piso, CANT_PISO, posiciones);
    generarMensaje(posiciones);
    return 0;
}