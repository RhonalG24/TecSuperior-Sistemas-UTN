#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;

    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;

    if (num1 > num2)
    {
        cout << num1 << " es mayor que " << num2 << endl;
    }
    else
    {
        cout << num2 << " es mayor que " << num1 << endl;
    }

    return 0;
}