
#!/bin/bash

set -e

mkdir -p results

files=(
    "test_var002.c"
    "test_var010.c"
    "test_var011.c"
)

names=(
    "insertion"
    "insertion_sentinel"
    "insertion_skip"
)

for i in {0..2}
do
    file="${files[$i]}"
    name="${names[$i]}"

    echo "Testing $name..."

    make clean
    make FILE_TST="$file"

    ./run_verifier.x > "results/${name}_verification.txt"

    if grep -q "FAIL" "results/${name}_verification.txt"; then
        echo "$name failed verification"
        exit 1
    fi

    ./run_timer.x 16 1024 16 1 "results/${name}.csv"

    echo "$name completed"
done

echo "All Objective B tests completed."
python plot_objective_b.py