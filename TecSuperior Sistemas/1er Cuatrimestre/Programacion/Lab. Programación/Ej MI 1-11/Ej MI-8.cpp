/* Ej. MI-8: Dado un triángulo representado por sus lados L1, L2, L3, determinar e imprimir una le&&enda según sea:
equilátero, isósceles o escalenos. */

#include <iostream>
using namespace std;

int main()
{

    float lado1, lado2, lado3;
    string mensaje;

    cout << "Ingrese el primer lado: " << endl;
    cin >> lado1;
    cout << "Ingrese el segundo lado: " << endl;
    cin >> lado2;
    cout << "Ingrese el tercer lado: " << endl;
    cin >> lado3;

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1)
    {
        if (lado1 == lado2 && lado2 == lado3 && lado1 == lado3)
        {
            mensaje = "Es un triángulo equilátero:";
        }
        else
        {
            if ((lado1 == lado2 && lado1 != lado3 && lado2 != lado3) || (lado1 == lado3 && lado1 != lado2 && lado3 != lado2) || (lado2 == lado3 && lado2 != lado1 && lado3 != lado1))
            {
                mensaje = "Es un triángulo isósceles.";
            }
            else
            {
                if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3)
                {
                    mensaje = "Es un triángulo escaleno.";
                }
            }
        }
    }
    else
    {
        mensaje = "No es un triángulo.";
    }

    cout << mensaje << endl;
    return 0;
}