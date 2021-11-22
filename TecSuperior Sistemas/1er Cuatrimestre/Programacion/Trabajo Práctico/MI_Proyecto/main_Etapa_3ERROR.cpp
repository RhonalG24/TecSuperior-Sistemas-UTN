/*
Etapa 3
En la etapa final, nuestro amigo ciclista desea volver a modificar la aplicación una vez más. En
este caso, quiere poder registrar los entrenamientos realizados en todo 1 mes y obtener datos
de todo el mes de entrenamiento.
El ciclista desea que luego de cargar los datos de todo el mes de entrenamiento, la aplicación
tenga la capacidad de indicarle:
a. Cúal fue el entrenamiento con la vuelta más rápida y su tiempo. Debe mostrar también
los datos de la vuelta correspondiente
b. Cúal fue el entrenamiento con la vuelta más lenta y su tiempo.
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

Etapa 3:
Estructura para los entrenamientos (Lista)
Procedimiento para cargar las vueltas por entrenamiento(Listo)
Mostrar listado de todos los entrenamiento con sus vueltas (Listo)
Calcular entrenamiento con la vuelta más rápida y su tiempo (Listo)
    -mostrar datos de la vuelta correspondiente (Listo)
Calcular entrenamiento con la vuelta más lenta y su tiempo (Listo)

 ** Etapa 3 Lista! **
*/

#include <iostream>
using namespace std;

#define CANT_VUELTAS 20
#define DIAS_DEL_MES 31

typedef struct
{
    int fecha;
    int tiempoMMSS;
    float velocidadMedia; // m/s
} ST_Vuelta;

typedef struct
{
    int fecha;
    ST_Vuelta vueltas[CANT_VUELTAS];
    //int distanciaCircuito; //km
    float velocidadMedia; // m/s
    int vueltaMasRapida;
    int tiempoVueltaMasRapida;
    int vueltaMasLenta;
    int tiempoVueltaMasLenta;
} ST_Entrenamiento;

void leer(string mensaje, int &valor);
float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida);
void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta);
void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta);
int convertirKmAMetros(int distancia);
int convertirMinutosASegundos(int tiempo);
float calcularlVelocidadMedia(int distancia, int tiempo);

//Etapa 3
void mostrarEncabezado();
void mostrarVuelta(int numero, ST_Entrenamiento entrenamiento);
void mostrarVectorVueltas(ST_Entrenamiento entrenamiento[], int cantidadVueltas, int dia);
void mostrarVectorMejoresVueltas(ST_Entrenamiento entrenamiento[], int cantidadVueltas, int dia);
void buscarVuelta(ST_Entrenamiento entrenamiento[], int dia);
void cargarEntrenamientos(ST_Entrenamiento entrenamiento[], int cantDias, int distanciaEnMetros, int &tiempoVueltaMasRapidaDelMes, int &vueltaMasRapidaDelMes, int &tiempoVueltaMasLentaDelMes, int &vueltaMasLentaDelMes);
void cargarVueltasDelEntrenamiento(ST_Entrenamiento &entrenamiento, int cantidadVueltas, int distanciaEnMetros, int &tiempoVueltaMasRapidaDelMes, int &vueltaMasRapidaDelMes, int &tiempoVueltaMasLentaDelMes, int &vueltaMasLentaDelMes);
void mostrarVuelta(int numero, ST_Entrenamiento entrenamiento);

