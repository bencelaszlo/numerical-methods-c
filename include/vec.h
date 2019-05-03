#include "stddef.h"

#ifndef _VEC_H_
#define _VEC_H_
    typedef struct Vec {
        float *elements;
        size_t len;
        size_t capacity;
    } Vec;
#endif
