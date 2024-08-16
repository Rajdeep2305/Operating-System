// First Come First Serve Scheduling

#include <stdio.h>
int main()
{
    int p;
    printf("Enter the total process:");
    scanf("%d", &p);
    int BT[p], AT[p], CT[p], TAT[p], RT[p], WT[p];
    printf("Enter the Burst Time and Arrival Time for each and every process.\n");
    for (int i = 0; i < p; i++)
    {
        printf("For process p%d\n", i);
        printf("Enter the Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Enter the Arrival time: ");
        scanf("%d", &AT[i]);
    }
    // CT = Completion Time
    // TAT = Tern Around Time
    // RT = Response Time
    // WT = Waiting Time
    for (int i = 0; i < p; i++)
    {
        if (i != 0)
        {
            CT[i] = BT[i] + CT[i - 1];
        }
        else
        {
            CT[i] = BT[i];
        }
        TAT[i] = CT[i] - AT[i];
        if (i != 0)
        {
            RT[i] = CT[i - 1];
        }
        else
        {
            RT[i] = 0;
        }
        WT[i] = TAT[i] - BT[i];
    }
    for (int i = 0; i < p; i++)
    {
        printf("For process%d Completion Time(CT): %d, Tern Around Time(TAT): %d, Response Time(RT): %d, Waiting Time(WT): %d \n", i, CT[i], TAT[i], RT[i], WT[i]);
    }
    return 0;
}