/*
Ej. 8: Dado un vector de productos que contiene 100 registros, y cada registro corresponde a un producto
que está codificado del 1 a 100, ordenado por código de producto con el siguiente diseño:
Código de producto (1..100)
Stock (int)

y otro vector de pedidos, con el siguiente diseño:
Número de pedido(int)
Número de cliente(long)
Código de producto (1..100, char)
Cantidad pedida (int)

Se pide desarrollar un procedimiento que reciba ambos vectores, y procese los pedidos haciendo lo siguiente

a) Actualizar el campo stock del vector de productos, por cada pedido que pueda ser realizado.

b) Imprima el listado de los pedidos satisfechos con el siguiente formato:
Pedidos satisfechos
NroPedido       NroCliente      CodProducto     CantPedida

c) Complete un tercer vector con el mismo diseño que el vector de pedidos, con aquellos pedidos que no
pueden ser satisfechos en su totalidad.
Pedidos NO satisfechos
NroPedido       NroCliente      CodProducto     CantPedida
*/

#include <iostream>
using namespace std;

typedef struct
{
    int codProducto;
    int stock;
} Productos;

typedef struct
{
    int nroPedido;
    long int nroCliente;
    int codProducto;
    int cantPedida;
} Pedidos;

void procesarPedidos(Productos productos[], int cantidad, Pedidos pedidos[], int cantPedidos, Pedidos pedidosNoSatisfechos[], int &cantPedidosNoSatisfechos)
{
    int codigoProducto = 0;
    // cantPedidosNoSatisfechos = 0;
    for (int i = 0; i < cantPedidos; i++)
    {
        codigoProducto = pedidos[i].codProducto;
        if (pedidos[i].cantPedida <= productos[codigoProducto - 1].stock)
        {
            cout << "NroPedido\t\t NroCliente\t\tCodProducto\t\tCantPedida\t\t" << endl;
            cout << pedidos[i].nroPedido << "\t\t" << pedidos[i].nroCliente << "\t\t" << pedidos[i].codProducto << "\t\t" << pedidos[i].cantPedida << "\t\t" << endl;
            productos[codigoProducto - 1].stock -= pedidos[i].cantPedida;
        }
        else
        {
            pedidosNoSatisfechos[cantPedidosNoSatisfechos] = pedidos[i];
            cantPedidosNoSatisfechos++;
        }
    }
}

int main()
{

    return 0;
}