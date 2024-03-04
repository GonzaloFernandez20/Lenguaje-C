#include <stdio.h>

void dividirFecha(int, int*, int*, int*);
int esBisiesto(int);

int main()
{
    int d,m,a;
    long fecha;


    int contadorMarzos = 0;
    int contadorBisiestos = 0;
    int errores = 0;
    int cantidad = 0;

    printf("Ingrese una fecha: "); scanf("%ld", &fecha);
    
    while (fecha != 0)
    {   
        dividirFecha(fecha, &d, &m, &a);

        if (m == 3)
        {
            contadorMarzos++;
        }

        if (esBisiesto(a))
        {
            contadorBisiestos++;
        }
        
        if (d == 29 && m == 2 && !esBisiesto(a))
        {
                errores++;
        }

        printf("Ingrese una fecha: "); scanf("%ld", &fecha);
    

        cantidad++;
    }
    printf("cantidad de fechas ingresadas: %d \n", cantidad);
    printf("cantidad de Marzos: %d \n", contadorMarzos);
    printf("cantidad de Bisiestos: %d \n", contadorBisiestos);
    printf("cantidad de errores: %d \n", errores);
    return 0;
}


void dividirFecha(int fecha, int* d, int* m, int* a){

    int resto;

    *a = fecha/10000;
    resto = fecha%10000;
    *m = resto/100;
    *d = resto%100;

}

int esBisiesto(int a){
    int mult4, mult100, mult400;

    mult4 = a%4 == 0;
    mult100 = a%100 == 0;
    mult400 = a%400 == 0;

    return (mult4 && !mult100) || mult400;
}