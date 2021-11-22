#include <iostream>
using namespace std;

struct Persona
{
    string nombre;
    int fechaNacimiento;
};

// int buscarMayor(Persona personas[], int cantidad){

// }

int main()
{

    Persona persona;
    // int mayorFechaNacimiento = 0;
    // string nombrePersonaMayor;
    Persona personaMayor;

    cout << "Ingrese el nombre: ";
    cin >> persona.nombre;
    while (persona.nombre != "FIN")
    {
        cout << "Ingrese fecha de nacimiento: ";
        cin >> persona.fechaNacimiento;

        if (personaMayor.fechaNacimiento == 0 || persona.fechaNacimiento < personaMayor.fechaNacimiento)
        {
            personaMayor.fechaNacimiento = persona.fechaNacimiento;
            personaMayor.nombre = persona.nombre;
        }

        cout << "Ingrese el nombre: ";
        cin >> persona.nombre;
    }
    cout << "La persona con la mayor edad era " << personaMayor.nombre << endl;
    return 0;
}