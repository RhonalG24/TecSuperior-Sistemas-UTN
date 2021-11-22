/*
Ej. MI-38: ​ Desarrollar la función
Int EdadAGrupoEtario ( ​ int edad)
que retorne un valor de 1 a 8
*/

#include <iostream>
using namespace std;

int edadAGrupoEtario(int edad);

int main()
{
    int edad = 99;
    cout << "edad: " << edad << ", grupo etario: " << edadAGrupoEtario(edad) << endl;
    return 0;
}

int edadAGrupoEtario(int edad)
{
    if (edad <= 14)
    {
        return 1;
    }
    else
    {
        if (edad <= 21)
        {
            return 2;
        }
        else
        {
            if (edad <= 28)
            {
                return 3;
            }
            else
            {
                if (edad <= 35)
                {
                    return 4;
                }
                else
                {
                    if (edad <= 42)
                    {
                        return 5;
                    }
                    else
                    {
                        if (edad <= 49)
                        {
                            return 6;
                        }
                        else
                        {
                            if (edad <= 63)
                            {
                                return 7;
                            }
                            else
                            {
                                return 8;
                            }
                        }
                    }
                }
            }
        }
    }
}