//Dado un valor M determinar y emitir un listado con los M primeros m�ltiplos de 3 que no lo sean de 5,
//dentro del conjunto de los n�meros naturales.

#include <iostream>
using namespace std;

int main()
{
	int nMultiplos;
	int multiploDe3 = 3;

	cout << "Ingrese cuántos múltiplos quiere mostrar" << endl;
	cin >> nMultiplos;

	int i = 0;

	while (i < nMultiplos)
	{
		if (multiploDe3 % 5 != 0)
		{
			i = i + 1;
			cout << multiploDe3 << ", ";
		}
		multiploDe3 = multiploDe3 + 3;
	}
	cout << endl;
	return 0;
}