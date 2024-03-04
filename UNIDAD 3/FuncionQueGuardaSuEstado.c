#include <stdio.h>

int siguienteNumeroPrimo(int*);
int esPrimo(int);

int main()
{
    int n;
    int ultimoPrimo = 0;

    printf("Cuantos numeros primos desea ver: "); scanf("%d", &n);
    
    while (n != 0)
    {   
        for (int i = 0; i < n; i++)
        {
        
        printf("%d \n",siguienteNumeroPrimo(&ultimoPrimo));
            
        }

    printf("Cuantos numeros primos desea ver: "); scanf("%d", &n);
        
    }
    
    
    return 0;
}

int siguienteNumeroPrimo(int* temp){
    *temp = *temp + 1;
    while (!esPrimo(*temp))
    {
        *temp = *temp + 1;
    }
    return *temp;
    
}

int esPrimo(int n){
    int ok = 1;
    for (int i = 2; i < n && ok; i++)
    {
        if (n % i == 0)
        {
            ok = 0;
        }
    }
    return ok;
    
}