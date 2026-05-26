

#include <stdio.h>

int main()
{
    int nb, np, i, j;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[20], b1[20], b2[20], b3[20];

    printf("Enter size of each memory block:\n");

    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);

        b1[i] = block[i];
        b2[i] = block[i];
        b3[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[20];

    printf("Enter size of each process:\n");

    for(i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
    }

    int ff[20], bf[20], wf[20];


    for(i = 0; i < np; i++)
    {
        ff[i] = -1;

        for(j = 0; j < nb; j++)
        {
            if(b1[j] >= process[i])
            {
                ff[i] = j;
                b1[j] -= process[i];
                break;
            }
        }
    }


    for(i = 0; i < np; i++)
    {
        int best = -1;

        for(j = 0; j < nb; j++)
        {
            if(b2[j] >= process[i])
            {
                if(best == -1 || b2[j] < b2[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            bf[i] = best;
            b2[best] -= process[i];
        }
        else
        {
            bf[i] = -1;
        }
    }


    for(i = 0; i < np; i++)
    {
        int worst = -1;

        for(j = 0; j < nb; j++)
        {
            if(b3[j] >= process[i])
            {
                if(worst == -1 || b3[j] > b3[worst])
                {
                    worst = j;
                }
            }
        }

        if(worst != -1)
        {
            wf[i] = worst;
            b3[worst] -= process[i];
        }
        else
        {
            wf[i] = -1;
        }
    }


    printf("\n========== FIRST FIT ==========\n");

    printf("Process\tSize\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        if(ff[i] != -1)
        {
            printf("P%d\t%d\t%d\n", i + 1, process[i], ff[i] + 1);
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
        }
    }


    printf("\n========== BEST FIT ==========\n");

    printf("Process\tSize\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        if(bf[i] != -1)
        {
            printf("P%d\t%d\t%d\n", i + 1, process[i], bf[i] + 1);
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
        }
    }


    printf("\n========== WORST FIT ==========\n");

    printf("Process\tSize\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        if(wf[i] != -1)
        {
            printf("P%d\t%d\t%d\n", i + 1, process[i], wf[i] + 1);
        }
        else
        {
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
        }
    }

    return 0;
}

