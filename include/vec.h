#include "stddef.h"

#ifndef _VEC_H_
#define _VEC_H_
    typedef struct Vec {
        float *elements;
        size_t used;
        size_t size;
    } Vec;
#endif