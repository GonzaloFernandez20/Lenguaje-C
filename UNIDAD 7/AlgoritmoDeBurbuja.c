#include <stdio.h>
#include <time.h>

void ordenar(int[], int);
int estaOrdenado(int [], int);

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
    

    printf("Array sin ordenar: ");
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    }

    ordenar(array, longitud);
    printf("\nArray ordenado: ");

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    } 
    
    return 0;
}

int estaOrdenado(int a[], int longitud){
    int i = 0;
    while (i < (longitud - 1))
    {
        if (a[i] <= a[i+1])
        {
            i++;
        }else{ return 0;}
    }
    return 1;
}

void ordenar(int a[], int longitud){
    int cantIteraciones = 0;

    while (!estaOrdenado(a, longitud))
    {
        for (int i = 0; i < (longitud - 1); i++)
        {
            int auxiliar = 0;
            if (a[i] >= a[i + 1])
            {
                    auxiliar = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = auxiliar;
            }   
        }
        cantIteraciones++;
    }
} 

//Alternativa mas sencilla
/* void ordenar(int a[],int len){
    int ordenado=0;

    while( !ordenado ){
        ordenado=1;

        for(int i=0; i<len-1; i++){
            if( a[i]>a[i+1] ){
                int aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                ordenado=0;
            }
        }
    }
}
 */