#include <stdio.h>
#include <stdlib.h>

#include "diff_schemas.h"
#include "csv.h"

double a = 1.0;
double start_x = 0.0;
double end_x = 10.0;
double start_t = 0.0;
double end_t = 5.0;
double dx = 0.1;

double T[] = {0.0, 1.0, 5.0};
double r[] = {0.25, 0.5, 1, 1.25};

static double init_first_layer(double x) {
    return x <= 3.0 ? 5.0 : 1.0;
}

int main() {
    for (int i = 0; i < 4; i++) {
        double dt = r[i] * dx / a;
        int nx = (int) ((end_x - start_x) / dx) + 2;
        int nt = (int) ((end_t - start_t) / dt) + 2;

        double **u = malloc(sizeof(double *) * nt);
        for (int n = 0; n < nt; n++) {
            u[n] = malloc(sizeof(double) * nx);
        }

        // Solution using Godunov schema
        godunov_schema(u, start_x, end_x, start_t, end_t, dx, dt, r[i], init_first_layer);
        for (int j = 0; j < 3; j++) {
            char path[256];
            sprintf(path, "godunov-schema_r=%.2lf_T=%.0lf.csv", r[i], T[j]);
            csv_file_t *csv = csv_create(path, 3);

            int t_j = (int) (T[j] / dt);
            for (int k = 0; k < nx; k++) {
                double line[3] = {k * dx, u[t_j][k], init_first_layer(k * dx - T[j])};
                csv_write_line(csv, line, 3);
            }

            csv_destroy(csv);
        }

        // Solution using Implicit schema
        implicit_schema(u, start_x, end_x, start_t, end_t, dx, dt, r[i], init_first_layer);
        for (int j = 0; j < 3; j++) {
            char path[256];
            sprintf(path, "implicit-schema_r=%.2lf_T=%.0lf.csv", r[i], T[j]);
            csv_file_t *csv = csv_create(path, 3);

            int t_j = (int) (T[j] / dt);
            for (int k = 0; k < nx; k++) {
                double line[3] = {k * dx, u[t_j][k], init_first_layer(k * dx - T[j])};
                csv_write_line(csv, line, 3);
            }

            csv_destroy(csv);
        }


        for (int n = 0; n < nt; n++) {
            free(u[n]);
        }
        free(u);
    }

    return 0;
}