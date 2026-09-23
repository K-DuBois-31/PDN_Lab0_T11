#!/bin/bash

set -euo pipefail

mkdir -p results plots assembly

# Initialize benchmark CSV.
echo "size,network_seconds,insertion_seconds" \
    > results/objective_e_benchmark.csv

for size in 4 8 16 32
do
    case "$size" in
        4)  variant=014 ;;
        8)  variant=015 ;;
        16) variant=016 ;;
        32) variant=017 ;;
    esac

    echo "Testing ${size}-element sorting network..."

    # Standard verifier.
    make clean
    make FILE_TST=test_var${variant}.c

    ./run_verifier.x |
        tee "results/network${size}_verifier.txt"

    if grep -q "FAIL" "results/network${size}_verifier.txt"; then
        echo "Verifier failed for network ${size}."
        exit 1
    fi

    # Compile network implementation.
    gcc -O2 \
        -DCOMPUTE_NAME=compute_tst \
        -c "test_var${variant}.c" \
        -o "network${size}.o"

    # Dedicated correctness test.
    gcc -O2 \
        "test_network${size}.c" \
        "network${size}.o" \
        -o "test_network${size}.x"

    "./test_network${size}.x" |
        tee "results/network${size}_correctness.txt"

    # Generate optimized assembly.
    gcc -O2 -S \
        -DCOMPUTE_NAME=compute_tst \
        "test_var${variant}.c" \
        -o "assembly/network${size}.s"

    # Compile dedicated benchmark.
    gcc -O2 \
        -DNETWORK_SIZE=$size \
        benchmark_network.c \
        "network${size}.o" \
        -o "benchmark${size}.x"

    # Append benchmark result.
    "./benchmark${size}.x" \
        >> results/objective_e_benchmark.csv

    echo "Network ${size} complete."
done

# Generate performance graph.
python plot_objective_e.py

echo "Objective E tests, benchmarks, and plot complete."