#include "integration/integration-methods.h"

long double simpsons_rule(function func, long double a, long double b, int n) {
    if (n % 2 == 1) {
        n++;
    }

    long double h = (b - a) / n;
    long double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
        sum += 2 * func(a + (i + 1) * h);
    }

    return h * sum / 3;
}