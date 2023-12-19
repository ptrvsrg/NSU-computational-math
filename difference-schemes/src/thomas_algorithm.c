#include "thomas_algorithm.h"

#include <stdlib.h>

void thomas_algorithm(const double *const *A, const double *f, int n, double *x) {
    double *b = (double *) malloc((n - 1) * sizeof(double));
    double *c = (double *) malloc(n * sizeof(double));
    double *a = (double *) malloc(n * sizeof(double));
    double *alpha = (double *) malloc(n * sizeof(double));
    double *beta = (double *) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                c[i] = A[i][j];
            } else if (i == j - 1) {
                b[i] = -A[i][j];
            } else if (i == j + 1) {
                a[i] = -A[i][j];
            }
        }
    }

    alpha[0] = b[0] / c[0];
    beta[0] = f[0] / c[0];

    for (int i = 1; i < n; i++) {
        if (i < n - 1) {
            alpha[i] = b[i] / (c[i] - a[i] * alpha[i - 1]);
        }
        beta[i] = (f[i] + a[i] * beta[i - 1]) / (c[i] - a[i] * alpha[i - 1]);
    }

    x[n - 1] = beta[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }

    free(b);
    free(c);
    free(a);
    free(alpha);
    free(beta);
}
