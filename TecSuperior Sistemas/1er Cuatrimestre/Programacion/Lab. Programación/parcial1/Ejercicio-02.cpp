/*
2) Un boliche ha decidido finalmente reemplazar al personal de seguridad por un sistema que controle la edad y
cantidad de personas máximas admitidas en el local.
Desarrolle el programa que permita cargar la capacidad máxima del local y las fechas de nacimiento de las
personas que desean ingresar.
Solo se permitirá el ingreso en caso que la persona sea mayor de edad (más de 18 años) y el local no haya
alcanzado la capacidad máxima. La carga de datos finalizará con una fecha de nacimiento igual a cero

TOP-DOWN main
    pedir fecha actual
    pedir capacidad maxima
    pedir fechas de nacimiento
    decidir si se le permite ingresar

Estrategia
    pedirNumero() -->para fecha actual
    pedirNumero() -->para capacidad total
    pedirNumero() -->fecha de nacimiento
    
    Mientras (cantPersonas < capacidadMaxima Y fechaNacimiento != 0 )

        calcularEdad()
        Si (edad < 18){
            mostrar("No puede ingresar")
        } SiNo {
            mostrar("Puede ingresar")
            cantPersonas + 1
        }

        pedirNumero() -->fecha de nacimiento
    FinMientras
    if(cantPersonas == capacidadMaxima){
        mostrar("Capacidad maxima alcanzada")
    }
*/
#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
void mostrar(string mensaje);

void convertirFecha(int fecha, int &anio, int &mes, int &dia);
void calcularEdad(int fechaActual, int fechaNacimiento, int &edad);
void verificarIngreso(int edad, int &cantidadPersonas);

int main()
{
    int fechaNacimiento;
    int cantidadPersonas = 0;
    int edad;

    const int fechaActual = pedirNumeros("Ingrese la fecha actual (AAAAMMDD): ");
    const int CAPACIDAD_MAXIMA = pedirNumeros("Ingrese la capacidad maxima del local: ");

    fechaNacimiento = pedirNumeros("Ingrese la fecha de nacimiento de la persona (AAAAMMDD) o 0 para terminar: ");

    while (cantidadPersonas < CAPACIDAD_MAXIMA && fechaNacimiento != 0)
    {
        calcularEdad(fechaActual, fechaNacimiento, edad);
        verificarIngreso(edad, cantidadPersonas);

        fechaNacimiento = pedirNumeros("Ingrese la fecha de nacimiento de la siguiente persona (AAAAMMDD) o 0 para terminar: ");
    }
    if (cantidadPersonas == CAPACIDAD_MAXIMA)
    {
        mostrar("Capacidad maxima alcanzada");
    }
    return 0;
}

int pedirNumeros(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

void mostrar(string mensaje)
{
    cout << mensaje << endl
         << endl;
    return;
}

void calcularEdad(int fechaActual, int fechaNacimiento, int &edad)
{
    int diaActual, mesActual, anioActual;
    int diaNac, mesNac, anioNac;

    convertirFecha(fechaActual, anioActual, mesActual, diaActual);
    convertirFecha(fechaNacimiento, anioNac, mesNac, diaNac);

    edad = anioActual - anioNac;

    if (mesActual < mesNac)
    {
        edad--;
    }
    else
    {
        if (mesActual == mesNac)
        {
            if (diaActual < diaNac)
            {
                edad--;
            }
        }
    }

    return;
}

void convertirFecha(int fecha, int &anio, int &mes, int &dia)
{
    anio = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = fecha % 100;
    return;
}

void verificarIngreso(int edad, int &cantidadPersonas)
{
    if (edad < 18)
    {
        mostrar("No puede ingresar");
    }
    else
    {
        mostrar("Puede ingresar");
        cantidadPersonas++;
    }
}
