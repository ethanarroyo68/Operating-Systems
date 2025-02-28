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

    for (int i = 0; i < 4; i++)
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            printf("Fork() failed.\n");
            exit(1);
        }
        // Parent process handling
        else if (pid > 0)
        {
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);

            // Wait for child process to finish
            int status;
            waitpid(pid, &status, 0);

            int result = WEXITSTATUS(status);
            printf("Coordinator: child process %d returned %d.\n", pid, result);

        }

        else // Child process
        {
            if (execlp("./checker", "checker", numbers[0], numbers[i + 1], NULL) == -1)
            {
                perror("execlp failed");
                exit(2); // Child exits if execlp fails
            }
            exit(0); // Just in case (though not needed if execlp works)
        }
    }

    return 0;
}