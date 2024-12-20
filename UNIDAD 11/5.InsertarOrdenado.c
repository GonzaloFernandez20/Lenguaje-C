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
void insertarOrdenado(Nodo**, int);

int main()
{
    Nodo* listaEnlazada = NULL;

    agregarNodo(&listaEnlazada, 2);
    agregarNodo(&listaEnlazada, 5);
    agregarNodo(&listaEnlazada, 6);
    agregarNodo(&listaEnlazada, 8);
    agregarNodo(&listaEnlazada, 9);
    agregarNodo(&listaEnlazada, 11);

    mostrarLista(listaEnlazada);

    insertarOrdenado(&listaEnlazada, 7);
    insertarOrdenado(&listaEnlazada, 12);
    insertarOrdenado(&listaEnlazada, 10);
    insertarOrdenado(&listaEnlazada, 1);

    mostrarLista(listaEnlazada);

    liberarMemoria(&listaEnlazada);

    return 0;
}


void insertarOrdenado(Nodo** p, int valorAInsertar){

    //Me crafteo un nuevo nodito
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valorDelNodo = valorAInsertar;
    nuevoNodo->sgteNodo = NULL;

    //Busco la posicion correcta para meter el nodo
    Nodo* aux = *p;
    Nodo* ant = NULL;
    while ((aux->valorDelNodo < valorAInsertar) && aux->sgteNodo != NULL )
    {   
        ant = aux;
        aux = aux->sgteNodo;
    }
    if (ant == NULL){
        nuevoNodo->sgteNodo = aux; //El nuevo nodo apunta al anterior inicio de lista
        *p = nuevoNodo; //el inicio de lista apunta al nuevo nodo
    }else if (aux->sgteNodo != NULL && ant != NULL){
        ant->sgteNodo = nuevoNodo;
        nuevoNodo->sgteNodo = aux;
    }else{
        aux->sgteNodo = nuevoNodo; // el nuevo nodo se pone al final
    }
    
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
