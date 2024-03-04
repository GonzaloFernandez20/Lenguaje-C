#include "OperacionesSobreArrays.h"

int main()
{   

    int aNum[100];
    int aCont[100];
    int longitud = 0;
    int v;
    int enc;
    int pos;

    iniciarContadores(aCont);

    printf("Ingrese un numero: \n"); scanf("%d", &v);

    while (v != 0)
    {   
        pos = buscarYAgregar(aNum, &longitud, v, &enc);
        aCont[pos] += 1; 

        printf("Ingrese un numero: \n"); scanf("%d", &v);
    }
    
    mostrarResultados(aNum, longitud, aCont);

    return 0;
}

