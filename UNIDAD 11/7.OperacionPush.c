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

    agregarAlaPila(&pila, 1);
    agregarAlaPila(&pila, 2);
    agregarAlaPila(&pila, 3);
    agregarAlaPila(&pila, 4);

    sacarDeLaPila(&pila);

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