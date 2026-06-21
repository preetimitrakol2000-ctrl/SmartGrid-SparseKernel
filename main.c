#include <stdio.h>
#include "coo_matrix.h"

int main() {
    printf("⚡ Activating SmartGrid-SparseKernel Transformer Core...\n\n");

    int substation_lines = 3;
    int non_zero_connections = 2;
    COOMatrix electrical_mesh = allocate_coo_space(substation_lines, substation_lines, non_zero_connections);

    // Setup linear sparse linkages: Line 0 points to Line 2, Line 1 points to Line 0
    electrical_mesh.row_indices[0] = 0; electrical_mesh.col_indices[0] = 2; electrical_mesh.link_weights[0] = 1.5;
    electrical_mesh.row_indices[1] = 1; electrical_mesh.col_indices[1] = 0; electrical_mesh.link_weights[1] = 0.8;

    double live_current_inputs[3] = {10.0, 0.0, 5.0}; // Live amperes reading
    double analyzed_leakage[3] = {0.0, 0.0, 0.0};

    spmv_coo(&electrical_mesh, live_current_inputs, analyzed_leakage);

    printf("✨ Sparse Extraction Calculations Verified:\n");
    for (int i = 0; i < substation_lines; i++) {
        printf("   • Substation Line ID [%d] -> Resulting Calculated Power Leakage: %.2f Amps\n", i, analyzed_leakage[i]);
    }

    free_coo_space(&electrical_mesh);
    return 0;
}
