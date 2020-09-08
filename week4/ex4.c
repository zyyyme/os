#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    char exit_string[5];


    while (1==1) {
        fgets(command, 100, stdin);

        // Since fgets get all elements of string, this is needed to check for exit
        strncpy(exit_string,command, 4);
        if (strcmp(exit_string, "exit") == 0) {
            exit(0);
        }

        int n = fork();
        
        if (n == 0) {
            char shell[] = "/bin/bash";
            char *args[] = {shell, "-c", command};
            char *env[] = {};

            execve(shell, args, env);
        }
    }
    return 0;
}