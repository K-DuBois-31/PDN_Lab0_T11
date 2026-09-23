import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

Path("plots").mkdir(exist_ok=True)

df = pd.read_csv("results/objective_e_benchmark.csv")

x = range(len(df))
width = 0.35

plt.figure(figsize=(10, 6))

plt.bar(
    [i - width / 2 for i in x],
    df["network_seconds"],
    width,
    label="Sorting Network"
)

plt.bar(
    [i + width / 2 for i in x],
    df["insertion_seconds"],
    width,
    label="Insertion Sort"
)

plt.xticks(x, df["size"])

plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.title("Objective E: Sorting Network vs. Insertion Sort")

plt.legend()
plt.grid(axis="y", alpha=0.3)
plt.tight_layout()

plt.savefig("plots/objective_e_comparison.png", dpi=300)
plt.close()

print("Saved plots/objective_e_comparison.png")