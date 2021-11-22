//a) El valor m�ximo negativo
//b) El valor m�nimo positivo
//c) El valor m�nimo dentro del rango -17.3 y 26.9
//d) El promedio de todos los valores.
//
//e)EN QUE POSICI�N SE ENCONTR� EL MAYOR Y EL MENOR?

#include <iostream>
using namespace std;

int main()
{

    float num;
    int cantNumeros = 0;
    float valorMaximoNeg = 0;
    float valorMinimoPos = 0;
    float minDelRango = 0;
    float promedio = 0;
    int posicionMayor;
    int posicionMenor;

    cout << "Ingrese un numero (o 0 para salir): " << endl;
    cin >> num;

    while (num != 0)
    {
        cantNumeros++;
        promedio = promedio + num;

        if (num < 0)
        {
            if (num > valorMaximoNeg || valorMaximoNeg == 0)
            {
                valorMaximoNeg = num;
                posicionMenor = cantNumeros;
            }
        }
        else if (num > 0)
        {
            if (num < valorMinimoPos || valorMinimoPos == 0)
            {
                valorMinimoPos = num;
                posicionMayor = cantNumeros;
            }
        }

        if (num >= -17.3 && num <= 26.9)
        {
            if (num < minDelRango || minDelRango == 0)
            {
                minDelRango = num;
            }
        }

        cout << "Ingrese otro numero (o 0 para salir): " << endl;
        cin >> num;
    }

    if (cantNumeros == 0)
    {
        cout << "No se ingresaron valores." << endl;
    }
    else
    {
        promedio = promedio / cantNumeros;

        cout << "El valor maximo entre los negativos fue: " << valorMaximoNeg << " y fue ingresado en la posicion " << posicionMenor << endl;
        cout << "El valor minimo entre los positivos fue: " << valorMinimoPos << " y fue ingresado en la posicion " << posicionMayor << endl;

        if (minDelRango == 0)
        {
            cout << "No se ingresaron valores entre -17.3 y 26.9. " << endl;
        }
        else
        {
            cout << "El valor minimo dentro del rango -17.3  y 26.9 fue: " << minDelRango << endl;
        }

        cout << "El promedio es: " << promedio << endl;
    }

    return 0;
}