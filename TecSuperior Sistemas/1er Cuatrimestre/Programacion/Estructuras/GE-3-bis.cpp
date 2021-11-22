#include <iostream>
using namespace std;

struct Persona
{
    string nombre;
    int fechaNacimiento;
};

int buscarMayor(Persona personas[], int cantidad)
{
    Persona personaMayor;

    int posPersonaMayor = 0;
    personaMayor = personas[0];

    for (int i = 0; i < cantidad; i++)
    {
        if (personas[i].fechaNacimiento < personaMayor.fechaNacimiento)
        {
            personaMayor = personas[i];
            posPersonaMayor = i;
        }
    }
    return posPersonaMayor;
}

int main()
{
    int cantMaxima;
    cout << "Indique cuántas personas ingresará: ";
    cin >> cantMaxima;

    Persona personas[cantMaxima];
    // int mayorFechaNacimiento = 0;
    // string nombrePersonaMayor;
    Persona persona;
    int cant = 0;

    cout << "Ingrese el nombre: ";
    cin >> persona.nombre;
    while (persona.nombre != "FIN")
    {
        cout << "Ingrese fecha de nacimiento: ";
        cin >> persona.fechaNacimiento;

        //Cargo la persona en el vector
        personas[cant] = persona;
        cant++;

        cout << "Ingrese el nombre: ";
        cin >> persona.nombre;
    }

    int posMayor = buscarMayor(personas, cant);
    Persona personaMayor = personas[posMayor];

    cout << "La persona con la mayor edad era " << personaMayor.nombre << endl;

    return 0;
}