#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include <unistd.h>

#define N 1E8
#define d 1E-8

int main (int argc, char **argv){

    double pi=0.0, x, y;
    int rank, size, error, i, start;
    int result=0, sum=0;
    FILE *fp;

    error=MPI_Init (&argc, &argv);
    
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    
    //Synchronize all processes and get the begin time
    MPI_Barrier(MPI_COMM_WORLD);
    start = MPI_Wtime();
    
    srand((int)time(0));

    //Parallelized part for partial results from different processes    
    for (i=rank; i<N; i+=size)
    {
        x=rand()/(RAND_MAX+1.0);
        y=rand()/(RAND_MAX+1.0);
        if(x*x+y*y<1.0)
            result++;
    }
    
    //Sum up all results
    MPI_Reduce(&result, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    //Synchronize all processes and get the end time
    MPI_Barrier(MPI_COMM_WORLD);
    
    //Caculate and write PI values from each itteration to a file
    fp = fopen("./pi_aprox/pi_sums.txt", "a");
    if (fp == NULL){
        printf("File cannot be openned, exiting...");
        exit(1);
    }
    if (rank==0){
        pi=4*d*sum;
        printf("np=%2d;    Time=%fs;    PI=%0.8f\n", size, MPI_Wtime() - start, pi);
        fprintf(fp, "%0.8f\n", pi);
    }
    fclose(fp);
    
    error=MPI_Finalize();

    return 0;
}