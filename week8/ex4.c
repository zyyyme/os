#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage mem_usage;
    int size = 1024*1024*10;

    for (int i = 0; i < 10; i ++) {
        void *ptr = malloc(size);

        memset(ptr, 0, size);

        getrusage(RUSAGE_SELF, &mem_usage);
        printf("Usage: %ld\n", mem_usage.ru_maxrss);

        sleep(1);
    }


    return 0;
}

/*
*
* After executing our program and checking with vmstat 1,
* We can see that free space is decreasing, si and so are equal to zero
* all the time. When we will run out of free space,
* system will use swap, and si and so will not be equal to 0.
*
*/


/*
*
* After executing our program with top -d 1 we will see that 
* virtual memory for our process will increase each second.
*
*/