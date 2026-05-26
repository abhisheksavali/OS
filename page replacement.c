

#include <stdio.h>

int main()
{
    int pages[50];
    int fifo[10], lru[10], opt[10];
    int n, f, i, j, k;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);



    for(i = 0; i < f; i++)
    {
        fifo[i] = -1;
    }

    int fifo_faults = 0;
    int index = 0;

    printf("\n========== FIFO ==========\n");
    printf("Ref\t");

    for(i = 0; i < f; i++)
    {
        printf("F%d\t", i + 1);
    }

    printf("Status\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(fifo[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            fifo[index] = pages[i];
            index = (index + 1) % f;
            fifo_faults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(fifo[j] == -1)
                printf("-\t");
            else
                printf("%d\t", fifo[j]);
        }

        if(found)
            printf("Hit\n");
        else
            printf("Fault\n");
    }

    printf("FIFO Page Faults = %d\n", fifo_faults);


    for(i = 0; i < f; i++)
    {
        lru[i] = -1;
    }

    int lru_faults = 0;

    printf("\n========== LRU ==========\n");
    printf("Ref\t");

    for(i = 0; i < f; i++)
    {
        printf("F%d\t", i + 1);
    }

    printf("Status\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(lru[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int least = 0, min = 999;

            for(j = 0; j < f; j++)
            {
                int flag = 0;

                for(k = i - 1; k >= 0; k--)
                {
                    if(lru[j] == pages[k])
                    {
                        flag = 1;

                        if(k < min)
                        {
                            min = k;
                            least = j;
                        }

                        break;
                    }
                }

                if(flag == 0)
                {
                    least = j;
                    break;
                }
            }

            lru[least] = pages[i];
            lru_faults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(lru[j] == -1)
                printf("-\t");
            else
                printf("%d\t", lru[j]);
        }

        if(found)
            printf("Hit\n");
        else
            printf("Fault\n");
    }

    printf("LRU Page Faults = %d\n", lru_faults);



    for(i = 0; i < f; i++)
    {
        opt[i] = -1;
    }

    int opt_faults = 0;

    printf("\n========== OPTIMAL ==========\n");
    printf("Ref\t");

    for(i = 0; i < f; i++)
    {
        printf("F%d\t", i + 1);
    }

    printf("Status\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(opt[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int replace = -1;
            int farthest = -1;

            for(j = 0; j < f; j++)
            {
                int next = -1;

                for(k = i + 1; k < n; k++)
                {
                    if(opt[j] == pages[k])
                    {
                        next = k;
                        break;
                    }
                }

                if(next == -1)
                {
                    replace = j;
                    break;
                }

                if(next > farthest)
                {
                    farthest = next;
                    replace = j;
                }
            }

            opt[replace] = pages[i];
            opt_faults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(opt[j] == -1)
                printf("-\t");
            else
                printf("%d\t", opt[j]);
        }

        if(found)
            printf("Hit\n");
        else
            printf("Fault\n");
    }

    printf("Optimal Page Faults = %d\n", opt_faults);

    return 0;
}
