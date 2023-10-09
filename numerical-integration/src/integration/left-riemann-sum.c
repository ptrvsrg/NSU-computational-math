#include "integration/integration-methods.h"

double left_riemann_sum(function func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }

    return h * sum;
}