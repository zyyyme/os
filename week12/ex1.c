#include <stdio.h>

int main() {
    FILE* rand;

    char string[20];

    rand = fopen("/dev/random", "r");
    fgets(string, 20, rand);

    printf("%s", string);

    return 0;
}