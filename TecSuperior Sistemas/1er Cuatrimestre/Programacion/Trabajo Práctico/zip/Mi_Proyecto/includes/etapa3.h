#include "comun.h"

bool esFechaValida(int anio, int mes);
bool esAnioBisisesto(int anio);
int obtenerCantidadDiasMes(int anio, int mes);
void ordenarEntrenamientosPorTiempoVueltaMasRapida(ST_Entrenamiento entrenamientos[], int diasMes);
void ordenarEntrenamientosPorTiempoVueltaMasLenta(ST_Entrenamiento entrenamientos[], int diasMes);
void mostrarEntrenamientoVueltaMasRapida(ST_Entrenamiento entrenamientos[], int diasMes);
void mostrarEntrenamientoVueltaMasLenta(ST_Entrenamiento entrenamientos[], int diasMes);
int buscarPosicionVueltaEntrenamiento(ST_Vuelta vueltas[], int cantVueltas, int numeroVuelta);
void ordenarEntrenamientosPorDia(ST_Entrenamiento entrenamientos[], int diasMes);
int buscarPosicionEntrenamientoPorDia(ST_Entrenamiento entrenamientos[], int diasMes, int diaSolicitado);