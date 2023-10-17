#include "runges-rule/runges-rule.h"

#include <math.h>

long double runges_rule(integration_method integration_meth, function func, long double a, long double b, int n) {
    long double I1 = integration_meth(func, a, b, n);
    long double I2 = integration_meth(func, a, b, 2*n);
    long double I3 = integration_meth(func, a, b, 4*n);

    return log2l(fabsl((I1 - I2) / (I2 - I3)));
}