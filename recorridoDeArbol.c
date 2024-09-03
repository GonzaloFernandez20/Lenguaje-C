#include <stdio.h>
#include <stdlib.h>

int *recorrer_en_pre_orden(int arbol[]);
void mostrar_arbol(int arbol[]);

int main() {
     int arbolBinario[] = {8,22,14,13,45,11,3,7,4,5,9};

     int *arbol_recorrido = recorrer_en_pre_orden(arbolBinario);
     mostrar_arbol(arbol_recorrido);
}

int *recorrer_en_pre_orden(int arbol[]){

     return arbol;
}

void mostrar_arbol(int arbol[]){

}