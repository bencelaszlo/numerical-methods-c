#ifndef _VEC_METHODS_H_
#define _VEC_METHODS_H_

    void vec_init(Vec *vector, size_t initial_size);

    void vec_init_int(Vec_int *vector, size_t inital_size);

    void vec_insert(Vec *vector, float element);

    void vec_insert_int(Vec_int *vector, int element);

    Vec vec_copy(Vec *original_vector);

    Vec_int vec_copy_int(Vec_int *original_vector);

    void vec_free(Vec *vector);
    
#endif