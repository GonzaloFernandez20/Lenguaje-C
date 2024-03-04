#include "OperacionesSobreArrays.h"

int main()
{
    int a[10] = {1,2,3,5,6};
    int longitud = 5;

    insertarEnOrden(a, &longitud, 4);

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
