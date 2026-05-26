

#include <stdio.h>

#define N 5

int main()
{
    int i;
    printf("ABHISHEK SAVALI ---1BM24CS013\n");

    for(i = 0; i < N; i++)
    {
        printf("Philosopher %d is thinking\n", i);
    }

    printf("\n");


    for(i = 0; i < N; i++)
    {
        printf("Philosopher %d picked up left fork %d\n", i, i);
    }

    printf("\n");

    for(i = 0; i < N; i++)
    {
        printf("Philosopher %d picked up right fork %d\n", i, (i + 1) % N);
    }

    printf("\n");


    for(i = 0; i < N; i++)
    {
        printf("Philosopher %d is eating\n", i);
    }

    printf("\n");

    for(i = 0; i < N; i++)
    {
        printf("Philosopher %d released forks\n", i);
    }

    return 0;
}
