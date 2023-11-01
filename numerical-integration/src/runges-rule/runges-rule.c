#include "runges-rule/runges-rule.h"

#include <math.h>

long double runges_rule(integration_method integration_meth, function func, long double a, long double b, int n) {
    long double I1 = integration_meth(func, a, b, n);
    long double I2 = integration_meth(func, a, b, 2*n);
    long double I3 = integration_meth(func, a, b, 4*n);

    long double I12 = I1 - I2;
    if (fabsl(I12) < 1E-15) I12 = 0.0;

    long double I23 = I2 - I3;
    if (fabsl(I23) < 1E-15) I23 = 0.0;

    return log2l(fabsl(I12 / I23));
}