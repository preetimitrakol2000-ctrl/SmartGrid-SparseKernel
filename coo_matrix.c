#include <stdlib.h>
#include "coo_matrix.h"

COOMatrix allocate_coo_space(int rows, int cols, int nnz) {
    COOMatrix mat;
    mat.total_rows = rows; mat.total_cols = cols; mat.nnz = nnz;
    mat.row_indices = (int*)malloc(nnz * sizeof(int));
    mat.col_indices = (int*)malloc(nnz * sizeof(int));
    mat.link_weights = (double*)malloc(nnz * sizeof(double));
    return mat;
}

void spmv_coo(COOMatrix* matrix, double* input_telemetry, double* output_signals) {
    // Zero out the tracking receiver array
    for (int i = 0; i < matrix->total_rows; i++) {
        output_signals[i] = 0.0;
    }
    
    // Core Coordinate List Matrix-Vector Multiplication processing loop
    for (int k = 0; k < matrix->nnz; k++) {
        int r = matrix->row_indices[k];
        int c = matrix->col_indices[k];
        output_signals[r] += matrix->link_weights[k] * input_telemetry[c];
    }
}

void free_coo_space(COOMatrix* matrix) {
    free(matrix->row_indices);
    free(matrix->col_indices);
    free(matrix->link_weights);
}
