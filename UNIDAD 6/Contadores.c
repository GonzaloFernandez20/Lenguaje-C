#include <stdio.h>

void inicializarContadores(int []);
void mostrarResultados(int []);

int main()
{
    int contadores[100];
    int valor;

    inicializarContadores(contadores);

    printf("Ingrese un valor: "); scanf("%d", &valor);

    while (valor >= 0)
    {
        contadores[valor] += 1;
        printf("Ingrese un valor: "); scanf("%d", &valor);
    }
    
    mostrarResultados(contadores);

    return 0;
}

void inicializarContadores(int a[]){
    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
}
void mostrarResultados(int a[]){
    for (int i = 0; i < 100; i++)
    {
        if (a[i] > 0)
        {
            printf("El valor %d aparecio %d veces", i, a[i]);
        }
        
    }
    
}