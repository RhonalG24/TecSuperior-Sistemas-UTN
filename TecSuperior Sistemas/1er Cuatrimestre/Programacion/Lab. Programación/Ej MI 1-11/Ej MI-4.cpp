/*
Ej. MI-4: A partir de un valor entero ingresado por teclado, se pide informar:
a) La quinta parte de dicho valor
b) El resto de la división por 5
c) La séptima parte del resultado del punto a)
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    float quintaParte, resto, septimaParte;

    cout << "Ingrese un número: " << endl;
    cin >> num;

    quintaParte = num / 5.;
    resto = num % 5;
    septimaParte = quintaParte / 7.;

    cout << "La quinta parte de " << num << " es: " << quintaParte << endl;
    cout << "El resto es: " << resto << endl;
    cout << "La septima parte de " << num << " es: " << septimaParte << endl;
}