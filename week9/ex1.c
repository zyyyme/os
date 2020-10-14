#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>


int find(int * frames, int number, int frames_number) {
    for (int i = 0; i < frames_number; i ++) {
        if (frames[i] == number) {
            return i;
        }
    }

    return -1;
}


void move_right(unsigned char * age, int frames_number) {
    for (int i = 0; i < frames_number; i ++) {
        age[i] = age[i] << 1;
    }
}


void add(char * age, int number) {
    age[number] = age[number] + 128;
}


int find_min_age(unsigned char * age, int frames_number) {
    int min = 0;

    int max = 256;

    for (int i = 0; i < frames_number; i ++) {
        int tmp = (unsigned int) age[i];

        if (tmp < max) {
            max = tmp;
            min = i;
        }
    }

    return min;
}


void print_info(int * frames, unsigned char * age, int number, int frames_number, int hit, int miss) {
    
    printf("Frames: ");
    for (int i = 0; i < frames_number; i ++) {
        printf("%d ", frames[i]);
    }
    printf("\n");

    printf("Age: ");
    for (int i = 0; i < frames_number; i ++) {
        printf("%d ", (int) age[i]);
    }
    printf("\n");

    printf("Hit: %d; Miss: %d; Current number: %d\n", hit,miss,number);
}


int main() {
    printf("Number of page frames:");

    int frames_number;
    scanf("%d", &frames_number);

    char filename[] = "input.txt";
    FILE *input;

    input = fopen(filename, "r");

    int number;
    int *frames = (int*) calloc(frames_number, sizeof(int));

    for (int i = 0; i < frames_number; i ++) {
        frames[i] = -1;
    }

    unsigned char * age = (char*) calloc(frames_number, sizeof(char));

    int hit = 0;
    int miss = 0;

    fscanf(input, "%d", &number);

    while (!feof(input)) {
        move_right(age, frames_number);

        int free_space = find(frames, -1, frames_number);
        int index = find(frames, number, frames_number);
        printf("%d \n", index);
        if (index != -1) {
            hit ++;
            add(age,index);
        } else {
            if (free_space != -1) {
                miss ++;
                frames[free_space] = number;
                age[free_space] = 0;
                add(age, free_space);
            } else {
                miss ++;
                index = find_min_age(age, frames_number);

                frames[index] = number;
                age[index] = 0;
                add(age, index);
            }
        }
        print_info(frames, age, number, frames_number, hit, miss);

        fscanf(input, "%d", &number);
    }
    printf("Hit: %d; Miss: %d; Hit/miss: %f", hit, miss, (double)hit/miss);
    return 0;
}