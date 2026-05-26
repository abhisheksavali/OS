

#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m];
    int finish[n], work[m];
    int safeSeq[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for(i = 0; i < n; i++)
    {
        finish[i] = 0;

        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(alloc[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            finish[i] = 1;
        }
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        break;
                    }
                }


                if(j == m)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            break;
        }
    }

    if(deadlock == 1)
    {
        printf("\nDeadlock Detected!\n");
        printf("Processes in Deadlock: ");

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }
    }
    else
    {
        printf("\nNo Deadlock Detected\n");

        printf("Safe Sequence: ");

        for(i = 0; i < count; i++)
        {
            printf("P%d", safeSeq[i]);

            if(i != count - 1)
            {
                printf(" -> ");
            }
        }
    }

    return 0;
}
