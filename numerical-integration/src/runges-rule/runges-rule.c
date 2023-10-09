#include "runges-rule/runges-rule.h"

#include <math.h>

double runges_rule(integration_method integration_meth, function func, double a, double b, int n) {
    double I1 = integration_meth(func, a, b, n);
    double I2 = integration_meth(func, a, b, 2*n);
    double I3 = integration_meth(func, a, b, 4*n);

    return log2(fabs((I1 - I2) / (I2 - I3)));
}