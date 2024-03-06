#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longitudDeCadena(char s[]){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;    
}

int main()
{
    int a[] = {1,2,3,4,5,6};

    printf("Longitud: %d",longitudDeCadena(a));
    return 0;
}
