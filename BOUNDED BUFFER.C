

#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 2;
int x = 0;


int wait(int s)
{
    return (--s);
}


int signal(int s)
{
    return (++s);
}


void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);

    printf("Produced : %d at buffer[%d]\n", x, x % 2);

    x++;

    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);

    x--;

    printf("Consumed : %d from buffer[%d]\n", x, x % 2);

    mutex = signal(mutex);
}

int main()
{
    printf("ABHISHEK SAVALI ---1BM24CS013\n");
    producer();
    consumer();

    producer();
    consumer();

    producer();

    return 0;
}
