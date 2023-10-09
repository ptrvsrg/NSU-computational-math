#ifndef RUNGES_RULE_H
#define RUNGES_RULE_H

typedef double (*function)(double);
typedef double (*integration_method)(function, double, double, int);

double runges_rule(integration_method integration_meth, function func, double a, double b, int n);

#endif //RUNGES_RULE_H
