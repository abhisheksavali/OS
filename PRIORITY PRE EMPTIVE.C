

#include <stdio.h>

int main()
{
    int n, i, time = 0, count = 0;
    int at[20], bt[20], rt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int highest;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time, Burst Time and Priority
    for(i = 0; i < n; i++)
    {
        printf("\nArrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Priority for P%d: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i]; // Remaining Time
    }

    int gantt[100], gantt_time[100];
    int k = 0;

    // Priority Preemptive Scheduling
    while(count < n)
    {
        highest = -1;

        // Find process with highest priority
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(highest == -1 || pr[i] < pr[highest])
                {
                    highest = i;
                }
            }
        }

        // If no process is ready
        if(highest == -1)
        {
            time++;
        }
        else
        {
            // Store process in Gantt chart
            if(k == 0 || gantt[k - 1] != highest)
            {
                gantt[k] = highest;
                gantt_time[k] = time;
                k++;
            }

            // Execute process for 1 unit
            rt[highest]--;
            time++;

            // Process completed
            if(rt[highest] == 0)
            {
                count++;

                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];

                avg_tat += tat[highest];
                avg_wt += wt[highest];
            }
        }
    }

    gantt_time[k] = time;

    // Display Output Table
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

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

    // Gantt Chart
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
