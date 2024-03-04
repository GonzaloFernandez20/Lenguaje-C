/* Si durante la ejecución de un programa necesitamos asignar una cadena a un char[] 
tendremos que hacerlo asignando uno a uno los caracteres de la cadena a los caracteres del array.*/

#include <stdio.h>

void copiarCadena(char[], char[]);
int longitudDeCadena(char[]);
int cadenaVacia(char[]);
void concatenarCadena(char[], char[]); 
int compararCadenas(char [], char[]);

int main()
{
    //char cadena[] = "";
    //char b[25] = "Hola";
    //char c[20] = "\0 que pasa ahora?"; // -> Si arranca con el \0 entonces todo lo otro se anula por ser el \0 el fin de cadena

    //copiarCadena("Pablo", cadena);
    //concatenarCadena(b, " que tal?");
    //printf("Contenido de cadena: %s \n", cadena);
    //printf("Longitud de la cadena: %d", longitudDeCadena(cadena));

    /* printf("cadena = [%s] es vacia? %d\n", cadena, cadenaVacia(cadena));
    printf("cadena = [%s] es vacia? %d\n", b, cadenaVacia(b));
    printf("cadena = [%s] es vacia? %d\n", c, cadenaVacia(c)); */

    //printf("Contenido de cadena: %s \n", b);
    char nom[]="Pablo"; int edad=39; double altura=1.70; 
    char salida[50]; 
    sprintf(salida
    ,"Mi nombre es %s, tengo %d y mido %lf"
    ,nom
    ,edad
    ,altura);
 
    printf("%s\n",salida);

    //printf("Las cadenas son iguales: %d\n", compararCadenas("TX9XD-98N7V-6WMQ6-BX7FG-H8Q99", "7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH"));
    
    return 0;
}

void concatenarCadena(char t[], char s[]){ //agrega los caracteres de s al final del último carácter de t.
    
    int longitudDeLaPrimerCadena = longitudDeCadena(t);
    int i = 0;

    while (s[i] != '\0')
    {
        t[longitudDeLaPrimerCadena] = s[i];
        i++; longitudDeLaPrimerCadena++;
    }
    
    t[longitudDeLaPrimerCadena] = '\0';

}

void copiarCadena(char c1[], char c2[]){ //La cadena c1 se copia en c2
    
    int i = 0;

    while (c1[i] != '\0')
    {
        c2[i] = c1[i]; //Cuando detecta el fin de cadena de la cadena original sale del ciclo y agrega el \0
        i++;

        // Alternativa: *c2++ = *c1++;
    }

    c2[i] = '\0';
    
}

/* Version compacta:
void copiarCadena(char* t,char* s)
    {
        while( *t++=*s++ );
    }
*/

int longitudDeCadena(char s[]){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;    
}

/*Version compacta: 
int longitud(char* t)
    {
        int i; for( i=0; *t++; i++ ); 
        return i;
    }
*/

int cadenaVacia(char s[]){
    /* if (s[0] == '\0')
    {
        return 1;
    }else{ return 0; } */

    //Mejor implementacion: 
    return s[0] == '\0';
}

int compararCadenas(char s[], char t[]){
    int i = 0;
    while (s[i] != '\0' || t[i] != '\0') //Cuando ambos sean diferentes del \0 sale del while, mientras tanto evualua 
    {
        if (s[i] == t[i])
        {
            i++;
        }else{ return 1; }
        
    }
    return 0;
}