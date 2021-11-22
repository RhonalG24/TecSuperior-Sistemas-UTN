

#include <iostream>
using namespace std;

#define MAX_LIBROS 100

struct StockLocal
{
    int codLibro;
    string autor;
    int stock;
    string titulo;
    string editorial;
    string genero;
};

struct StockDeposito
{
    int codLibro;
    int stock;
};

void imprimir(int codLibro, string mensaje)
{
    cout << codLibro << "\t\t" << mensaje << endl;
    return;
}

void cargar(StockLocal stock[], int &cant)
{
    cant = 0;
    stock[cant].codLibro = 111;
    stock[cant++].stock = 1;

    stock[cant].codLibro = 222;
    stock[cant++].stock = 0;

    stock[cant].codLibro = 444;
    stock[cant++].stock = 1;

    stock[cant].codLibro = 555;
    stock[cant++].stock = 0;

    stock[cant].codLibro = 777;
    stock[cant++].stock = 1;
}

void cargar(StockDeposito stock[], int &cant)
{
    cant = 0;
    stock[cant].codLibro = 111;
    stock[cant++].stock = 1;

    stock[cant].codLibro = 222;
    stock[cant++].stock = 0;

    stock[cant].codLibro = 444;
    stock[cant++].stock = 0;

    stock[cant].codLibro = 555;
    stock[cant++].stock = 1;

    stock[cant].codLibro = 888;
    stock[cant++].stock = 0;
}

void imprimirFaltantes(StockLocal stockLocal[], int cantLocal, StockDeposito stockDeposito[], int cantDeposito)
{
    int i = 0, j = 0, faltantes = 0;

    cout << "\tLibros Faltantes" << endl;
    cout << "Codigo\t\tObservacion" << endl;
    while (i < cantLocal && j < cantDeposito)
    {
        if (stockLocal[i].stock == 0 && stockDeposito[j].stock == 0)
        {
            if (stockLocal[i].codLibro < stockDeposito[j].codLibro)
            {
                imprimir(stockLocal[i].codLibro, "Faltante en local");
                i++;
            }
            else if (stockDeposito[j].codLibro < stockLocal[i].codLibro)
            {
                imprimir(stockDeposito[j].codLibro, "Faltante en deposito");
                j++;
            }
            else
            {
                imprimir(stockDeposito[j].codLibro, "Faltante en ambos");
                i++;
                j++;
            }
            faltantes++;
        }
        else
        {
            if (stockLocal[i].stock > 0)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    while (i < cantLocal)
    {
        if (stockLocal[i].stock == 0)
        {
            imprimir(stockLocal[i].codLibro, "Faltante en local");
            faltantes++;
        }
        i++;
    }

    while (j < cantDeposito)
    {
        if (stockDeposito[j].stock == 0)
        {
            imprimir(stockDeposito[j].codLibro, "Faltante en deposito");
            faltantes++;
        }
        j++;
    }

    cout << "Total de libros en falta: " << faltantes << endl;
}

int main()
{
    StockLocal stockLocal[MAX_LIBROS];
    StockDeposito stockDeposito[MAX_LIBROS];

    int cantLibrosLocal = 0;
    cargar(stockLocal, cantLibrosLocal);

    int cantLibrosDeposito = 0;
    cargar(stockDeposito, cantLibrosDeposito);

    imprimirFaltantes(stockLocal, cantLibrosLocal, stockDeposito, cantLibrosDeposito);

    system("pause");
    return 0;
}
