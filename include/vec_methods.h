#ifndef _VEC_METHODS_H_
#define _VEC_METHODS_H_
    void vec_init(Vec *vector, size_t initial_size);

    void vec_insert(Vec *vector, float element);

    Vec vec_copy(Vec *original_vector);

    void vec_free(Vec *vector);
#endif