#include "integration/integration-methods.h"

double middle_riemann_sum(function func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = (a + i * h) + h / 2; // (x_i + x_(i+1)) / 2
        sum += func(x);
    }

    return h * sum;
}