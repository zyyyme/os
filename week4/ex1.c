#include <stdio.h>
#include <unistd.h>

int main() {
    int n = fork();
    if (n == 0) {
        printf("Hello from child [PID - %d]\n", n);
    } else {
        printf("Hello from parent [PID - %d]\n", n);
    }
    
    return 0;
}
// fork returns PID different result for different thread
// For child thread it will return 0, for parent another integer
// (probably PID of child process)