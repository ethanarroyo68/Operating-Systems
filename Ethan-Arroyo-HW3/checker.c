#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int argOne = atoi(argv[1]);
    int argTwo = atoi(argv[2]);
    int fd = atoi(argv[3]);
    int sharedMemoryId;

    read(fd, &sharedMemoryId, sizeof(sharedMemoryId));

    // Attach to shared memory segment
    int *sharedMemoryPointer = (int *)shmat(sharedMemoryId, NULL, 0);

    printf("Checker process [%d]: Starting.\n", getpid());
    printf("Checker process [%d]: Read 4 bytes containing shm ID %d\n", getpid(), sharedMemoryId);

    if (argTwo % argOne == 0)
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), argTwo, argOne);
        *sharedMemoryPointer = 1;
        printf("Checker process [%d]: Wrote result (1) to shared memory.\n", getpid());
        return 1; // success code
    }

    else
    {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", getpid(), argTwo, argOne);
        *sharedMemoryPointer = 0;
        printf("Checker process [%d]: Wrote result (0) to shared memory.\n", getpid());
        return 0; // failure code
    }
}