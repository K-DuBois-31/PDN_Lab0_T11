
import pandas as pd
import matplotlib.pyplot as plt

files = {
    "Original Insertion Sort": "insertion",
    "Sentinel Insertion Sort": "insertion_sentinel",
    "Early-Skip Insertion Sort": "insertion_skip"
}

plt.figure(figsize=(10, 6))

for label, name in files.items():

    df = pd.read_csv(f"results/{name}.csv")

    plt.plot(
        df["size"],
        df["throughput"],
        label=label
    )

plt.xlabel("Array Size")
plt.ylabel("Throughput (elements/ns)")
plt.title("Objective B - Insertion Sort Tuning")

plt.legend()
plt.grid(True)

plt.savefig(
    "plots/objective_b_comparison.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close()

print("Objective B plot generated.")