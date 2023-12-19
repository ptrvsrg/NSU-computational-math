#ifndef DIFFERENCE_SCHEMES_CSV_H
#define DIFFERENCE_SCHEMES_CSV_H

struct csv_file_t_;
typedef struct csv_file_t_ csv_file_t;

csv_file_t *csv_create(char *path, int columns);
int csv_write_line(csv_file_t *csv, double *line, int columns);
void csv_destroy(csv_file_t *csv);

#endif // DIFFERENCE_SCHEMES_CSV_H
