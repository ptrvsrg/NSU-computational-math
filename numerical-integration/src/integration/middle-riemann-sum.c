#include "integration/integration-methods.h"

long double middle_riemann_sum(function func, long double a, long double b, int n) {
    long double h = (b - a) / n;
    long double sum = 0;

    for (int i = 0; i < n; i++) {
        long double x = (a + i * h) + h / 2; // (x_i + x_(i+1)) / 2
        sum += func(x);
    }

    return h * sum;
}