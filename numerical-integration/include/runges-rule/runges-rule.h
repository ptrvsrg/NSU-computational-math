#ifndef RUNGES_RULE_H
#define RUNGES_RULE_H

typedef long double (*function)(long double);
typedef long double (*integration_method)(function, long double, long double, int);

long double runges_rule(integration_method integration_meth, function func, long double a, long double b, int n);

#endif //RUNGES_RULE_H
