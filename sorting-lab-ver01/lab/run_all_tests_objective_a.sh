
#!/bin/bash

set -e

mkdir -p results

names=(
    "bubble"
    "bubble_optimized"
    "insertion"
    "insertion_optimized"
    "selection"
    "selection_optimized"
    "merge"
    "merge_optimized"
    "quick"
    "quick_optimized"
)

for i in {0..9}
do
    num=$(printf "%03d" "$i")
    file="test_var${num}.c"
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

echo "All Objective A tests completed."
python plot_objective_a.py