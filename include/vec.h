#include "stddef.h"

#ifndef _VEC_H_
#define _VEC_H_
    typedef struct Vec {
        float *elements;
        size_t used;
        size_t size;
    } Vec;

    typedef struct Vec_int {
        int *elements;
        size_t used;
        size_t size;
    } Vec_int;
#endif