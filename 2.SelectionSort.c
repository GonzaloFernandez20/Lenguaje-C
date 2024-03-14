#include <stdio.h>
#include <stdlib.h>

void selectionSort(int[], int);
void mostrarArreglo(int [], int);

int main()
{
    int array[5] = {11,4,67,22,7};
    int longitud = 5;

    mostrarArreglo(array, longitud);
    selectionSort(array, longitud);
    mostrarArreglo(array, longitud);

    return 0;
}

void selectionSort(int array[], int longitud){

    int minimoActual;
    for (int i = 0; i < longitud; i++)
    {   
        minimoActual = i;
        for (int j = i; j < longitud; j++)
        {
            if (array[j] < array[minimoActual])
            {
                minimoActual = j;
            }

        }

        int aux = array[i];
        array[i] = array[minimoActual];
        array[minimoActual] = aux;
        
    }
    
}

void mostrarArreglo(int arreglo[], int longitud){

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", arreglo[i]);
    }
    puts("\n");
    
}