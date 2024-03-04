#include "OperacionesSobreArrays.h"

int main()
{
    int array[10] = {1,2,3,4,5,6,7};
    int longitud = 7;
    eliminar(array, &longitud, 5);

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}
