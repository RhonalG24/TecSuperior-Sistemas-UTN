#include "includes/etapa1.h"
#include "includes/etapa2.h"
#include "includes/etapa3.h"

int main()
{
    mostrar("\n\t##########################################");
    mostrar("\n\tTSSI - Laboratorio de Programación I\n");
    mostrar("\n\tTrabajo Práctico - Ciclista\n");
    mostrar("\t1er Cuatrimestre 2021\n");
    mostrar("\t##########################################\n\n");

    int distanciaCircuito; //km

    leer("\tIngrese la distancia del circuito (En KM): ", distanciaCircuito);
    int distanciaEnMetros = convertirKmAMetros(distanciaCircuito);

    int anio, mes;
    do
    {
        leer("\tIngrese año (YYYY): ", anio);
        leer("\tIngrese mes (MM): ", mes);
    } while (!esFechaValida(anio, mes));

    int diasMes = obtenerCantidadDiasMes(anio, mes);

    ST_Entrenamiento entrenamientos[diasMes];

    for (int i = 0; i < diasMes; i++)
    {
        ST_Entrenamiento entrenamiento = cargarVueltasDelEntrenamiento(distanciaEnMetros);
        entrenamientos[i] = entrenamiento;
    }

    int opcion;
    bool repetir = true;
    do
    {
        mostrar("\t¿Qué desea hacer ahora? \n");
        mostrar("\t 1. Mostrar todas las vueltas \n");
        mostrar("\t 2. Mostrar las mejores vueltas\n");
        mostrar("\t 3. Buscar una vuelta \n");
        mostrar("\t 4. Mostrar entrenamiento con vuelta más rápida \n");
        mostrar("\t 5. Mostrar entrenamiento con vuelta más lenta \n");
        mostrar("\t 0. Salir \n\n");
        leer("\t Indique el número de su opcion: ", opcion);
        switch (opcion)
        {
        case 1:
        {
            for (int i = 0; i < diasMes; i++)
            {
                mostrarVectorVueltas(entrenamientos[i].vueltas, CANT_VUELTAS);
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < diasMes; i++)
            {
                mostrarVectorMejoresVueltas(entrenamientos[i].vueltas, CANT_VUELTAS, entrenamientos[i].velocidadMedia);
            }
            break;
        }
        case 3:
        {
            bool repetirLocal = false;
            int opcionDia;
            do
            {
                leer("\t¿A qué día pertenece la vuelta que desea buscar?: ", opcionDia);
                if (opcionDia > diasMes || opcionDia < 0)
                {
                    mostrar("\tIngresó un día incorrecto.");
                    repetirLocal = true;
                }
                else if (opcionDia == 0)
                {
                    repetirLocal = false;
                }
            } while (repetirLocal);

            ordenarEntrenamientosPorDia(entrenamientos, diasMes);
            int pos = buscarPosicionEntrenamientoPorDia(entrenamientos, diasMes, opcionDia);
            if (pos == -1)
            {
                mostrar("\tNo existe un entrenamiento para el día solicitado.");
            }
            else
            {
                buscarVuelta(entrenamientos[pos].vueltas);
            }
            break;
        }
        case 4:
        {
            ordenarEntrenamientosPorTiempoVueltaMasRapida(entrenamientos, diasMes);
            mostrarEntrenamientoVueltaMasRapida(entrenamientos, diasMes);
            break;
        }
        case 5:
        {
            ordenarEntrenamientosPorTiempoVueltaMasLenta(entrenamientos, diasMes);
            mostrarEntrenamientoVueltaMasLenta(entrenamientos, diasMes);
            break;
        }
        case 0:
        {
            repetir = false;
            break;
        }
        default:
        {
            mostrar("\tOpción no válida.\n");
            break;
        }
        }
    } while (repetir);

    return 0;
}