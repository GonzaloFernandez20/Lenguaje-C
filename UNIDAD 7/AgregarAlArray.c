#include "OperacionesSobreArrays.h"

int main()
{
    int a[10] = {1,2,3,4,5,6};
    int longitud = 6;

    insertarEn(a, &longitud, 11, 0);
    insertarEn(a, &longitud, 22, 4);

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}
