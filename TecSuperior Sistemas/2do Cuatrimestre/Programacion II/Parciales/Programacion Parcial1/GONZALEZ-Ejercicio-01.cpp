/* EJERCICIO 1
    
Entrada:
        archivos:   
            Pedidos.txt
            Agenda.dat


Salida
    archivoBinario

Estrategia
    abrir archivos
    guardar agenda en un array
    recorrer archivo de pedidos
        pedido = leerArchivoTxt

        si (pedido.recibido == 'S')
            generar linea en el archivo binario}
        

        pedido = leerArchivoTxt
    cerrar archivos

Restriccion:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codPedido[10];
    int codCliente; //1-100
    char recibido;  //S/N
} Pedido;           //Pedidos.txt

typedef struct
{
    int codigo; //1-100
    char nombre[20];
    char apellido[20];
    char email[20];
} Cliente; //Agenda.dat

typedef struct
{
    char email[20];
    char mensaje[256];
} Registro;

FILE *abrirArchivo(const char *nombreArchivo, const char *modo);
Pedido leerTXT(FILE *ptrFile);
void generarArray(Cliente *clientes, FILE *ptrAgendaDat);
void registrar(Cliente *clientes, Pedido pedido, FILE *ptrRegistroDat);

int main()
{
    FILE *ptrPedidosTxt = abrirArchivo("Pedidos.txt", "r");
    FILE *ptrAgendaDat = abrirArchivo("Agenda.dat", "rb");
    FILE *ptrRegistroDat = abrirArchivo("Registro.dat", "wb");

    Cliente clientes[100];
    generarArray(clientes, ptrAgendaDat);

    Pedido pedido;
    pedido = leerTXT(ptrPedidosTxt);
    while (!feof(ptrPedidosTxt))
    {

        if (pedido.recibido == 'S')
        {
            registrar(clientes, pedido, ptrRegistroDat);
        }
        pedido = leerTXT(ptrPedidosTxt);
    }

    fclose(ptrAgendaDat);
    fclose(ptrPedidosTxt);
    fclose(ptrRegistroDat);
    return 0;
}

FILE *abrirArchivo(const char *nombreArchivo, const char *modo)
{
    FILE *ptrArchivo = fopen(nombreArchivo, modo);
    if (ptrArchivo == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s", nombreArchivo);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Archivo %s encontrado!\n", nombreArchivo);
    }

    return ptrArchivo;
}

Pedido leerTXT(FILE *ptrFile)
{
    //inicializo la variable con la estructura que necesito
    Pedido pedidos;
    char *aux;
    //inicializo una cadena de caracteres donde se va a guardar la línea a leer
    char buffer[200];
    //si la linea no tiene nada, regresa la estructura como NULL y termina la funcion
    if (fgets(buffer, 200, ptrFile) == NULL)
    {
        return pedidos;
    }

    strcpy(pedidos.codPedido, strtok(buffer, " "));
    pedidos.codCliente = atoi(strtok(NULL, " "));
    strcpy(aux, strtok(NULL, " \n"));
    pedidos.recibido = aux[0];

    //Si el último dato a leer es un string se añade "\n" en los separadores del strtok

    //se retorna la estructura
    return pedidos;
}

void generarArray(Cliente *clientes, FILE *ptrAgendaDat)
{
    Cliente cliente;
    int pos;

    fread(&cliente, sizeof(Cliente), 1, ptrAgendaDat);
    while (!feof(ptrAgendaDat))
    {
        pos = cliente.codigo - 1;
        clientes[pos] = cliente;
        fread(&cliente, sizeof(Cliente), 1, ptrAgendaDat);
    }
    return;
}

void registrar(Cliente *clientes, Pedido pedido, FILE *ptrRegistroDat)
{
    Registro registro;

    int pos = pedido.codCliente - 1;

    registro.email = clientes[pos].email;
    strcpy(registro, ("Estimado " + (clientes[pos].nombre) + ", su pedido " + (pedido.codPedido) " se encuentra disponible para ser retirado.\n"));
    // registro.mensaje = "Estimado " + (clientes[pos].nombre) + ", su pedido " + (pedido.codPedido) " se encuentra disponible para ser retirado.\n";

    fwrite(&registro, sizeof(Registro), 1, ptrRegistroDat);
    return;
}