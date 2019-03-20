#ifndef _VEC_METHODS_H_
#define _VEC_METHODS_H_

    void vec_init(Vec *vec, size_t with_capacity);

    void vec_init_int(Vec_int *vec, size_t with_capacity);

    void vec_insert(Vec *vec, float element);

    void vec_insert_int(Vec_int *vec, int element);

    Vec vec_copy(Vec *original_vec);

    Vec_int vec_copy_int(Vec_int *original_vec);

    void vec_free(Vec *vec);
    
#endif