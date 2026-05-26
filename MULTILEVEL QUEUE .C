

#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int time = 0, count = 0;
    float avg_tat = 0, avg_wt = 0;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++)
    {
        printf("\nArrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Queue Priority for P%d (1-System / 2-User): ", i + 1);
        scanf("%d", &pr[i]);
    }

    int gantt[50], gantt_time[50];
    int k = 0;


    while(count < n)
    {
        int process = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0 && pr[i] == 1)
            {
                process = i;
                break;
            }
        }

        if(process == -1)
        {
            for(i = 0; i < n; i++)
            {
                if(at[i] <= time && completed[i] == 0 && pr[i] == 2)
                {
                    process = i;
                    break;
                }
            }
        }

        if(process == -1)
        {
            time++;
        }
        else
        {
            gantt[k] = process;
            gantt_time[k] = time;
            k++;

            time += bt[process];

            ct[process] = time;
            tat[process] = ct[process] - at[process];
            wt[process] = tat[process] - bt[process];

            avg_tat += tat[process];
            avg_wt += wt[process];

            completed[process] = 1;
            count++;
        }
    }

    gantt_time[k] = time;


    printf("\nPID\tAT\tBT\tQueue\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               pr[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);

    printf("\n\nGantt Chart:\n");

    for(i = 0; i < k; i++)
    {
        printf("| P%d ", gantt[i] + 1);
    }

    printf("|\n");

    for(i = 0; i <= k; i++)
    {
        printf("%d\t", gantt_time[i]);
    }

    return 0;
}
