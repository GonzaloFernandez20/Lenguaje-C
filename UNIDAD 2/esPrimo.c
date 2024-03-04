//Mostrar los primeros n numeros primos siendo n un valor ingresado por el usuario. 

#include <stdio.h>

void esPrimo(int);

int main()
{
    int a;

    printf("ingrese la cantidad de numeros primos que desea ver: ");
    scanf("%d", &a);

    esPrimo(a);

    return 0;
}

void esPrimo(int a){
    int esPrimo;
    int contadorDePrimos = 0;
    int iterador = 1;
    
    while (contadorDePrimos < a)
    {
        esPrimo = 1;
        for (int i = 2; i < iterador && esPrimo; i++)
        {
            if(iterador % i == 0){
                esPrimo = 0;
            }
        }   
        if(esPrimo){
            printf("el numero %d es primo \n", iterador);
            contadorDePrimos++;
        }
        iterador++;
    }
}