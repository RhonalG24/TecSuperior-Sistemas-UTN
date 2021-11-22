/*
APAREO

obtener un 3er vector combinando otros dos

a) Anexar: uno detrás del otro
vector A: 3 -2 1
vector B: 8  5 0
------
resultado: 3 -2 1 8 5 0

ejemplo


*/
#include <iostream>
using namespace std;

int main()
{

    return 0;
}

//En caso de que los vectores vengan ordenandos
void apareo(int vecA[], int n, int vecB[], int m, int vecC[], int &k)
{
    //contadores para la posicion de los vectores A y B
    int i = 0, j = 0;
    //contador para la posicion del vector resultante
    k = 0;

    //mientras pueda comparar valores
    while (i < n && j < m)
    {

        if (vecA[i] < vecB[j])
        {
            vecC[k] = vecA[i];
            i++; //me muevo en el vector A
        }
        else
        {
            vecC[k] = vecB[j];
            j++;
        }
        k++;
    }
    //Para kos valores restantes de los vectores
    while (i < n)
    {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while (j < m)
    {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}

//********************* Corte de Control **************
/*
Permite obtener informacion a partie de un conjunto de datos

Listado, cantidades, promedios, etc, agrupados con algun criterio, y 
parte de la base de que los datos originales cumplen o se puede hacer que cumplan con el agrupamiento 
necesario para su procesamiento.

permite obtener información a partir de un conjunto
de datos de forma eficiente realizando la menor cantidad
de lecturas posibles
*/

struct ST_HABITANTE
{
    int dni;
    string nombreCompleto;
    int provincia;
};

ST_HABITANTE padron[45000000];

//cargar vectores
//mostrar un listado de las provincias y su cantidad de habitantes

//Ejemplo

//Necesitas el vector ORDENADO!**

// void listar(Struct vec[], int n)
void contarHabitantes(ST_HABITANTE vec[], int n)
{
    int i = 0;
    int habitantes = 0;
    int key;

    while (i < n)
    { //corte de control
        key = vec[i].provincia;
        habitantes = 0;

        while (i < n && key == vec[i].provincia)
        { //agrupamiento
            habitantes++;
            i++;
        }

        cout << "Provincia: " << key << " habitantes: " << habitantes << endl;
    }
}

//más general
struct MiEstructura
{
    int codigo;
};

void corteDeControl(MiEstructura vector[], int cantidadDeElementos)
{
    //inicializacion de variables para recorrer vector
    int i = 0;
    //inicializacion de variables para obtener resultados variables
    int resultado = 0;
    int clave;

    //mientras tenga elementos el vector
    while (i < cantidadDeElementos)
    {
        //fijar la clave
        clave = vector[i].codigo;

        //inicializar las variables de resultados
        resultado = 0;

        //ciclo para obtener resultados parciales
        //mientras tenga elementos el vector y se mantenga la clave
        while (i < cantidadDeElementos && clave == vector[i].codigo)
        {
            //calculos para obtener resultados parciales

            //avanzamos i
        }
        //muestro resultados parciales
    }
}

// PARA 3 solicitudes, ejemplo
struct MiEstructura2
{
    int codigo;
    int dpto;
};
void corteDeControl(MiEstructura2 vector[], int cantidadDeElementos)
{
    //inicializacion de variables para recorrer vector
    int i = 0;
    //inicializacion de variables para obtener resultados variables
    int resultado = 0;
    int clave, dpto_key, hab_dpto;

    //mientras tenga elementos el vector
    while (i < cantidadDeElementos)
    {
        //fijar la clave
        clave = vector[i].codigo;

        //inicializar las variables de resultados
        resultado = 0;

        //ciclo para obtener resultados parciales
        //mientras tenga elementos el vector y se mantenga la clave
        while (i < cantidadDeElementos && clave == vector[i].codigo)
        {
            //calculos para obtener resultados parciales
            dpto_key = vector[i].dpto;

            hab_dpto = 0;

            while (i < cantidadDeElementos && clave == vector[i].codigo && dpto_key == vector[i].dpto)
            {
                //avanzamos i
                i++;
            }
            //mostrar hab_dpto
        }
        //muestro resultados parciales (mostrar hab_codProv)
    }
}