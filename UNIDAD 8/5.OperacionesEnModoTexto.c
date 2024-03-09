#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE* archivo1 = fopen(argv[1], "r+");
    FILE* archivo2 = fopen(argv[2], "w+");

    char c; 
    while ((c=getc(archivo1)) != EOF) //c=getc(archivo1) != feof(f2)
    {
        putc(c,archivo2);
    }
    
    fclose(archivo1); fclose(archivo2);
    return 0;
}
