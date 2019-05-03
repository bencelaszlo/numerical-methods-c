#include <stdio.h>
#include <time.h>
#include "../include/vec.h"
#include "../include/vec_methods.h"
#include "../include/utils.h"
#include "../include/interpolation.h"
#include "../include/sort.h"
#include "../include/integration.h"

int main() {
	clock_t start_time, end_time;
    //printf("INTERPOLATION\n");

    //float x_known[7] = {-250.0, -200.0, -100.0, 0.0, 100.0, 200.0, 250.0};
    //float y_known[7] = {0.0, 280.0, 540.0, 640.0, 1200.0, 1600.0, 1800.0};

   	//Vec x;
   	//x = file_read("input.txt");

    //printf("Linear interpolation\n");

	//start_time = clock();

   	//Vec y;
   	//y = vec_copy(&x);

   	//linear_interpolation_array(x_known, y_known, &x, &y);

    /*for (unsigned i = 0; i < x.capacity; i++) {
        printf("%f\n", y.elements[i]);
    }

    printf("\n\n\n");
    printf("SORTING\n");
	*/
    Vec test_vec;
    test_vec = file_read("input.txt");
	start_time = clock();
    //int length = test_vec.len;
    /*
    for (unsigned k = 0; k < test_vec.capacity; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\n\n\n");
    printf("Shell sort\n");*/
    shell_sort(test_vec.capacity, &test_vec);
	/*
    for (unsigned k = 0; k < test_vec.capacity; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\nQuicksort\n");
    vec_free(&test_vec);*/
    //test_vec = file_read("input.txt");
	//quicksort(0, (test_vec.capacity-1), &test_vec);
    /*for (unsigned k = 0; k < test_vec.capacity; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\nHeap sort\n");
    vec_free(&test_vec);
    test_vec = file_read("input.txt");
	*/
    //heapsort(test_vec.capacity, &test_vec);
	/*
    for (unsigned k = 0; k < test_vec.capacity; k++) {
        printf("%f\n", test_vec.elements[k]);
    }

    printf("\n\n\n");
    printf("INTEGRATION OF FUNCTIONS\n");

    printf("\nTrapedozial Rule\n");*/
   // printf("%f\n", q_trapedozial_rule(0, 40.0f, 40) );
	
   	//printf("\nIterative Trapedozial Rule\n");
    //int j_max = file_read_int("input.txt");
    //float result_integration = q_trapedozial_rule(0, 40.0f, j_max);

    //printf("%f\n", result_integration);
	/*
    printf("\nSimpson's Rule\n");
    printf("%f\n", q_simpsons_rule(0, 3.0f, 40) );

    printf("\nIterative Simpson's Rule\n");*/
    //float result_integration = q_simpsons_rule(0, 40.0f, j_max);
    //printf("%f\n", result_integration);
	/*
    printf("\nGauss-Legendre\n");
    printf("%f\n", q_gauss_legendre(0, 3.0f) );
	*/
	end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("%lf\n", elapsed_time);
    return 0;
}