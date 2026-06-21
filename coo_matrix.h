#ifndef COO_MATRIX_H
#define COO_MATRIX_H

typedef struct {
    int total_rows;
    int total_cols;
    int nnz; // Number of Non-Zero electrical links
    int* row_indices;
    int* col_indices;
    double* link_weights;
} COOMatrix;

COOMatrix allocate_coo_space(int rows, int cols, int nnz);
void spmv_coo(COOMatrix* matrix, double* input_telemetry, double* output_signals);
void free_coo_space(COOMatrix* matrix);

#endif
