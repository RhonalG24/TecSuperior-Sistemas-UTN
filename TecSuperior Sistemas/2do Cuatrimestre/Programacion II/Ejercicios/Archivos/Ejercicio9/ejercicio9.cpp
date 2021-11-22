/*
    Dado el archivo binario generado en el ejercicio 7, que contiene todas las inscripciones del día, y
    otro con el mismo diseño que contiene las inscripciones anteriores (FINALES.DAT), desarrolle un
    7programa que agregue al archivo de inscripciones anteriores el contenido del archivo del día. Al final del
    proceso emita un listado del archivo de los registros agregados al archivo.
    Estrategia:
         Asignar archivos
         Abrir archivos para leer y actualizar
          Ubicarse al final del archivo de inscripciones anteriores
         Recorrer secuencialmente el archivo de inscripciones del día 
        o Leer registro archivo de inscripciones del día
        o Grabar registro en archivo de inscripciones anteriores
         
        Ubicarse en el primer registro de los agregados
          Recorrer secuencialmente el archivo de inscripciones anteriores desde donde fue ubicado
        o Leer registro archivo de inscripciones anteriores
        o Listar datos del registro
        
         Cerrar archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    int codMateria;
    int diaExamen;
    int mesExamen;
    int anioExamen;
    char nombreApellido[26];
} Boleta;

int main()
{
    FILE *ptrArchivoDiaFinalesBin = NULL;
    FILE *ptrArchivoFinalesAnterioresBin = NULL;
    Boleta alumno;

    ptrArchivoFinalesAnterioresBin = fopen("finales.dat", "ab");
    if (ptrArchivoFinalesAnterioresBin == NULL)
    {
        printf("Archivo Finales.dat NO encontrado\n");
        return -1;
    }
    else
    {
        printf("Archivo Finales.dat encontrado.\n");
    }

    // ptrArchivoDiaFinalesBin = fopen("../Ejercicio_6/diaFinalesBin.dat", "rb");
    ptrArchivoDiaFinalesBin = fopen("../Ejercicio-6-11-funciones/Ej6/diaFinalesBin.dat", "rb");

    if (ptrArchivoDiaFinalesBin == NULL)
    {
        printf("Archivo diaFinales.dat NO encontrado.\n");
        return -1;
    }
    int posicion = ftell(ptrArchivoFinalesAnterioresBin) / sizeof(alumno); //me indica donde estoy parado dentro del archivo. Se divide entre el tamaño de bytes de la estrutuctura para tener el número/posicion del registro donde estoy. Devuelve bytes
    fread(&alumno, sizeof(alumno), 1, ptrArchivoDiaFinalesBin);
    while (!feof(ptrArchivoDiaFinalesBin))
    {
        fwrite(&alumno, sizeof(alumno), 1, ptrArchivoFinalesAnterioresBin);
        fread(&alumno, sizeof(alumno), 1, ptrArchivoDiaFinalesBin);
    }
    fflush(ptrArchivoFinalesAnterioresBin);

    //Ahora a mostrar los archivos copiados
    fseek(ptrArchivoFinalesAnterioresBin, posicion * sizeof(alumno), SEEK_SET); //Me paro en la posicion indicada dentro del archivo. Uso la posicion que me guardé antes, lo multiplico por la cantidad de bytes de la estructura y luego indico que debo desplazarme desde el inicio con el SEEK_SET.

    printf("Legajo\tCod. Materia\tFecha\tNombre\n");
    fread(&alumno, sizeof(alumno), 1, ptrArchivoFinalesAnterioresBin);
    while (!feof(ptrArchivoFinalesAnterioresBin))
    {
        printf("%d\t%d\t%d/%d/%d\t%s\n", alumno.legajo, alumno.codMateria, alumno.diaExamen, alumno.mesExamen, alumno.anioExamen, alumno.nombreApellido);
        fread(&alumno, sizeof(alumno), 1, ptrArchivoFinalesAnterioresBin);
    }

    fclose(ptrArchivoDiaFinalesBin);
    fclose(ptrArchivoFinalesAnterioresBin);
}
