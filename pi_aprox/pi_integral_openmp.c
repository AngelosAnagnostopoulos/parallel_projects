#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv){

    long double x, y, dx, area = 0.0;
    float time;
    int i, steps, threads;
    
    steps = atoi(argv[1]) * 10000;
    threads = atoi(argv[2]);
    time = omp_get_wtime();
    dx = 1.0 / (long double)steps;
    x = dx;

    omp_set_num_threads(threads);
    #pragma omp parallel for schedule(dynamic) reduction(+: area) private(x, y, i, dx)
    for (i = 1; i < steps; i++)
    {
        dx = 1.0 / (long double)steps;
        x = (long double)i * dx;
        y = sqrt((long double)1.0 - (pow(x, 2)));
        area += dx * y;
    }
    printf("Constant π value: %1.10Lf\n", area * 4.0);
    printf("Time taken = %f\n",omp_get_wtime() - time);
}
