#include "../includes/etapa1.h"

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void mostrar(string mensaje)
{
    cout << mensaje << endl;
    return;
}

void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor)
{
    while (valor <= condicion)
    {
        mostrar(mensajeAlerta);
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