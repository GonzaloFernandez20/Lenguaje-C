#include <stdio.h>
#include <stdlib.h>
void insertionSort(int[], int);
void mostrarArreglo(int [], int);

int main()
{
    int array[100] = {537, 244, 684, 912, 751, 870, 88, 170, 858, 493, 23, 81, 469, 153, 947, 944, 
                      246, 173, 799, 545, 72, 377, 502, 824, 412, 916, 997, 286, 173, 965, 369, 650, 
                      847, 196, 881, 572, 845, 262, 709, 869, 67, 401, 218, 764, 932, 785, 169, 707, 
                      57, 846, 890, 836, 801, 26, 54, 139, 890, 49, 853, 98, 194, 56, 254, 750, 127, 
                      699, 133, 813, 511, 774, 345, 885, 200, 273, 488, 455, 925, 777, 401, 742, 35, 
                      609, 918, 234, 400, 383, 878, 167, 654, 716, 364, 882, 930, 481, 289, 847, 236, 
                      484, 822, 672};
    int longitud = 100;

    mostrarArreglo(array, longitud);

    insertionSort(array, longitud);
    
    mostrarArreglo(array, longitud);

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

void mostrarArreglo(int arreglo[], int longitud){

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", arreglo[i]);
    }
    puts("\n");
    
}
