//Ej. MI-24: Se dispone de un lote de valores enteros positivos que finaliza con un numero negativo.
//El lote esta dividido en sublotes por medio de valores cero. Desarrollar un programa que determine e informe:
//	a) por cada sublote el promedio de valores
//	b) el total de sublotes procesados
//	c) el valor maximo del conjunto, indicando en que sublote se encontro y la posicion relativa del mismo dentro
//	del sublote
//	d) valor minimo de cada sublote
//Nota: el lote puede estar vacio (primer valor negativo), o puede haber uno, varios o todos los sublotes vacios (ceros
//	consecutivos)

#include <iostream>
using namespace std;

int main()
{
    float num;

    int cantSublotes = 0;
    bool sumarSublote = true;

    float promedioValSublote = 0;
    float valoresEnSublote = 0;

    float valorMaximoDelLote = 0;
    int numSubLote = 0;
    int posicionEnSublote = 0;

    float valorMinDelSublote = 0;

    cout << "Ingrese el primer numero del lote, 0 para terminar el sublote o un numero negativo para salir: " << endl;
    cin >> num;

    while (num >= 0)
    {
        if (sumarSublote == true)
        {
            cantSublotes++;
            sumarSublote = false;
        }

        if (num == 0)
        {
            cout << "haz terminado el sublote " << cantSublotes << endl
                 << endl;
            sumarSublote = true;
            cout << "Ingrese el siguiente numero, 0 para terminar el sublote o un numero negativo para salir: " << endl;
            cin >> num;
        }
        else
        {
            while (num > 0)
            {
                valoresEnSublote++;
                promedioValSublote += num;

                if (num > 0 || valorMaximoDelLote == 0)
                {
                    valorMaximoDelLote = num;
                    posicionEnSublote = valoresEnSublote;
                    numSubLote = cantSublotes;
                }

                if (num < valorMinDelSublote || valorMinDelSublote == 0)
                {
                    valorMinDelSublote = num;
                }

                cout << "Ingrese el siguiente numero, 0 para terminar el sublote o un numero negativo para salir: " << endl;
                cin >> num;
            }

            promedioValSublote /= valoresEnSublote;
            cout << "El promedio de los valores del sublote " << cantSublotes << " es: " << promedioValSublote << endl;
            cout << "El valor m�nimo ingresado en este sublote fue: " << valorMinDelSublote << endl
                 << endl;

            promedioValSublote = 0;
            valoresEnSublote = 0;
            valorMinDelSublote = 0;
        }
    }

    if (cantSublotes == 0)
    {
        cout << "No se creo el sublote." << endl;
    }
    else
    {
        cout << "Se procesaron en total " << cantSublotes << " sublotes." << endl;
        if (valorMaximoDelLote > 0)
        {
            cout << "El valor maximo del lote es " << valorMaximoDelLote << ". Se encontro en el sublote " << numSubLote << ", en la posicion " << posicionEnSublote << endl
                 << endl;
        }
    }
    return 0;
}