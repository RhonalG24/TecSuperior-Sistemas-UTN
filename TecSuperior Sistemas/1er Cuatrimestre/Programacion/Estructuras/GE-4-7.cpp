/*
Ej. 4: Se dispone de un conjunto de boletas de inscripción de alumnos (100 como máximo) 
a examen en el mes de mayo. Cada boleta tiene los siguientes datos: apellido, número de legajo, 
código de materia, día, mes y año del examen. Los datos finalizan con un legajo igual a 0.
Desarrollar un programa que, a partir del ingreso de las boletas mencionadas, por teclado 
genere un vector de inscripción de alumnos a exámenes finales según el siguiente diseño:
a.1 Nro. de legajo (8 dígitos)
a.3 Día del examen (1..31)
a.5 Año del examen (4 dígitos)
a.2 Código de materia (6 dígitos)
a.4 Mes del examen (1..12)
a.6 Apellido (25 caract)
*/

#include <iostream>
using namespace std;
#define MAX_INSCRIPCIONES 100
#define MAX_LEGAJOS 100

struct Inscripcion
{
    int legajo;
    string apellido;
    int codMateria;
    int dia;
    int mes;
    int anio;
};

struct Alumno
{
    int legajo;
    string apellido;
};

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
}

void leer(string mensaje, string &valor)
{
    cout << mensaje;
    cin >> valor;
}

void imprimir(Inscripcion inscripciones[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << inscripciones[i].legajo << "\t\t" << inscripciones[i].apellido << "\t\t" << inscripciones[i].codMateria << "\t\t" << inscripciones[i].dia << "\t\t" << inscripciones[i].mes << "\t\t" << inscripciones[i].anio << "\t\t" << endl
             << endl;
    }
}

void burbujeoXLegajo(Inscripcion inscripciones[], int cantidad)
{
    int i = 0;
    bool ordenado = false;
    Inscripcion aux;

    while (i < cantidad && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (inscripciones[j].legajo > inscripciones[j + 1].legajo)
            {

                aux = inscripciones[j];
                inscripciones[j] = inscripciones[j + 1];
                inscripciones[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void burbujeoXApellido(Inscripcion inscripciones[], int cantidad)
{
    int i = 0;
    bool ordenado = false;
    Inscripcion aux;

    while (i < cantidad && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (inscripciones[j].apellido > inscripciones[j + 1].apellido)
            {

                aux = inscripciones[j];
                inscripciones[j] = inscripciones[j + 1];
                inscripciones[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}
void imprimirHeader()
{
    cout << "legajo"
         << "\t\t"
         << "apellido"
         << "\t\t"
         << "codMateria"
         << "\t\t"
         << "dia"
         << "\t\t"
         << "mes"
         << "\t\t"
         << "anio"
         << "\t\t" << endl;
    return;
}
/*
Ej. 5: Desarrolle un procedimiento que dado un código de materia y el vector generado en el ejercicio 4,
seleccione todos los registros que se anotaron para rendir esa materia y los imprima con el diseño
Legajo  Nombre  Fecha   CodMateria
--      --      --      --
*/
void imprimirXMateria(Inscripcion inscripciones[], int cantidad, int codMateria)
{
    cout << "Legajo\t\tApellido\t\tdia\t\tmes\t\tanio\t\tcodMateria" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        if (inscripciones[i].codMateria == codMateria)
        {
            cout << inscripciones[i].legajo << "\t\t" << inscripciones[i].apellido << "\t\t" << inscripciones[i].dia << "\t\t" << inscripciones[i].mes << "\t\t" << inscripciones[i].anio << "\t\t" << inscripciones[i].codMateria << endl;
        }
    }
    return;
}

/*
Ej. 6 : Dado el vector generado en el ejercicio 5, que contiene todas las inscripciones de mayo, y otro con el
mismo diseño que contiene las inscripciones anteriores desarrolle un procedimiento que agregue al vector de
inscripciones anteriores el contenido del vector de finales del día.
*/

/**
 * Procedimiento para añadir un vector al final de otro.
 * vectorA es el vector base.
 * vectorB es el vector que se agregará al final del vector base.
 */
void añadirVector(Inscripcion vectorA[], int &dimensionA, Inscripcion vectorB[], int dimensionB)
{
    int aux = 0;
    for (int i = dimensionA; i < dimensionA + dimensionB; i++)
    {
        vectorA[i] = vectorB[aux];
        aux++;
    }
    dimensionA += dimensionB;
    return;
}

/*
Ej. 7 : Dado el vector generado en el ejercicio 5, desarrolle un procedimiento que genere un vector ordenado
por número de legajo (cada registro debe tener los campos legajo y apellido y nombre) para todos los alumnos
que se inscribieron una o más veces. Cada legajo debe ocupar una posición única y predecible. El intervalo de
los legajos es 80001 a 80100 y están todos al menos una vez.
*/

void generarVectorInscritos(Inscripcion inscripciones[], int cantidad, Alumno inscritos[], int &cantInscritos)
{
    for (int i = 0; i < cantidad; i++)
    {
        inscritos[inscripciones[i].legajo - 80001].legajo = inscripciones[i].legajo;
        inscritos[inscripciones[i].legajo - 80001].apellido = inscripciones[i].apellido;
    }
    cantInscritos = MAX_LEGAJOS;
    return;
}

int main()
{
    Inscripcion inscripciones[MAX_INSCRIPCIONES];
    Inscripcion inscripcion;

    int cant = 0;

    leer("Ingrese el legajo: ", inscripcion.legajo);
    while (inscripcion.legajo != 0)
    {
        leer("Apellido:", inscripcion.apellido);
        leer("Cod. Materia:", inscripcion.codMateria);
        leer("Día:", inscripcion.dia);
        leer("Mes:", inscripcion.mes);
        leer("Año:", inscripcion.anio);

        inscripciones[cant] = inscripcion;
        cant++;

        leer("Ingrese el legajo: ", inscripcion.legajo);
    }

    cout << "Sin orden" << endl;
    imprimirHeader();
    imprimir(inscripciones, cant);

    cout << "Ordenado por legajo" << endl;
    imprimirHeader();

    burbujeoXLegajo(inscripciones, cant);
    imprimir(inscripciones, cant);

    cout << "Ordenado por apellido" << endl;
    imprimirHeader();
    burbujeoXApellido(inscripciones, cant);
    imprimir(inscripciones, cant);

    //EJ 5
    int codMateria;
    leer("Ingrese el código de la materia que quiere buscar: ", codMateria);
    imprimirXMateria(inscripciones, cant, codMateria);

    //EJ 6
    Inscripcion inscripcionesAnteriores[MAX_INSCRIPCIONES];

    return 0;
}