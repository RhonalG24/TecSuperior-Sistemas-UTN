#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    int producto = 0;

    cout << "Inserte el primer número:" << endl;
    cin >> num1;
    cout << "Inserte el segundo número" << endl;
    cin >> num2;

    for (int i = 0; i < num2; i++)
    {
        producto = producto + num1;
    }

    cout << "El producto de " << num1 << " por " << num2 << " es: " << producto << endl;

    return 0;
}