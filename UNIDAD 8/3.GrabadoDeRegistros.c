/*La información de todos los empleados de la empresa DATASYSTEM está almacenada en  una  variable  de  tipo  struct    llamada  “empleado”.  La  información  con  que  se cuenta de cada empleado es: nombre, sexo y sueldo. Por tanto se pide: Realizar un programa en C que lea en un array de estructuras los datos de los N trabajadores de la empresa y que imprima los datos del empleado con mayor y menor salario.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Empleado{
    char nombre[15];
    char sexo;
    int sueldo;
}Empleado;

void menuDeOpciones(int*);
void cargarEmpleado(Empleado e[], int*, char [], char, int);
void empleadoDeMayorSalario(Empleado e[], int);
void empleadoDeMenorSalario(Empleado [], int);


int main()
{
    int opcion;
    int n;
    char nombre[20];
    char sexo;
    int sueldo;

    printf("Ingrese la cantidad de empleados: "); scanf("%d", &n);

    Empleado e[n];
    int longitud = 0;
    //iniciarPlanillaDeEmpleados(e);

    menuDeOpciones(&opcion);
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            if (longitud < n)
            {
                printf("\nIngrese el nombre del empleado: "); scanf("%s", nombre); 
                printf("Ingrese el sueldo bruto: "); scanf("%d", &sueldo); fflush(stdin);
                printf("Ingrese su sexo: "); scanf("%c", &sexo);

                cargarEmpleado(e, &longitud, nombre, sexo, sueldo);    
            }else{
                printf("No se pueden cargar mas empleados.\n");
            }
            

            break;
        case 2:
            empleadoDeMayorSalario(e, longitud);

            break;
        case 3: 
            empleadoDeMenorSalario(e, longitud);

            break;
        case 4:
            FILE* archivo = fopen("Registro.txt", "w+b");

            for (int i = 0; i < longitud; i++)
            {
                //fwrite(&e[i], sizeof(Empleado), 1,archivo);
                fprintf(archivo, "Nombre: %s\n", e[i].nombre);
                fprintf(archivo, "Sexo: %c\n", e[i].sexo);
                fprintf(archivo, "Sueldo: %d\n\n", e[i].sueldo);
            }
            fclose(archivo);

            break;
        default:
            printf("Opcion Incorrecta: \n");
            menuDeOpciones(&opcion);

            break;
        }
        menuDeOpciones(&opcion);
    }
    return 0;
}
void menuDeOpciones(int* opcion){
    
    printf("\nSeleccione una opcion del menu: \n");
    printf("1. Ingresar nuevo empleado \n");
    printf("2. Obtener empleado con mayor salario \n");
    printf("3. Obtener empleado con menor salario \n");
    printf("4. Obtener detalle de empleados \n");
    printf("0. Salir del menu \n");
    scanf("%d", opcion);
}

void cargarEmpleado(Empleado e[], int* longitud, char nombre[], char sexo, int sueldo){
    strcpy(e[*longitud].nombre, nombre);
    e[*longitud].sexo = sexo;
    e[*longitud].sueldo = sueldo;
    (*longitud)++;
}

void empleadoDeMayorSalario(Empleado e[], int longitud){
    int posMayorSalario = 0;
    
    for (int i = 0; i < longitud; i++)
    {
        if (e[i].sueldo > e[posMayorSalario].sueldo)
        {
            posMayorSalario = i;
        }
    }
    
    printf("\nEl empleado con mayor salario es %s con un sueldo de %d.\n", e[posMayorSalario].nombre, e[posMayorSalario].sueldo);
}

void empleadoDeMenorSalario(Empleado e[], int longitud){
    int posMenorSalario = 0;
    
    for (int i = 1; i < longitud; i++)
    {
        if (e[i].sueldo < e[posMenorSalario].sueldo)
        {
            posMenorSalario = i;
        }
    }
    printf("\nEl empleado con menor salario es %s con un sueldo de %d.\n", e[posMenorSalario].nombre, e[posMenorSalario].sueldo);
}