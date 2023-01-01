# Parallel programming in C notes

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