#include <iostream>
using namespace std;

struct Inscripcion
{
    int codMateria;
    int codLegajo;
    string nombreApellido;
};

void apareo(Inscripcion diarias[], int cantDiarias, Inscripcion maestro[], int cantTotales, Inscripcion actualizadas[], int &cant)
{
    int i = 0, j = 0;
    cant = 0;

    while (i < cantDiarias && j < cantTotales)
    {
        if (diarias[i].codMateria < maestro[j].codMateria)
        {
            actualizadas[cant] = diarias[i];
            i++;
        }
        else
        {
            actualizadas[cant] = maestro[j];
            j++;
        }
        cant++;
    }

    while (i < cantDiarias)
    {
        actualizadas[cant] = diarias[i];
        i++;
        cant++;
    }

    while (j < cantTotales)
    {
        actualizadas[cant] = maestro[j];
        j++;
        cant++;
    }
}

void imprimir(Inscripcion inscripciones[], int cantidad)
{
    cout << "Materia\t\tLegajo\t\tNombre" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << inscripciones[i].codMateria << "\t\t" << inscripciones[i].codLegajo << "\t\t" << inscripciones[i].nombreApellido << endl;
    }
    return;
}

void imprimirXMateria(Inscripcion inscripciones[], int cantidad)
{
    int i = 0, cantAlumnos = 0, cantMaterias = 0;

    while (i < cantidad)
    {
        int key = inscripciones[i].codMateria;
        cantAlumnos = 0;

        cout << "Materia: " << key << endl;
        cout << "Legajo\t\tNombre" << endl;
        while (i < cantidad && key == inscripciones[i].codMateria)
        {
            cout << inscripciones[i].codLegajo << "\t\t" << inscripciones[i].nombreApellido << endl;
            cantAlumnos++;
            i++;
        }

        cantMaterias++;
        cout << "Cantidad Alumnos: " << cantAlumnos << endl;
    }

    cout << "Cantidad de Materias: " << cantMaterias << endl;
}

int main()
{
    Inscripcion inscDiarias[3] = {
        {111, 222, "Pepe"},
        {111, 223, "Leo"},
        {222, 222, "Pepe"},
    };

    Inscripcion maestro[5] = {
        {111, 777, "Juan"},
        {112, 223, "Carlos"},
        {333, 232, "Mario"},
        {333, 445, "Maria"},
        {333, 765, "Ana"},
    };

    Inscripcion actualizado[8];

    int cant = 0;
    apareo(inscDiarias, 3, maestro, 5, actualizado, cant);

    imprimir(actualizado, cant);

    cout << endl;
    cout << "Inscripciones por materias:" << endl;
    imprimirXMateria(actualizado, cant);

    system("pause");
    return 0;
}