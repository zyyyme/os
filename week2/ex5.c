#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);

    printf("Triangle: \n");
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n-i; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2*i+1; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("Right triangle: \n");
    for (int i = 0; i < 2*n-1; i ++) {

        for (int j = 0; j < i+1; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("Rectangle: \n");
    for (int i = 0; i < 2*n-1; i ++) {

        for (int j = 0; j < n; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("Rotated triangle: \n");
    for (int i = 0; i < 2*n-1; i ++) {

        if (i >= n){
            for (int j = 2*(n -1) - i; j >= 0; j--) {
                printf("*");
            }
        } else {
            for (int j = 0; j < i+1; j++) {
                printf("*");
            }
        }

        printf("\n");
    }
}