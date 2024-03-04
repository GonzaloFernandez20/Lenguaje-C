#include <stdio.h>
#include <string.h>

void ordenar(int[], int);
int estaOrdenado(int [], int);

int main()
{
    int array[10] = {5, 8, 2, 10, 1, 7, 3, 9, 6, 4};
    int longitud = 10;

    printf("Array sin ordenar: ");
    for (int i = 0; i < longitud; i++)
    {
        printf("%d, ", array[i]);
    }

    ordenar(array, longitud);
    printf("\nArray ordenado: ");

    for (int i = 0; i < longitud; i++)
    {
        printf("%d, ", array[i]);
    }

    return 0;
}

int estaOrdenado(int a[], int longitud){
    int i = 0;
    while (i < longitud)
    {
        if (a[i] <= a[i+1])
        {
            i++;
        }else{ return 0;}
    }
    return 1;
}

void ordenar(int a[], int longitud){

    while (!estaOrdenado(a, longitud))
    {
        for (int i = 0; i < longitud; i++)
        {
            if (a[i] > a[i + 1])
            {
                int auxiliar;
                    auxiliar = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = auxiliar;
                i++;
            }   
        }
    }
}

/* Alternativa mas sencilla
void ordenar(int a[],int len){
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