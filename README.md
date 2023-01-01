# Parallel programming in C:
## Author: Anagnostopoulos Angelos

## Introduction

This is the code repository for the programming exam part of parallel computing, of the 9th semester in the ECE department of University of Patras. 

The code for pi's approximation with OpenMP is a refactored and extended version of [this](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/blob/master/pi_estimation_integration.c) repository in order to be able to use different steps, threads and with some minor changes to variable types and optimizations, whereas the e and ln(x) approximations were original code (although Defcon27's repository has excelent solutions to those as well).

As for the MPI implementation for approximating pi, it is an extended and improved version of [this](https://kiwenlau.blogspot.com/2015/02/calculate-pi-using-mpi-with-three.html) blog article on different methods of calculating pi with parallel alogirhtms.

### Compilation
All files are compiled from the <b>root directory</b> of the project and their binaries are stored in a separate <b>/bin</b> directory.

A compilation script was created for user ease with the commands specified bellow. To run it, simply execute:
```sh
./compile.sh
```

If you shall compile the files manually, remember to <b>link</b> used libraries (openmp and math):
```sh
gcc <optimizations> <file.c> -o <alias> -lgomp -lm
```
All .c files compilation options listed below:
```sh
gcc -O2 ./pi_aprox/pi_integral_openmp.c -o ./bin/pi_openmp -lgomp -lm 
gcc -O2 ./euler_aprox/euler_openmp.c -o ./bin/euler -lgomp -lm 
gcc -O2 ./ln_aprox/ln_openmp.c -o ./bin/ln_openmp -lgomp -lm 
```

<i>For the MPI calculation of pi, the .sh script takes care of compilation for us.</i>

### Execution
Code is written with argv in mind for the required <b>steps</b> and the <b>threads</b> to be used. Steps are <b>multiplied by 10.000</b> for user ease, therefore execute the output with:

```sh
./bin/<binary> <steps> <threads_number>
```
with the exception of the natural logarithm approximation,
in which we need to specify a value for <b>x between [0,2]</b>

```sh
./bin/ln_openmp <x> <steps> <threads_number>
```
For the MPI implementation of the pi approximation, the method of <b>Monte Carlo</b> was chosen. Since this method does not yeild accurate results even for very large numbers of itterations, the approach here is to run the C program multiple (10) times and write partial resuts into a file. Then, a small python script is used to calculate the median value for better accuracy. For this, a shell script was used to automate the above process.

To execute the MPI version of the pi approximation, simply run:
```sh
./run.sh
```