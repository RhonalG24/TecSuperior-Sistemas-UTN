/*

Introducción
Un ciclista desea obtener una aplicación que le permita obtener datos estadísticos sobre sus
entrenamientos con el fin de mejorar en su actividad.
El ciclista nos cuenta que registra una cantidad aleatoria de vueltas, que elige también de forma
aleatoria, de las 20 vueltas que realiza en cada entrenamiento.
De cada vuelta siempre se conoce:
● Su posición (primera vuelta, segunda vuelta, etc)
● Su duración, expresada como un número entero en el formato MMSS
(minutos,segundos)
También se conoce la extensión de la vuelta expresada en Km, para todas las vueltas es la
misma ya que el ciclista realiza los entrenamientos en un circuito cerrado.

Etapa 1
Desarrollar una aplicación que permita al ciclista:
a. Cargar los datos de las vueltas seleccionadas. Se debe poder cargar los datos de una
cantidad arbitraria de vueltas determinada por el ciclista.
b. Cuál fue, de las ingresadas, la vuelta más rápida y su tiempo.
c. Cuál fue, de las ingresadas, la vuelta más lenta y su tiempo.
d. Cuál es el porcentaje de reducción de tiempo entre el peor y mejor tiempo (Tmin / TMax -1)
*/

#include <iostream>

using namespace std;

void leer(string mensaje, int &valor);
void mostrarAlerta(string mensaje);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida);
void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta);
void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta);

int main()
{
    int cantVueltas = 0;
    int distanciaVuelta = 0; //km
    int numeroDeVuelta = 0;
    int tiempoVueltaMMSS = 0;

    int vueltaMasRapida = 0;
    int tiempoVueltaMasRapida = 0;
    int vueltaMasLenta = 0;
    int tiempoVueltaMasLenta = 0;

    leer("Ingrese la cantidad de vueltas: ", cantVueltas);
    verificarCondicion(cantVueltas, 0, "La cantidad de vueltas tiene que ser mayor a 0", "Ingrese la cantidad de vueltas: ");
    leer("Ingrese la distancia del circuito: ", distanciaVuelta);

    int contador = 0;
    while (contador < cantVueltas)
    {
        leer("Ingrese el numero de la vuelta: ", numeroDeVuelta);
        leer("Ingrese el tiempo de la vuelta (MMSS): ", tiempoVueltaMMSS);
        verificarCondicion(tiempoVueltaMMSS, 0, "El tiempo de las vueltas tiene que ser mayor a 0", "Ingrese el tiempo de la vuelta (MMSS): ");
        calcularVueltaMasRapida(tiempoVueltaMMSS, tiempoVueltaMasRapida, vueltaMasRapida, numeroDeVuelta);
        calcularVueltaMasLenta(tiempoVueltaMMSS, tiempoVueltaMasLenta, vueltaMasLenta, numeroDeVuelta);
        contador++;
    }

    cout << "La vuelta mas rapida fue la " << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida << endl;
    cout << "La vuelta mas lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMasLenta << endl;

    if (tiempoVueltaMasRapida != 1)
    {
        float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);
        cout << "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;
    }
    else
    {
        cout << "No se puede calcular el porcentaje." << endl;
    }

    system("pause");

    return 0;
}

void leer(string mensaje, int &valor)
{
    cout << mensaje << endl;
    cin >> valor;
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
