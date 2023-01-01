#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv){
 
 	long double ln = 0.0, part_sol, x;
    float time;
    int i, steps, threads;

    x = atof(argv[1]);
    steps = atoi(argv[2]) * 10000;
    threads = atoi(argv[3]);

    time = omp_get_wtime();
    //Number of threads to use for parallel region
    omp_set_num_threads(threads);
	#pragma omp parallel for shared(part_sol) reduction(+: ln)
    for (i = 1; i <= steps; i++)
    {
        part_sol = pow(-1.0, (i+1)) * (pow((x-1),i) / i);
        ln += part_sol;
    }

    printf("Natural log value: %1.10Lf\n", ln);
    printf("Time taken = %f\n", omp_get_wtime() - time);
 
 	return 0;
}
