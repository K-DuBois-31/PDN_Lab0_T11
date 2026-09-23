#!/bin/bash

set -e

mkdir -p results

# Benchmark recursive dispatch at different thresholds.
for threshold in 16 32 64 128
do
    echo "Testing recursive dispatch with threshold $threshold"

    make clean
    make FILE_TST=test_var013.c CFLAGS="-O2 -DTHRESHOLD=$threshold"

    ./run_verifier.x
    ./run_timer.x 16 1024 16 1 "results/recursive_dispatch_${threshold}.csv"
done

echo "Objective D benchmarks complete."
python plot_objective_d.py