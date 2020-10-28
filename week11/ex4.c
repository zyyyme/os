#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/mman.h>


int main() {

    int input = open("ex1.txt", O_RDONLY);
    int output = open("ex1.memcpy.txt", O_RDWR | O_CREAT);

    struct stat filestat;
    fstat(input, &filestat);

    long size = filestat.st_size;
    ftruncate(output, size);

    void* input_source = mmap(NULL, size, PROT_READ, MAP_SHARED, input, 0);
    void* output_source = mmap(NULL, size, PROT_WRITE, MAP_SHARED, output, 0);
    memcpy(output_source, input_source, size);

    return 0;
}