#include "diff_schemas.h"

void godunov_schema(double **u, double start_x, double end_x, double start_t, double end_t, double dx,
                    double dt, double r, double (*init_first_layer)(double)) {
    int nx = (int) ((end_x - start_x) / dx) + 2;
    int nt = (int) ((end_t - start_t) / dt) + 2;

    for (int j = 0; j < nx; j++) {
        u[0][j] = init_first_layer(start_x + j * dx);
    }

    for (int n = 0; n < nt - 1; n++) {
        for (int j = 0; j < nx; j++) {
            if (j == 0) {
                u[n + 1][j] = u[n][j] - r * (u[n][j] - init_first_layer(start_x - dt * n));
            } else {
                u[n + 1][j] = u[n][j] - r * (u[n][j] - u[n][j - 1]);
            }
        }
    }
}
