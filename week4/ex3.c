#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char command[100];
    while (1 == 1){
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            exit(0);
        }
        system(command);
    }
    
    return 0;
}