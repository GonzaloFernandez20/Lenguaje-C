#include <stdio.h>
#include <stdlib.h>
void insertionSort(int[], int);
void mostrarArreglo(int []);

int main()
{
    int array[] = {6,5,3,1,4,2};
    int longitud = 6;

    mostrarArreglo(array);

    insertionSort(array, longitud);
    
    mostrarArreglo(array);

    return 0;
}

void insertionSort(int array[], int longitud){

    for (int i = 1; i < longitud; i++)
    {   
        int aux = array[i]; //saco el valor a modificar de la lista
        int j = (i - 1); // desde la posicion de ese valor hacia atras voy recorriendo

        while (j >= 0 && array[j] > aux) //tengo que ir corriendo todos para el costado hasta llegar al correcto
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = aux;//me queda justo el hueco para meter ahi mi valor pero ya en su orden 
  
    }

}

/* void insertionSort(int array[], int longitud){

    for (int i = 2; i < longitud; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (array[j] < array[(j - 1)])
            {
                int aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
            }
            
        }
        
    }

} */


void mostrarArreglo(int arreglo[]){
    int longitud = 6;

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", arreglo[i]);
    }
    puts("\n");
    
}
