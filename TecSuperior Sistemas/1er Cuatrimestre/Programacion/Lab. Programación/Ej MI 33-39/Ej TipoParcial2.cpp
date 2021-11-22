/*
Ejercicio 1
Una empresa que necesita realizar un estudio sobre el impacto de su actividad sobre el medioambiente, le encarga que
desarrolle un software que le permita obtener estadísticas sobre el clima en la zona en que se ubica la empresa.
Para llevar a cabo esta tarea, el gerente de producción le especifica que las variables de interés son temperatura y humedad.
Ambos son números reales.
El gerente también nos comenta que para poder ingresar los datos, el usuario deberá ingresar una letra “T” para indicar
temperatura o una letra “H” para indicar humedad y a continuación deberá ingresar la medición correspondiente. La carga
de datos finaliza cuando el usuario ingresa la letra “F”.
Al finalizar la carga de datos, el programa deberá indicar:
● la temperatura máxima, la temperatura mínima.
● El promedio de humedad

Entrada 
    char opcion ('T', 'H' o 'F')
    float temperatura
    float humedad

Salida
    float temperaturaMaxima
    float temperaturaMinima
    float promedioHumedad

Top-Down main
    - Pedir qué se ingresará (temp o humedad)
    - Pedir medición correspondiente 
    - Verificar la temperatura
    - Calcular promedio de humedad
    - Mostrar resultados

Estrategia:
    pedirOpcion()
    mientras(opcion)
        if(opcion == 'T')
            pedirMedicion()
            verificarTemperatura()
        else
            pedirMedicion()
            sumarHumedad()

        pedirOpcion()
    FinMientras

    calcularPromedioHumedad()

    mostrarDatos()

*/

#include <iostream>
using namespace std;

char pedirOpcion(string mensaje);
float pedirMedicion(string mensaje);
void verificarTemperatura(float temperatura, float &temperaturaMinima, float &temperaturaMaxima, bool &primeraTempMaxima, bool &primeraTempMinima);
void sumarHumedad(float humedad, float &promedioHumedad, int &contador);
void calcularPromedioHumedad(float &promedioHumedad, int contador);
void mostrarMedicion(string mensaje, float medicion, char opcion);

int main()
{
    char opcion;
    float temperatura;
    float temperaturaMaxima = 0;
    float temperaturaMinima = 0;
    bool primeraTempMaxima = true; //Por si la temperatura mayor nunca es mayor a 0
    bool primeraTempMinima = true; //Por si la temperatura menor es 0 o mayor a 0
    float humedad = -1;
    float promedioHumedad = 0;
    int contador = 0;

    opcion = pedirOpcion("¿Qué ingresará? ('T' para Temperatura, 'H' para Humedad o 'F' para terminar): ");

    while (opcion != 'F')
    {
        if (opcion == 'T')
        {
            temperatura = pedirMedicion("Ingrese la medición de temperatura: ");
            verificarTemperatura(temperatura, temperaturaMinima, temperaturaMaxima, primeraTempMaxima, primeraTempMinima);
        }
        else
        {
            humedad = pedirMedicion("Ingrese la medición de humedad: ");
            sumarHumedad(humedad, promedioHumedad, contador);
        }

        opcion = pedirOpcion("¿Qué ingresará ahora? ('T' para Temperatura, 'H' para Humedad o 'F' para terminar): ");
    }

    calcularPromedioHumedad(promedioHumedad, contador);

    mostrarMedicion("La temperatura máxima fue de ", temperaturaMaxima, 'T');
    mostrarMedicion("La temperatura mínima fue de ", temperaturaMinima, 'T');
    mostrarMedicion("El promedio de humedad es de ", promedioHumedad, 'H');

    return 0;
}

char pedirOpcion(string mensaje)
{
    char option;
    cout << mensaje << endl;
    cin >> option;
    cout << endl;
    return option;
}

float pedirMedicion(string mensaje)
{
    float medicion;
    cout << mensaje << endl;
    cin >> medicion;
    cout << endl;
    return medicion;
}

void verificarTemperatura(float temperatura, float &temperaturaMinima, float &temperaturaMaxima, bool &primeraTempMaxima, bool &primeraTempMinima)
{
    if (temperatura > temperaturaMaxima || primeraTempMaxima == true)
    {
        temperaturaMaxima = temperatura;
        primeraTempMaxima = false;
    }
    if (temperatura < temperaturaMinima || primeraTempMinima == true)
    {
        temperaturaMinima = temperatura;
        primeraTempMinima = false;
    }
    return;
}

void sumarHumedad(float humedad, float &promedioHumedad, int &contador)
{
    promedioHumedad += humedad;
    contador++;
    return;
}

void calcularPromedioHumedad(float &promedioHumedad, int contador)
{
    if (promedioHumedad == 0)
    {
        return;
    }
    else
    {
        promedioHumedad /= contador;
        return;
    }
}

void mostrarMedicion(string mensaje, float medicion, char opcion)
{
    if (opcion == 'T')
    {
        if (medicion == 0)
        {
            cout << "No se ingresó ninguna temperatura." << endl;
        }
        else
        {
            cout << mensaje << medicion << "°." << endl;
            return;
        }
    }
    else
    {

        if (medicion == 0)
        {
            cout << "No se ingresó ninguna medición de humedad." << endl;
        }
        else
        {
            cout << mensaje << medicion << "%." << endl
                 << endl;
            return;
        }
    }
}