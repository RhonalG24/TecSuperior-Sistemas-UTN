/*
Top-Down

Pedir direccion
Pedir distancia en metros
Descargar bateria(metros)
sumar distancia recorrida (++)
sumar distancia avanzada (+-)
sumar distancia en direccion (R+)
Informar 

Estrategia:

pedir direccion

Mientras direccion != 'E' O Bateria > 0
    pedir distancia
    
    Descargar bateria()
    
    SumaRecorrido()
    CalculaDistancia()
    SumaTrayectoEnDireccion
    
    Pedir direccion

FinMientras

Mostrar datos
*/

#include <iostream>
using namespace std;

char pedirDireccion(string mensaje);
int pedirDistancia(string mensaje);
void descargarBateria(int &bateria, char distancia);
void sumarRecorrido(int distancia, int &recorrido);
void calcularDistanciaAvanzada(char direccion, int distancia, int &distanciaAvanzada, int &distanciaEnF, int &distanciaEnB, int &distanciaEnL, int &distanciaEnR);
void trayectoMayor(int distanciaEnF, int distanciaEnB, int distanciaEnL, int distanciaEnR, int &trayecto, char &direccionMayor);

int main()
{
    int bateria = 1000;
    int recorrido = 0;
    int distancia = 0;
    int distanciaAvanzada = 0;
    int distanciaEnF = 0;
    int distanciaEnB = 0;
    int distanciaEnL = 0;
    int distanciaEnR = 0;
    int trayecto = 0;
    char direccionMayor = ' ';
    char direccion = ' ';

    direccion = pedirDireccion("Ingrese la dirección en la que desea mover al robot ('F' - Adelante, 'B' - Atrás, 'L' - Izquierda, 'R' - Derecha) O 'E' para terminar: ");

    while (direccion != 'E' && bateria > 0)
    {

        distancia = pedirDistancia("Ingrese la distancia en metros");

        descargarBateria(bateria, distancia);

        sumarRecorrido(distancia, recorrido);
        calcularDistanciaAvanzada(direccion, distancia, distanciaAvanzada, distanciaEnF, distanciaEnB, distanciaEnL, distanciaEnR);
        trayectoMayor(distanciaEnF, distanciaEnB, distanciaEnL, distanciaEnR, trayecto, direccionMayor);
        direccion = pedirDireccion("Ingrese la dirección en la que desea mover al robot ('F' - Adelante, 'B' - Atrás, 'L' - Izquierda, 'R' - Derecha) O 'E' para terminar: ");
    }

    cout << "La cantidad total de metros recorridos fue: " << recorrido << endl;
    cout << "La cantidad total de metros avanzados fue: " << distanciaAvanzada << endl;
    cout << "La dirección en la que se recorrió el trayecto más largo fue: " << direccionMayor << " con un total de " << trayecto << " metros." << endl;

    return 0;
}

char pedirDireccion(string mensaje)
{
    char direccion;
    cout << mensaje << endl;
    cin >> direccion;
    cout << endl;
    return direccion;
}

int pedirDistancia(string mensaje)
{
    int distancia;
    cout << mensaje << endl;
    cin >> distancia;
    cout << endl;
    return distancia;
}

void descargarBateria(int &bateria, char distancia)
{
    if (distancia % 2 == 0)
    {
        bateria -= distancia / 4;
    }
    else
    {
        bateria -= distancia / 3;
    }
    return;
}

void sumarRecorrido(int distancia, int &recorrido)
{
    recorrido += distancia;
}

void calcularDistanciaAvanzada(char direccion, int distancia, int &distanciaAvanzada, int &distanciaEnF, int &distanciaEnB, int &distanciaEnL, int &distanciaEnR)
{
    switch (direccion)
    {
    case 'F':
        distanciaAvanzada += distancia;
        distanciaEnF += distancia;
        break;
    case 'B':
        distanciaAvanzada -= distancia;
        distanciaEnB += distancia;
        break;
    case 'L':
        distanciaAvanzada -= distancia;
        distanciaEnL += distancia;
        break;
    case 'R':
        distanciaAvanzada += distancia;
        distanciaEnR += distancia;
        break;
    }

    return;
}

void trayectoMayor(int distanciaEnF, int distanciaEnB, int distanciaEnL, int distanciaEnR, int &trayecto, char &direccionMayor)
{
    if (distanciaEnF > distanciaEnB && distanciaEnF > distanciaEnL && distanciaEnF > distanciaEnR)
    {
        trayecto = distanciaEnF;
        direccionMayor = 'F';
    }
    if (distanciaEnB > distanciaEnF && distanciaEnB > distanciaEnL && distanciaEnB > distanciaEnR)
    {
        trayecto = distanciaEnB;
        direccionMayor = 'B';
    }
    if (distanciaEnL > distanciaEnB && distanciaEnL > distanciaEnF && distanciaEnL > distanciaEnR)
    {
        trayecto = distanciaEnL;
        direccionMayor = 'L';
    }
    if (distanciaEnR > distanciaEnB && distanciaEnR > distanciaEnL && distanciaEnR > distanciaEnF)
    {
        trayecto = distanciaEnR;
        direccionMayor = 'R';
    }
    return;
}

// string devuelveFrase(){
//     string frase;
//     cout << "Ingrese frase: ";
//     getline(cin, frase);
//     cout << endl;

//     return frase;
// }