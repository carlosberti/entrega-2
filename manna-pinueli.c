#include <stdio.h>
#include <pthread.h>

#define NUM_OF_THREADS 4
#define ITERATIONS 10000000

long sum = 0, request = 0, respond = 0, iterations_per_thread = ITERATIONS / NUM_OF_THREADS;

void *client(void *i)
{
    for (long j = 0; j < iterations_per_thread; j++)
    {
        while (respond != (long)i)
        {
            request = (long)i;
        }

        sum++;
        respond = 0;
    }

    pthread_exit(NULL);
}

void *server()
{
    while (1)
    {
        while (request == 0)
        {
        }

        respond = request;

        while (respond != 0)
        {
        }
        request = 0;
    }

    pthread_exit(NULL);
}

int main()
{
    long i;
    pthread_t client_threads[NUM_OF_THREADS], server_thread;

    printf("iterations_per_thread: %ld\n", iterations_per_thread);

    pthread_create(&server_thread, NULL, server, NULL);

    clock_t begin = clock();
    for (i = 1; i <= NUM_OF_THREADS; i++)
    {
        pthread_create(&client_threads[i - 1], NULL, client, (void *)i);
    }

    for (i = 0; i < NUM_OF_THREADS; i++)
    {
        pthread_join(client_threads[i], NULL);
    }
    clock_t end = clock();

    printf("soma: %ld\n", sum);
    printf("Elapsed: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

    return 0;
}