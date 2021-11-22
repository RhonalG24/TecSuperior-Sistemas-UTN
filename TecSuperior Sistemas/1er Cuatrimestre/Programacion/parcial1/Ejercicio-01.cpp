/*
Ejercicio 1

Desarrollar una aplicación que permita ingresar números enteros. Se deben procesar todos los números hasta que se ingrese
un 0.
Sólo contemplando aquellos números que no sean primos, informar si la secuencia de números está ordenada, y en tal caso,
informar si es ascendente o descendente.
Nota: Un número primo es aquel que sólo es divisible por 1 y por si mismo.
Punto mínimos que debe contener este ejercicio:
c. Desarrollar la función bool esNumeroPrimo(int) utilizando lenguaje C/C++
d. Desarrollar el diagrama de flujo del programa principal.

TOP-DOWN

Pedir datos
Verificar si es primo
verificar secuencia ordenada y si es ascendente o descendente
informar

Estrategia
    pedirNumero()
    
    mientras(numero != 0 && primerNumeroNoPrimo == false )
        esNumeroPrimo()
        si (primo == false)
            primerNumeroNoPrimo = true
            numeroAnterior = numero

        pedirNumero()
    FinMientras

    si (numero != 0)
        mientras (numero != 0)
            esNumeroPrimo()
            si (primo == false)
                si (numero > numeroAnterior && ordenado == false)
                    ordenado = true
                    orden = "ascendente"
                sino
                    si (numero < numeroAnterior)
                        ordenado = true
                        orden = "descendente"


            pedirNumero()

    FinMientras 



*/

#include <iostream>
using namespace std;

bool esNumeroPrimo(int num);

int main()
{

    return 0;
}

bool esNumeroPrimo(int num)
{
    int resto = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            resto++;
        };
    };

    if (resto == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
