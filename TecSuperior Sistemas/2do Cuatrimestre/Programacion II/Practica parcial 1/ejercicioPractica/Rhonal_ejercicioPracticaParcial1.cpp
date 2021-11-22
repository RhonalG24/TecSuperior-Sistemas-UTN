/*
Ejercicio
Una empresa de repartos posee un archivo binario con las entregas realizadas(REGISTRADAS) en el día
DIARIAS.DAT, con la siguiente estructura:
    ● Identificador de entrega (30 caracteres max.)
    ● Peso del paquete (numero con decimales)
    ● Entregado (verdadero o falso)
    ● Calificación del cliente (nro de 1 a 5)
El Identificador de cada entrega se forma con la hora de registro, código de repartidor y DNI
del cliente separados por -
    <HHMMSS (hora de registro de la entrega)>-<COD. REPARTIDOR>-<DNI CLIENTE>
Ejemplo: 221301-15-30231967

Además se tiene un archivo de texto NOMINA.txt con los repartidores activos en el día, con
la siguiente información (separada por ; )

    Código Repartidor (1 a 100)
    Apellido (25 caracteres max.)
    Nombre (25 caracteres max)
    Fecha de nacimiento (como dd/mm/yyyy)
    Calificación promedio (nro de 1 a 5)
    Paquetes entregados
El archivo NOMINA se encuentra ordenado en forma ascendente por Codigo de Repartidor
y como máximo la empresa tiene 100 repartidores activos
Se solicita realizar el diagrama y codificación del programa que permita:
    ● Procesar las entregas diarias y al finalizar generar un nuevo archivo NOMINA.txt con
    los valores actualizados de calificación y paquetes entregados para cada repartidor
    ● Generar un archivo binario PENDIENTES.DAT con los datos de las entregas que no
    se han podido entregar
    ● Anexar en el archivo de texto CLIENTES_PENDIENTES.txt una nueva linea por
    cada entrega que no se haya entregado indicando

        ○ HHMMSS
        ○ DNI del cliente
        ○ Peso del paquete


Estrategia
    Abrir archivos DIARIAS.DAT (read), NOMINA.txt (read), PENDIENTES.DAT (write), CLIENTES_PENDIENTES.txt (append)
    Crear array de Repartidores
    Leer archivo de las entregas y por cada campo ir actualizando el array de Repartidores con PUP
        Entregado? {
            Actualizar datos del repartidor
                -izo la info (calificación y paquetes entregados) del array usando el codigo del repartid Guardo el codigo del repartidor del id de la entrega usando strtok
                - Actualor como indice en el array
        } Sino {
            Añadir al archivo PENDIENTES.DAT
                misma estructura
            Añadir linea en CLIENTES_PENDIENES.txt
                -Desmenuso el id de la entrega con strtok para obtener HHMMSS y DNI del cliente
                - Los copio al archivo junto con el peso del parquete
        }
    Generar el nuevo archivo NOMINA.txt usando el array de Repartidores
    Cerrar los archivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REPARTIDORES 100

typedef struct
{
    char id[31]; //<HHMMSS (hora de registro de la entrega)>-<COD. REPARTIDOR>-<DNI CLIENTE>
    float peso;
    bool entregado;
    int calificacion; //nro de 1 a 5
} Entrega;

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

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
Repartidor leerTXT(FILE *ptrFile);
void generarArray(Repartidor *repartidores, FILE *ptrNominasTxt);
void actualizarRegistro(Entrega entrega, Repartidor *repartidores);
void llenarClientesPendientes(Entrega entrega, FILE *ptrClientesPendTxt);
void generarNomina(Repartidor *repartidores, FILE *ptrNominas2Txt);

int main()
{
    FILE *ptrDiariasDat = abrirArchivo("DIARIAS.DAT", "rb");
    FILE *ptrNominasTxt = abrirArchivo("NOMINA.txt", "r"); // separada por ;
    FILE *ptrPendientesDat = abrirArchivo("PENDIENTES.DAT", "wb");
    FILE *ptrClientesPendTxt = abrirArchivo("CLIENTES_PENDIENES.txt", "a");

    Repartidor repartidores[MAX_REPARTIDORES]; //ordenado en forma ascendente por Codigo de Repartidor y como máximo la empresa tiene 100 repartidores activos
    generarArray(repartidores, ptrNominasTxt);

    Entrega entrega;

    fread(&entrega, sizeof(Entrega), 1, ptrDiariasDat);
    while (!feof(ptrDiariasDat))
    {

        if (entrega.entregado)
        {
            actualizarRegistro(entrega, repartidores); //actualiza el registro del repartidor
            /*
            Actualizar datos del repartidor
                - Guardo el codigo del repartidor del id de la entrega usando strtok
                - Actualizo la info (calificación y paquetes entregados) del array usando el codigo del repartidor como indice en el array
            */
        }
        else
        {
            fwrite(&entrega, sizeof(Entrega), 1, ptrPendientesDat); //Copio en el archivo de entregas pendientes
            llenarClientesPendientes(entrega, ptrClientesPendTxt);  //Agrego linea al archivo de clientes pendientes

            /*
            Añadir al archivo PENDIENTES.DAT
                misma estructura
            Añadir linea en CLIENTES_PENDIENES.txt
                -Desmenuso el id de la entrega con strtok para obtener HHMMSS y DNI del cliente
                - Los copio al archivo junto con el peso del parquete
            */
        }
        fread(&entrega, sizeof(Entrega), 1, ptrDiariasDat);
    }

    fclose(ptrNominasTxt);

    //Generar Nomina actualizada
    FILE *ptrNominas2Txt = abrirArchivo("NOMINA2.txt", "a");
    generarNomina(repartidores, ptrNominas2Txt);

    fclose(ptrNominas2Txt);

    fclose(ptrDiariasDat);
    fclose(ptrPendientesDat);
    fclose(ptrClientesPendTxt);

    remove("NOMINA.txt");
    rename("NOMINA2.txt", "NOMINA.txt");
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

