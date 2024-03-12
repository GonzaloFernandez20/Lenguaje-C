#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valorDelNodo;
    struct Nodo* sgteNodo;
}Nodo;

void agregarNodo(Nodo**, int);
void mostrarLista(Nodo*);
void liberarMemoria(Nodo**);
void eliminarNodo(Nodo**, int);

int main()
{
    Nodo* listaEnlazada = NULL;

    agregarNodo(&listaEnlazada, 5);
    agregarNodo(&listaEnlazada, 6);
    agregarNodo(&listaEnlazada, 7);
    agregarNodo(&listaEnlazada, 8);

    mostrarLista(listaEnlazada);
    eliminarNodo(&listaEnlazada, 8); puts("\n");
    mostrarLista(listaEnlazada);

    liberarMemoria(&listaEnlazada);
    return EXIT_SUCCESS;
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
void mostrarLista(Nodo* p){

    if (p == NULL)
    {
        printf("Error, la lista que paso esta vacia. \n");
    }else
    {
        Nodo* nodoAuxiliar = p;
        int i = 0;
        while (nodoAuxiliar != NULL)
        {
            printf("valor del nodo %d: %d\n", i++, nodoAuxiliar->valorDelNodo);
            nodoAuxiliar = nodoAuxiliar->sgteNodo;
        }
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
void eliminarNodo(Nodo** p, int valor){
    Nodo* aux = *p;
    Nodo* ant = NULL;

    while ((aux != NULL) && (aux->valorDelNodo != valor))
    {
        ant = aux;
        aux = aux->sgteNodo;
    }
    if (aux != NULL)
    {
        if (ant != NULL)
        {
            ant->sgteNodo = aux->sgteNodo;
        }else
        {
            *p = aux->sgteNodo;
        }
        free(aux);
    }
}