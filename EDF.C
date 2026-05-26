

#include <stdio.h>

int main()
{
    int n, i, time, total_time;
    int c[10], d[10], p[10];
    int rem[10], deadline[10];
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input Task Details
    for(i = 0; i < n; i++)
    {
        printf("\nTask %d\n", i + 1);

        printf("Execution Time (C%d): ", i + 1);
        scanf("%d", &c[i]);

        printf("Deadline (D%d): ", i + 1);
        scanf("%d", &d[i]);

        printf("Time Period (P%d): ", i + 1);
        scanf("%d", &p[i]);

        rem[i] = 0;
        deadline[i] = d[i];
    }

    printf("\nEnter Total Scheduling Time: ");
    scanf("%d", &total_time);

    printf("\n--- EDF Scheduling (Periodic Tasks) ---\n");

    // EDF Scheduling
    for(time = 0; time < total_time; time++)
    {
        // Release tasks periodically
        for(i = 0; i < n; i++)
        {
            if(time % p[i] == 0)
            {
                rem[i] = c[i];
                deadline[i] = time + d[i];
            }
        }

        int earliest = -1;

        // Find task with earliest deadline
        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                if(earliest == -1 || deadline[i] < deadline[earliest])
                {
                    earliest = i;
                }
            }
        }

        // Execute selected task
        if(earliest != -1)
        {
            printf("Time %d : Task %d\n", time, earliest + 1);
            rem[earliest]--;
        }
        else
        {
            printf("Time %d : Idle\n", time);
        }
    }

    return 0;
}
