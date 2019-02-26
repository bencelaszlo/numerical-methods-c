#include <stdio.h>

#include "../include/vec.h"
#include "../include/vec_methods.h"
#include "../include/utils.h"
#include "../include/interpolation.h"
#include "../include/sort.h"
#include "../include/integration.h"

int main() {
    printf("INTERPOLATION\n");

    float x_known[7] = {-250.0, -200.0, -100.0, 0.0, 100.0, 200.0, 250.0};
    float y_known[7] = {0.0, 280.0, 540.0, 640.0, 1200.0, 1600.0, 1800.0};

    Vec x;
    x = file_read("input_data.txt");

    printf("Linear interpolation\n");

    Vec y;
    y = vec_copy(&x);

    linear_interpolation_array(x_known, y_known, &x, &y);

    for (unsigned i = 0; i < x.used; i++) {
        printf("%f\n", y.elements[i]);
    }

    printf("\n\n\n");
    printf("SORTING\n");

    Vec test_vec;
    vec_init(&test_vec, 9);
    vec_insert(&test_vec, 6.4);
    vec_insert(&test_vec, -0.21);
    vec_insert(&test_vec, 3.1415926);
    vec_insert(&test_vec, 4.2);
    vec_insert(&test_vec, 2.225);
    vec_insert(&test_vec, 2.3);
    vec_insert(&test_vec, 1.2);
    vec_insert(&test_vec, 2.4);
    vec_insert(&test_vec, 5.2);
    
    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\n\n\n");
    printf("Shell sort\n");
    
    shell_sort(test_vec.used, &test_vec);

    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\nQuicksort\n");
    vec_free(&test_vec);

    vec_init(&test_vec, 9);
    vec_insert(&test_vec, 6.4);
    vec_insert(&test_vec, -0.21);
    vec_insert(&test_vec, 3.1415926);
    vec_insert(&test_vec, 4.2);
    vec_insert(&test_vec, 2.225);
    vec_insert(&test_vec, 2.3);
    vec_insert(&test_vec, 1.2);
    vec_insert(&test_vec, 2.4);
    vec_insert(&test_vec, 5.2);

    quicksort(0, (test_vec.used-1), &test_vec);

    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\nHeap sort\n");
    vec_free(&test_vec);

    vec_init(&test_vec, 9);
    vec_insert(&test_vec, 6.4);
    vec_insert(&test_vec, -0.21);
    vec_insert(&test_vec, 3.1415926);
    vec_insert(&test_vec, 4.2);
    vec_insert(&test_vec, 2.225);
    vec_insert(&test_vec, 2.3);
    vec_insert(&test_vec, 1.2);
    vec_insert(&test_vec, 2.4);
    vec_insert(&test_vec, 5.2);

    heapsort(test_vec.used, &test_vec);

    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }


    return 0;
}