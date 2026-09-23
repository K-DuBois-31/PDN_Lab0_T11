
#!/bin/bash

set -e

mkdir -p results

# Benchmark original algorithms
files=("test_var002.c" "test_var006.c")
names=("insertion" "merge")

for i in {0..1}
do
    echo "Testing ${names[$i]}..."

    make clean
    make FILE_TST="${files[$i]}"

    ./run_verifier.x > "results/${names[$i]}_verification.txt"

    if grep -q "FAIL" "results/${names[$i]}_verification.txt"; then
        echo "${names[$i]} failed verification"
        exit 1
    fi

    ./run_timer.x 16 1024 16 1 "results/${names[$i]}.csv"
done

# Benchmark dispatch thresholds
for threshold in 16 32 64 128
do
    echo "Testing dispatch threshold $threshold..."

    make clean

    make FILE_TST=test_var012.c \
        CFLAGS="-O2 -DTHRESHOLD=$threshold"

    ./run_verifier.x > "results/dispatch_${threshold}_verification.txt"

    if grep -q "FAIL" "results/dispatch_${threshold}_verification.txt"; then
        echo "Dispatch threshold $threshold failed verification"
        exit 1
    fi

    ./run_timer.x 16 1024 16 1 \
        "results/dispatch_${threshold}.csv"

    echo "Dispatch $threshold completed"
done

echo "All Objective C tests completed."
python plot_objective_c.py