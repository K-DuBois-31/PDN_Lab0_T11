
import os

import pandas as pd
import matplotlib.pyplot as plt

# Sorting algorithms and their corresponding files
algorithms = {
    "Bubble Sort": (
        "bubble",
        "bubble_optimized"
    ),
    "Insertion Sort": (
        "insertion",
        "insertion_optimized"
    ),
    "Selection Sort": (
        "selection",
        "selection_optimized"
    ),
    "Merge Sort": (
        "merge",
        "merge_optimized"
    ),
    "Quick Sort": (
        "quick",
        "quick_optimized"
    )
}

os.makedirs("plots", exist_ok=True)

# Generate individual comparison graphs
for algorithm, (original, optimized) in algorithms.items():

    original_df = pd.read_csv(
        f"results/{original}.csv"
    )

    optimized_df = pd.read_csv(
        f"results/{optimized}.csv"
    )

    plt.figure(figsize=(10, 6))

    plt.plot(
        original_df["size"],
        original_df["throughput"],
        label="Original"
    )

    plt.plot(
        optimized_df["size"],
        optimized_df["throughput"],
        label="Optimized"
    )

    plt.xlabel("Array Size")
    plt.ylabel("Throughput (elements/ns)")

    plt.title(f"{algorithm} Performance Comparison")

    plt.legend()
    plt.grid(True)

    filename = original + "_comparison.png"

    plt.savefig(
        f"plots/{filename}",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()

# Generate combined comparison graph
plt.figure(figsize=(12, 7))

for algorithm, (original, optimized) in algorithms.items():

    for name in (original, optimized):

        df = pd.read_csv(f"results/{name}.csv")

        plt.plot(
            df["size"],
            df["throughput"],
            label=name
        )

plt.xlabel("Array Size")
plt.ylabel("Throughput (elements/ns)")

plt.title("All Sorting Algorithms - Performance Comparison")

plt.legend()
plt.grid(True)

plt.savefig(
    "plots/all_algorithms.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close()

print("All performance graphs generated successfully.")