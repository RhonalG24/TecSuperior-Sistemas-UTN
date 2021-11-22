#include "../includes/etapa3.h"

bool esFechaValida(int anio, int mes)
{
    if (anio < 1000 || anio > 9999)
    {
        mostrar("Año no válido");
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        mostrar("Mes no válido");
        return false;
    }
    return true;
}

bool esAnioBisisesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 100 == 0 && anio % 400 == 0))
    {
        return true;
    }
    return false;
}

int obtenerCantidadDiasMes(int anio, int mes)
{
    int cantidadDias = 0;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cantidadDias = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cantidadDias = 30;
        break;
    case 2:
        cantidadDias = 28;
        if (esAnioBisisesto(anio))
        {
            cantidadDias += 1;
        }
        break;
    default:
        cantidadDias = 0;
        break;
    }
    return cantidadDias;
}

void ordenarEntrenamientosPorTiempoVueltaMasRapida(ST_Entrenamiento entrenamientos[], int diasMes)
{
    int i, j;
    ST_Entrenamiento aux;
    bool ordenado = false;
    while (i < diasMes && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < diasMes - 1 - i; j++)
        {
            if (entrenamientos[j].tiempoVueltaMasRapida > entrenamientos[j + 1].tiempoVueltaMasRapida)
            {
                aux = entrenamientos[j];
                entrenamientos[j] = entrenamientos[j + 1];
                entrenamientos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
};

void ordenarEntrenamientosPorTiempoVueltaMasLenta(ST_Entrenamiento entrenamientos[], int diasMes)
{
    int i, j;
    ST_Entrenamiento aux;
    bool ordenado = false;
    while (i < diasMes && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < diasMes - 1 - i; j++)
        {
            if (entrenamientos[j].tiempoVueltaMasLenta < entrenamientos[j + 1].tiempoVueltaMasLenta)
            {
                aux = entrenamientos[j];
                entrenamientos[j] = entrenamientos[j + 1];
                entrenamientos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
};

void ordenarEntrenamientosPorDia(ST_Entrenamiento entrenamientos[], int diasMes)
{
    int i, j;
    ST_Entrenamiento aux;
    bool ordenado = false;
    while (i < diasMes && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < diasMes - 1 - i; j++)
        {
            if (entrenamientos[j].fecha.dia > entrenamientos[j + 1].fecha.dia)
            {
                aux = entrenamientos[j];
                entrenamientos[j] = entrenamientos[j + 1];
                entrenamientos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
};

int buscarPosicionVueltaEntrenamiento(ST_Vuelta vueltas[], int cantVueltas, int numeroVuelta)
{
    int inicio = 0;
    int fin = cantVueltas - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (vueltas[mitad].numeroVuelta == numeroVuelta)
        {
            return mitad;
        }
        if (vueltas[mitad].numeroVuelta > numeroVuelta)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
};

void mostrarEntrenamientoVueltaMasRapida(ST_Entrenamiento entrenamientos[], int diasMes)
{
    ST_Entrenamiento mejorEntrenamiento = entrenamientos[0];
    int pos = buscarPosicionVueltaEntrenamiento(mejorEntrenamiento.vueltas, CANT_VUELTAS, mejorEntrenamiento.vueltaMasRapida);
    if (pos == -1)
    {
        mostrar("\tNo se encontró la vuelta más rápida del entrenamiento.");
        return;
    }
    ST_Vuelta vueltaMasRapida = mejorEntrenamiento.vueltas[pos];
    mostrar("\tEntrenamiento con la vuelta más rapida:");
    cout << "\tFecha\t\tTiempo\t\tNro de vuelta\t\tVelocidad media" << endl;
    cout << "\t" << mejorEntrenamiento.fecha.dia << "/" << mejorEntrenamiento.fecha.mes << "/" << mejorEntrenamiento.fecha.anio
         << "\t" << vueltaMasRapida.tiempoMMSS << "\t\t" << vueltaMasRapida.numeroVuelta << "\t\t\t" << vueltaMasRapida.velocidadMedia << "\n\n"
         << endl;
    return;
};

void mostrarEntrenamientoVueltaMasLenta(ST_Entrenamiento entrenamientos[], int diasMes)
{
    ST_Entrenamiento peorEntrenamiento = entrenamientos[0];
    int pos = buscarPosicionVueltaEntrenamiento(peorEntrenamiento.vueltas, CANT_VUELTAS, peorEntrenamiento.vueltaMasLenta);
    if (pos == -1)
    {
        mostrar("\tNo se encontró la vuelta más lenta del entrenamiento.");
        return;
    }
    ST_Vuelta vueltaMasLenta = peorEntrenamiento.vueltas[pos];
    mostrar("\tEntrenamiento con la vuelta más lenta:");
    cout << "\tFecha\t\tTiempo\t\tNro de vuelta\t\tVelocidad media" << endl;
    cout << "\t" << peorEntrenamiento.fecha.dia << "/" << peorEntrenamiento.fecha.mes << "/" << peorEntrenamiento.fecha.anio
         << "\t" << vueltaMasLenta.tiempoMMSS << "\t\t" << vueltaMasLenta.numeroVuelta << "\t\t\t" << vueltaMasLenta.velocidadMedia << "\n\n"
         << endl;
    return;
};

int buscarPosicionEntrenamientoPorDia(ST_Entrenamiento entrenamientos[], int diasMes, int diaSolicitado)
{
    int inicio = 0;
    int fin = diasMes - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (entrenamientos[mitad].fecha.dia == diaSolicitado)
        {
            return mitad;
        }
        if (entrenamientos[mitad].fecha.dia > diaSolicitado)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
};