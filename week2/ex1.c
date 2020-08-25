#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("int: max: %d; size: %lu\n", a, sizeof(a));
    printf("float: max: %f; size: %lu\n", b, sizeof(b));
    printf("double: max: %lf; size: %lu\n", c, sizeof(c));

    return 0;
}