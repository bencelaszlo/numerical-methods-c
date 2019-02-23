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