#include <stdio.h>

void burbujeoMejor(int arr[], int n)
{
    int aux;
    int i = 0;
    bool ordenado = false;
    while (i < n && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
}