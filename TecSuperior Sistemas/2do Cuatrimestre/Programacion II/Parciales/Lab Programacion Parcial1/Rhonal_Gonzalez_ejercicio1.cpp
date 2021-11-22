/*
Ejercicio 1: 


Dado un conjunto de N materias ( <=20) de una carrera, se tiene un archivo “MATERIAS.DAT” con la información de cada uno de ellas: 

Código de materia ( 4 caracteres).
Cantidad de alumnos ( número entero). 

Además se tiene en otro archivo “ALUMNOS.DAT” con los siguientes datos:

Código de materia (4 caracteres).
Número de legajo del alumno (6 caracteres).
Nota (1 a 10) de cada alumno.

Se pide:
Informar de la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10.
informar al final del proceso el código de materia, el % de aprobados y el de insuficientes de cada materia.

    Materia: AA11 - Aprobados 78% - Reprobados 22%
    Materia: BJD5 - Aprobados 95% - Reprobados 5%
    (...)

*/

/*
    Datos:
        “MATERIAS.DAT” (<= 20)
            Código de materia ( 4 caracteres).
            Cantidad de alumnos ( número entero). 

        “ALUMNOS.DAT”
            Código de materia (4 caracteres).
            Número de legajo del alumno (6 caracteres).
            Nota (1 a 10) de cada alumno.

    Salida:
        1) Cantidad de alumnos por nota
        2) Mostrar listado con código de materia, el % de aprobados y el de insuficientes de cada materia.

    Estrategia
        Abrir archivos ("rb")
        Paso el archivo “MATERIAS.DAT” a un array donde a su vez cargo los registros por materias (regMaterias[20])
        Creo array de notas[9] (la nota es el indice del array) para cargar la cantidad de alumnos por nota
        Recorro el archivo “ALUMNOS.DAT” y proceso
            notas[alumno.nota-1]++ //aumento el contador por nota en el array de notas
            busco en regMaterias la posicion con burbujeo
            si (nota > 5){
                regMaterias[pos].cantAprobados++
            } sino {
                regMaterias[pos].cantDesaprobados++
            }
        
    1)  Muestro la cantidad de alumnos por notas (recorro array de notas)
    2)  Genero listado usando regMaterias


        Cerrar archivos  

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOTA 10
#define MAX_MATERIAS 20

typedef struct
{
    char codigo[5]; //( 4 caracteres)
    int cantAlumnos;
} Materia;

typedef struct
{
    char codigoMateria[5]; //( 4 caracteres)
    char legajo[7];        // (6 caracteres)
    int nota;              //1-10
} Alumno;

//estructuras auxiliares
typedef struct
{
    char codigo[5]; //( 4 caracteres)
    int cantAlumnos;
    int cantAprobados;
    int cantDesaprobados;
} Registro_Materia;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
void generarArray(Registro_Materia *regMaterias, FILE *ptrMateriasDat);
int buscarCodigo(Registro_Materia *vec, int cant, char *valor);
void mostrarNotas(const int *notas);
void generarListado(const Registro_Materia *regMaterias);

int main()
{
    //  Abrir archivos ("rb")
    FILE *ptrMateriasDat = abrirArchivo("MATERIAS.DAT", "rb");
    FILE *ptrAlumnosDat = abrirArchivo("ALUMNOS.DAT", "rb");

    Alumno alumno;
    Registro_Materia regMaterias[MAX_MATERIAS - 1];

    generarArray(regMaterias, ptrMateriasDat);

    //  Creo array de notas[9] (la nota es el indice del array) para cargar la cantidad de alumnos por nota
    int notas[MAX_NOTA - 1] = {0};

    //         Recorro el archivo “ALUMNOS.DAT” y proceso
    fread(&alumno, sizeof(Alumno), 1, ptrAlumnosDat);
    while (!feof(ptrAlumnosDat))
    {
        notas[alumno.nota - 1]++;                                                //aumento el contador por nota en el array de notas. Accedo por PUP
        int pos = buscarCodigo(regMaterias, MAX_MATERIAS, alumno.codigoMateria); //busco en regMaterias la posicion con busqueda secuencial dado que el vector no esta ordenado
        if (pos == -1)
        {
            printf("No se encontro la materia");
        }
        else
        {

            if (alumno.nota > 5)
            {
                regMaterias[pos].cantAprobados++; //Accedo por PUP al array y actualizo el contador
            }
            else
            {
                regMaterias[pos].cantDesaprobados++;
            }
        }
        fread(&alumno, sizeof(Alumno), 1, ptrAlumnosDat);
    }

    //     1)  Muestro la cantidad de alumnos por notas (recorro array de notas)
    mostrarNotas(notas);

    //     2)  Genero listado usando regMaterias
    generarListado(regMaterias);

    fclose(ptrAlumnosDat);
    fclose(ptrMateriasDat);

    return 0;
}

FILE *abrirArchivo(const char *nombreArchivo, const char *modo)
{
    FILE *ptrArchivo = fopen(nombreArchivo, modo);
    if (ptrArchivo == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s", nombreArchivo);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Archivo %s encontrado!\n", nombreArchivo);
    }

    return ptrArchivo;
}

void generarArray(Registro_Materia *regMaterias, FILE *ptrMateriasDat)
{
    Materia materia;

    regMaterias->cantAprobados = {0};
    regMaterias->cantDesaprobados = {0};

    int contador = 0;

    fread(&materia, sizeof(Materia), 1, ptrMateriasDat);
    while (!feof(ptrMateriasDat) && contador < MAX_MATERIAS)
    {
        strcpy(regMaterias[contador].codigo, materia.codigo);
        regMaterias[contador].cantAlumnos = materia.cantAlumnos;

        contador++;

        fread(&materia, sizeof(Materia), 1, ptrMateriasDat);
    }
    return;
}

int buscarCodigo(Registro_Materia *vec, int cant, char *valor)
{
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(vec[i].codigo, valor) == 0)
        {
            return i;
        }
    }
    //Si no salió todavía, no estaba en el vector
    return -1;
}

void mostrarNotas(const int *notas)
{
    for (int i = 0; i < MAX_NOTA; i++)
    {
        printf("Nota: %d - %d alumnos.\n", i + 1, notas[i]);
    }
    return;
}

void generarListado(const Registro_Materia *regMaterias)
{

    float porcentajeAprobados = 0;
    float porcentajeDesaprobados = 0;

    for (int i = 0; i < MAX_MATERIAS; i++)
    {
        //calculo los porcentajes
        porcentajeAprobados = (regMaterias[i].cantAprobados * 100) / regMaterias[i].cantAlumnos;
        porcentajeDesaprobados = (regMaterias[i].cantDesaprobados * 100) / regMaterias[i].cantAlumnos;

        printf("Materia: %s - Aprobados %.2f - Reprobados %.2f\n", regMaterias[i].codigo, porcentajeAprobados, porcentajeDesaprobados);
    }
    return;
}