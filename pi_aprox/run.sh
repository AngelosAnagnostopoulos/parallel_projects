#!/bin/sh

mpicc -o ./bin/pi_mpi ./pi_aprox/pi_montecarlo_MPI.c

for i in $(seq 1 10); do
    mpirun -np $i ./bin/pi_mpi
done

python3 ./pi_aprox/sumfile.py

