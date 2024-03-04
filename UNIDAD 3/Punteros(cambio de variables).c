#include <stdio.h>
void modificarValor(int* , int*);


int main()
{
    int a = 1;
    int b = 5;

    printf("Los valores que guardo el sistema son: \n a: %d \n b: %d \n", a, b);

    modificarValor(&a, &b);

    printf("Los valores post cambio en el sistema son: \n a: %d \n b: %d \n", a, b);

    return 0;
}

void modificarValor(int* a, int* b){ //Recibe 2 punteros a enteros
    int aux;

    aux = *a; //Asigno el contenido de a a la variable aux
    *a = *b; // asigno el contenido de b al contenido de a
    *b = aux; // asigno el valor de aux al contenido de b
}