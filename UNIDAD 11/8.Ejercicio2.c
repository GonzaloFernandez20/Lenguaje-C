/*
Problema 11.3
Se ingresa por teclado un conjunto de valores que finaliza con la llegada de un 0 (cero). 
Se pide mostrar los elementos del conjunto en orden inverso al original.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valorDelNodo;
    struct Nodo* sgteNodo;
}Nodo;

void agregarAlaPila(Nodo**, int);
void sacarDeLaPila(Nodo**);
void mostrarPila(Nodo*);
void liberarMemoria(Nodo**);

int main()
{
    Nodo* pila;
    int n;

    while (1)
    {
        printf("Ingrese un valor: "); scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        agregarAlaPila(&pila, n);
    }

    mostrarPila(pila);

    liberarMemoria(&pila);

    return 0;
}

void agregarAlaPila(Nodo** p, int valor){

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo*));
    nuevoNodo->valorDelNodo = valor;
    nuevoNodo->sgteNodo = NULL;

    if (*p != NULL)
    {
        nuevoNodo->sgteNodo = *p;
    }
    *p = nuevoNodo;
    
}
void sacarDeLaPila(Nodo** p){
    Nodo* aux = (*p)->sgteNodo;
    free(*p);
    *p = aux;
}
void mostrarPila(Nodo* p){
    Nodo* aux = p;
    while (aux->sgteNodo != NULL)
    {
        printf(" %d", aux->valorDelNodo);
        aux = aux->sgteNodo;
    }
    
}
void liberarMemoria(Nodo** p){
    while ((*p) != NULL)
    {
        Nodo* proximoNodito = (*p)->sgteNodo;
        free(*p);
        *p = proximoNodito;
    }
    puts("\nMEMORIA LIBERADA\n");
}