/*
Ejercicio 1
La biblioteca del barrio recientemente recibió una donación con varias cajas llenas de libros. Para poder organizarlos y
hacerlos disponibles a la comunidad, la comisión que dirige la biblioteca decidió desarrollar un sistema que le permita
organizar y gestionar los libros que posee sumados a los que acaba de recibir. De cada libro la biblioteca conoce:

ISBN (int)
Nombre (char 30)
Categoría (short int)
Autor (int)
Año de publicación(int)

typedef struct{
    int isbn;
    string nombre;
    short int categoria;
    int autor;
    int anioPublicacion;
} Libro;

La biblioteca ya posee una planilla de cálculo con las categorías de libros. Esta planilla se encuentra ordenada por Código
ascendente, con la siguiente información:
■
■
Código Categoría (short int)
Nombre (char 30)

typedef struct{
    short int codigoCategoria;
    string nombre;
} Categoria;
Nota: las categorías sólo son 30 y se encuentran todas cargadas y codificadas en el rango [20-50]

Por otra parte la biblioteca dispone del listado de autores desordenado pero con la siguiente información:
●
●
●
Código de Autor (int)
Nombre (char 30)
Fecha de nacimiento (int) - formato AAAAMMDD
typedef struct{
    short int codigoAutor;
    string nombre;
    int fechaNacimiento; //AAAAMMDD
} Autor;

Se pide:

a. Suponiendo que ya se encuentran cargados los vectores de categorías y autores, desarrollar un módulo que
permita cargar el vector de libros. Tener en cuenta que el usuario ingresará el nombre del autor y no su código, por
lo que el sistema deberá realizar las acciones correspondientes para completar la información a guardar de un
libro. El ingreso de libros finaliza cuando el operador ingresa un ISBN 0 (cero). No podemos asegurar ningún orden
en la carga del usuario.


b. Desarrolle un módulo que permita al usuario generar el siguiente listado:
Autor: <código> - <nombre>
Nombre Libro    Categoría       Año de publicación 
...
Nombre Libro    Categoría       Año de publicación
----
Cantidad de obras del autor: 9999

Autor: <código> - <nombre>
Nombre Libro    Categoría      Año de publicación
...
Nombre Libro    Categoría      Año de publicación

----
Cantidad de obras del autor: 9999
...
Cantidad total de obras de la biblioteca: 9999
c.
Desarrolle la función main, de forma tal que presente un menú al usuario de la biblioteca que le permita o bien
cargar la información del punto “a” o bien generar el listado del punto “b”.
Restricciones y consideraciones:
●
●
Sobre los vectores de categorías y autores no se puede realizar búsquedas secuenciales.
Determine un valor arbitrario para la cantidad de autores y libros a cargar.
*/

#include <iostream>
using namespace std;
#define CANT_CATEGORIAS 30
#define CANT_AUTORES 100
#define CANT_LIBROS 50

typedef struct
{
    int isbn;
    string nombre;
    short int categoria;
    int autor;
    int anioPublicacion;
} Libro;

typedef struct
{
    short int codigoCategoria;
    string nombre;
} Categoria; //ordenada por Código ascendente. Sólo son 30 y se encuentran todas cargadas y codificadas en el rango [20-50]

typedef struct
{
    short int codigoAutor;
    string nombre;
    int fechaNacimiento; //AAAAMMDD
} Autor;                 //listado de autores desordenado

/*
desarrollar un módulo que
permita cargar el vector de libros. Tener en cuenta que el usuario ingresará el nombre del autor y no su código

Determine un valor arbitrario para la cantidad de autores y libros a cargar.
*/
void leerInt(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}
void leerShortInt(string mensaje, short int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}
void leerString(string mensaje, string &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void ordenarAutoresPorNombre(Autor arr[], int n)
{
    int i = 0, j;
    Autor aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].nombre > arr[j + 1].nombre)
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void ordenarLibrosPorAutor(Libro arr[], int n)
{
    int i = 0, j;
    Libro aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].autor > arr[j + 1].autor)
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

int buscarAutor(Autor arr[], int cantElementos, string valorBuscado)
{
    int inicio = 0;
    int fin = cantElementos - 1;

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;

        if (arr[mitad].nombre == valorBuscado)
        {
            return mitad;
        }

        if (arr[mitad].nombre > valorBuscado)
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

void cargarLibros(Libro libros[], int cantidad, Autor autores[])
{
    Libro aux;
    string nombreAutor;
    int posicionAutor;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Registro " << i + 1 << "/" << cantidad << endl; //formato
        leerInt("Ingrese el ISBN del libro: ", aux.isbn);
        leerShortInt("Ingrese el codigo de la categoría", aux.categoria);
        leerString("Ingrese el nombre del autor: ", nombreAutor);
        posicionAutor = buscarAutor(autores, CANT_AUTORES, nombreAutor);
        aux.autor = autores[posicionAutor].codigoAutor;
        leerInt("Ingrese el año de publicación del libro: ", aux.anioPublicacion);
        cout << endl; //formato

        //cargo el vector de libros
        libros[i] = aux;
    }
    return;
}

void generarListado(Libro libros[CANT_AUTORES], int totalLibros, Autor autores[], Categoria categorias[CANT_CATEGORIAS])
{
    int i = 0;
    int key, posicion = 0;
    int totalObrasAutor = 0;
    int totalObrasBiblioteca = 0;

    while (i < totalLibros)
    {
        key = libros[i].autor;
        string nombreAutor = buscarNombre(autores, libros[i].autor);
        cout << "Autor: " << libros[i].autor << " - " << nombreAutor << endl;
        while (i < totalLibros && libros[i].autor == key)
        {
            string nombreCategoria = buscarNombreCategoria(categorias, libros[i].categoria); //Ingreso el codigo y busca por PUP
            cout << libros[i].nombre << "\t\t" << nombreCategoria << "\t\t" << libros[i].anioPublicacion << endl;
            totalObrasAutor++;
            totalObrasBiblioteca++;
            i++;
        }
        cout << "----" << endl;
        cout << "Cantidad de obras del autor: " << totalObrasAutor;
        totalObrasAutor = 0;
    }
    cout << ". . . ." << endl;
    cout << "Cantidad total de obras de la biblioteca: " << totalObrasBiblioteca;
    return;
}

int main()
{
    //ya se encuentran cargados los vectores de categorías y autores
    Categoria categorias[CANT_CATEGORIAS]; //codificadas en el rango [20-50]
    Autor autores[CANT_AUTORES];
    Libro libros[CANT_LIBROS];

    int opcion;
    leerInt("¿Qué desea hacer? 1- Cargar libros. 2- Generar listado de libros.", opcion);

    if (opcion == 1)
    {
        ordenarAutoresPorNombre(autores, CANT_AUTORES); //para la carga de libros
        cargarLibros(libros, CANT_LIBROS, autores);
    }
    else
    {
        ordenarLibrosPorAutor(libros, CANT_LIBROS);
        generarListado(libros, CANT_LIBROS, autores, categorias);
    }

    return 0;
}