#include <stdio.h>

int main() {
    int n, choice;
    scanf("%i", &n);

    printf("1 - Triangle, 2 - Right triangle, 3 - Rectangle, 4 - Rotated triangle: ");
    scanf("%i", &choice);

    switch (choice) {
    case 1:

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
        break;

    case 2:
        printf("Right triangle: \n");
        for (int i = 0; i < 2*n-1; i ++) {

            for (int j = 0; j < i+1; j++) {
                printf("*");
            }

            printf("\n");
        }
        break;

    case 3:
        printf("Rectangle: \n");
        for (int i = 0; i < 2*n-1; i ++) {

            for (int j = 0; j < n; j++) {
                printf("*");
            }

            printf("\n");
        }
        break;

    case 4:
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
        break;

    }
}