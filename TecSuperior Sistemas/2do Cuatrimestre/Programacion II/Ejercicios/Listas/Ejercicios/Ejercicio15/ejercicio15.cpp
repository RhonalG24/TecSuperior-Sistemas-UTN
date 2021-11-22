/*
Dado un archivo de registros de alumnos, donde cada registro contiene: 
    a) Apellido y Nombre del alumno (35 caracteres) 
    b) Número de legajo (7 dígitos) 
    c) División asignada (1 a 100) 
ordenado por número de legajo, 
desarrollar el algoritmo y codificación del programa que imprima el listado de alumnos por división, ordenado por​ ​ división​ ​ y ​ ​ número​ ​ de​ ​ legajo​ ​ crecientes,​ ​ a ​ ​ razón​ ​ de​ ​ 55​ alumnos​ ​ por​ ​ hoja.


ingreso el archivo en una cola

    alumno = read();
    while (!FEOF(ptrReg)){
        pos = alumno.division -1;
        add(queue[div], alumno);
        alumno = read();


corte de control

while()

for (int div = 1; div <= 100; i++){
    int contadorAlumnos = 0;
    if(contadorAlumnos == 55-1)
        print(Nueva Hoja!)
        print(alumno\n)
        contadorAlumnos = 0;

    else{
        print(alumno\n)
        contadorAlumnos++;
    }    
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_DIVISION 100

typedef struct
{
    char apellidoNombre[36];
    int legajo;
    int division; //1 a 100
} Alumno;

typedef struct nodo
{
    Alumno dato;
    nodo *ste;
} STR_NODO;

typedef struct queue
{
    STR_NODO *fte;
    STR_NODO *fin;
} STR_QUEUE;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);

bool isEmpty(STR_QUEUE queue)
{
    return queue.fte == NULL && queue.fin == NULL;
}

STR_QUEUE create()
{
    STR_QUEUE queue;
    queue.fte = NULL;
    queue.fin = NULL;
    return queue;
}

/**
 * Crea un vector de colas
 * Se le ingresa la cantidad de colas a crear
 */
void crearVectorDeColas(STR_QUEUE *queue, int cantColas)
{

    for (int i = 0; i < cantColas; i++)
    {
        queue[i] = create();
    }
    return;
}

void add(STR_QUEUE *queue, Alumno valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    if (queue->fte == NULL)
    {
        queue->fte = nodo;
    }
    else
    {
        queue->fin->ste = nodo;
    }
    queue->fin = nodo;
}

Alumno remove(STR_QUEUE *queue)
{
    STR_NODO *aux = queue->fte;
    Alumno valor = queue->fte->dato;
    queue->fte = queue->fte->ste;

    if (queue->fte == NULL)
    {
        queue->fin = NULL;
    }

    free(aux);
    return valor;
}

void print(STR_QUEUE *queue)
{
    while (!isEmpty(*queue))
    {
        printf("%d\n", remove(queue));
    }
}

void printDatos(STR_QUEUE *queue)
{
    Alumno alumno;
    while (!isEmpty(*queue))
    {
        alumno = remove(queue);
        printf("%d %s\n", alumno.legajo, alumno.apellidoNombre);
    }
}
void crearDAT(FILE *ptrArchivo)
{
    Alumno alumno;
    int divisiones[12] = {1, 5, 8, 9, 4, 6, 2, 1, 5, 7, 6};                                                               //11
    char nombres[11][36] = {"Rhonal", "Andres", "Edita", "Mora", "Raul", "Hector", "Claudet", "Maylube", "Marcos", "\0"}; //9
    int div = 0, names = 0, leg = 0;

    for (int i = 0; i < 200; i++)
    {

        strcpy(alumno.apellidoNombre, nombres[names]);
        alumno.division = divisiones[div];
        alumno.legajo = leg;
        fwrite(&alumno, sizeof(alumno), 1, ptrArchivo);
        // add(&queue[alumno.division], alumno);
        div++;
        if (div >= 11)
        {
            div = 0;
        }
        names++;
        if (names >= 9)
        {
            names = 0;
        }
        leg++;
    }
}

int main()
{
    //creo archivo
    FILE *ptrAlumnosDat = abrirArchivo("alumnos.dat", "wb");
    crearDAT(ptrAlumnosDat);
    fclose(ptrAlumnosDat);

    //comienzo del ejercicio
    ptrAlumnosDat = abrirArchivo("alumnos.dat", "rb");

    STR_QUEUE queue[CANT_DIVISION];
    crearVectorDeColas(queue, CANT_DIVISION);

    Alumno alumno;
    fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
    while (!feof(ptrAlumnosDat))
    {
        int nroDivision = alumno.division - 1;
        add(&queue[nroDivision], alumno);

        fread(&alumno, sizeof(alumno), 1, ptrAlumnosDat);
    }

    fclose(ptrAlumnosDat);

    /*
    int divisiones[12] = {1, 5, 8, 9, 4, 6, 2, 1, 5, 7, 6};                                                               //9
    char nombres[10][36] = {"Rhonal", "Andres", "Edita", "Mora", "Raul", "Hector", "Claudet", "Maylube", "Marcos", "\0"}; //9
    int div = 0, names = 0, leg = 0;

    for (int i = 0; i < 200; i++)
    {

        strcpy(alumno.apellidoNombre, nombres[names]);
        alumno.division = divisiones[div];
        alumno.legajo = leg;
        add(&queue[alumno.division], alumno);
        div++;
        if (div >= 12)
        {
            div = 0;
        }
        names++;
        if (names >= 9)
        {
            names = 0;
        }
        leg++;
    }
*/

    for (int i = 0; i < CANT_DIVISION; i++)
    {
        printf("Division %d: \n", i + 1);
        if (!isEmpty(queue[i]))
        {
            printDatos(&queue[i]);
        }
        printf("\n");
    }

    // printf("La cola %s esta vacía", isEmpty(queue) ? "" : "NO ");

    return 0;
}

/**
 * Pasa el contenido de la cola pasada por parametro a una nueva.
 * En funcion: *newQueue = pasarCola(&queue)
 */
STR_QUEUE pasarCola(STR_QUEUE *queue)
{
    STR_QUEUE newQueue = create();
    Alumno value;
    while (!isEmpty(*queue))
    {
        value = remove(queue);
        add(&newQueue, value);
    }
    return newQueue;
}
// // para copiar a otra cola mientras se saca de la original
// while(!isEmpty(*queue)){
// // add(&newQueue, remove(queue));
// }

STR_QUEUE ordenar(STR_QUEUE *original)
{
    STR_QUEUE queueOrd = create();
    STR_QUEUE queueCand = create();
    STR_QUEUE queueAux = create();

    Alumno numOriginal;
    Alumno numCand;

    while (!isEmpty(*original))
    {
        numOriginal = remove(original);
        add(&queueCand, numOriginal);

        while (!isEmpty(*original))
        {
            numOriginal = remove(original);
            numCand = remove(&queueCand);

            if (numCand.legajo <= numOriginal.legajo)
            {
                add(&queueCand, numCand);
                add(&queueAux, numOriginal);
            }
            else
            {
                add(&queueCand, numOriginal);
                add(&queueAux, numCand);
            }
        }
        numCand = remove(&queueCand);
        add(&queueOrd, numCand);

        *original = pasarCola(&queueAux);
    }

    return queueOrd;
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