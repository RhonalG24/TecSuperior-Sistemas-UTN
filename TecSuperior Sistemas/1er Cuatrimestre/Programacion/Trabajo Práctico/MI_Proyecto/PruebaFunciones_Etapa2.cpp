#include <iostream>
using namespace std;

#define MAX_VUELTAS 20

typedef struct
{
    // int numero;
    // ST_Fecha fecha;
    int fecha;
    int tiempoMMSS;
    float velocidadMedia;
} ST_Vuelta;

void leer(string mensaje, int &valor);
int convertirKmAMetros(int distancia);
int convertirMinutosASegundos(int tiempo);
float calcularlVelocidadMedia(int distancia, int tiempo);
void cargarVueltasDelEntrenamiento(ST_Vuelta vueltas[], int cantidad, int distancia, float &velocidadMediaEntrenamiento);
void mostrarVuelta(int numero, ST_Vuelta vuelta);
void mostrarVectorVueltas(ST_Vuelta vueltas[], int cantidad);
void mostrarVectorMejoresVueltas(ST_Vuelta vueltas[], int cantidad, float velocidadMediaEntrenamiento);
void buscarVuelta(ST_Vuelta vueltas[]);

int main()
{

    ST_Vuelta vueltas[5];
    int distancia;                     //km
    float velocidadMediaEntrenamiento; // m/s

    leer("Ingrese la distancia del circuito (En KM): ", distancia);
    int distanciaEnMetros = convertirKmAMetros(distancia);

    cargarVueltasDelEntrenamiento(vueltas, 5, distanciaEnMetros, velocidadMediaEntrenamiento);
    mostrarVectorVueltas(vueltas, 5);
    mostrarVectorMejoresVueltas(vueltas, 5, velocidadMediaEntrenamiento);
    buscarVuelta(vueltas);

    return 0;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

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
    return distancia / (tiempoEnSegundos - 0);
}

/**
 * Procedimiento para cargar todas las vueltas de un entrenamiento
 * Retorna a su vez la velocidad media de dicho entrenamiento
 * Parámetros:
 * - Vector de las vueltas
 * - Cantidad de vueltas a cargar
 * - Distancia del circuito
 * - Variable para cargar la velocidad media del entrenamiento
 */
void cargarVueltasDelEntrenamiento(ST_Vuelta vueltas[], int cantidad, int distancia, float &velocidadMediaEntrenamiento)
{
    int i = 0;        //contador del while
    int nroVuelta;    //variable para cargar el vector de vueltas según el número de la vuelta
    ST_Vuelta vuelta; //variable auxiliar para cargar el vector de las vueltas

    //Carga de la fecha del entrenamiento
    leer("Ingrese la fecha del entrenamiento (Formato AAAAMMDD): ", vuelta.fecha); //se carga en todas las vueltas del vector

    while (i < cantidad)
    {
        cout << "Registro N° " << i + 1 << "/" << cantidad << endl
             << endl; //Muestra la cantidad de vueltas registradas
        leer("Ingrese el número de la vuelta a cargar: ", nroVuelta);
        leer("Ingrese el tiempo de la vuelta (MMSS): ", vuelta.tiempoMMSS);
        vuelta.velocidadMedia = calcularlVelocidadMedia(distancia, vuelta.tiempoMMSS); //Carga la velicidad media de la vuelta
        cout << endl;

        //carga del vector con método PUP
        vueltas[nroVuelta - 1] = vuelta;

        velocidadMediaEntrenamiento += vuelta.velocidadMedia;
        i++;
    }
    velocidadMediaEntrenamiento /= cantidad;

    cout << "La velocidad media del entrenamiento fue de " << velocidadMediaEntrenamiento << " m/s." << endl
         << endl;

    return;
}

/**
 * Procedimiento para mostrar la información de una vuelta en una línea
 * numero    fecha      tiempo   velMedia
 */
void mostrarVuelta(int numero, ST_Vuelta vuelta)
{
    //numero    fecha      tiempo   velMedia (m/s)
    cout << numero + 1 << "\t\t" << vuelta.fecha << "\t" << vuelta.tiempoMMSS << "\t\t" << vuelta.velocidadMedia << endl;
    return;
}

void mostrarVectorVueltas(ST_Vuelta vueltas[], int cantidad)
{
    cout << "Número\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        mostrarVuelta(i, vueltas[i]);
    }
    cout << endl;
    return;
}

void mostrarVectorMejoresVueltas(ST_Vuelta vueltas[], int cantidad, float velocidadMediaEntrenamiento)
{
    cout << "Las vueltas que superaron la velocidad media del entrenamiento fueron: " << endl
         << endl;
    cout << "Número\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
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
    leer("Ingrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    while (valorBuscado != 0)
    {
        posicion = valorBuscado - 1;

        cout << "Número\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
        mostrarVuelta(posicion, vueltas[posicion]);
        cout << endl;

        leer("Ingrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    }
    return;
}