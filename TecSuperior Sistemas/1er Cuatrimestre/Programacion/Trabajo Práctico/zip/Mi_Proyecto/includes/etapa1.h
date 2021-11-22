#include "comun.h"

void leer(string mensaje, int &valor);
void verificarCondicion(int &valor, int condicion, string mensajeAlerta, string mensajeValor);
float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida);
void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta);
void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta);