

#include<stdio.h>

int main()
{
    int n, i, j, time = 0, smallest;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int completed[20] = {0};
    float avg_tat = 0, avg_wt = 0;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int count = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    while(count < n)
    {
        smallest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(smallest == -1 || bt[i] < bt[smallest])
                {
                    smallest = i;
                }
            }
        }


        if(smallest == -1)
        {
            time++;
        }
        else
        {
            time += bt[smallest];
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            avg_tat += tat[smallest];
            avg_wt += wt[smallest];

            completed[smallest] = 1;
            count++;
        }
    }


    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);

    return 0;
}
