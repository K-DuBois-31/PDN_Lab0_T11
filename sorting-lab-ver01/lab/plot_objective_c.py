
import pandas as pd
import matplotlib.pyplot as plt

files = {
    "Insertion Sort": "insertion",
    "Merge Sort": "merge",
    "Dispatch 16": "dispatch_16",
    "Dispatch 32": "dispatch_32",
    "Dispatch 64": "dispatch_64",
    "Dispatch 128": "dispatch_128"
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
plt.title("Objective C - Dispatch Threshold Comparison")

plt.legend()
plt.grid(True)

plt.savefig(
    "plots/objective_c_comparison.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close()

print("Objective C plot generated.")