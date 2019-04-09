#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #define RANDOM_POINTS 1000000

//  linear
// const double center [2] = {0, 0};


int main (int argc, char ** argv) {
    if (argc != 2){
        fprintf(stderr, "usage: ./pi_serial <total_points>\n");
        exit(1);
    }

    unsigned int rand_state = rand();
    unsigned long long points_within_circle = 0;
    const unsigned long long random_points = atoi(argv[1]);

    
    time_t start = time(NULL);

    srand((unsigned)time(NULL));

    // generate points
    for (int i = 0; i < random_points; ++i) {
        // printf("%d\n", i);
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        // printf("%lf  %lf\n", points[i][0], points[i][1]);
        
        if (x * x + y * y < 1) ++points_within_circle;

    }
    // printf("%u\n", points_within_circle);
    double pi = (double)points_within_circle / (double)(random_points) * 4;
    printf("pi ~= %lf\n", pi);
    printf("Time: %d sec\n", (unsigned int)(time(NULL) - start));


    return 0;
}