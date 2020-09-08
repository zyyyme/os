#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 5; i ++) {
        fork();
        sleep(5);
    }
 
    return 0;
}

// Each time we call fork(), the amount of processes doubles. 
// We did fork() 5 times, hence we have 2^5 = 32 processes.