#include <iostream>

using namespace std;

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
    return;
}

float calcularPorcentajeReduccionTiempo(float tiempoVueltaMasLenta, float tiempoVueltaMasRapida) {
    return tiempoVueltaMasLenta / tiempoVueltaMasRapida - 1;
}

void calcularVueltaMasRapida(int tiempoVueltaMMSS, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int numeroDeVuelta) {
    if (tiempoVueltaMMSS > tiempoVueltaMasRapida) {
        tiempoVueltaMasRapida = tiempoVueltaMMSS;
        vueltaMasRapida = numeroDeVuelta;
    }
    return;
}

void calcularVueltaMasLenta(int tiempoVueltaMMSS, int &tiempoVueltaMasLenta, int &vueltaMasLenta, int numeroDeVuelta) {
    if (tiempoVueltaMMSS < tiempoVueltaMasLenta || tiempoVueltaMasLenta == 0) {
        tiempoVueltaMasLenta = tiempoVueltaMMSS;
        vueltaMasLenta = numeroDeVuelta;
    }
    return;
}

int main () {
    int cantVueltas = 0;
    int distanciaVuelta = 0;
    int numeroDeVuelta = 0;
    int tiempoVueltaMMSS = 0;

    int vueltaMasRapida = 0;
    int tiempoVueltaMasRapida = 0;
    int vueltaMasLenta = 0;
    int tiempoVueltaMasLenta = 0;

    leer("Ingrese la cantidad de vueltas: ", cantVueltas);
    leer("Ingrese la distancia del circuito: ", distanciaVuelta);
    
    if (cantVueltas <= 0) {
        cout << "La cantidad de vueltas tiene que ser mayor a 0" << endl;        
        return 0;
    }

    int contador = 0;
    while(contador < cantVueltas) {
        leer("Ingrese el numero de vuelta: ", numeroDeVuelta);
        leer("Ingrese el tiempo de la vuelta: ", tiempoVueltaMMSS);

        if (tiempoVueltaMMSS > 0000) {
            calcularVueltaMasRapida(tiempoVueltaMMSS, tiempoVueltaMasRapida, vueltaMasRapida, numeroDeVuelta);
            calcularVueltaMasLenta(tiempoVueltaMMSS, tiempoVueltaMasLenta, vueltaMasLenta, numeroDeVuelta);
            contador++;
        }
    }

    float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);

    cout << "La vuelta mas rapida fue la " << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida << endl;
    cout << "La vuelta mas lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMasLenta << endl;
    cout << "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;

    system("pause");

    return 0;
}