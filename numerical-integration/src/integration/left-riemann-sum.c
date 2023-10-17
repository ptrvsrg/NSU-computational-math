#include "integration/integration-methods.h"

long double left_riemann_sum(function func, long double a, long double b, int n) {
    long double h = (b - a) / n;
    long double sum = 0;

    for (int i = 0; i < n; i++) {
        long double x = a + i * h;
        sum += func(x);
    }

    return h * sum;
}