#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // 1. Prepare new arguments array
    // Need: program name + existing args + 1 new arg + NULL terminator
    char *new_argv[argc + 2]; 
    
    new_argv[0] = "originalcontainerd"; // The program to call
    new_argv[1] = "--no-pivot";       // The added argument
    
    // Copy existing arguments (skipping argv[0])
    for (int i = 1; i < argc; i++) {
        new_argv[i + 1] = argv[i];
    }
    
    // Last element must be NULL for execvp
    new_argv[argc + 1] = NULL;

    printf("Parent: Calling child_prog with new argument.\n");

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child Process
        execvp(new_argv[0], new_argv);
        // If execvp returns, it failed
        perror("execvp failed");
        exit(1);
    } else {
        // Parent Process
        wait(NULL); // Wait for child to finish
        printf("Parent: Child finished.\n");
    }

    return 0;
}
