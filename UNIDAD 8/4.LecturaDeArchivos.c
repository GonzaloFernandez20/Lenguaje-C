#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************************************************************************************************/
//Creamos un archivo, le grabamos 3 estructuras y despues lo leemos. 
typedef struct Jugador{
    char nombre[15];
    int puntaje; 
}Jugador;

void salvarJugador(Jugador* , char [], int);

/************************************************************************************************************************/

int main()
{   
    FILE* archivo;
    Jugador jugador;
    /**************************************** Escribo el archivo que voy a leer ****************************************/
    archivo = fopen("ArchivoDeLectura.txt", "w");

    salvarJugador(&jugador, "Pablo", 200);
    fwrite(&jugador, sizeof(Jugador), 1, archivo);

    salvarJugador(&jugador, "Juan", 400);
    fwrite(&jugador, sizeof(Jugador), 1, archivo);

    salvarJugador(&jugador, "Hector", 1200);
    fwrite(&jugador, sizeof(Jugador), 1, archivo);

    salvarJugador(&jugador, "Damian", 50);
    fwrite(&jugador, sizeof(Jugador), 1, archivo);

    fclose(archivo);
    /************************************************** Leo el archivo **************************************************/
    archivo = fopen("ArchivoDeLectura.txt", "r");

    while (fread(&jugador, sizeof(Jugador), 1, archivo) == 1){ //Mientras puede leer, lo hace
        printf("%s -> %d \n", jugador.nombre, jugador.puntaje);
    }

    fclose(archivo);
    
    return 0;
}
/************************************************************************************************************************/
void salvarJugador(Jugador *jugador, char nombre[], int puntaje){ //Recibe la referencia de jugador y con eso modifica los valores de la variable original
    strcpy(jugador->nombre, nombre);
    jugador->puntaje = puntaje;
}