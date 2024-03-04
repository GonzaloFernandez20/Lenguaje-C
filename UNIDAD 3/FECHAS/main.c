#include <stdio.h>
#include "funciones.h"

int main()
{
    int d1, d2, m1, m2, a1, a2;
    long fecha1, fecha2;

    printf("Ingrese el dia de la primer fecha: \n"); scanf("%d", &d1);
    printf("Ingrese el mes de la primer fecha: \n"); scanf("%d", &m1);
    printf("Ingrese el anio de la primer fecha: \n"); scanf("%d", &a1);
    
    printf("Ingrese el dia de la segunda fecha: \n"); scanf("%d", &d2);
    printf("Ingrese el mes de la segunda fecha: \n"); scanf("%d", &m2);
    printf("Ingrese el anio de la segunda fecha: \n"); scanf("%d", &a2);

    fecha1 = unificarFecha(d1, m1, a1);
    fecha2 = unificarFecha(d2, m2, a2);

    if (fecha1 > fecha2)
    {
        printf("La fecha mas grande es la primera");
    }else
    {
        printf("La fecha mas grande es la segunda");
    }
    
    return 0;
} 