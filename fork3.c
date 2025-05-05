#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t child_pid;

    printf("Parent Process: PID = %d\n", getpid());

    for (int i = 0; i < 5; i++) {
        child_pid = fork();

        if (child_pid == 0) {
            // In child process
            printf("Child Process %d: PID = %d, Parent PID = %d\n", i+1, getpid(), getppid());
            exit(0); // Important: child exits to prevent creating more children
        }
        else if (child_pid > 0) {
            // Parent process continues to create more children
            sleep(1); // Optional: slows down output for clarity
        }
        else {
            perror("Fork Failed");
            exit(1);
        }
    }

    return 0;
}
