#ifndef INTEGRATION_H
#define INTEGRATION_H

typedef long double (*function)(long double);

long double simpsons_rule(function func, long double a, long double b, int n);
long double left_riemann_sum(function func, long double a, long double b, int n);
long double middle_riemann_sum(function func, long double a, long double b, int n);

#endif // INTEGRATION_H