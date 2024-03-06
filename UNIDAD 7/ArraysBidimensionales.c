/*
Se ingresa un conjunto de ternas de valores que representan el año, el grado y la cantidad de alumnos 
que se inscribieron en un colegio durante ese año y para ese grado en 
particular. Solo se ingresará la información comprendida entre los años 2000 y 2009. En 
el colegio, los alumnos cursan desde el primer grado y hasta el séptimo. Los datos se 
ingresan sin ningún tipo de orden.
Se pide:
1. Emitir un listado ordenado por año detallando para cada año la cantidad de inscritos 
por grado.
2. Emitir un listado ordenado por grado detallando para cada grado la cantidad de inscritos por año.
*/

#include <stdio.h>

void listarXgrado(int [][3]);
void listarXanio(int [][3]);

int main()
{
    int matriz[2][3];
    

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {   
            printf("\nIngrese la cantidad de inscriptos del anio %d y %d grado: ",2000 + i,j + 1); 
            scanf("%d", &matriz[i][j]); 
        }
    }
    // Imprimir la matriz
    printf("Matriz 1: \n");
    listarXgrado(matriz);
    printf("Matriz 2: \n");
    listarXanio(matriz);
    return 0;
}

void listarXgrado(int matriz[][3]){
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void listarXanio(int matriz[][3]){
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}