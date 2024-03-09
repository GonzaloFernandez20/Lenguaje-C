#include <stdio.h>
#include <time.h>

void ordenar(int[], int);
int estaOrdenado(int [], int);

int main()
{
    time_t tiempoDeInicio = time(NULL);

    int array[10] = {57, 12, 90, 34, 68};
    int longitud = 5;
    double tiempoTotal;

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

    time_t tiempoFinal = time(NULL);
    tiempoTotal = difftime(tiempoFinal, tiempoDeInicio);
    printf("\n%.0lf segundos\n",tiempoTotal);
    
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