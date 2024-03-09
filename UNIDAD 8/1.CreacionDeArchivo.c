#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE* archivo = fopen("MiArchivo.txt","w+b");
    /* char c = 'A';
    fwrite(&c, sizeof(char), 1, archivo);
    c = 'B';
    fwrite(&c, sizeof(char), 1, archivo);
    c = 'C';
    fwrite(&c, sizeof(char), 1, archivo);
    */ 

    char cadena[50];
    strcpy(cadena, "Hola, este es mi archivo...");

    fwrite(cadena, strlen(cadena)*sizeof(char), 1, archivo);
    // strlen(cadena)*sizeof(char) Con esto saco exactamente la cantidad de bytes que necesita 
    // escribir en el archivo y no se me escribe basura una vez terminada la cadena.
    
    fclose(archivo);
    return 0;
}
