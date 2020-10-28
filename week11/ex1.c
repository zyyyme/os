#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <zconf.h>

int main() {

    int file = open("ex1.txt", O_RDWR);

    char example_string[] = "This is a nice day";

    int length = sizeof(example_string) - 1;

    char *source;

    ftruncate(file, length);

    source = mmap(NULL, length, PROT_WRITE, MAP_SHARED, file, 0);
    strcpy(source, example_string);

    return 0;
}