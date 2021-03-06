#include <stdio.h>

#include "vec.h"
#include "vec_methods.h"

Vec file_read(char file_path[]) {
    Vec input_numbers;
    vec_init(&input_numbers, 1);

    FILE *fp;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("File read error.");
    }

    float temp_number;
    while(!feof(fp) ) {
        fscanf(fp, "%f", &temp_number);
        vec_insert(&input_numbers, temp_number);
    }

    fclose(fp);

    return input_numbers;
}

int file_read_int(char file_path[]) {
    int read_number;

    FILE *fp;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("File read error.");
    }

    while(!feof(fp) ) {
        fscanf(fp, "%d", &read_number);
    }

    fclose(fp);

    return read_number;
}

float abs_float(float number) {
    float abs_value = number;

    if (number < 0.0f) {
        abs_value *= -1.0f;
    }

    return abs_value;
}
