#include "integration/integration-methods.h"

long double simpsons_rule(function func, long double a, long double b, int n) {
    long double h = (b - a) / (2 * n);
    long double sum = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        sum += 2 * func(a + (2 * i) * h);
        sum += 4 * func(a + (2 * i + 1) * h);
    }

    sum += 4 * func(a + h);

    return h * sum / 3;
}