int main()
{
    ST_Entrenamiento entrenamiento[DIAS_DEL_MES];
    int vueltaMasRapidaDelMes = 0, tiempoVueltaMasRapidaDelMes = 0;
    int vueltaMasLentaDelMes = 0, tiempoVueltaMasLentaDelMes = 0;

    int distanciaCircuito; //km
    leer("Ingrese la distancia del circuito (En KM): ", distanciaCircuito);

    int distanciaEnMetros = convertirKmAMetros(distanciaCircuito);

    cargarEntrenamientos(entrenamiento, DIAS_DEL_MES, distanciaEnMetros, tiempoVueltaMasRapidaDelMes, vueltaMasRapidaDelMes, tiempoVueltaMasLentaDelMes, vueltaMasLentaDelMes);

    int opcion;
    int opcionDia;
    leer("¿Qué desea hacer ahora? \n 1- Mostrar todas las vueltas del entrenamiento \n 2- Mostrar las mejores vueltas\n 3- Buscar una vuelta \n 0- Salir \n\n Indique el número de su opcion: ", opcion);
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            leer("Ingrese el número del día para ver el listado correspondiente o 0 para verlas todas: ", opcionDia);
            if (opcionDia == 0)
            {
                for (opcionDia = 0; opcionDia < DIAS_DEL_MES; opcionDia++)
                {
                    mostrarVectorVueltas(entrenamiento, CANT_VUELTAS, opcionDia);
                }
            }
            else if (opcionDia > DIAS_DEL_MES || opcionDia < 0)
            {
                cout << "Ingresó un día inválido. " << endl
                     << endl;
            }
            else
            {
                mostrarVectorVueltas(entrenamiento, CANT_VUELTAS, opcionDia - 1);
            }

            break;

        case 2:
            leer("¿De cuál día desea ver las mejores vueltas?: ", opcionDia);
            if (opcionDia > DIAS_DEL_MES || opcionDia < 0)
            {
                cout << "Ingresó un día inválido. " << endl
                     << endl;
            }
            else
            {

                mostrarVectorMejoresVueltas(entrenamiento, CANT_VUELTAS, opcionDia - 1);
            }
            break;

        case 3:
            leer("¿A qué día pertenece la vuelta que desea buscar?: ", opcionDia);
            if (opcionDia > DIAS_DEL_MES || opcionDia < 0)
            {
                cout << "Ingresó un día inválido. " << endl
                     << endl;
            }
            else
            {
                buscarVuelta(entrenamiento, opcionDia - 1);
            }
            break;

        case 0:
            break;
        default:
            cout << "Opcion no válida." << endl;
            break;
        }
        leer("¿Qué desea hacer ahora? \n 1- Mostrar todas las vueltas del entrenamiento\n 2- Mostrar las mejores vueltas\n 3- Buscar una vuelta \n 0- Salir \n\n Indique el número de su opcion: ", opcion);
    }

    return 0;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
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

void mostrarEncabezado()
{
    cout << "N° vuelta\tFecha\t\tTiempo(MMSS)\tVelocidad Media(m/s)" << endl;
    return;
}

/**
 * Procedimiento para mostrar la información de una vuelta en una línea
 * numero    fecha      tiempo   velMedia
 */
void mostrarVuelta(int numero, ST_Entrenamiento entrenamiento)
{
    //numero    fecha      tiempo   velMedia (m/s)
    cout << numero + 1 << "\t\t" << entrenamiento.vueltas[numero].fecha << "\t" << entrenamiento.vueltas[numero].tiempoMMSS << "\t\t" << entrenamiento.vueltas[numero].velocidadMedia << endl;
    return;
}

void mostrarVectorVueltas(ST_Entrenamiento entrenamiento[], int cantidadVueltas, int dia)
{
    cout << "Entrenamiento del " << dia + 1 << "° día: " << endl;
    mostrarEncabezado();
    for (int i = 0; i < cantidadVueltas; i++)
    {
        mostrarVuelta(i, entrenamiento[dia]);
    }
    cout << endl;
    return;
}

void mostrarVectorMejoresVueltas(ST_Entrenamiento entrenamiento[], int cantidadVueltas, int dia)
{
    cout << "Las vueltas que superaron la velocidad media del entrenamiento fueron: " << endl
         << endl;
    mostrarEncabezado();
    for (int i = 0; i < cantidadVueltas; i++)
    {
        if (entrenamiento[dia].vueltas[i].velocidadMedia > entrenamiento[dia].velocidadMedia)
        {
            mostrarVuelta(i, entrenamiento[dia]);
        }
    }
    cout << endl;
    return;
}

void buscarVuelta(ST_Entrenamiento entrenamiento[], int dia)
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

            mostrarEncabezado();
            mostrarVuelta(posicion, entrenamiento[dia]);
            cout << endl;
        }
        leer("Ingrese el número de la vuelta que desea ver (0 para terminar): ", valorBuscado);
    }
    return;
}

//////////////////////

