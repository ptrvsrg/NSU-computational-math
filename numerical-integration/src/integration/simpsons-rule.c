#include "integration/integration-methods.h"

double simpsons_rule(function func, double a, double b, int n) {
    if (n % 2 == 1) {
        n++;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 4 * func(x);

        i++;
        x = a + i * h;
        sum += 2 * func(x);
    }

    return (h / 3) * sum;
}