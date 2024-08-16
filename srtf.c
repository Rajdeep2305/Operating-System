// Shortest Remaining Time First 
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int main(){
    int p;
    printf("Enter the total process:");
    scanf("%d", &p);
    int BT[p], AT[p], CT[p], TAT[p], WT[p];
    int process[p], ATCopy[p];
    printf("Enter the Burst Time and Arrival Time for each and every process.\n");
    for (int i = 0; i < p; i++)
    {
        process[i] = i + 1;
    }
    for (int i = 0; i < p; i++)
    {
        printf("For process p%d\n", process[i]);
        printf("Enter the Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Enter the Arrival time: ");
        scanf("%d", &AT[i]);
    }
    printf("\n");
    // CT = Completion Time
    // TAT = Tern Around Time
    // RT = Response Time = First CPU allocation time - Arrival time(AT)
    // WT = Waiting Time

    int totalTime = 0;                          // find out the total time for finish the job
    for(int i = 0; i< p;i++){
        totalTime = totalTime + BT[i];
    }
    printf("Total time = %d\n",totalTime);      //print this total time

    int readyQueue[p];                          // Create a ready queue
    int dummyBT[p];                             // Create a dummy BT array to store remaining burst times

    for (int i = 0; i < p; i++) {
        dummyBT[i] = BT[i];                     // Initialize the dummyBT with the original burst times
    }

    int front = 0, back = 0;                    // Front and back of the ready queue

    for (int m = 0; m < totalTime; m++) {       // Loop through each time unit
        printf("Time %d of", m);

        for (int j = 0; j < p; j++) {           // Check for arriving processes and add them to the ready queue
            if (m == AT[j]) {
                readyQueue[back] = j;           // Store the process index in the ready queue
                back++;
            }
        }

        for (int i = 0; i < back - 1; i++) {    // Sort the ready queue by remaining burst time
            int bool = 0;
            for (int j = 0; j < back - i - 1; j++) {
                if (dummyBT[readyQueue[j]] > dummyBT[readyQueue[j + 1]]) {
                    swap(&readyQueue[j], &readyQueue[j + 1]);
                    bool = 1;
                }
            }
            if (bool == 0) {
                break;
            }
        }
        dummyBT[readyQueue[front]]--;           // Execute the process at the front of the ready queue

        if (front <= back) {                     // Print the currently executing process
            printf(" process P%d\t", process[readyQueue[front]]);
        }

        if (dummyBT[readyQueue[front]] == 0) {  // If the process is completed, remove it from the ready queue
            CT[readyQueue[front]] = m + 1;      // Completion time
            front++;
        }

        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < p; i++){
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];\
    }
    for (int i = 0; i < p; i++)
    {
        printf("process%d => Arrival Time: %d, Burst Time: %d, Completion Time(CT): %d, Tern Around Time(TAT): %d, Waiting Time(WT): %d \n", process[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
}

// input: 1 2 5 1 1 4 6 0 3 2
// for process 5