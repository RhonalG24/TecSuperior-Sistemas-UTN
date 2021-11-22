/*
1) Una empresa de eventos necesita nuestra ayuda para poder programar un mes de congresos sobre la vida
silvestre en las afueras de Vicente Lopez.
La empresa ha decidido administrar los eventos con dos niveles, los Congresos y los Simposios.Sabemos que
hay un congreso por día y que durante cada Congreso ocurren varios Simposios en simultáneo.

De los congresos tendremos un conjunto ya cargado con la siguiente información::
● Código (texto)
● Nombre (texto)
● Hora Inicio (HHMMSS en formato 24hrs)
● Hora Fin (HHMMSS en formato 24hrs)
● Capacidad Mínima por simposio (0 a 500)

Por otro lado también tenemos un conjunto de Inscripciones a los simposios:
● Código de Simposio
● DNI (numérico)
● Apellido (texto)
● Fecha de Nacimiento (AAAAMMDD)

Y por último contamos con el conjunto de Simposios, con la siguiente información:
● Código (numérico de 100 a 250)
● Código de Congreso
● Nombre (texto)
● Hora Inicio (HHMMSS en formato 24hrs)
● Hora Fin (HHMMSS en formato 24hrs)
● Inscriptos (0 a 500)

a. Realizar una función o procedimiento según crea conveniente que a partir de las Inscripciones
complete el conjunto de simposios con los inscriptos.

b. Realizar una función o procedimiento según crea conveniente que valide los datos de un simposio, un
simposio es válido si:
i. Sus horas de inicio y fin están dentro de las horas de inicio y fin de su congreso
ii. La cantidad de inscriptos supera la capacidad mínima por simposio de su congreso
iii. Tiene un nombre distinto de cadena vacía


c. Realizar una función o procedimiento según crea conveniente que reciba el conjunto de congresos, y
el conjunto de Simposios y emita un listado con los Simposios inválidos.
Congreso: Codigo - Nombre
Codigo Simposio Nombre Simposio Estado
999 AAAAAAAAAAAA Valido/Invalido
Cantidad Válidos: 99


Consideraciones
● El conjunto de inscripciones se encuentra ordenado por DNI en forma ascendente
● El conjunto de Congresos se encuentra ordenado por Código en forma descendente
● El conjunto de simposios está completo y ordenado en forma ascendente por código

2) Realizar el programa principal para demostrar el llamado a las funciones/procedimientos realizados en el
punto anterior.
*/

#include <iostream>
using namespace std;

#define CANT_CONGRESOS 30   //Uno por dia durante un mes
#define CANT_SIMPOSIOS 150  //(100-250)
#define CANT_INSCRIPTOS 500 //arbitrario

typedef struct
{
    string codigo;
    string nombre;
    int horaInicio;                 //HHMMSS
    int horaFin;                    //HHMMSS
    int capacidadMinimaPorSimposio; //0 a 500
} Congreso;                         //Uno por día por un mes .. 30 - Ordenado por Código en forma descendente

typedef struct
{
    int codigo; //(de 100 a 250)
    string codigoCongreso;
    string nombre;
    int horaInicio; //HHMMSS
    int horaFin;    //HHMMSS
    int inscriptos; //0 a 500
} Simposio;         //completo y ordenado en forma ascendente por código

typedef struct
{
    int codigoSimposio;
    int dni;
    string apellido;
    int fechaNacimiento;
} Inscripto; //Ordenado por dni de forma ascendente

// a
int buscarCodigoDeSimposio(Inscripto inscripciones[CANT_INSCRIPTOS], int valor);
void llenarInscriptos(Simposio simposios[CANT_SIMPOSIOS], Inscripto inscripciones[CANT_INSCRIPTOS], int totalInscriptos);

//b
/**
 * Ordena por código de congreso de forma descendente
 */
void ordenarPorCodigoDeCongreso(Simposio arr[], int n);
int buscarCongreso(Congreso arr[], int cantElementos, string valorBuscado);
bool validarSimposio(Simposio simposios[CANT_SIMPOSIOS], Inscripto inscripciones[CANT_INSCRIPTOS], int posicion);

