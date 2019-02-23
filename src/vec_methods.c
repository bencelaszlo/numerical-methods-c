#include <stdlib.h>

#include "../include/vec.h"

void vec_init(Vec *vector, size_t initial_size) {
    vector->elements = (float*)malloc(initial_size * sizeof(float) );
    vector->used = 0;
    vector->size = initial_size;
}

void vec_insert(Vec *vector, float element) {
    if (vector->used == vector->size) {
        vector->size *= 2;
        vector->elements = (float *)realloc(vector->elements, vector->size * sizeof(float) );
    }
    vector->elements[vector->used++] = element;
}

void vec_free(Vec *vector) {
    free(vector->elements);
    vector->elements = NULL;
    vector->used = vector->size = 0;
}