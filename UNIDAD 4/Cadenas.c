#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Desarrollar un programa que le permita al usuario ingresar un conjunto de 5 cadenas de 
caracteres. Luego se debe imprimir el conjunto que el usuario ingresó, pero en orden 
inverso.
*/
int main()
{
    char* cadena[10]; //array de cadenas
    char cadenaAuxiliar[10]; //una sola cadena

    for (int i = 0; i < 5; i++)
    {   
        printf("Ingrese una cadena: "); scanf("%s", cadenaAuxiliar);

        cadena[i] = (char*) malloc(strlen(cadenaAuxiliar)+1); // creo el array en la posicion i con el tamanio de la cadena ingresada
        strcpy(cadena[i],cadenaAuxiliar); //cargo la cadena en ese array creado.
    }
    

    for (int i = 4; i >= 0; i--)
    {
        printf("%s ", cadena[i]);
    }
    
    return 0;
}