//c
void imprimirListado(Simposio simposios[CANT_SIMPOSIOS], int cantSimposios, Congreso congresos[CANT_CONGRESOS]);

int main()
{
    Congreso congresos[CANT_CONGRESOS];       //Ordenado por Código en forma descendente
    Simposio simposios[CANT_SIMPOSIOS];       //completo y ordenado en forma ascendente por código
    Inscripto inscripciones[CANT_INSCRIPTOS]; //Ordenado por dni de forma ascendente

    llenarInscriptos(simposios, inscripciones, CANT_INSCRIPTOS);

    ordenarPorCodigoDeCongreso(simposios, CANT_SIMPOSIOS);
    imprimirListado(simposios, CANT_SIMPOSIOS, congresos);

    return 0;
}

//a
int buscarCodigoDeSimposio(Inscripto inscripciones[CANT_INSCRIPTOS], int valor)
{
    int posicion = inscripciones[valor].codigoSimposio - 100;
    return posicion;
}

void llenarInscriptos(Simposio simposios[CANT_SIMPOSIOS], Inscripto inscripciones[CANT_INSCRIPTOS], int totalInscriptos)
{
    int posicion;
    for (int i = 0; i < totalInscriptos; i++)
    {
        int posicion = buscarCodigoDeSimposio(inscripciones, i);
        simposios[posicion].inscriptos++; //accede por PUP
    }
    return;
}

//b
bool validarSimposio(Simposio simposios[CANT_SIMPOSIOS], Congreso congresos[CANT_CONGRESOS], int posicion)
{
    bool valido = true;
    int posicionCongreso = buscarCongreso(congresos, CANT_CONGRESOS, simposios[posicion].codigoCongreso);

    // b.i
    if (simposios[posicion].horaInicio < congresos[posicionCongreso].horaInicio)
    {
        valido = false;
        return valido;
    }
    if (simposios[posicion].horaFin > congresos[posicionCongreso].horaFin)
    {
        valido = false;
        return valido;
    }
    // b.ii
    if (simposios[posicion].inscriptos < congresos[posicionCongreso].capacidadMinimaPorSimposio)
    {
        valido = false;
        return valido;
    }

    // b.iii
    if (simposios[posicion].nombre == " ")
    {
        valido = false;
        return valido;
    }
    return valido;
}

int buscarCongreso(Congreso arr[], int cantElementos, string valorBuscado)
{
    //Cuando arranco evalúo todo el vector de 0 a cantElementos-1
    int inicio = 0;
    int fin = cantElementos - 1;

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

/**
 * Ordena por código de congreso de forma descendente
 */
void ordenarPorCodigoDeCongreso(Simposio arr[], int n)
{
    int i = 0, j;
    Simposio aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].codigoCongreso < arr[j + 1].codigoCongreso)
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

//c
void imprimirListado(Simposio simposios[CANT_SIMPOSIOS], int cantSimposios, Congreso congresos[CANT_CONGRESOS])
{
    int i = 0;
    string key;
    int posicionCongreso, cantSimposiosValidos = 0;
    string nombreCongreso;
    bool simposioValido;

    while (i < cantSimposios)
    {
        key = simposios[i].codigoCongreso;
        posicionCongreso = buscarCongreso(congresos, CANT_CONGRESOS, simposios[i].codigoCongreso);
        nombreCongreso = congresos[posicionCongreso].nombre;
        cout << "Congreso: " << key << " - " << nombreCongreso << endl;
        cout << "Codigo Simposio \t\t Nombre Simposio \t\t Estado" << endl;
        while (i < cantSimposios && simposios[i].codigoCongreso == key)
        {
            simposioValido = validarSimposio(simposios, congresos, i);

            if (simposioValido)
            {
                cantSimposiosValidos++;
            }
            else
            {
                cout << simposios[i].codigo << "\t\t" << simposios[i].nombre << "\t\t"
                     << "Inválido"
                     << "\t\t" << endl;
            }
            i++;
        }
        cout << "Cantidad Válidos: " << cantSimposiosValidos << endl
             << endl;
        cantSimposiosValidos = 0;
    }

    return;
}