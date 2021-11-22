//MI-1 Dados dos valores enteros A y B, informar la suma, la resta y el producto.
#include <iostream>
using namespace std;

int main()
{

	int numeroA, numeroB;
	int suma, resta, producto;

	cout << "Ingrese el primer número: " << endl;
	cin >> numeroA;
	cout << "Ingrese el segundo número: " << endl;
	cin >> numeroB;

	suma = numeroA + numeroB;
	resta = numeroA - numeroB;
	producto = numeroA * numeroB;

	cout << "La suma es: " << suma << endl;
	cout << "La resta es: " << resta << endl;
	cout << "El producto es: " << producto << endl;
}