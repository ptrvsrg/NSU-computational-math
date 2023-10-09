/**
 * @author ptrvsrg (s.petrov1@g.nsu.ru)
 * @brief Find the roots of the function f(x) = x^3 + ax^2 + bx + c using numerical methods (finding extremes and applying the dichotomy method)
 * @version 1.0.0
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double a, b, c, epsilon, delta;

static double f(double x);
static int find_extremes(double *extreme_1, double *extreme_2);
static int find_roots(double *roots);
static double find_border(double border_1, bool to_right);
static double dichotomy_method(double border_1, double border_2);

int main(int argc, char **argv) {
    if (argc != 6) {
        fprintf(stderr, "%s: Not enough parameters", argv[0]);
        fprintf(stderr, "Usage: %s <a> <b> <c> <delta> <epsilon>", argv[0]);
        return EXIT_FAILURE;
    }

    a = strtod(argv[1], NULL);
    b = strtod(argv[2], NULL);
    c = strtod(argv[3], NULL);
    delta = strtod(argv[4], NULL);
    epsilon = strtod(argv[5], NULL);

    double roots[3];
    int root_count = find_roots(roots);

    for (int i = 0; i < root_count; ++i)
        printf("Root: %lf\n", roots[i]);

    return EXIT_SUCCESS;
}

/**
 * @brief Calculate the value of the function f(x) = x^3 + ax^2 + bx + c.
 *
 * @param x argument.
 * @return The result of the function.
 */
double f(double x) {
    return x * x * x + a * x * x + b * x + c;
}

/**
 * @brief Find the roots of the function f(x) using numerical methods.
 *
 * This function attempts to find the roots of the function f(x) using a combination
 * of techniques, including finding extremes and applying the dichotomy method.
 *
 * @param[out] roots An array to store the root(s) found.
 * @return The number of roots found (1, 2, or 3).
 */
int find_roots(double *roots) {
    int res;
    double extreme_1, extreme_2;

    // Find the extremes of the function.
    res = find_extremes(&extreme_1, &extreme_2);

    if (res == 0) {
        double border_1 = 0;
        double f_0 = f(border_1);
        if (fabs(f_0) < epsilon) {
            roots[0] = border_1;
            return 1;
        } else if (f_0 < -epsilon) {
            double border_2 = find_border(0, true);
            roots[0] = dichotomy_method(border_1, border_2);
            return 1;
        } else {
            double border_2 = find_border(0, false);
            roots[0] = dichotomy_method(border_1, border_2);
            return 1;
        }
    } else {
        double f_1 = f(extreme_1);
        double f_2 = f(extreme_2);

        // Check different cases for root(s) existence and location.
        if (f_1 >= epsilon && f_2 >= epsilon) {
            double border_1 = find_border(extreme_1, false);
            roots[0] = dichotomy_method(border_1, extreme_1);
            return 1;
        } else if (f_1 <= -epsilon && f_2 <= -epsilon) {
            double border_2 = find_border(extreme_2, true);
            roots[0] = dichotomy_method(extreme_1, border_2);
            return 1;
        } else if (fabs(f_1) < epsilon && fabs(f_2) < epsilon) {
            roots[0] = (extreme_1 + extreme_2) / 2;
            return 1;
        } else if (f_1 >= epsilon && fabs(f_2) < epsilon) {
            double border_1 = find_border(extreme_1, false);
            roots[0] = dichotomy_method(border_1, extreme_1);
            roots[1] = extreme_2;
            return 2;
        } else if (fabs(f_1) < epsilon && f_2 <= -epsilon) {
            double border_2 = find_border(extreme_2, true);
            roots[0] = extreme_1;
            roots[1] = dichotomy_method(extreme_2, border_2);
            return 2;
        } else if (f_1 >= epsilon && f_2 <= -epsilon) {
            double border_1 = find_border(extreme_1, false);
            double border_2 = find_border(extreme_2, true);
            roots[0] = dichotomy_method(border_1, extreme_1);
            roots[1] = dichotomy_method(extreme_1, extreme_2);
            roots[2] = dichotomy_method(extreme_2, border_2);
            return 3;
        }
    }
}

/**
 * @brief Find the extremes of the function f(x).
 *
 * This function calculates the extremes of the function using the discriminant
 * and returns the number of extremes found.
 *
 * Derivative of a function:
 * f`(x) = 3x^2 + 2ax + b
 *
 * Discriminant:
 * D` = D/4 = a^2 - 3b
 *
 * Roots:
 * x_1 = (-a - sqrt(D`)) / 3
 * x_2 = (-a + sqrt(D`)) / 3
 *
 * Coordinates of the vertex of the derivative parabola:
 * x_0 = -a / 3
 * y_0 = -D` / 3
 *
 * @param[out] extreme_1 Pointer to store the first extreme.
 * @param[out] extreme_2 Pointer to store the second extreme.
 * @return The number of extremes found (0 or 2).
 */
int find_extremes(double *extreme_1, double *extreme_2) {
    double discriminant = a * a - 3 * b;
    double y_0 = -discriminant / 3;

    if (y_0 >= epsilon) return 0;

    *extreme_1 = (-a - sqrt(discriminant)) / 3;
    *extreme_2 = (-a + sqrt(discriminant)) / 3;

    return 2;
}

/**
 * @brief Find a border where the function changes sign.
 *
 * This function iteratively finds a border where the function f(x) changes sign
 * when starting from the given border_1 and moving either to the right or left.
 *
 * @param border_1 The initial border.
 * @param to_right If true, move to the right; otherwise, move to the left.
 * @return The border where the function changes sign.
 */
double find_border(double border_1, bool to_right) {
    double value_1 = f(border_1);
    double step = delta * (to_right ? 1 : -1);
    double border_2 = border_1 + step;

    while (value_1 * f(border_2) > 0) {
        border_2 += step;
    }

    return border_2;
}

/**
 * @brief Use the dichotomy method to find a root within a given interval.
 *
 * This function applies the dichotomy method to find a root within the given
 * interval [border_1, border_2].
 *
 * @param border_1 The left border of the interval.
 * @param border_2 The right border of the interval.
 * @return The estimated root within the interval.
 */
double dichotomy_method(double border_1, double border_2) {
    double f_1 = f(border_1);
    double f_2 = f(border_2);

    if (fabs(f_1) < epsilon) return border_1;
    if (fabs(f_2) < epsilon) return border_2;

    while (true) {
        double c = (border_1 + border_2) / 2;
        double f_c = f(c);

        if (fabs(f_c) < epsilon) return c;
        if (f_1 * f_c < 0) {
            border_2 = c;
        } else {
            border_1 = c;
            f_1 = f_c;
        }
    }
}