void cargarEntrenamientos(ST_Entrenamiento entrenamiento[], int cantDias, int distanciaEnMetros, int &tiempoVueltaMasRapidaDelMes, int &vueltaMasRapidaDelMes, int &tiempoVueltaMasLentaDelMes, int &vueltaMasLentaDelMes)
{
    int diaVueltaMasRapida, diaVueltaMaslenta;

    // tiempoVueltaMasRapidaDelMes = 0;
    // vueltaMasRapidaDelMes = 0;

    for (int i = 0; i < cantDias; i++)
    {
        cout << "Entrenamiento del " << i + 1 << "° día del mes:" << endl
             << endl;

        cargarVueltasDelEntrenamiento(entrenamiento[i], CANT_VUELTAS, distanciaEnMetros, tiempoVueltaMasRapidaDelMes, vueltaMasRapidaDelMes, tiempoVueltaMasLentaDelMes, vueltaMasLentaDelMes);

        cout << "Has terminado con el registro del " << i + 1 << "° día." << endl
             << endl;

        //entrenamiento con vuelta más rápida
        calcularVueltaMasRapida(entrenamiento[i].tiempoVueltaMasRapida, tiempoVueltaMasRapidaDelMes, vueltaMasRapidaDelMes, entrenamiento[i].vueltaMasRapida);
        calcularVueltaMasLenta(entrenamiento[i].tiempoVueltaMasLenta, tiempoVueltaMasLentaDelMes, vueltaMasLentaDelMes, entrenamiento[i].vueltaMasLenta);
        if (entrenamiento[i].tiempoVueltaMasRapida == tiempoVueltaMasRapidaDelMes)
        {
            diaVueltaMasRapida = i;
        }
        if (entrenamiento[i].tiempoVueltaMasLenta == tiempoVueltaMasLentaDelMes)
        {
            diaVueltaMaslenta = i;
        }
    }

    cout << "La vuelta más rápida se dió el " << diaVueltaMasRapida + 1 << "° día del mes. Fue la " << vueltaMasRapidaDelMes << " con un tiempo de " << tiempoVueltaMasRapidaDelMes << endl;
    mostrarEncabezado();
    mostrarVuelta(vueltaMasRapidaDelMes - 1, entrenamiento[diaVueltaMasRapida]);
    cout << endl;

    cout << "La vuelta más lenta se dió el " << diaVueltaMaslenta + 1 << "° día del mes. Fue la " << vueltaMasLentaDelMes << " con un tiempo de " << tiempoVueltaMasLentaDelMes << endl;
    mostrarEncabezado();
    mostrarVuelta(vueltaMasLentaDelMes - 1, entrenamiento[diaVueltaMaslenta]);
    cout << endl;
    return;
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
void cargarVueltasDelEntrenamiento(ST_Entrenamiento &entrenamiento, int cantidadVueltas, int distanciaEnMetros, int &tiempoVueltaMasRapidaDelMes, int &vueltaMasRapidaDelMes, int &tiempoVueltaMasLentaDelMes, int &vueltaMasLentaDelMes)
{
    int i = 0;     //contador del while
    int nroVuelta; //variable para cargar el vector de vueltas según el número de la vuelta

    entrenamiento.vueltaMasRapida = 0;       // Variable para cargar el número de la vuelta más rápida
    entrenamiento.tiempoVueltaMasRapida = 0; // Variable para cargar el tiempo de la vuelta más rápida
    entrenamiento.vueltaMasLenta = 0;        // Variable para cargar el número de la vuelta más lenta
    entrenamiento.tiempoVueltaMasLenta = 0;  // Variable para cargar el tiempo de la vuelta más lenta
    entrenamiento.velocidadMedia = 0;

    ST_Vuelta vuelta; //variable auxiliar para cargar el vector de las vueltas

    //Carga de la fecha del entrenamiento
    leer("Ingrese la fecha del entrenamiento (Formato AAAAMMDD): ", vuelta.fecha); //se carga en todas las vueltas del vector
    entrenamiento.fecha = vuelta.fecha;
    while (i < cantidadVueltas)
    {
        cout << "Registro N° " << i + 1 << "/" << cantidadVueltas << endl
             << endl; //Muestra la cantidad de vueltas registradas
        leer("Ingrese el número de la vuelta a cargar: ", nroVuelta);
        leer("Ingrese el tiempo de la vuelta (MMSS): ", vuelta.tiempoMMSS);
        vuelta.velocidadMedia = calcularlVelocidadMedia(distanciaEnMetros, vuelta.tiempoMMSS); //Carga la velicidad media de la vuelta
        cout << endl;

        calcularVueltaMasRapida(vuelta.tiempoMMSS, entrenamiento.tiempoVueltaMasRapida, entrenamiento.vueltaMasRapida, nroVuelta);
        calcularVueltaMasLenta(vuelta.tiempoMMSS, entrenamiento.tiempoVueltaMasLenta, entrenamiento.vueltaMasLenta, nroVuelta);

        //carga del vector con método PUP
        entrenamiento.vueltas[nroVuelta - 1] = vuelta;

        entrenamiento.velocidadMedia += vuelta.velocidadMedia;
        i++;
    }

    cout << "La vuelta más rápida fue la " << entrenamiento.vueltaMasRapida << " con un tiempo de " << entrenamiento.tiempoVueltaMasRapida << endl;
    cout << "La vuelta más lenta fue la " << entrenamiento.vueltaMasLenta << " con un tiempo de " << entrenamiento.tiempoVueltaMasLenta << endl;

    if (entrenamiento.tiempoVueltaMasRapida != 0)
    {
        float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(entrenamiento.tiempoVueltaMasLenta, entrenamiento.tiempoVueltaMasRapida);
        cout << "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;
    }
    else
    {
        cout << "No se puede calcular el porcentaje." << endl;
    }
    cout << endl;

    entrenamiento.velocidadMedia /= cantidadVueltas;

    cout << "La velocidad media del entrenamiento fue de " << entrenamiento.velocidadMedia << " m/s." << endl
         << endl;

    return;
}
