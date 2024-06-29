//------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

//------------------------------------------------

sem_t sem_a;
sem_t sem_b;
sem_t sem_c;
sem_t sem_bc;

//------------------------------------------------

void *imprimirA(){
    int aux = 4;
    while (aux != 0)
    {
        sem_wait(&sem_bc);
            puts("A");
            aux--;
        sem_post(&sem_a);
    }
}
void *imprimirB(){
    while (1)
    {   
        sem_wait(&sem_c);
        sem_wait(&sem_a);
            puts("B");
        sem_post(&sem_bc);
        sem_post(&sem_b);
    }
}
void *imprimirC(){
    while (1)
    {   
        sem_wait(&sem_b);
        sem_wait(&sem_a);
            puts("C");
        sem_post(&sem_bc);
        sem_post(&sem_c);
    }
}

int main(void)
{
    sem_init(&sem_b, 0, 0);
    sem_init(&sem_bc, 0, 0);
    sem_init(&sem_a, 0, 1);
    sem_init(&sem_c, 0, 1);

    pthread_t hiloA;
    pthread_t hiloB;
    pthread_t hiloC;

    pthread_create(&hiloA, NULL, imprimirA, NULL);
    pthread_create(&hiloB, NULL, imprimirB, NULL);
    pthread_create(&hiloC, NULL, imprimirC, NULL);

    pthread_join(hiloA, NULL);
    pthread_join(hiloB, NULL);
    pthread_join(hiloC, NULL);
    
    return 0;
}
