#include "../includes/etapa1.h"
#include "../includes/etapa2.h"

/**
 * Función para pasar de KM a metros
 */
int convertirKmAMetros(int distancia)
{
    return distancia * 1000;
}

/**
 * Función para convertir de minutos(MMSS) a segundos
 */
int convertirMinutosASegundos(int tiempo)
{
    return (tiempo / 100) * 60 + tiempo % 100;
}

/**
 * Calcula la velicidad media de una vuelta
 * Recibe el tiempo en minutos y lo pasa a segundos para retornar las velocidad media en m/s
 */
float calcularlVelocidadMedia(int distancia, int tiempo)
{
    int tiempoEnSegundos = convertirMinutosASegundos(tiempo);
    return (float)distancia / tiempoEnSegundos;
}

ST_Fecha convertirFecha(int fecha)
{
    ST_Fecha stFecha;
    stFecha.anio = fecha / 10000;
    stFecha.mes = (fecha % 10000) / 100;
    stFecha.dia = fecha % 100;
    return stFecha;
};

/**
 * Procedimiento para cargar todas las vueltas de un entrenamiento
 * Muestra y retorna a su vez la velocidad media de dicho entrenamiento
 * Muestra también la vuelta más rápida, la más lenta y la relación de reducción de tiempo 
 * Parámetros:
 * - Distancia del circuito
 */
ST_Entrenamiento cargarVueltasDelEntrenamiento(int distancia)
{
    ST_Entrenamiento entrenamiento;

    int i = 0; //contador del while

    int nroVuelta;                 //variable para cargar el vector de vueltas según el número de la vuelta
    int vueltaMasRapida = 0;       // Variable para cargar el número de la vuelta más rápida
    int tiempoVueltaMasRapida = 0; // Variable para cargar el tiempo de la vuelta más rápida
    int vueltaMasLenta = 0;        // Variable para cargar el número de la vuelta más lenta
    int tiempoVueltaMasLenta = 0;  // Variable para cargar el tiempo de la vuelta más lenta
    float velocidadMediaEntrenamiento = 0;

    ST_Vuelta vuelta; // Variable auxiliar para cargar el vector de las vueltas

    // Carga de la fecha del entrenamiento
    leer("\tIngrese la fecha del entrenamiento (Formato AAAAMMDD): ", vuelta.fecha); //se carga en todas las vueltas del vector
    entrenamiento.fecha = convertirFecha(vuelta.fecha);

    while (i < CANT_VUELTAS)
    {
        cout << "\tRegistro N° " << i + 1 << "/" << CANT_VUELTAS << endl
             << endl; //Muestra la cantidad de vueltas registradas
        leer("\tIngrese el número de la vuelta a cargar: ", nroVuelta);
        vuelta.numeroVuelta = nroVuelta;
        leer("\tIngrese el tiempo de la vuelta (MMSS): ", vuelta.tiempoMMSS);
        vuelta.velocidadMedia = calcularlVelocidadMedia(distancia, vuelta.tiempoMMSS); //Carga la velicidad media de la vuelta
        cout << endl;

        calcularVueltaMasRapida(vuelta.tiempoMMSS, tiempoVueltaMasRapida, vueltaMasRapida, nroVuelta);
        calcularVueltaMasLenta(vuelta.tiempoMMSS, tiempoVueltaMasLenta, vueltaMasLenta, nroVuelta);

        //carga del vector con método PUP
        entrenamiento.vueltas[nroVuelta - 1] = vuelta;

        velocidadMediaEntrenamiento += vuelta.velocidadMedia;
        i++;
    }

    cout << "\tLa vuelta más rápida fue la " << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida << endl;
    cout << "\tLa vuelta más lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMasLenta << endl;

    if (tiempoVueltaMasRapida != 0)
    {
        float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);
        cout << "\tEl porcentaje de reducción de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;
    }
    else
    {
        cout << "\tNo se puede calcular el porcentaje." << endl;
    }
    cout << endl;

    velocidadMediaEntrenamiento /= CANT_VUELTAS;

    cout << "\tLa velocidad media del entrenamiento fue de " << velocidadMediaEntrenamiento << " m/s." << endl
         << endl;

    entrenamiento.vueltaMasRapida = vueltaMasRapida;
    entrenamiento.tiempoVueltaMasRapida = tiempoVueltaMasRapida;
    entrenamiento.vueltaMasLenta = vueltaMasLenta;
    entrenamiento.tiempoVueltaMasLenta = tiempoVueltaMasLenta;
    entrenamiento.velocidadMedia = velocidadMediaEntrenamiento;

    return entrenamiento;
}

/**
 * Procedimiento para mostrar la información de una vuelta en una línea
 * numero    fecha      tiempo   velMedia
 */
void mostrarVuelta(int numero, ST_Vuelta vuelta)
{
    //numero    fecha      tiempo   velMedia (m/s)
    cout << "\t" << numero + 1 << "\t\t" << vuelta.fecha << "\t" << vuelta.tiempoMMSS << "\t\t" << vuelta.velocidadMedia << endl;
    return;
}

void mostrarVectorVueltas(ST_Vuelta vueltas[], int cantidad)
{
    cout << "\tNúmero\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        mostrarVuelta(i, vueltas[i]);
    }
    cout << endl;
    return;
}

void mostrarVectorMejoresVueltas(ST_Vuelta vueltas[], int cantidad, float velocidadMediaEntrenamiento)
{
    cout << "\tLas vueltas que superaron la velocidad media del entrenamiento fueron: " << endl
         << endl;
    cout << "\tNúmero\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        if (vueltas[i].velocidadMedia > velocidadMediaEntrenamiento)
        {
            mostrarVuelta(i, vueltas[i]);
        }
    }
    cout << endl;
    return;
}

void buscarVuelta(ST_Vuelta vueltas[])
{
    int valorBuscado, posicion;
    leer("\tIngrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    while (valorBuscado != 0)
    {
        if (valorBuscado > CANT_VUELTAS)
        {
            cout << "\tNúmero de vuelta no válido." << endl
                 << endl;
        }
        else
        {
            posicion = valorBuscado - 1;

            cout << "\tNúmero\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
            mostrarVuelta(posicion, vueltas[posicion]);
            cout << endl;
        }
        leer("\tIngrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    }
    return;
}