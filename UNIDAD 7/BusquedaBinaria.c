#include <stdio.h>

int busquedaBinaria(int [], int, int);

int main()
{
    int a[] = {1,2,3,4,5,6};
    int longitud = 6;
    int num = 10;

    int pos = busquedaBinaria(a,longitud,num);
    //printf("El numero buscado [%d] se encontro en la posicion: %d",num, pos);
    
    if (pos > 0){
        printf("Se encontro %d en la posicion: %d", num, pos);
    }else{
        printf("No se encontro %d dentro del conjunto.",num);
    }
    

    return 0;
}

int busquedaBinaria(int a[], int longitud, int valor){

    int inicio = 0;
    int final = longitud - 1;
    int medio = (inicio + final)/2;
    int encontrado = 0;

    while (!encontrado && (inicio <= final))
    {
        if (a[medio] > valor)
        {
            final = (medio - 1);
        }else{ 
            if (a[medio] < valor)
            {
                inicio = (medio + 1);
            }else
            {
                encontrado = 1;
            }
        }
        medio = (inicio + final)/2; 
    } 
    return (encontrado!=0?medio:-1);
}