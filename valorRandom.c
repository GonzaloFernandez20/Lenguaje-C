#include "valorRandom.h"

int valorRandomEntre(int min_value, int max_value){

    // Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    // Generar un valor aleatorio dentro del rango
    int random_value = rand() % (max_value - min_value + 1) + min_value;

    return random_value;
}