#!/bin/bash

set -euo pipefail

# Run from the directory containing this script.
cd "$(dirname "$0")"

# Remove previous generated output.
rm -rf results plots assembly

# Recreate output directories.
mkdir -p results plots assembly

# Activate the Python virtual environment.
if [ -f ".venv/bin/activate" ]; then
    source .venv/bin/activate
fi

echo "Running Objective A..."
bash run_all_tests_objective_a.sh

echo "Running Objective B..."
bash run_all_tests_objective_b.sh

echo "Running Objective C..."
bash run_all_tests_objective_c.sh

echo "Running Objective D..."
bash run_all_tests_objective_d.sh

echo "Running Objective E..."
bash run_all_tests_objective_e.sh

echo "All Objective A-E tests completed successfully."