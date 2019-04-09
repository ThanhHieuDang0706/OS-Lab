/* Michael Ballantyne Homework 3 CMPT 351 Spring 2012 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define thread_count 4
long incircle[thread_count] = {0};
long points_per_thread[thread_count] = {0};
long in = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner(void* k) {
    long incircle_thread = 0;
    int j = (int)k;
    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < points_per_thread[j]; i++) {

        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            incircle_thread++;
        }
    }
    
    // pthread_mutex_lock(&mutex);
    incircle[j] = incircle_thread;
    // pthread_mutex_unlock(&mutex);
}


int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: ./pi_multi-thread <total points>\n");
        exit(1);
    }

    long totalpoints = atol(argv[1]);
    // int thread_count = atoi(argv[2]);
    for (int i = 0; i < thread_count; ++i) {
        points_per_thread[i] = (totalpoints / thread_count);
    }
    points_per_thread[thread_count - 1] += (totalpoints % thread_count);


    time_t start = time(NULL);

    srand((unsigned)time(NULL));

    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int i;
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], &attr, runner, (void *)i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);

    for (int i = 0; i < thread_count; ++i){
        in += incircle[i];
    }

    printf("Pi: %f\n", (4. * (double)in) / ((double)totalpoints));
    printf("Time: %d sec\n", (unsigned int)(time(NULL) - start));
    pthread_exit(NULL);
    return 0;
}