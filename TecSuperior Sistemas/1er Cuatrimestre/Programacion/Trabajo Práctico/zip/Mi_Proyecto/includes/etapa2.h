#include "comun.h"

int convertirKmAMetros(int distancia);
int convertirMinutosASegundos(int tiempo);
float calcularlVelocidadMedia(int distancia, int tiempo);
ST_Entrenamiento cargarVueltasDelEntrenamiento(int distancia);
void mostrarVuelta(int numero, ST_Vuelta vuelta);
void mostrarVectorVueltas(ST_Vuelta vueltas[], int cantidad);
void mostrarVectorMejoresVueltas(ST_Vuelta vueltas[], int cantidad, float velocidadMediaEntrenamiento);
void buscarVuelta(ST_Vuelta vueltas[]);