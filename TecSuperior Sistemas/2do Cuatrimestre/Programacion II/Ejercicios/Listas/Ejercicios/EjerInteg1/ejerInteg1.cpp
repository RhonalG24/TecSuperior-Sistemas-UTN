/*
Ejercicio 1
Una empresa desea realizar el resumen mensual de las horas trabajadas y horas de ausencia de sus
empleados. Para realizar el cálculo cuenta con un archivo binario “HORAS_DIARIAS.dat” donde cada
registro se compone de los siguientes datos:
● Legajo del empleado: 10 caracteres
● Día del mes: número de 1 a 31
● Horas: número entero de 1 a 24
● Ausencia: 1 o 0 (si es 1: las Horas son horas de ausencia, si es 0: las Horas son horas
trabajadas)
El archivo se encuentra desordenado y por haber distintos turnos puede haber más de un registro
por día de un mismo empleado. Se solicita:

a. Definir la estrategia y estructuras necesarias para la lectura del archivo y realización
de los puntos b. y c.
b. Imprimir por pantalla el listado de las horas imputadas por cada empleado para el
mes, ordenado por legajo en forma creciente. imprimiendo:

Legajo  Hs.Trabajadas   Hs. Ausencia    % Ausentismo (HA / HT + HA)

c. Indicar el día del mes con mayor cantidad de Horas de Ausencia
d. Indicar el legajo con mayor Ausentismo

*/
/*
    Abrir el archivo
    crear lista para los datos
    crear array dias del mes

    empleado = leer archivo
    mientras no sea fin de archivo{
        cargarNodo(list, empleado){
            datos->legajo = archivo.legajo;
            datos->horas = archivo.horas;
            dato->ausencia = archivo.ausencia;        
        }
        if(insertWithoutDuplicates == )
        insertarNodoOrdenado() //por legajo
        
        if(ausencia=1){
            diasMes[archivo.dia]++;
        }


        empleado = leer archivo
    }

    cerrar el archivo
*/

typedef struct
{
    char legajo[11];
    int dia;
    int horas;
    bool ausencia;
} Diarias; //HORAS_DIARIAS.dat

typedef struct
{
    char legajo[11];
    int horas;
    bool ausencia;
} Dato; //para  llenar la lista

typedef struct nodo
{
    Dato dato;
    struct nodo *ste;
} STR_NODO;