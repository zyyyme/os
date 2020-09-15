#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int container[1];
static int start;
static int count;

static int producer_ready;
static int consumer_ready;

void consumer_sleep(){
    consumer_ready = 0;
}

void consumer_wakeup(){
    consumer_ready = 1;
}

void producer_sleep(){
    producer_ready = 0;
}

void producer_wakeup(){
    producer_ready = 1;
}

void *producer_main(void *vararg){
    while (1) {
        if (container == 1){
            producer_sleep();
        }
        while (1){
            if (producer_ready == 1){
                break;
            }
        };
        count++;
        container[start] = count;
        start++;
        printf("Producer added %d, top is %d\n", count, start);
        consumer_wakeup();
    }
    pthread_exit(0);
}

void *consumer_main(void *varang){
    while (1){
        if (start == 0){
            consumer_sleep();
        }
        while (1){
            if (consumer_ready == 1){
                break;
            }
        };
        printf("Comsumer removed %d, top now is %d\n", container[start - 1], start - 1);
        container[start - 1] = 0;
        start = start - 1;
        producer_wakeup();
    }
    pthread_exit(0);
}

int main() {
    pthread_t th1, th2;
    start = 0;
    producer_wakeup();
    consumer_wakeup();
    pthread_create(&th1, NULL, producer_main, NULL);
    pthread_create(&th2, NULL, consumer_main, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}