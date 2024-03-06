#include "funciones.h"

int main()
{   
    // "creo" las fechas 2/10/1970 y 3/8/2010
    Fecha f1 = unificarFecha(2,10,1970);
    Fecha f2 = unificarFecha(3,8,2010);

    // obtengo sus representaciones con formato "dd/mm/aaaa"
    char* sF1 = toString(f1);
    char* sF2 = toString(f2);

    // las comparo para ver cual es posterior
    if( compararFechas(f1,f2) <0 ){
        printf("%s es posterior a %s\n",sF2,sF1);
    }else{
        printf("%s es posterior a %s\n",sF1,sF2);
    }
    return 0;
}