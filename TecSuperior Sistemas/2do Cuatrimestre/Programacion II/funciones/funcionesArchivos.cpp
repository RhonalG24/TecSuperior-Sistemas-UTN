#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Escribir txt
    fprintf(ptrArchivo, "%d\t%.2f\n", alumno.legajo, alumno.promedio);

Leer  txt
     //inicializo la variable con la estructura que necesito
    Episodio episodio;

    //inicializo una cadena de caracteres donde se va a guardar la línea a leer
    char buffer[500];
    
    //si la linea no tiene nada, regresa la estructura como NULL y termina la funcion
    if (fgets(buffer, 500, ptrFile) == NULL)
    {
        return episodio;
    }

Escribir binario
    fwrite(&alumno, sizeof(alumno), 1, ptrAlumActDat);

Leer binario
    fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
*/

int contarRegistrosBin(FILE *pFile)
{
    // tomo la posicion actual
    long actualPos = ftell(pFile);
    // muevo el puntero al final del archivo
    fseek(pFile, 0, SEEK_END);
    // tomo la posicion actual (ubicado al final)
    long ultimo = ftell(pFile);
    // vuelvo a donde estaba al principio
    fseek(pFile, actualPos, SEEK_SET);

    return (int)(ultimo / sizeof(persona)); //cant total de registros

    //printf(“Cantidad de registros: %d\n”, (int)(ultimo / sizeof(persona)); //cant total de registros
}

/**
 * Lee el registro en la posicion especificada
 */
int leer(Alumno *registro, FILE *file)
{
    return fread(registro, sizeof(Alumno), 1, file);
}

int leer(int pos, Alumno *registro, FILE *file)
{
    fseek(file, sizeof(Alumno) * pos, SEEK_SET);
    return leer(registro, file);
}

int escribir(Alumno registro, FILE *file)
{
    return fwrite(&registro, sizeof(Alumno), 1, file);
}
/*
Moverte dentro de archivo binario

int fseek ( FILE * stream, long int offset, int origin ): permite situar el puntero del archivo en una
posición determinada.
    ● stream: puntero al archivo
    ● offset: desplazamiento expresado en bytes
    ● origin: indica desde donde se realizará el desplazamiento. Para esto podemos utilizar
    cualquiera de estas 3 constantes
        ○ SEEK_SET: indica que el desplazamiento debe hacerse desde el principio del
        archivo
        ○ SEEK_CUR: indica que el desplazamiento debe hacerse desde la posición actual
        del archivo
        ○ SEEK_END: indica que el desplazamiento debe hacerse desde el final del archivo

    // posiciona el puntero en el 4to registro del archivo
        fseek(pFile, 3 * sizeof(persona), SEEK_SET);

Posicion actual: ftell(ptrFile)
    // tomo la posicion actual
    long actualPos = ftell(pFile);
    // muevo el puntero al final del archivo
    fseek(pFile, 0, SEEK_END);
    // tomo la posicion actual (ubicado al final)
    long ultimo = ftell(pFile);
    // vuelvo a donde estaba al principio
    fseek(pFile, actualPos, SEEK_SET);
    printf(“Cantidad de registros: %d\n”, (int)(ultimo / sizeof(persona)); //cant total de registros

*/

/*
Puntero constante: es un puntero que no puede cambiar la dirección de
memoria a la que apunta, pero sí puede cambiar el contenido de aquello a lo
que apunta.
    <tipo de dato> *const <nombre>;

Puntero a constante: es un puntero que puede cambiar la dirección de
memoria a la que apunta, pero no puede cambiar el contenido de aquello a
lo que apunta.
    const <tipo de dato> * <nombre>;
*/
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

typedef struct
{
    int idSerie;
    int numeroTemporada;
    long cantDescargas;
    char titulo[21];
    unsigned char numeroEpisodio;
    int ultimaDescarga; //aaaammdd
} Episodio;

/* en el main:
Episodio episodio;

FILE *ptrEpisodios = NULL;

ptrEpisodios = abrirArchivo("Episodios.txt", "r");

episodio = leerTXT(ptrEpisodios);
*/
/**
 * Lee una linea de un txt (hasta encontrar un '\0') y la guarda en una variable con la estructura especificada
 */
Episodio leerTXT(FILE *ptrFile)
{
    //inicializo la variable con la estructura que necesito
    Episodio episodio;
    //inicializo una cadena de caracteres donde se va a guardar la línea a leer
    char buffer[500];
    //si la linea no tiene nada, regresa la estructura como NULL y termina la funcion
    if (fgets(buffer, 500, ptrFile) == NULL)
    {
        return episodio;
    }

    //Ahora la asignación dentro de la estructura

    //para convertir de string a int se usa atoi()
    //para convertir de string a float se usa atof()
    //strtok crea un token (conjunto de caracteres que se leyó), strtok(de donde empieza a leer, separador) ..Luego de la primera lectura se debe colocar NULL para que siga leyendo desde donde quedó
    episodio.idSerie = atoi(strtok(buffer, ","));
    episodio.numeroTemporada = atoi(strtok(NULL, ","));
    episodio.cantDescargas = atoi(strtok(NULL, ","));
    //strcpy(var, variable que quiero que se copie)
    strcpy(episodio.titulo, strtok(NULL, ","));
    episodio.numeroEpisodio = atoi(strtok(NULL, ","));
    episodio.ultimaDescarga = atoi(strtok(NULL, ","));

    //Si el último dato a leer es un string se añade "\n" en los separadores del strtok

    //se retorna la estructura
    return episodio;
}

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;
typedef struct
{
    int codigo; //1 a 100
    char apellido[26];
    char nombre[26];
    Fecha fechaNacimiento;    // dd/mm/yyyy
    int calificacionPromedio; //1 a 5
    int paquetesEntregados;
} Repartidor;

void generarArray(Repartidor *repartidores, FILE *ptrNominasTxt)
{
    Repartidor repatidor;

    repatidor = leerTXT(ptrNominasTxt);

    int contador = 0;
    while (!feof(ptrNominasTxt))
    {
        repartidores[contador] = repatidor;
        contador++;
        repatidor = leerTXT(ptrNominasTxt);
    }
    return;
}
