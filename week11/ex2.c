#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>

int main() {
    char* buffer = malloc(256);
    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);

    return 0;
}