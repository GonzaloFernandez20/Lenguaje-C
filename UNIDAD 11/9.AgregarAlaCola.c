#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo* sgteNodo;
}Nodo;

void agregarAlaCola(Nodo**, int);
void mostrarCola(Nodo*);
void desencolar(Nodo**);

int main()
{
    Nodo* cola = NULL;

    agregarAlaCola(&cola, 1);
    agregarAlaCola(&cola, 2);
    agregarAlaCola(&cola, 3);
    agregarAlaCola(&cola, 4);

    mostrarCola(cola);

    desencolar(&cola);

    mostrarCola(cola);

    desencolar(&cola);

    mostrarCola(cola);

    desencolar(&cola);

    mostrarCola(cola);
    return 0;
}

void agregarAlaCola(Nodo** p, int valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->sgteNodo = NULL;

    if (*p == NULL)
    {
        nuevoNodo->sgteNodo = nuevoNodo;
    }else
    {
        nuevoNodo->sgteNodo = (*p)->sgteNodo;
        (*p)->sgteNodo = nuevoNodo;
    }
    *p = nuevoNodo;
}
void mostrarCola(Nodo* p){
    Nodo* aux = p->sgteNodo;
    while (1)
    {
        if (aux->valor != p->valor)
        {
            printf(" %d", aux->valor); //Imprime todos los valores de la cola menos el ultimo
            aux = aux->sgteNodo;
        }else
        {
            printf(" %d", aux->valor);// Imprime el ultimo valor y sale del ciclo
            break;
        } 
    }
    puts("");

}
void desencolar(Nodo** p){
    
    if (*p == (*p)->sgteNodo)
    {
        free(*p);
        *p = NULL;
    }else
    {
        Nodo* aux = (*p)->sgteNodo;
        (*p)->sgteNodo = aux->sgteNodo;
        free(aux);
    }
  
}