

#include <stdio.h>

int main()
{
    int n, i, time = 0, count = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int smallest;
    float avg_tat = 0, avg_wt = 0;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++)
    {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // Remaining time
    }

    // SRTF Scheduling
    while(count != n)
    {
        smallest = -1;

        // Find process with minimum remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(smallest == -1 || rt[i] < rt[smallest])
                {
                    smallest = i;
                }
            }
        }

        // If no process is ready
        if(smallest == -1)
        {
            time++;
        }
        else
        {
            rt[smallest]--;
            time++;

            // Process completed
            if(rt[smallest] == 0)
            {
                count++;

                ct[smallest] = time;
                tat[smallest] = ct[smallest] - at[smallest];
                wt[smallest] = tat[smallest] - bt[smallest];

                avg_tat += tat[smallest];
                avg_wt += wt[smallest];
            }
        }
    }

    // Display Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);

    return 0;
}
