#include <stdio.h>

int main()
{
    int a = 5, b = 7;

    int* p;

    p = &b;

    *p = 3;

    printf("La direccion de memoria de a es: %p \n",&a);
    printf("La direccion de memoria de p es: %p \n",p);
    printf("La valor de p es: %d",*p);

    return 0;
}
