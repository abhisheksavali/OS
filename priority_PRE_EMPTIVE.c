#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n];

    float avg_tat = 0, avg_wt = 0;

    printf("\nEnter Arrival Time, Burst Time and Priority\n");

    for(i = 0; i < n; i++)
    {
        printf("Process P%d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed != n)
    {
        int highest = -1;
        int min_pr = 999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min_pr)
            {
                min_pr = pr[i];
                highest = i;
            }
        }

        if(highest == -1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;

            ct[highest] = time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];

            avg_tat += tat[highest];
            avg_wt += wt[highest];
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
