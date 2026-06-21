# SmartGrid-SparseKernel

A pure C99 optimization kernel designed to parse sparse connectivity states across smart electricity grids. This system implements a **Coordinate List (COO) Sparse Matrix** structure to track active electrical connections, drastically dropping memory space requirements during grid anomaly checking loops.

## 🧮 Mathematical & DSA Foundations
* **Matrix Encoding:** Maps structural anomalies via three parallel 1D tracking arrays (`rows`, `cols`, `values`).
* **Space Complexity:** Reduces grid representation allocations from quadratic $O(N^2)$ to linear $O(NNZ)$ bounds.
* **Execution Utility:** Provides a clean-room implementation of Sparse Matrix-Vector Multiplication (SpMV).

## 📦 Compilation & Execution
```bash
gcc main.c coo_matrix.c fault_calc.c -o grid_kernel -lm
./grid_kernel
