#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // Array to store numbers as strings
    char *numbers[argc - 1];

    // Loop through arguments
    for (int i = 1; i < argc; ++i)
    {
        numbers[i - 1] = argv[i];
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        printf("Fork() failed.\n");
    }

    // Child process handling
    else if (pid == 0)
    {
        execlp("checker", "checker", numbers[0], numbers[1], NULL);
    }

    // Parent process handling
    else
    {
        printf("Coordinator: forked process with ID %d.\n", getpid());
        printf("Coordinator: waiting for process [%d].\n", getpid());

        // Wait for child process to finish
        int status;
        waitpid(pid, &status, 0);

        int result = WEXITSTATUS(status);
        printf("Coordinator: child process %d returned %d.\n", pid, result);
    }

    return 0;
}