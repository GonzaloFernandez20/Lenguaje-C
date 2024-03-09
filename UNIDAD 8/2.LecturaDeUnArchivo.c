#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fileSize(FILE* f);
// fileSize(archivo)/sizeof(Estructura);  -> Para saber la cantidad de registros que hay en un archivo
int main()
{   
    FILE* archivo;
    archivo = fopen("MiArchivo.txt", "r+b");
    char c,t;
    
    int n; 
    printf("Ingrese la posicion desde donde desea leer: "); scanf("%d", &n);
    printf("Ingrese el valor que desea modificar en esa posicion: "); scanf(" %c",&t);
    //printf("Tamanio del archivo: %d bytes \n", fileSize(archivo));

    fseek(archivo, n*sizeof(char), SEEK_SET); //Apuntamos el inicio del archivo a la posicion n
    fwrite(&t, sizeof(char), 1, archivo);
    fclose(archivo);

    archivo = fopen("MiArchivo.txt", "r");
    do
    {   
        fread(&c, sizeof(char),1,archivo);
        int pos = ftell(archivo);
        printf("Lectura: %c en el byte Nro: %d\n",c,pos);

    } while (!feof(archivo));
    

    fclose(archivo);
    return 0;
}

int fileSize(FILE* f){

    int valorActual = ftell(f); 
    fseek(f, 0, SEEK_END);
    int ultimoValor = ftell(f);
    fseek(f, valorActual, SEEK_SET);

    return ultimoValor;
}