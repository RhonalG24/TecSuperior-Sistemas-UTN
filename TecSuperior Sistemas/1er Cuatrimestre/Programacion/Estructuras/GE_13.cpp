/*
Ej. 13: Una empresa carga los datos del presentismo de sus empleados ingresando por cada empleado:
Legajo (entero de 8 dígitos) y por cada día del mes un 1 si se presentó a trabajar o un 0 si faltó. Para
simplificar, todos los empleados trabajan 31 días. Realizar un programa que permita:
a- Cargar los datos de N empleados, siendo N también informado por el usuario
b- Informar los legajos de los tres empleados con mejor presentismo
c- Informar el número del día con mayor ausentismo.
*/

#include <iostream>
using namespace std;
#define CANT_DIAS 31
#define CANT_MEJORES_EMPLEADOS 3

typedef struct
{
    int legajo;
    int presentismos[CANT_DIAS];
    int presentismoTotal;
} Empleado;

void leerInt(string mensaje, int &valor);
void verificarPresentismo(int presentismo, int &presentismoTotal, int &ausentismosDelDia);
void verificarMejoresEmpleados(int legajo, int presentismoTotal, Empleado mejoresEmpleados[]);
void mostrarMejoresEmpleados(Empleado mejoresEmpleados[]);
void buscarMayorAusentismo(int ausentismo[], int &mayorAusentismo, int &diaMayorAusentismo);

int main()
{
    int cantEmpleados;
    leerInt("Ingrese la cantidad de empleados a procesar: ", cantEmpleados);

    Empleado empleados[cantEmpleados]; //vector de empleados

    Empleado mejoresEmpleados[CANT_MEJORES_EMPLEADOS]; //vector para los 3 mejores empleados
    mejoresEmpleados->presentismoTotal = {0};          //el campo presentismoTotal de todos los mejores empleados se inicializa en 0
    int ausentismo[CANT_DIAS] = {0};                   //vector de ausentismos por día
    int mayorAusentismo, diaMayorAusentismo;

    for (int i = 0; i < cantEmpleados; i++)
    {
        leerInt("Ingrese el legajo del empleado: ", empleados[i].legajo);
        empleados[i].presentismoTotal = 0;

        for (int j = 0; j < CANT_DIAS; j++)
        {
            cout << "Día " << j + 1 << ":" << endl;
            leerInt("¿Se presentó? (1 para sí o 0 para no): ", empleados[i].presentismos[j]);
            cout << endl;

            verificarPresentismo(empleados[i].presentismos[j], empleados[i].presentismoTotal, ausentismo[j]);
        }

        verificarMejoresEmpleados(empleados[i].legajo, empleados[i].presentismoTotal, mejoresEmpleados);
    }
    buscarMayorAusentismo(ausentismo, mayorAusentismo, diaMayorAusentismo);
    mostrarMejoresEmpleados(mejoresEmpleados);
    cout << "El día con más ausentimo fue el día " << diaMayorAusentismo + 1 << " con " << mayorAusentismo << endl;
    return 0;
}

void leerInt(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

/**
 * Verifica el valor del presentismo
 * Si es 1, aumenta el presentismo total del empleado.
 * Si es 0, aumenta el ausentismo total del día en el vector correspondiente. 
 */
void verificarPresentismo(int presentismo, int &presentismoTotal, int &ausentismosDelDia)
{
    if (presentismo == 0)
    {
        ausentismosDelDia++;
    }
    else
    {
        presentismoTotal++;
    }
    return;
}

void verificarMejoresEmpleados(int legajo, int presentismoTotal, Empleado mejoresEmpleados[])
{
    if (presentismoTotal > mejoresEmpleados[0].presentismoTotal)
    {
        mejoresEmpleados[2].presentismoTotal = mejoresEmpleados[1].presentismoTotal;
        mejoresEmpleados[2].legajo = mejoresEmpleados[1].legajo;

        mejoresEmpleados[1].presentismoTotal = mejoresEmpleados[0].presentismoTotal;
        mejoresEmpleados[1].legajo = mejoresEmpleados[0].legajo;

        mejoresEmpleados[0].presentismoTotal = presentismoTotal;
        mejoresEmpleados[0].legajo = legajo;
    }
    else
    {
        if (presentismoTotal > mejoresEmpleados[1].presentismoTotal)
        {
            mejoresEmpleados[2].presentismoTotal = mejoresEmpleados[1].presentismoTotal;
            mejoresEmpleados[2].legajo = mejoresEmpleados[1].legajo;

            mejoresEmpleados[1].presentismoTotal = presentismoTotal;
            mejoresEmpleados[1].legajo = legajo;
        }
        else
        {
            if (presentismoTotal > mejoresEmpleados[2].presentismoTotal)
            {
                mejoresEmpleados[2].presentismoTotal = presentismoTotal;
                mejoresEmpleados[2].legajo = legajo;
            }
        }
    }
    return;
}

void mostrarMejoresEmpleados(Empleado mejoresEmpleados[])
{
    cout << "Los mejores empleados fueron: " << endl;
    cout << "   Legajo \t Presentismo" << endl;
    for (int i = 0; i < CANT_MEJORES_EMPLEADOS; i++)
    {
        cout << i + 1 << "° " << mejoresEmpleados[i].legajo << "\t\t" << mejoresEmpleados[i].presentismoTotal << endl;
    }
    cout << endl;
    return;
}

/**
 * retorna la posición del mayor ausentismo y la cantidad
 */
void buscarMayorAusentismo(int ausentismo[], int &mayorAusentismo, int &diaMayorAusentismo)
{
    mayorAusentismo = 0;
    for (int i = 0; i < CANT_DIAS; i++)
    {
        if (ausentismo[i] > mayorAusentismo)
        {
            mayorAusentismo = ausentismo[i];
            diaMayorAusentismo = i;
        }
    }
    return;
}