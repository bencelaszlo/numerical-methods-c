#ifndef _VEC_METHODS_H_
#define _VEC_METHODS_H_

    void vec_init(Vec *vec, size_t with_capacity);

    void vec_insert(Vec *vec, float element);

    Vec vec_copy(Vec *original_vec);

    void vec_free(Vec *vec);
    
#endif
