/*
Ordenar > búsqueda

Algoritmos de búsqueda:
- Secuencial
- Posición Única Predecible (PUP)
- Binaria

TODOS los algoritmos de BUSQUEDA devuelven la POSICION DEL ELEMENTO, No el elemento.

************
Algoritmos de Ordenamiento:
- Insertion Sort
- Bubble Sort
- Quick Sort

***********
*/

#include <iostream>
using namespace std;

/*
************************BUSQUEDA*************************
*/

//Secuencial - Es simple, Poco eficiente.

int buscarSecuencial(int vec[], int cant, int valor)
{
    for (int i = 0; i < cant; i++)
    {
        if (vec[i] == valor)
        {
            return i;
        }
    }
    //Si no salió todavía, no estaba en el vector
    return -1;
}

//con while
int buscarSecuencial(int vec[], int cant, int valor)
{
    int i = 0;
    int pos = -1;

    while (i < cant && pos == -1)
    {
        if (vec[i] == valor)
        {
            pos = i;
        }
        return pos;
    }
}

//USO EN EL MAIN

// int posicion = -1;
// posicion = buscarSecuencial(vector, 10, 7)
// if(posicion >= 0){
//     //lo encontró
// } else {
//     //NO lo encontró
// }

//*********************************************

// //Posición Unica Predecible (PUP) - Es como un acceso directo
// - Simple
// - Eficiente
// - Requiere que el conjunto esté ordenado *****
// - Requiere conocer el rango de valores de las claves ****
// - Requiere que el conjunto esté completo (Sin huecos) ****
// - Equivalencia entre alguna clave del dato y la posición

//Cuando conozco o puedo establecer alguna fórmula que me permita calcular la posicion de un elemento
// posVect = valor_key - valor_inicial_conjunto
//meses(1-12) -> pos = mes - 1
//dias(1-31) -> pos = dia - 1
//legajo(100-131) -> pos = legajo - 100

//Es establecer una key para asociarla al índice del vector

//Uso en el main
int main()
{
    float ventas[31];

    for (int i = 0; i < 31; i++)
    {
        cout << "Ingrese la venta del día " << i + 1 << ": ";
        cin >> ventas[i];
    }
}

//otro ejemplo
int main()
{
    float ventas[31];
    int dia;
    float venta;
    cout << "Ingrese las ventas del mes";
    for (int i = 0; i < 31; i++)
    {
        cout << "Día: ";
        cin >> dia;
        cout << "Ventas: ";
        cin >> venta;
        ventas[dia - 1] = ventas[dia - 1] + venta; //Acumulo la venta leída.
    }
}

//**********************************************

// //Busqueda Binaria - Reduce la búsqueda a la mitad de iteraciones que haría una busqueda secuencial.

// - Simple
// - Eficiente
// - Requiere que el conjunto esté ordenado *******
// - No impone otras restricciones

int busquedaBinaria(int arr[], int cantElementos, int valorBuscado)
{
    //Cuando arranco evalúo todo el vector de 0 a cantElementos-1
    int inicio = 0;
    int fin = cantElementos - 1;

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;

        //Si el elemento es el del medio, devolvemos la posición
        if (arr[mitad] == valorBuscado)
        {
            return mitad;
        }

        //Si el elemento es menor, entonces sólo puede estar en la 1ra mitad del array
        if (arr[mitad] > valorBuscado)
        {
            fin = mitad - 1; //Cambio el límite superior
        }
        else
        {
            inicio = mitad + 1; //Cambio el límite inferior
        }
    }
    return -1; //Si no se encuentra
}

/*
************************ORDENAMIENTO*************************
*/

// Insertion Sort

// Movemos los elemento de arr[0... i-1], que son más grandes que key,
// a la posición siguiente a su posición actual

void insertionSort(int arr[], int cantElementos)
{
    int i;
    int j;
    int key;
    for (i = 1; i < cantElementos; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + i] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort

void burbujeo(int arr[], int cantElementos)
{
    int i;
    int j;
    int aux;
    for (i = 0; i < cantElementos - 1; i++)
    {
        //los últimos i elementos ya están ordenados
        for (j = 0; j < cantElementos - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// Bubble Sort Reloaded

void burbuejoMejor(int arr[], int n)
{
    int i = 0, j, aux;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true; // Arranco asumiendo que si esta ordenado
        // Los ultimos i elementos ya estan ordenados
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false; // Cambio el flag si hice un swap
            }
        }
        i++;
    }
}

int main()
{

    return 0;
}
