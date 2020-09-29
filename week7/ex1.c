#include <stdio.h>
#include <pthread.h>


void *print(void* a) {
    int* ptr = (int*) a;

    int id = *ptr;

    printf("Thread number %d \n", id);

    pthread_exit(0);
} 


int main() {
    pthread_t tid[5];

    for (int i = 0; i < 5; i ++) {
        pthread_create(&tid[i], NULL, print, &i);

        printf("Created thread %d \n", i); 
        pthread_join(tid[i], NULL);
        printf("Exited thread %d \n", i);
    }


    return 0;
}