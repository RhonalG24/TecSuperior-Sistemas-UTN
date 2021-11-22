/*
Ej. 13: Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT, ambos
ordenados ascendente por código de materia y con el siguiente diseño:
a.1Nro de legajo (8 dígitos)
a.2 Código de materia (6 dígitos)
a.3 ApellidoNombre(25caract)
8Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.
Estrategia:

    Asignar y abrir archivos
    Leer registro archivo maestro con control de EOF
    Leer registro archivo finales del día con control de EOF
    Mientras no sea fin de archivo de ninguno de los dos archivos
    o Si el código de materia del registro del maestro es menor al código de materia del registro
    del archivo del día
     Grabar registro archivo maestro en archivo de finales actualizado
     Leer registro archivo maestro con control de EOF
    o De lo contrario
     Grabar registro archivo finales del día en archivo de finales actualizado
     Leer registro archivo finales del día con control de EOF
    Por fin de archivo del maestro mientras no sea fin de archivo de finales del día
    o Grabar registro archivo finales del día en archivo de finales actualizado
    o Leer registro archivo finales del día con control de EOF
    Por fin de archivo finales del día mientras no sea fin de archivo maestro
    o Grabar registro archivo maestro en archivo de finales actualizado
    o Leer registro archivo maestro con control de EOF
    Cerrar archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    int codMateria;
    char apellidoNombre[26];
} Inscripcion;

int main()
{
    Inscripcion maestro;
    Inscripcion diaFinal;

    FILE *ptrArcMaestroFinales = NULL;
    FILE *ptrArcDiaFinales = NULL;

    ptrArcMaestroFinales = fopen("maestroFinales.dat", "rb");
    if (ptrArcMaestroFinales == NULL)
    {
        printf("Archivo maestroFinales.dat NO encontrado.\n");
        return -1;
    }
    ptrArcDiaFinales = fopen("diaFinales.dat", "rb");
    if (ptrArcDiaFinales == NULL)
    {
        printf("Archivo diaFinales.dat NO encontrado.\n");
        return -1;
    }

    FILE *ptrArcFinalesAct = NULL;
    ptrArcFinalesAct = fopen("finalesAct.dat", "wb");
    if (ptrArcFinalesAct == NULL)
    {
        printf("Archivo finalesAct.dat NO encontrado.\n");
        return -1;
    }

    fread(&maestro, sizeof(maestro), 1, ptrArcMaestroFinales);
    fread(&diaFinal, sizeof(diaFinal), 1, ptrArcDiaFinales);
    while (!feof(ptrArcMaestroFinales) && !feof(ptrArcDiaFinales))
    {
        if (maestro.codMateria > diaFinal.codMateria)
        {
            fwrite(&diaFinal, sizeof(diaFinal), 1, ptrArcFinalesAct);
            fread(&diaFinal, sizeof(diaFinal), 1, ptrArcDiaFinales);
        }
        else
        {
            fwrite(&maestro, sizeof(maestro), 1, ptrArcFinalesAct);
            fread(&maestro, sizeof(maestro), 1, ptrArcMaestroFinales);
        }
    }

    while (!feof(ptrArcMaestroFinales))
    {
        fwrite(&maestro, sizeof(maestro), 1, ptrArcFinalesAct);
        fread(&maestro, sizeof(maestro), 1, ptrArcMaestroFinales);
    }

    while (!feof(ptrArcDiaFinales))
    {
        fwrite(&diaFinal, sizeof(diaFinal), 1, ptrArcFinalesAct);
        fread(&diaFinal, sizeof(diaFinal), 1, ptrArcDiaFinales);
    }

    fclose(ptrArcDiaFinales);
    fclose(ptrArcMaestroFinales);
    fclose(ptrArcFinalesAct);

    return 0;
}