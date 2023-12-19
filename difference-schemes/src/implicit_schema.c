#include "diff_schemas.h"

#include <stdlib.h>

#include "thomas_algorithm.h"

void implicit_schema(double **u, double start_x, double end_x, double start_t, double end_t, double dx, double dt,
                     double r, double (*init_first_layer)(double)) {
    int nx = (int) ((end_x - start_x) / dx) + 2;
    int nt = (int) ((end_t - start_t) / dt) + 2;

    double **A = malloc(sizeof(double *) * nx);
    for (int i = 0; i < nx; i++) {
        A[i] = malloc(sizeof(double) * nx);
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < nx; j++) {
            if (i == j) {
                A[i][j] = 1;
            } else if (i == j + 1) {
                A[i][j] = -r / 2;
            } else if (i == j - 1) {
                A[i][j] = r / 2;
            } else {
                A[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < nx; j++) {
        u[0][j] = init_first_layer(start_x + j * dx);
    }

    for (int n = 1; n < nt; n++) {
        u[n - 1][0] += init_first_layer(start_x - dx - (n - 1) * dt) * r / 2;
        u[n - 1][nx - 1] -= init_first_layer(end_x - (n - 1) * dt) * r / 2;

        thomas_algorithm(A, u[n - 1], nx, u[n]);

        u[n - 1][0] -= init_first_layer(start_x - dx - (n - 1) * dt) * r / 2;
        u[n - 1][nx - 1] += init_first_layer(end_x - (n - 1) * dt) * r / 2;
    }
}