#ifndef INTEGRATION_H
#define INTEGRATION_H

typedef double (*function)(double);

double simpsons_rule(function func, double a, double b, int n);
double left_riemann_sum(function func, double a, double b, int n);
double middle_riemann_sum(function func, double a, double b, int n);

#endif // INTEGRATION_H