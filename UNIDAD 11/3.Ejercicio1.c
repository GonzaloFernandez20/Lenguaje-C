/*
Problema 11.1
Se ingresa por teclado un conjunto de valores enteros. El ingreso de datos finalizará cuando 
el usuario ingrese el valor 0 (cero). Luego se ingresa otro conjunto de valores enteros y, por 
cada uno de estos, se debe informar si el valor ingresado pertenece o no al primer conjunto.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Nodo
{
    int valorDelNodo;
    struct Nodo* sgteNodo;
}Nodo;

void agregarNodo(Nodo**, int);
void liberarMemoria(Nodo**);
void mostrarLista(Nodo*);
void ingresoDeNumeros(Nodo**, int*);
int comprobarEnLista(Nodo*, int);

int main()
{
    int n;
    Nodo* listaEnlazada1 = NULL; //Creamos el inicio de nuestra estructura y lo inicializamos en valor nulo
    Nodo* listaEnlazada2 = NULL;

    ingresoDeNumeros(&listaEnlazada1, &n);
    ingresoDeNumeros(&listaEnlazada2, &n);
    
    mostrarLista(listaEnlazada1);
    mostrarLista(listaEnlazada2);


    Nodo* auxLista1 = listaEnlazada1;

    while (auxLista1 != NULL)
    {
        if(comprobarEnLista(listaEnlazada2, auxLista1->valorDelNodo)){
            printf("El valor %d pertenece a la primer lista\n", auxLista1->valorDelNodo );
        }
        auxLista1 = auxLista1->sgteNodo;
    }
    

    liberarMemoria(&listaEnlazada1);
    liberarMemoria(&listaEnlazada2);
    return 0;
}
void agregarNodo(Nodo** p, int valorDelNodo){

    //Creacion de un nuevo nodo final
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valorDelNodo = valorDelNodo;
    nuevoNodo->sgteNodo = NULL;

    if (*p == NULL)
    {
        *p = nuevoNodo;
    }else
    {
        Nodo* aux = *p;
        
        while (aux->sgteNodo != NULL)
        {
            aux = aux->sgteNodo;
        }
        //como aux apunta al ultimo entonces su siguiente sera el nuevo nodo
        aux->sgteNodo = nuevoNodo;
    }
}
int comprobarEnLista(Nodo* p, int valor){

    Nodo* aux = p;
    while (aux != NULL)
    {
        if (aux->valorDelNodo == valor)
        {
            return true;
        }else
        {
            aux = aux->sgteNodo;
        }
    }
    return false;
}
void ingresoDeNumeros(Nodo** p, int* valor){
    printf("Ingrese el valor del nodo: "); scanf("%d", valor);
    agregarNodo(p, *valor);

    while (*valor != 0)
    {
        printf("Ingrese el valor del nodo: "); scanf("%d", valor);
        agregarNodo(p, *valor);
    }
    
}
void mostrarLista(Nodo* p){

    if (p == NULL)
    {
        printf("Error, la lista que paso esta vacia. \n");
    }else
    {
        Nodo* nodoAuxiliar = p;
        
        while (nodoAuxiliar != NULL)
        {
            printf(" %d ", nodoAuxiliar->valorDelNodo);
            nodoAuxiliar = nodoAuxiliar->sgteNodo;
        }
        puts("");
    }
}
void liberarMemoria(Nodo** p){
    while (*p != NULL)
    {
        Nodo* proximoNodo = (*p)->sgteNodo;
        free(*p);
        *p = proximoNodo;
    }
    puts("MEMORIA LIBERADA\n");
}

//Quedan pendientes por hacer los otros puntos del mismo problema.