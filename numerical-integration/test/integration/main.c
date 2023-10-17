#include "integration/integration-methods.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static long double function1(long double x) {
    return x;
}

static long double function2(long double x) {
    return 0.7 * x * x;
}

static long double function3(long double x) {
    return sqrtl(7 * x);
}

static long double function4(long double x) {
    return logl(x + 2);
}

static long double function5(long double x) {
    return x * sinl(x);
}

static long double function6(long double x) {
    return 1 / (1 + expl(x));
}

static struct {
    function func;
    long double a;
    long double b;
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
            printf("Test with func_id=%d, a=%Lf, b=%Lf, n=%d\n",
                   i, funcs_and_borders[i].a, funcs_and_borders[i].b, segment_counts[j]);
            printf("Simpson's rule:     %Lf\n",
                   simpsons_rule(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                 segment_counts[j]));
            printf("Left Riemann sum:   %Lf\n",
                   left_riemann_sum(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                    segment_counts[j]));
            printf("Middle Riemann sum: %Lf\n",
                   middle_riemann_sum(funcs_and_borders[i].func, funcs_and_borders[i].a, funcs_and_borders[i].b,
                                      segment_counts[j]));
            printf("-----------------------------------------------------\n");
        }
    }

    return EXIT_SUCCESS;
}