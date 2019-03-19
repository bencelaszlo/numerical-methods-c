#include <stdlib.h>

#include "../include/vec.h"

void vec_init(Vec *vector, size_t initial_size) {
    vector->elements = (float*)malloc(initial_size * sizeof(float) );
    vector->used = 0;
    vector->size = initial_size;
}

void vec_init_int(Vec_int *vector, size_t inital_size) {
    vector->elements = (int*)malloc(inital_size * sizeof(int) );
    vector->used = 0;
    vector->size = inital_size;
}

void vec_insert(Vec *vector, float element) {
    if (vector->used == vector->size) {
        vector->size *= 2;
        vector->elements = (float *)realloc(vector->elements, vector->size * sizeof(float) );
    }
    vector->elements[vector->used++] = element;
}

void vec_insert_int(Vec_int *vector, int element) {
    if (vector->used == vector-> size) {
        vector->size *= 2;
        vector->elements = (int *)realloc(vector->elements, vector->size * sizeof(int) );
    }
    vector->elements[vector->used++] = element;
}

Vec vec_copy(Vec *original_vector) {
    Vec new_vector;
    vec_init(&new_vector, original_vector->size);
    
    for (unsigned i = 0; i < original_vector->used; i++) {
        vec_insert(&new_vector, original_vector->elements[i]);
    }
    return new_vector;
}

Vec_int vec_copy_int(Vec_int *original_vector) {
    Vec_int new_vector;
    vec_init_int(&new_vector, original_vector->size);

    for (unsigned i = 0; i < original_vector->used; i++) {
        vec_insert_int(&new_vector, original_vector->elements[i]);
    }
    return new_vector;
}

void vec_free(Vec *vector) {
    free(vector->elements);
    vector->elements = NULL;
    vector->used = vector->size = 0;
}