#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signum)
{
    static int signals = 0;
    static int gen = 0;

    signals++;
    if (signum == SIGUSR1)
    {
        printf("Received %d signals.\n", signals);
        fflush(NULL);
    }
    else if (signum == SIGUSR2)
    {
        printf("Current generation: %d\n", gen);
        fflush(NULL);
    }
    else if (signum == SIGTERM)
    {
        signals = 0;
        gen++;

        pid_t cpid = fork();
        if (cpid == -1)
        {
            exit(1);
        }
        if (cpid > 0)
        {
            exit(0);
        }
    }
    else if (signum == SIGINT)
    {
        exit(0);
    }
}

int main(void)
{
    pid_t cpid = fork();
    if (cpid == -1)
    {
        return 1;
    }
    else if (cpid)
    {
        exit(0);
    }

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handler;

    if (sigemptyset(&sa.sa_mask) < 0)
    {
        exit(1);
    }

    if (sigaction(SIGUSR1, &sa, NULL) < 0)
    {
        exit(1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
    {
        exit(1);
    }
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {
        exit(1);
    }
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {
        exit(1);
    }

    while (1)
    {}

    return 0;
}
