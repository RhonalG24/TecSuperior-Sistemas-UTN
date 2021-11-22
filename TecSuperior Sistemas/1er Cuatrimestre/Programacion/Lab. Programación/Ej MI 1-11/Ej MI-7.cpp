/* Ej. MI-7: Dado tres valores determinar e imprimir una 
leyenda según sea: “Forman triangulo” o “No forman triángulo”. */

#include <iostream>
using namespace std;

int main()
{
    float lado1 = 0;
    float lado2 = 0;
    float lado3 = 0;
    string mensaje;

    cout << "Ingrese el primer lado: " << endl;
    cin >> lado1;
    cout << "Ingrese el segundo lado: " << endl;
    cin >> lado2;
    cout << "Ingrese el tercer lado: " << endl;
    cin >> lado3;

    if ((lado1 + lado2 > lado3) && (lado2 + lado3 > lado1) && (lado1 + lado3 > lado2))
    {
        mensaje = "Forman triangulo.";
    }
    else
    {
        mensaje = "No forman triangulo.";
    }

    cout << mensaje << endl;
    return 0;
}