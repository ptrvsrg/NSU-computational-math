#include "integration/integration-methods.h"
#include "runges-rule/runges-rule.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double function1(double x) {
    return 2 * x * x + 0.124;
}

static double function2(double x) {
    return cos(x);
}

static struct {
    function func;
    double a;
    double b;
} funcs_and_borders[] = {
        {function1, 0, 2},
        {function2, -M_PI / 6, M_PI_2}
};

static int segment_counts[] = {
        10, 100, 1000
};

int main(int argc, char **argv) {
    for (int i = 0; i < sizeof(funcs_and_borders) / sizeof(*funcs_and_borders); ++i) {
        for (int j = 0; j < sizeof(segment_counts) / sizeof(*segment_counts); ++j) {
            printf("Test with func_id=%d, a=%lf, b=%lf, n=%d\n",
                   i, funcs_and_borders[i].a, funcs_and_borders[i].b, segment_counts[j]);
            printf("Accuracy of Simpson's rule:     %lf\n",
                   runges_rule(simpsons_rule, funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                               segment_counts[j]));
            printf("Accuracy of left Riemann sum:   %lf\n",
                   runges_rule(left_riemann_sum, funcs_and_borders[i].func, funcs_and_borders[i].a,
                               funcs_and_borders[i].b, segment_counts[j]));
            printf("Accuracy of middle Riemann sum: %lf\n",
                   runges_rule(middle_riemann_sum, funcs_and_borders[i].func, funcs_and_borders[i].a,
                               funcs_and_borders[i].b, segment_counts[j]));
            printf("-----------------------------------------------------\n");
        }
    }

    return EXIT_SUCCESS;
}