/*
Se tiene una tabla que detalla la facturación emitida por un comercio durante el período 
de un mes, con el siguiente formato:
• nroFactura (número entero de 8 dígitos)
• dia (número entero entre 1 y 31)
• importe (número real) 
• codCliente (alfanumérico, 5 caracteres)
Los datos no necesariamente están ordenados y puede haber más de una factura emitida en un mismo día. 
Finaliza cuando se ingresa un nroFactura igual a cero.
Se pide determinar e informar:
1. Total facturado por día, solo para aquellos días en los que hubo facturación.
2. Día de mayor facturación (será único) y monto total facturado ese día.
*/
#include <stdio.h>
#include <string.h>
void iniciarMes(int []);
void diaDeMayorFacturacion(int []);
void mostrarTotales(int []);
int main()
{
    int opcion, dia;
    long int nroFactura;
    int importe;
    //int codCliente[5];

    int nuevoMes[31];


    iniciarMes(nuevoMes);


    printf("Seleccione una opcion del menu: \n");
    printf("1. Ingresar nueva factura \n");
    printf("2. Obtener total facturado por dia \n");
    printf("3. Obtener dia de mayor facturacion y monto \n");
    printf("0. Salir del menu \n");
    scanf("%d", &opcion);


    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            printf("\nIngrese el numero de factura: \n"); scanf("%ld", &nroFactura); 
            printf("Ingrese el dia: \n"); scanf("%d", &dia);
            printf("Ingrese el importe: \n"); scanf("%d", &importe);
           // printf("Ingrese el codigo de cliente: \n"); scanf("%d", &codCliente);

            nuevoMes[dia - 1] += importe; 

            break;
        case 2:
            mostrarTotales(nuevoMes);
            break;
        case 3:     
            diaDeMayorFacturacion(nuevoMes);
            break;
        
        default:
                printf("Opcion Incorrecta: \n");
                printf("1. Ingresar nueva factura \n");
                printf("2. Obtener total facturado por dia \n");
                printf("3. Obtener dia de mayor facturacion y monto \n");
                scanf("%d", &opcion);
            break;
        }

        printf("Seleccione una opcion del menu: \n");
        printf("1. Ingresar nueva factura \n");
        printf("2. Obtener total facturado por dia \n");
        printf("3. Obtener dia de mayor facturacion y monto \n");
        printf("0. Salir del menu \n");
        scanf("%d", &opcion);
    }
    return 0;
}

void iniciarMes(int a[]){
    for (int i = 0; i < 31; i++)
    {
        a[i] = 0;
    }
}

void diaDeMayorFacturacion(int a[]){
    int mayorValor = 0;
    int posActual = 0;
    int posMayorValor = 0;

        for (int i = 0; i < 31; i++)
            {
                posActual = a[i];

                if (posActual > mayorValor)
                {
                    mayorValor = posActual;
                    posMayorValor = i;

                }
                    
        }

    printf("El dia %d se recaudo %d \n", posMayorValor + 1, mayorValor);
}

void mostrarTotales(int a[]){
    for (int i = 0; i < 31; i++)
        {   
            if (a[i] > 0)
            {
                printf("El dia %d se facturo %d \n", i + 1, a[i]);
            }
        }
}