g++ -O2 ./pi_aprox/pi_integral_openmp.c -o ./bin/pi_openmp -lgomp -lm -fopenmp
g++ -O2 ./euler_aprox/euler_openmp.c -o ./bin/euler -lgomp -lm -fopenmp
g++ -O2 ./ln_aprox/ln_openmp.c -o ./bin/ln_openmp -lgomp -lm -fopenmp
