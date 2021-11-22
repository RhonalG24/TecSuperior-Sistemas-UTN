#include <iostream>
using namespace std;

struct Alumno
{
    int legajo;
    string apellidoNombre;
    int nota;
};

int main()
{
    Alumno unAlumno;
    unAlumno.apellidoNombre = "Perez Juan";
    unAlumno.legajo = 1111;
    unAlumno.nota = 8;

    cout << unAlumno.apellidoNombre << endl;

    return 0;
}