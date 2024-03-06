#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long Fecha; 

Fecha unificarFecha(int, int, int); 

int obtenerDia(Fecha);
int obtenerMes(Fecha);
int obtenerAnio(Fecha);

int compararFechas(Fecha, Fecha);

char* toString(Fecha f);