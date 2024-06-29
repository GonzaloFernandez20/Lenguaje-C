#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t PID;

    PID = fork();

    if (PID == (-1))
    {
        perror("Fallo en la creacion del hilo...");
    }else
    {
        if (PID == 0)
        {
            printf("PID del proceso hijo: %d\n", getpid());
        }else
        {
            printf("PID del proceso padre: %d\n", getpid());
        }
    }
    return 0;
}
