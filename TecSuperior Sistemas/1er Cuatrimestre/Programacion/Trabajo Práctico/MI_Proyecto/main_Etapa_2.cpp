/*
Etapa 2
En esta nueva etapa, el ciclista desea realizar algunos cambios a la aplicación.

Ahora el ciclista desea poder registrar las 20 vueltas, aunque nos avisa que no siempre se
cargan en orden de ocurrencia. Por lo que uno de sus primeros requerimientos es poder ver un
listado con la información de cada vuelta ordenadas según su orden de ocurrencia.

Otro de los requerimientos para esta nueva etapa es poder registrar la fecha del entrenamiento.

Por otra parte, nos solicita poder visualizar un listado de todas las vueltas cuya velocidad
supera la velocidad media del entrenamiento. Tener en cuenta que al disponer de todas las
vueltas del entrenamiento, el cálculo de la velocidad media será: Vm = distancia / Tfin - Tini

Adicionalmente el ciclista desea poder ingresar el número de una vuelta y poder obtener toda su
información (orden, tiempo, fecha, velocidad media de la vuelta).
*/

/*
                    ***REGISTRO DEL PROGRESO***
Etapa 1:
Cargar vueltas
    -calcular vuelta más lenta
    -calcular vuelta más rápida
    -calcular porcentaje de reducción

 ** Etapa 1 Lista! **

Etapa 2:
Cargar fecha del entrenamiento (listo)
Cargar todas las 20 vueltas
    - Calcular velocidad media de cada vuelta en m/s (Listo)  
        *funcion para convertir de km a m (Listo)
        *funcion para convertir de MMSS a SS ..a segundos (Listo)
Calcular velocidad media total del entrenamiento (Listo)

Mostrar listado con todas las vueltas por orden de ocurrencia (Listo)
Mostrar listado con todas las vueltas que superan la velocidad media del entrenamiento (Listo)
Ingresar numero de vuelta y mostrar la información (Listo)
Main (LISTO)

 ** Etapa 2 Lista! **

*/

#include <iostream>

using namespace std;

#define CANT_VUELTAS 20

typedef struct
{
    int fecha;
    int tiempoMMSS;
    float velocidadMedia;
} ST_Vuelta;

void leer(string mensaje, int &valor);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida);
void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta);
void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta);

//Etapa 2
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

    ST_Vuelta vueltas[CANT_VUELTAS];
    int distanciaCircuito; //km

    float velocidadMediaEntrenamiento = 0; // m/s

    int opcion;

    leer("Ingrese la distancia del circuito (En KM): ", distanciaCircuito);
    int distanciaEnMetros = convertirKmAMetros(distanciaCircuito);

    cargarVueltasDelEntrenamiento(vueltas, CANT_VUELTAS, distanciaEnMetros, velocidadMediaEntrenamiento);

    leer("¿Qué desea hacer ahora? \n 1- Mostrar todas las vueltas \n 2- Mostrar las mejores vueltas\n 3- Buscar una vuelta \n 0- Salir \n\n Indique el número de su opcion: ", opcion);
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            mostrarVectorVueltas(vueltas, CANT_VUELTAS);
            break;
        case 2:
            mostrarVectorMejoresVueltas(vueltas, CANT_VUELTAS, velocidadMediaEntrenamiento);
            break;
        case 3:
            buscarVuelta(vueltas);
            break;
        case 0:
            break;
        default:
            cout << "Opcion no válida." << endl;
            break;
        }
        leer("¿Qué desea hacer ahora? \n 1- Mostrar todas las vueltas \n 2- Mostrar las mejores vueltas\n 3- Buscar una vuelta \n 0- Salir \n\n Indique el número de su opcion: ", opcion);
    }

    system("pause");

    return 0;
}

//Funciones Etapa 1
void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void mostrarAlerta(string mensaje)
{
    cout << mensaje << endl;
    return;
}

void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor)
{
    while (valor <= condicion)
    {
        mostrarAlerta(mensajeAlerta);
        leer(mensajeValor, valor);
    }
    return;
}

float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida)
{
    return tiempoVueltaMasLenta / tiempoVueltaMasRapida;
}

void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta)
{
    if (tiempoVueltaMMSS < tiempoVueltaMasRapida || tiempoVueltaMasRapida == 0)
    {
        tiempoVueltaMasRapida = tiempoVueltaMMSS;
        vueltaMasRapida = numeroDeVuelta;
    }
    return;
}

void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta)
{
    if (tiempoVueltaMMSS > tiempoVueltaMasLenta || tiempoVueltaMasLenta == 0)
    {
        tiempoVueltaMasLenta = tiempoVueltaMMSS;
        vueltaMasLenta = numeroDeVuelta;
    }
    return;
}

//Funciones Etapa 2

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
 * Muestra y retorna a su vez la velocidad media de dicho entrenamiento
 * Muestra también la vuelta más rápida, la más lenta y la relación de reducción de tiempo 
 * Parámetros:
 * - Vector de las vueltas
 * - Cantidad de vueltas a cargar
 * - Distancia del circuito
 * - Variable para cargar la velocidad media del entrenamiento
 */
void cargarVueltasDelEntrenamiento(ST_Vuelta vueltas[], int cantidad, int distancia, float &velocidadMediaEntrenamiento)
{
    int i = 0;     //contador del while
    int nroVuelta; //variable para cargar el vector de vueltas según el número de la vuelta

    int vueltaMasRapida = 0;       // Variable para cargar el número de la vuelta más rápida
    int tiempoVueltaMasRapida = 0; // Variable para cargar el tiempo de la vuelta más rápida
    int vueltaMasLenta = 0;        // Variable para cargar el número de la vuelta más lenta
    int tiempoVueltaMasLenta = 0;  // Variable para cargar el tiempo de la vuelta más lenta

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

        calcularVueltaMasRapida(vuelta.tiempoMMSS, tiempoVueltaMasRapida, vueltaMasRapida, nroVuelta);
        calcularVueltaMasLenta(vuelta.tiempoMMSS, tiempoVueltaMasLenta, vueltaMasLenta, nroVuelta);

        //carga del vector con método PUP
        vueltas[nroVuelta - 1] = vuelta;

        velocidadMediaEntrenamiento += vuelta.velocidadMedia;
        i++;
    }

    cout << "La vuelta más rápida fue la " << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida << endl;
    cout << "La vuelta más lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMasLenta << endl;

    if (tiempoVueltaMasRapida != 0)
    {
        float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);
        cout << "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;
    }
    else
    {
        cout << "No se puede calcular el porcentaje." << endl;
    }
    cout << endl;

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
        if (valorBuscado > CANT_VUELTAS)
        {
            cout << "Número de vuelta no válido." << endl
                 << endl;
        }
        else
        {

            posicion = valorBuscado - 1;

            cout << "Número\t\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
            mostrarVuelta(posicion, vueltas[posicion]);
            cout << endl;
        }
        leer("Ingrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    }
    return;
}