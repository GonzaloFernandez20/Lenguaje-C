#include "OperacionesSobreArrays.h"


/*-------------------------------------------------------------------------------*/

int agregar(int array[], int* longitud, int valor){
    array[(*longitud)++] = valor;
    return *longitud - 1;
}

/*-------------------------------------------------------------------------------*/

int buscar(int array[], int longitud, int valor){
    int i = 0;

    while (i<longitud)
    {
        if (array[i] == valor)
        {
            return i;
        }else { i++; }
        
    }
    return -1;
}
/*
int buscar(int a[],int len,int v)
    {
        int i;
        for(i=0;i<len && a[i]!=v;i++);
        return i<len?i:-1;
    }
*/
/*-------------------------------------------------------------------------------*/

int buscarYAgregar(int array[], int* longitud, int valor, int *enc){
    int pos;
    pos = buscar(array, *longitud, valor);
    if ( pos >= 0)
    {
        *enc = 1; 
    }else{
        *enc = 0;
        pos = agregar(array, longitud, valor);
    }
    return pos;
}

/*-------------------------------------------------------------------------------*/

void iniciarContadores(int a[]){
    for (int i = 0; i < 31; i++)
    {
        a[i] = 0;
    }
}

/*-------------------------------------------------------------------------------*/

void mostrarResultados(int aNum[],int len,int aCont[])
{
    for(int i=0; i<len; i++)
    {
    printf("%d aparece %d veces\n",aNum[i],aCont[i]);
    }
}

/*-------------------------------------------------------------------------------*/


/* int main()
{
    int array[10];
    int longitud = 0;

    agregar(array, &longitud, 3);
    agregar(array, &longitud, 5);
    agregar(array, &longitud, 7);
    agregar(array, &longitud, 9);

    for (int i = 0; i < longitud; i++)
    {
        printf("%d \n", array[i]);
    } 
    int array [] = {1,2,3,4,5,6,7,8,9};
    printf("Se encontro el valor en la posicion: %d \n", buscar(array, 9, 7));
    
    return 0;
} */
