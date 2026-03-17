#include <stdio.h>

int main()
{
    int n, i, time = 0, remain, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    float avg_tat = 0, avg_wt = 0;
    printf("\nEnter Arrival Time and Burst Time\n");

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avg_tat += tat[i];
                    avg_wt += wt[i];

                    remain--;
                }
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
