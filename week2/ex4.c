#include <stdio.h>

#define swap(a,b) int t=a; a=b; b=t

int main() {
    int a,b;
    scanf("%i %i", &a, &b);

    swap(a,b);

    printf("a: %i, b: %i", a,b);

    return 0;
}   