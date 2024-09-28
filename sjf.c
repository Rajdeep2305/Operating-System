//Shortest Job First
#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp; 
}

int main()
{
    int p;
    printf("Enter the total process:");
    scanf("%d", &p);
    int BT[p], AT[p], CT[p], TAT[p], RT[p], WT[p];
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
    // CT = Completion Time
    // TAT = Tern Around Time
    // RT = Response Time
    // WT = Waiting Time
    
    for (int i = 0; i < p - 1; i++)
    {
        int bool = 0;
        for (int j = 0; j < p - i - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&process[j], &process[j+1]);
                bool = 1;
            }
        }
        if (bool == 0)
        {
            break;
        }
    }

    printf("\n");
    int totalTime = 0;
    for (int i = 0; i < p; i++)
    {
        printf("process%d => AT: %d\tBT: %d\n", process[i], AT[i], BT[i]);
    }
    printf("\n");
    int count = 0;
    while (count < p)
    {
        int primaryArray[BT[count]];
        int k = 0;
        totalTime = totalTime + BT[count];
        for (int i = count + 1; i < p; i++)
        {
            if (AT[i] <= totalTime)
            {
                primaryArray[k] = BT[i];
                k++;
            }
            else
            {
                break;
            }
        }
        if (k > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                int bool = 0;
                for (int j = 0; j < k - i - 1; j++)
                {
                    if (primaryArray[j] > primaryArray[j + 1])
                    {
                        swap(&primaryArray[j], &primaryArray[j + 1]);
                        bool = 1;
                    }
                }
                if (bool == 0)
                {
                    break;
                }
            }
        }
        int c = 0;
        while (primaryArray[0] != BT[c])
        {
            if (c < p)
            {
                c++;
            }
            else
            {
                break;
            }
        }
        int a = BT[count + 1];
        BT[count + 1] = primaryArray[0];
        int xyz = AT[count + 1];
        AT[count + 1] = AT[c];
        AT[c] = xyz;
        int abc = process[count + 1];
        process[count + 1] = process[c];
        process[c] = abc;
        if (k > 1)
        {
            for (int i = count + 2; i < p; i++)
            {
                if (primaryArray[0] == BT[i])
                {
                    BT[i] = a;
                }
            }
        }
        count++;
    }
    for (int i = 0; i < p; i++)
    {
        printf("process%d => AT: %d\tBT: %d\n", process[i], AT[i], BT[i]);
    }
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
        printf("For process%d: Completion Time(CT): %d, Tern Around Time(TAT): %d, Response Time(RT): %d, Waiting Time(WT): %d \n", process[i], CT[i], TAT[i], RT[i], WT[i]);
    }
    printf("commited");
    return 0;
}

// input :: 6 2 2 5 8 1 3 0 4 4
//  for process 5