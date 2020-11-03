#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    int input = fileno(stdin);
    int output;

    if (argc == 2) {
        output = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
    } else if (argc == 3 && strcmp(argv[1], "-a") == 0) {
        output = open(argv[2], O_RDWR | O_APPEND | O_CREAT, 0777);
    } else {
        return 0;
    }

    char byte;
    int status = read(input, &byte, 1);

    while (status != 0) {
        write(output, &byte, 1);
        status = read(input, &byte, 1);
    }

    close(input);
    close(output);

    return 0;
}