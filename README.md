# Parallel programming in C notes

This is the code repository for the programming exam part of parallel computing, of the 9th semester in the ECE department of University of Patras. 

The code for pi's approximation is a refactored and extended version of [this](https://github.com/Defcon27/Parallel-Computing-in-C-using-OpenMP/blob/master/pi_estimation_integration.c) repository in order to be able to use different steps, threads and with some minor changes to variable types and optimizations, whereas the e and ln(x) approximations were original code (although Defcon27's repository has excelent solutions to those as well).

## Compilation
Remember to <b>link</b> used libraries when compiling:
```sh
gcc <optimizations> <file.c> -o <alias> -lgomp -lm (For openmp and math libraries)
```
All .c files compilation options listed below:
```sh
gcc -O2 pi_integral_openmp.c -o pi_openmp -lgomp -lm 
```
```sh
gcc -O2 euler_openmp.c -o euler -lgomp -lm 
```
```sh
gcc -O2 ln_openmp.c -o ln_openmp -lgomp -lm 
```

## Execution
Code is written with argv in mind for the required <b>steps</b> and the <b>threads</b> to be used,
therefore execute the output with:

```sh
./<file> <steps> <threads_number>
```
with the exception of the natural logarithm approximation,
in which we need to specify a value for <b>x between [0,2]</b>

```sh
./ln_openmp <x> <steps> <threads_number>
```