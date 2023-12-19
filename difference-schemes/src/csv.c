#include "csv.h"

#include <stdio.h>
#include <stdlib.h>

struct csv_file_t_ {
    FILE *file;
    int columns;
};

csv_file_t *csv_create(char *path, int columns) {
    if (columns <= 0) {
        return NULL;
    }

    csv_file_t *csv = malloc(sizeof(csv_file_t));
    if (csv == NULL) {
        return NULL;
    }

    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return NULL;
    }

    csv->file = file;
    csv->columns = columns;

    return csv;
}

int csv_write_line(csv_file_t *csv, double *line, int columns) {
    if (csv == NULL || csv->columns != columns) {
        return -1;
    }

    for (int i = 0; i < columns; i++) {
        fprintf(csv->file, "%lf", line[i]);
        if (i < columns - 1) {
            fprintf(csv->file, ",");
        }
    }
    fprintf(csv->file, "\n");
    return 0;
}

void csv_destroy(csv_file_t *csv) {
    fclose(csv->file);
    free(csv);
}