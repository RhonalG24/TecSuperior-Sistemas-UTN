#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define CANTCHARCODIGO 5
#define CANTCHARLEGAJO 6

struct Materia
{
    char codigo[CANTCHARCODIGO];
    float cantAlumnos;
};

struct NotaAlumno
{
    char codMateria[CANTCHARCODIGO];
    char legajo[CANTCHARLEGAJO];
    int nota;
};

void generarArchivoMaterias(Materia materias[], int cant);
void generarArchivoNotasPorAlumno(NotaAlumno alumnos[], int cant);

int main()
{
    int cantMaterias = 3;
    int cantAlumnos = 11;
    int cantNotas = 11;
    // notas del 0 al 10
    Materia materias[cantMaterias] = {
        {"MA1", 5}, {"MA2", 2}, {"MA3", 3}};

    NotaAlumno notasPorAlumno[cantAlumnos] = {{"MT1", "12345", 6}, {"MT1", "22356", 1}, {"MT1", "32456", 4}, {"MT1", "42356", 9}, {"MT1", "52356", 6}, {"MT2", "62356", 4}, {"MT2", "72356", 5}, {"MAT", "82356", 7}, {"MA3", "92356", 8}, {"MA3", "03341", 2}, {"MA3", "04342", 6}};

    generarArchivoMaterias(materias, cantMaterias);

    generarArchivoNotasPorAlumno(notasPorAlumno, cantAlumnos);
}
void generarArchivoMaterias(Materia materias[], int cant)
{
    FILE *fileMaterias = fopen("MATERIAS.DAT", "wb");
    for (int i = 0; i < cant; i++)
    {
        fwrite(&materias[i], sizeof(Materia), 1, fileMaterias);
    }
    fclose(fileMaterias);
}
void generarArchivoNotasPorAlumno(NotaAlumno alumnos[], int cant)
{
    FILE *fileAlumnos = fopen("ALUMNOS.DAT", "wb");
    for (int i = 0; i < cant; i++)
    {
        fwrite(&alumnos[i], sizeof(NotaAlumno), 1, fileAlumnos);
    }
    fclose(fileAlumnos);
}