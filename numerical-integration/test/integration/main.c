#include "integration/integration-methods.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double function1(double x) {
    return x;
}

static double function2(double x) {
    return 0.7 * x * x;
}

static double function3(double x) {
    return sqrt(7 * x);
}

static double function4(double x) {
    return log(x + 2);
}

static double function5(double x) {
    return x * sin(x);
}

static double function6(double x) {
    return 1 / (1 + exp(x));
}

static struct {
    function func;
    double a;
    double b;
} funcs_and_borders[] = {
        {function1, 2, 7},
        {function2, -1, 0},
        {function3, 0, 3},
        {function4, 0, 1},
        {function5, -M_PI, M_PI},
        {function6, -1, 0}
};

static int segment_counts[] = {
        10, 20, 50, 100, 1000
};

int main(int argc, char **argv) {
    for (int i = 0; i < sizeof(funcs_and_borders) / sizeof(*funcs_and_borders); ++i) {
        for (int j = 0; j < sizeof(segment_counts) / sizeof(*segment_counts); ++j) {
            printf("Test with func_id=%d, a=%lf, b=%lf, n=%d\n",
                   i, funcs_and_borders[i].a, funcs_and_borders[i].b, segment_counts[j]);
            printf("Simpson's rule:     %lf\n",
                   simpsons_rule(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                 segment_counts[j]));
            printf("Left Riemann sum:   %lf\n",
                   left_riemann_sum(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                    segment_counts[j]));
            printf("Middle Riemann sum: %lf\n",
                   middle_riemann_sum(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                      segment_counts[j]));
            printf("-----------------------------------------------------\n");
        }
    }

    return EXIT_SUCCESS;
}