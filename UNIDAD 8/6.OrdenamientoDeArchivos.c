#include <stdio.h>
#include <stdlib.h>

typedef struct Emp
{
    int idEmp;
    char nombre[30];
    char direccion[120];
    long fechaDeIngreso;
}Emp;

int subirArchivo(FILE*, Emp[]);
void ordenar(Emp[], int);
void bajarArchivo(FILE*, Emp[], int);

int main()
{   
    Emp array[100];
    FILE* archivo = fopen("EMP.txt","r+b");
    int longitud = subirArchivo(archivo, array);

    ordenar(array, longitud);

    fclose(archivo);

    archivo = fopen("EMP.txt", "w+b");

    bajarArchivo(archivo, array, longitud);

    fclose(archivo);

    return 0;
}

int subirArchivo(FILE* archivo, Emp array[]){
    int longitud = 0;
    Emp registro;
    
}



void leerEmp(FILE* a, Emp* reg)
{
 fread(reg,sizeof(Emp),1,a);
}
// escribe un entero en el archivo
void grabarEmp(FILE* a, Emp* reg)
{
 fwrite(reg,sizeof(Emp),1,a);
}