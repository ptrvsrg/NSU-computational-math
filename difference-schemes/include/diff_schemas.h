#ifndef DIFFERENCE_SCHEMES_DIFF_SCHEMAS_H
#define DIFFERENCE_SCHEMES_DIFF_SCHEMAS_H

void godunov_schema(double **u, double start_x, double  end_x, double  start_t, double  end_t, double  dx,
                    double dt, double r, double (*init_first_layer)(double));
void implicit_schema(double **u, double start_x, double  end_x, double  start_t, double  end_t, double  dx,
                    double dt, double r, double (*init_first_layer)(double));

#endif // DIFFERENCE_SCHEMES_DIFF_SCHEMAS_H
