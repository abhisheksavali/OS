

#include <stdio.h>

int main()
{
    int n, tq;
    int i, time = 0, remain, flag = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    float avg_tat = 0, avg_wt = 0;


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 2

int buffer[SIZE];
int in = 0;
int out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int item;

    for(item = 0; item < 3; item++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;

        printf("Produced : %d at buffer[%d]\n", item, in);

        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item, i;

    for(i = 0; i < 2; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];

        printf("Consumed : %d from buffer[%d]\n", item, out);

        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    pthread_mutex_destroy(&mutex);

    return 0;
}
    printf("Enter number of processes: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++)
    {
        printf("\nArrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    int gantt[100], gantt_time[100];
    int k = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(time = 0, i = 0; remain != 0; )
    {
        if(rt[i] <= tq && rt[i] > 0)
        {

            gantt[k] = i;
            gantt_time[k] = time;
            k++;

            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0)
        {

            gantt[k] = i;
            gantt_time[k] = time;
            k++;

            rt[i] -= tq;
            time += tq;
        }

        if(rt[i] == 0 && flag == 1)
        {
            remain--;

            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            avg_tat += tat[i];
            avg_wt += wt[i];

            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                   i + 1,
                   at[i],
                   bt[i],
                   ct[i],
                   tat[i],
                   wt[i]);

            flag = 0;
        }

        if(i == n - 1)
        {
            i = 0;
        }
        else if(at[i + 1] <= time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    gantt_time[k] = time;

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);


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
