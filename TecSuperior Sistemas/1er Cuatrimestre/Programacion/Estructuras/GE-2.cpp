#include <iostream>
using namespace std;

//***********************ESTRUCTURAS************************
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct NombreCompleto
{
    string apellido;
    string nombre;
};

struct Calificaciones
{
    int nota1;
    int nota2;
    int nota3;
};

struct Alumno
{
    int legajo;
    NombreCompleto apellidoNombre;
    Calificaciones calificaciones;
    Fecha fechaNacimiento;
};

//***************************************************************

float promedioCalificaciones(Calificaciones calificaciones)
{
    return (calificaciones.nota1 + calificaciones.nota2 + calificaciones.nota3) / 3.0;
}

void cargarAlumno(Alumno &unAlumno)
{
    unAlumno.apellidoNombre.nombre = "Perez Juan";
    unAlumno.legajo = 1111;
    unAlumno.calificaciones.nota1 = 8;
    unAlumno.fechaNacimiento = enteroAFecha(20011023);
    return;
}
int fechaAEntero(Fecha fecha)
{
    return fecha.anio * 10000 + fecha.mes * 100 + fecha.dia;
}

//FUNCION retornar una estructura
Fecha enteroAFecha(int fechaCompuesta)
{
    Fecha fecha;
    fecha.anio = fechaCompuesta / 10000;
    fecha.mes = (fechaCompuesta % 10000) / 100;
    fecha.dia = fechaCompuesta % 100;
    return fecha;
}

int main()
{
    Alumno unAlumno;

    Fecha fechaNac;

    // fechaNac.dia = 24;
    // fechaNac.mes = 02;
    // fechaNac.anio = 2021;

    // unAlumno.apellidoNombre = "Perez Juan";
    // unAlumno.legajo = 1111;
    // unAlumno.nota = 8;
    // unAlumno.fechaNacimiento.dia = 24;
    // unAlumno.fechaNacimiento.mes = 02;
    // unAlumno.fechaNacimiento.anio = 1995;

    cargarAlumno(unAlumno);
    cout << unAlumno.apellidoNombre.apellido << endl;

    return 0;
}