Repartidor leerTXT(FILE *ptrFile)
{
    //inicializo la variable con la estructura que necesito
    Repartidor repartidor;
    //inicializo una cadena de caracteres donde se va a guardar la línea a leer
    char buffer[255];
    //si la linea no tiene nada, regresa la estructura como NULL y termina la funcion
    if (fgets(buffer, 255, ptrFile) == NULL)
    {
        return repartidor;
    }

    //Ahora la asignación dentro de la estructura

    //para convertir de string a int se usa atoi()
    //para convertir de string a float se usa atof()
    //strtok crea un token (conjunto de caracteres que se leyó), strtok(de donde empieza a leer, separador) ..Luego de la primera lectura se debe colocar NULL para que siga leyendo desde donde quedó
    repartidor.codigo = atoi(strtok(buffer, ";"));
    //strcpy(var, variable que quiero que se copie)
    strcpy(repartidor.apellido, strtok(NULL, ";"));
    strcpy(repartidor.nombre, strtok(NULL, ";"));
    repartidor.fechaNacimiento.dia = atoi(strtok(NULL, "/"));
    repartidor.fechaNacimiento.mes = atoi(strtok(NULL, "/"));
    repartidor.fechaNacimiento.anio = atoi(strtok(NULL, ";"));
    repartidor.calificacionPromedio = atoi(strtok(NULL, ";"));
    repartidor.paquetesEntregados = atoi(strtok(NULL, ";"));

    //Si el último dato a leer es un string se añade "\n" en los separadores del strtok

    //se retorna la estructura
    return repartidor;
}

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

void actualizarRegistro(Entrega entrega, Repartidor *repartidores)
{
    char *aux;
    strcpy(aux, entrega.id); //copio el registro para no dañar el original

    strtok(aux, "-"); //descarto la HHMMSS porque no la necesito
    int codRepartidor = atoi(strtok(NULL, "-"));
    int pos = codRepartidor - 1;

    repartidores[pos].paquetesEntregados++;
    repartidores[pos].calificacionPromedio = (repartidores[pos].calificacionPromedio + entrega.calificacion) / 2;
    return;
}

void llenarClientesPendientes(Entrega entrega, FILE *ptrClientesPendTxt)
{
    char aux[26];
    strcpy(aux, entrega.id);

    int hora = atoi(strtok(aux, "-"));
    strtok(NULL, "-");
    int dni = atoi(strtok(NULL, "-"));

    fprintf(ptrClientesPendTxt, "%d,%d,%.2f", hora, dni, entrega.peso);
    return;
}

void generarNomina(Repartidor *repartidores, FILE *ptrNominas2Txt)
{

    for (int i = 0; i < MAX_REPARTIDORES; i++)
    {
        fprintf(ptrNominas2Txt, "%d;%s;%s;%d/%d/%d;%d;%d\n", repartidores[i].codigo, repartidores[i].apellido, repartidores[i].nombre, repartidores[i].fechaNacimiento.dia, repartidores[i].fechaNacimiento.mes, repartidores[i].fechaNacimiento.anio, repartidores[i].calificacionPromedio, repartidores[i].paquetesEntregados);
    }
    return;
}