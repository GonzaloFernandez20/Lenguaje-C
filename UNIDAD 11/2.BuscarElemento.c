#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valorDelNodo;
    struct Nodo* sgteNodo;
}Nodo;

void agregarNodo(Nodo**, int);
void buscarElemento(Nodo*, int);

int main()
{
    Nodo* ListaEnlazada;

    agregarNodo(&ListaEnlazada, 5);
    agregarNodo(&ListaEnlazada, 6);
    agregarNodo(&ListaEnlazada, 7);
    agregarNodo(&ListaEnlazada, 8);
    agregarNodo(&ListaEnlazada, 9);

    buscarElemento(ListaEnlazada, 5);

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
void buscarElemento(Nodo* p, int valorBuscado){

    if (p != NULL)
    {
        Nodo* auxiliar = p;
        int contador = 0; 
        while (auxiliar != NULL && auxiliar->valorDelNodo != valorBuscado)
        {
            
            auxiliar = auxiliar->sgteNodo; 
            contador++; 
        }
        if(auxiliar == NULL)
        {
            puts("No se encontro el valor");
        }else
        {
            printf("Se encontro en la posicion %d\n", contador);
        }
    }else
    {
        puts("LISTA VACIA\n");
    }   
}
