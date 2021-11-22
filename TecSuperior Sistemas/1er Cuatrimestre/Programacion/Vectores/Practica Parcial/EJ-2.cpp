/*
Ejercicio 2
Una plataforma de juegos requiere desarrollar un sistema que le permita obtener algunos datos
estadísticos sobre sus juegos y jugadores.

Esta plataforma posee un conjunto de 100 juegos a los cuales pueden jugar los usuarios (jugadores)
registrados en la plataforma. Este conjunto de juegos se encuentra completo pero desordenado. Los
códigos de juegos se encuentran en el rango [100, 200].

De cada juego se conoce su código y nombre.

De los usuarios registrados en la plataforma, se conoce:
Código: número entero secuencial que inicia en 1.
Nombre
Fecha de registración en formato AAAAMMDD

Actualmente la plataforma cuenta con 1000 usuarios que se encuentran ordenados por código de usuario.

Finalmente se dispone de un conjunto de datos qué relaciona a los usuarios con los juegos en los que
participan. Este conjunto de datos se encuentra ordenado por juego y usuario y posee la siguiente
estructura:

Código de juego
Código de usuario

Juego Usuario
1       1
1       2
1       3
...     ...
39      5

Se pide:
1. Desarrolle un módulo que permita generar un listado con la siguiente información:
Juego: <nombre del juego 1>
<Nombre Usuario 1> - Fecha de registración
<Nombre Usuario 2> - Fecha de registración
----
Cantidad total de usuario del juego: <cantidad>
Juego: <nombre del juego 1>
<Nombre Usuario 1> - Fecha de registración
<Nombre Usuario 2> - Fecha de registración
----
Cantidad total de usuario del juego: <cantid

Restricciones:
Sobre el vector de juegos no puede realizar búsqueda secuenciales ni binarias.
Sobre el vector de usuarios no puede realizar búsqueda secuenciales

estrategia
Ordenar vector juegos 
generar listado con corte de control
    -buscar juego con PUP por código
    -buscar en vector usuarios con busqueda binaria
*/

#include <iostream>
using namespace std;
#define MAX_JUEGOS 100
#define MAX_JUGADORES 1000

typedef struct
{
    int codigo; //[100,200]
    string nombre;
} Juego;

typedef struct
{
    int codigo;
    string nombre;
    int fechaRegistro; //formatoAAAAMMDD
} Usuario;

typedef struct
{
    int codJuego;
    int codUsuario;
} Relacion;

/**
 * Procedimiento para generar un vector con los juegos ordenados por código
 */
// void ordenarJuegos(Juego juegos[], string juegosOrdenados[]){
//     for(int i = 0; i < MAX_JUEGOS; i++){
//         juegosOrdenados[juegos[i].codigo-100] = juegos[i].nombre;
//     }
// }

void ordenarJuegos(Juego juegos[MAX_JUEGOS])
{
    int i = 0, j;
    Juego aux;
    bool ordenado = false;
    while (i < MAX_JUEGOS && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < MAX_JUEGOS - i - 1; j++)
        {
            if (juegos[j].codigo > juegos[j + 1].codigo)
            {
                aux = juegos[j];
                juegos[j] = juegos[j + 1];
                juegos[j + 1] = aux;
                ordenado = false; // Cambio el flag si hice un swap
            }
        }
        i++;
    }
}

//retorna una posición
int buscarUsuario(Usuario arr[MAX_JUGADORES], int valorBuscado)
{
    //Cuando arranco evalúo todo el vector de 0 a cantElementos-1
    int inicio = 0;
    int fin = MAX_JUGADORES - 1;

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;

        //Si el elemento es el del medio, devolvemos la posición
        if (arr[mitad].codigo == valorBuscado)
        {
            return mitad;
        }

        //Si el elemento es menor, entonces sólo puede estar en la 1ra mitad del array
        if (arr[mitad].codigo > valorBuscado)
        {
            fin = mitad - 1; //Cambio el límite superior
        }
        else
        {
            inicio = mitad + 1; //Cambio el límite inferior
        }
    }
    return -1; //Si no se encuentra
}

string buscarNombre(Juego juegos[MAX_JUEGOS], int codigo)
{
    int posicion = codigo - 100;
    return juegos[posicion].nombre;
}

void corteDeControl(Relacion jugadas[MAX_JUGADORES], Juego juegos[], Usuario jugadores[])
{
    int i = 0;
    int pos = 0;
    int usuariosDelJuego = 0;
    int clave;

    //mientras tenga elementos el vector
    while (i < MAX_JUGADORES)
    {
        clave = jugadas[i].codJuego;

        usuariosDelJuego = 0;

        string nombreJuego = buscarNombre(juegos, clave);
        cout << "Juego: " << nombreJuego << endl;

        //ciclo para obtener resultados parciales
        //mientras tenga elementos el vector y se mantenga la clave
        while (i < MAX_JUGADORES && clave == jugadas[i].codJuego)
        {
            pos = buscarUsuario(jugadores, jugadas[i].codUsuario);
            if (pos > -1)
            {
                cout << jugadores[pos].nombre << "\t - \t " << jugadores[pos].fechaRegistro << endl;
                usuariosDelJuego++;
            }

            i++;
            //avanzamos i
        }
        cout << "Cantidad total de usuario del juego: " << usuariosDelJuego << endl
             << endl;
        //muestro resultados parciales
    }
}

int main()
{
    Juego juegos[MAX_JUEGOS];
    Usuario jugadores[MAX_JUGADORES];
    Relacion jugadas[MAX_JUGADORES];

    ordenarJuegos(juegos);
    corteDeControl(jugadas, juegos, jugadores);

    return 0;
}