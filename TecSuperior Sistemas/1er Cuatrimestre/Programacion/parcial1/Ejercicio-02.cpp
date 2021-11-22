/*
Ejercicio 2
Desarrollar una aplicación que permita ingresar nombre y apellido, edad y sistema operativo que utilizan los/as alumnos/as
de un curso.
Al finalizar la carga, cuando el usuario ingresa como edad un 0 (cero) o un número negativo, se pide informar:
●
●
●
●
Total de alumnos/as, cantidad y porcentaje para cada sistema operativo.
Promedio general de las edades ingresadas, el promedio de edad de quienes usan linux.
La persona de mayor edad y la de menor edad.
Cuántos alumnos/as tienen la edad máxima y cuántos la mínima.
Punto mínimos que debe contener este ejercicio:
a. Procedimiento para el ingreso de los datos.
b. Función o procedimiento que permita obtener el promedio de edades y el promedio de edad de quienes usan linux.
Justifique brevemente su decisión.
c. Desarrollar el diagrama de flujo del programa principal.

TOP-DOWN
pedir datos
procesar datos de alumnos y sistemas operativos
procesar edades
mostrar datos

Estrategia
    pedirDatos()
    mientras (edad > 0)
        cantidadAlumnos + 1
        
        switch(sistOperativo)
            case 1:
                alumnoslinux + 1
                edadesLinux + edad
                break
            case 2:
                alumnoWindows + 1
                break
            case 3:
                alumnoMacOS + 1
                break
        FinSwitch
        
        si (edad > edadMayor || edadMayor == 0)
                edadMayor = edad
                alumnosEdadMayor = 1;
                personaMayorEdad = nombre
        
        si (edad < edadMenor || edadMenor == 0)
            edadMenor = edad
            alumnosEdadMenor = 1
            personaMenorEdad = nombre

        si (edad == edadMayor)
            alumnosEdadMayor + 1
        SiNO
            si (edad == edadMenor)
                alumosEdadMenor + 1

        pedirDatos()
    FinMientras

    promedioEdadesGeneral = promedioEdades(totalEdades, totalAlumnos)
    promedioEdadesLinux = promedioEdades(edadesLinux, alumnosLinux)
    
    porcentajeLinux = calcularPorcentaje(alumnosLinux, totalAlumnos)
    porcentajeWindows = calcularPorcentaje(alumnosWindows, totalAlumnos)
    porcentajeMacOS = calcularPorcentaje(alumnosMacOS, totalAlumnos)

    mostrar totalAlumnos, alumnosLinux, porcentajeLinux, alumnosWindows, porcentajeWindows, alumnosMacOS, porcentajeMacOS
    mostrar promedioEdadesGeneral, promedioEdadesLinux
    mostrar personaMayorEdad, personaMenorEdad
    mostrar alumnosEdadMayor, alumnosEdadMenor
    
    Total de alumnos/as, cantidad y porcentaje para cada sistema operativo.
    Promedio general de las edades ingresadas, el promedio de edad de quienes usan linux.
    La persona de mayor edad y la de menor edad.
    Cuántos alumnos/as tienen la edad máxima y cuántos la mínima.



*/

#include <iostream>
using namespace std;

void pedirDatos(string &nombre, int &edad, string &sistOperativo);

//Una función porque ambos promedios se calculan igual.
float promedioEdades(int totalEdades, int totalAlumnos);

float calcularPorcentaje(int alumnos, int totalAlumnos);

int main()
{

    return 0;
}

void pedirDatos(string &nombre, int &edad, int &sistOperativo)
{

    cout << "Ingrese el nombre y apellido del alumno: ";
    getline(cin, nombre);
    cout << endl;

    cin.ignore();

    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << endl;

    cin.ignore();

    cout << "Ingrese el numero correspondiente al sistema operativo que utiliza: ";
    cout << "(1 para Linux, 2 para Windows o 3 para MacOS)";
    cin >> sistOperativo;
    cout << endl;

    return;
}

float promedioEdades(int totalEdades, int totalAlumnos)
{
    float promedio;
    promedio = totalEdades / totalAlumnos;
    return promedio;
}

float calcularPorcentaje(int alumnos, int totalAlumnos)
{
    float porcentaje;
    porcentaje = (alumnos * 100) / totalAlumnos;
    return porcentaje;
}