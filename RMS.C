

#include <stdio.h>

int main()
{
    int n, i, j, time, hyper = 1;
    int c[10], p[10], rem[10];
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input Execution Time and Period
    for(i = 0; i < n; i++)
    {
        printf("\nTask %d\n", i + 1);

        printf("Execution time (C%d): ", i + 1);
        scanf("%d", &c[i]);

        printf("Period (P%d): ", i + 1);
        scanf("%d", &p[i]);

        rem[i] = 0;
    }

    // Hyperperiod Calculation
    for(i = 0; i < n; i++)
    {
        hyper *= p[i];
    }

    printf("\n--- RMS Scheduling ---\n");

    // RMS Scheduling
    for(time = 0; time < 20; time++)
    {
        // Release tasks at their periods
        for(i = 0; i < n; i++)
        {
            if(time % p[i] == 0)
            {
                rem[i] = c[i];
            }
        }

        int highest = -1;

        // Select highest priority task
        // Smaller period => Higher priority
        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                if(highest == -1 || p[i] < p[highest])
                {
                    highest = i;
                }
            }
        }

        // Execute selected task
        if(highest != -1)
        {
            printf("Time %d : Task %d\n", time, highest + 1);
            rem[highest]--;
        }
        else
        {
            printf("Time %d : Idle\n", time);
        }
    }

    return 0;
}
