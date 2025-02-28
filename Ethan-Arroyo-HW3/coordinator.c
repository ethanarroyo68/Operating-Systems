#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // Array to store numbers as strings initially
    char *numbers[argc - 1];

    // Loop through arguments, storing them
    for (int i = 1; i < argc; ++i)
    {
        numbers[i - 1] = argv[i];
    }

    // Store the shared memory and child ids for later access
    int sharedMemoryIds[4];

    for (int i = 0; i < 4; i++)
    {
        // Perform pipe()
        int fd[2];
        pipe(fd);

        // Perform fork()
        pid_t pid = fork();

        // Create shared memory segment for each pair of child and parent
        int sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        sharedMemoryIds[i] = sharedMemoryId;

        // If fork failed
        if (pid < 0)
        {
            printf("Fork() failed.\n");
            exit(1);
        }

        // Parent process handling
        else if (pid > 0)
        {
            // Close read end of the pipe
            close(fd[0]);

            printf("Coordinator: forked process with ID %d.\n", pid);

            // Write sharedMemoryId to the pipe
            write(fd[1], &sharedMemoryId, sizeof(sharedMemoryId));
            printf("Coordinator: wrote shm ID %d to pipe (4 bytes)\n", sharedMemoryId);

            // Close the write end of the pipe after writing
            close(fd[1]);
        }

        // Child process handling
        else
        {
            // Close the write end of the pipe
            close(fd[1]);

            char fd_str[10];
            sprintf(fd_str, "%d", fd[0]);

            if (execlp("./checker", "checker", numbers[0], numbers[i + 1], fd_str, NULL) == -1)
            {
                perror("execlp failed");
                exit(2); // Child exits if execlp fails
            }
            exit(0); // Just in case (though not needed if execlp works)
        }
    }

    // Now wait for all children
    for (int i = 0; i < 4; i++)
    {
        int status;
        pid_t child_pid = waitpid(-1, &status, 0); // Wait for any child
        printf("Coordinator: waiting on child process ID %d...\n", child_pid);
    }

    for (int i = 0; i < 4; i++)
    {
        // Wait child
        // int status;
        // pid_t child_pid = waitpid(-1, &status, 0); // Wait for any child
        // printf("Coordinator: waiting on child process ID %d...\n", child_pid);

        // Attach to the shared memory segment
        int *sharedMemoryPointer = (int *)shmat(sharedMemoryIds[i], NULL, 0);

        if (*sharedMemoryPointer == 1)
        {
            printf("Coordinator: result 1 read from shared memory: %s is divisible by %s.\n", numbers[i + 1], numbers[0]);
        }
        else
        {
            printf("Coordinator: result 0 read from shared memory: %s is NOT divisible by %s.\n", numbers[i + 1], numbers[0]);
        }

        // Destroy shared memory segment
        shmctl(sharedMemoryIds[i], IPC_RMID, NULL);
    }

    printf("Coordinator: exiting.\n");

    return 0;
}
/*
make clean
make all
clear
./coordinator 3 6 12 15 9
*/