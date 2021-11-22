/*
Dado 3 valores enteros:
a. Determinar si forman triangulo
b. Imprimir tipo de pantalla
c. Si es rectangulo hallar el area (b*h/2)

Dtos entrada: 3 lados tipo entero > 0
Dtos Salida: mensaje.
*/

#include <iostream>
using namespace std;

void leerValor(int &valor, string mensaje)
{
    cout << mensaje << endl;
    cin >> valor;
    return;
}

/**
 * Retorna true cuando los 3 lados forman un triangulo 
 * @return bool
*/
bool esTriangulo(int lado1, int lado2, int lado3)
{
    return lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1;
}

string obtenerTipoTriangulo(int lado1, int lado2, int lado3)
{
    string tipoTriangulo = "";
    if (lado1 == lado2 && lado2 == lado3)
    {
        tipoTriangulo = "Equilatero";
    }
    else
    {
        if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3)
        {
            tipoTriangulo = "Escaleno";
        }
        else
        {
            tipoTriangulo = "Isosceles";
        }
    }
    return tipoTriangulo;
}

int potencia(int base, int exponente)
{
    int potencia = base;
    for (int i = 1; i < exponente; i++)
    {
        potencia *= base;
    }
    return potencia;
}

bool esTrianguloRectangulo(int catetoA, int catetoB, int hipotenusa)
{
    return potencia(catetoA, 2) + potencia(catetoB, 2) == potencia(hipotenusa, 2);
}

void obtenerCatetos(int lado1, int lado2, int lado3, int &catetoA, int &catetoB, int &hipotenusa)
{
    if (lado1 > lado2 && lado1 > lado3)
    {
        hipotenusa = lado1;
        catetoA = lado2;
        catetoB = lado3;
    }

    if (lado2 > lado1 && lado2 > lado3)
    {
        hipotenusa = lado2;
        catetoA = lado1;
        catetoB = lado3;
    }

    if (lado3 > lado2 && lado3 > lado1)
    {
        hipotenusa = lado3;
        catetoA = lado2;
        catetoB = lado1;
    }
    return;
}

bool esRectangulo(int lado1, int lado2, int lado3)
{
    int catetoA, catetoB, hipotenusa;
    obtenerCatetos(lado1, lado2, lado3, catetoA, catetoB, hipotenusa);
    return esTrianguloRectangulo(catetoA, catetoB, hipotenusa);
}

int areaTriaguloRectangulo(int base, int altura)
{
    return base * altura / 2;
}

int areaTriaguloRectangulo(int lado1, int lado2, int lado3)
{
    int catetoA, catetoB, hipotenusa;
    obtenerCatetos(lado1, lado2, lado3, catetoA, catetoB, hipotenusa);
    return areaTriaguloRectangulo(catetoA, catetoB);
}

int main()
{
    int lado1, lado2, lado3;
    int catetoA, catetoB, hipotenusa;
    int area = 0;

    leerValor(lado1, "Ingrese el lado1:");
    leerValor(lado2, "Ingrese el lado2:");
    leerValor(lado3, "Ingrese el lado3:");

    // Determinar si forman triangulos

    if (esTriangulo(lado1, lado2, lado3))
    {
        string tipoTriangulo = obtenerTipoTriangulo(lado1, lado2, lado3);

        obtenerCatetos(lado1, lado2, lado3, catetoA, catetoB, hipotenusa);
        if (esTrianguloRectangulo(catetoA, catetoB, hipotenusa))
        {
            area = areaTriaguloRectangulo(catetoA, catetoB);
        };
    }

    return 0;
}