#include "funciones.h"

Fecha unificarFecha(int d, int m, int a){
    return a*10000 + m*100 + d;
}

int compararFechas(Fecha f1, Fecha f2){
    return f1-f2;
}

int obtenerDia(Fecha f){
    return f%100;
}
int obtenerMes(Fecha f){
    return (f%10000)/100;
}
int obtenerAnio(Fecha f){
    return f/10000;
}

char* toString(Fecha f){
    int dia = obtenerDia(f);
    int mes = obtenerMes(f);
    int anio = obtenerAnio(f);

    char* s = (char*) malloc(11);
    sprintf(s,"%02d/%02d/%04d",dia,mes,anio);
    return s;
}
