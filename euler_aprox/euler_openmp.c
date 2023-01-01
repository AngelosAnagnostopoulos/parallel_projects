#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv){
 
 	long double e = 1.0, fact = 1.0, part_sol; //To skip the first itteration for e = 0 and 0! = 1
    float time;
    int i, steps, threads;

    steps = atoi(argv[1]) * 10000;
    threads = atoi(argv[2]);

    time = omp_get_wtime();

    //Number of threads to use for parallel region
    omp_set_num_threads(threads);
	#pragma omp parallel shared(part_sol, e)
    { 
        #pragma omp for reduction(+: e)
            for (i = 1; i <= steps; i++)
            {
                fact *= i;
                part_sol = 1.0 / fact;
                e += part_sol;
            }
        
    }
    
    printf("Euler's constant value: %1.11Lf\n", e); //We are correct up to 11 decimal points. Anything less and C rounds up the number w/ a small error.
    printf("Time taken = %f\n", omp_get_wtime() - time);
 
 	return 0;
}
