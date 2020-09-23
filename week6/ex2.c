#include <stdio.h>

//modified bubblesort from week3
//sorting initial tasks by their arrival time 
void bubble_sort(int * AT, int * BT, int n) {
    // n - length of array arr

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (AT[j] > AT[j+1]){
                int t = AT[j];
                AT[j] = AT[j+1];
                AT[j+1] = t;

                t = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = t;
            }
        }
    }

}

int* get_available_jobs(int *AT, int*BT, int n, int i, int time){
    int available_jobs[n];
    
    for (int j = i; j < n; j++) {
        if (AT[j] < time) {
            available_jobs[j] = BT[j];
        }
    }

    bubble_sort(available_jobs, BT, n);
}


int main() {

    int n;

    scanf("%d", &n);

    int BT[n], AT[n], CT[n], TAT[n], WT[n];
    int time = 0;
    int total_wt=0, total_tat=0;
    double avg_tat, avg_wt;

    printf("Enter arrival time and burst time for each process: \n");

    for (int i = 0; i < n; i ++) {
        scanf("%d %d", &AT[i], &BT[i]);
    }

    WT[0] = 0;
    CT[0] = BT[0];
    TAT[0] = CT[0] + WT[0];
    printf("Process 1: CT = %d, TAT = %d, WT = %d\n", CT[0], TAT[0], WT[0]);
    for (int i = 1; i < n; i ++) {
        time += BT[i];
        CT[i] = CT[i-1] + BT[i];
        WT[i] = WT[i-1] + BT[i-1];
        TAT[i] = WT[i] + BT[i];
        total_tat += TAT[i];
        total_wt += WT[i];
        printf("Process %d: CT = %d, TAT = %d, WT = %d\n", i+1, CT[i], TAT[i], WT[i]);

    }

    avg_tat = (double) total_tat / (double) n;
    avg_wt = (double) total_wt / (double) n;

    printf("Average TAT = %f, Average WT = %f\n", avg_tat, avg_wt);


    return 0;
}