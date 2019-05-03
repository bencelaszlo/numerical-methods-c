#include <stdlib.h>

#include "../include/vec.h"

void vec_init(Vec *vec, size_t with_capacity) {
    vec->elements = (float*)malloc(with_capacity * sizeof(float) );
    vec->len = 0;
    vec->capacity = with_capacity;
}

void vec_insert(Vec *vec, float element) {
    if (vec->len == vec->capacity) {
        vec->capacity *= 2;
        vec->elements = (float *)realloc(vec->elements, vec->capacity * sizeof(float) );
    }
    vec->elements[vec->len++] = element;
}

Vec vec_copy(Vec *original_vec) {
    Vec new_vec;
    vec_init(&new_vec, original_vec->capacity);
    
    for (unsigned i = 0; i < original_vec->len; i++) {
        vec_insert(&new_vec, original_vec->elements[i]);
    }
    return new_vec;
}

void vec_free(Vec *vec) {
    free(vec->elements);
    vec->elements = NULL;
    vec->len = vec->capacity = 0;
}
