#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int argOne = atoi(argv[1]);
    int argTwo = atoi(argv[2]);

    printf("Checker process [%d]: Starting.\n", getpid());

    if (argTwo % argOne == 0)
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), argOne, argTwo);
        printf("Checker process [%d]: Returning 1.\n", getpid());
        return 1; // success code
    }

    else
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), argOne, argTwo);
        printf("Checker process [%d]: Returning 2.\n", getpid());
        return 0; // failure code
    }
}