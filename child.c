#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid == 0) {
        printf("This is the Child Process.\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID (from Child): %d\n", getppid());
    }
    else {
        printf("This is the Parent Process.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (from Parent): %d\n", pid);
    }

    return 0;
}
