#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char string[MAX_LENGTH];
    printf("Enter something: \n");
    fgets(string, MAX_LENGTH, stdin);
    
    for (int i = strlen(string); i>=0; i-- ) {
        printf("%c", string[i]);
    }

    return 0;
}