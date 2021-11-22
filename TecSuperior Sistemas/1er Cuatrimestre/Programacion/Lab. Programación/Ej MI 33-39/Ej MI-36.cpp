/* Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de simplificaciones. 
Desarrolle y utilice una función que reciba dos números naturales y retorne el menor factor común.
 Ej: 360/60 = 180/30 = 90/15 = 30/5 = 6/1*/

#include <iostream>
using namespace std;

int pedirNumero(string mensaje);
int calcularMCD(int valorA, int valorB);
void fraccionar(int valorP, int valorQ, int &menorFactor, int &cantSimplificaciones);

int main()
{
    int menorFactorComun = 1;
    int cantSimplificaciones = 0;

    //pedir
    int num1 = pedirNumero("Ingrese un número: ");
    int num2 = pedirNumero("Ingrese otro numero: ");

    //fraccionar y cantSimplificaciones
    fraccionar(num1, num2, menorFactorComun, cantSimplificaciones);

    //salida
    cout << "El menor factor común entre " << num1 << " y " << num2 << " es " << menorFactorComun << endl;
    cout << "Ambos se simplificaron " << cantSimplificaciones << " veces." << endl
         << endl;
    return 0;
}

int pedirNumero(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

void fraccionar(int valorP, int valorQ, int &menorFactor, int &cantSimplificaciones)
{
    int i = 2;
    int factorComun = 0;

    while (calcularMCD(valorP, valorQ) > 1)
    {
        if (valorP % i == 0 && valorQ % i == 0)
        {
            valorP /= i;
            valorQ /= i;
            factorComun = i;
            cantSimplificaciones++;
        }
        else
        {
            i++;
        }

        if (factorComun < menorFactor || menorFactor == 1)
        {
            menorFactor = factorComun;
        }
    }

    return;
}

int calcularMCD(int valorA, int valorB)
{
    int resto = valorA % valorB;

    while (resto > 0)
    {
        valorA = valorB;
        valorB = resto;
        resto = valorA % valorB;
    }

    return valorB;
}