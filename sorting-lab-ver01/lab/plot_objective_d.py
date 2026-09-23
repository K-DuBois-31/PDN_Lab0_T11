import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

results = Path("results")

files = {
    "Recursive 16": results / "recursive_dispatch_16.csv",
    "Recursive 32": results / "recursive_dispatch_32.csv",
    "Recursive 64": results / "recursive_dispatch_64.csv",
    "Recursive 128": results / "recursive_dispatch_128.csv",
    "Top-level 32": results / "dispatch_32.csv",
}

plt.figure(figsize=(11, 7))

for label, path in files.items():
    if not path.exists():
        print(f"Missing file: {path}")
        continue

    df = pd.read_csv(path)

    # Match the timer's CSV format.
    x = df.iloc[:, 0]
    y = df.iloc[:, 1]

    plt.plot(x, y, marker="o", markersize=3, label=label)

plt.xlabel("Array Size")
plt.ylabel("Throughput")
plt.title("Objective D: Recursive vs. Top-Level Dispatch")
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()

Path("plots").mkdir(exist_ok=True)
plt.savefig("plots/objective_d_comparison.png", dpi=300)
plt.show()