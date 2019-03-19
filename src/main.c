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
    x = file_read("input.txt");

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
    test_vec = file_read("input.txt");
    
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
    test_vec = file_read("input.txt");
	
    quicksort(0, (test_vec.used-1), &test_vec);
	
    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\nHeap sort\n");
    vec_free(&test_vec);
    test_vec = file_read("input.txt");
	
    heapsort(test_vec.used, &test_vec);
	
    for (unsigned k = 0; k < test_vec.used; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\n\n\n");
    printf("INTEGRATION OF FUNCTIONS\n");

    printf("\nTrapedozial Rule\n");
    printf("%f\n", q_trapedozial_rule(0, 3.0f, 40) );

    printf("\nIterative Trapedozial Rule\n");
    Vec_int j_max;
    j_max = file_read_int("input.txt");
    Vec result_vec;
    vec_init(&result_vec, j_max.used);
    q_trapedozial_rule_vec(0, 3.0f, &j_max, &result_vec);

    for (unsigned k = 0; k < result_vec.used; k++) {
        printf("%f\n", result_vec.elements[k]);
    }

    printf("\nSimpson's Rule\n");
    printf("%f\n", q_simpsons_rule(0, 3.0f, 40) );

    printf("\nIterative Simpson's Rule\n");
    vec_free(&result_vec);
    vec_init(&result_vec, j_max.used);
    q_simpsons_rule_vec(0, 3.0f, &j_max, &result_vec);

    for (unsigned k = 0; k < result_vec.used; k++) {
        printf("%f\n", result_vec.elements[k]);
    }

    printf("\nGauss-Legendre\n");
    printf("%f\n", q_gauss_legendre(0, 3.0f) );

    return 0;
}