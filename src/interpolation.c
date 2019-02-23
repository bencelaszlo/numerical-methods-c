#include <stdio.h>

#include "vec.h"

float linear_interpolation(float x1, float y1, float x0, float y0, float x) {
    float delta;
    delta = x1 - x0;
    float y;

    if (delta == 0.0) {
        y = y0;
    } else {
        y = y0 + ( (x - x0) / delta) * y1;
    }

    return y;
}

void linear_interpolation_array(float * X, float * Y, Vec *x, Vec *y) {
    int X_length = sizeof(X);

    for (unsigned i = 0; i < x->size; i++) {
        int lower_bound_index = 0;
        int higher_bound_index = 0;

        for (int j = 0; j < X_length; j++) {
            if (X[j] < X[lower_bound_index]) {
                lower_bound_index = j;
            }
        
            if (X[j] > X[higher_bound_index]) {
                higher_bound_index = j;
            }
        }

        for (int j = 0; j < X_length; j++) {
            if (X[j] <= x->elements[i] && X[j] > X[lower_bound_index]) {
                lower_bound_index = j;
            }

            if (X[j] >= x->elements[i] && X[j] < X[higher_bound_index]) {
                higher_bound_index = j;
            }
        }

        y->elements[i] = linear_interpolation(X[higher_bound_index], Y[higher_bound_index], X[lower_bound_index], Y[lower_bound_index], x->elements[i]);
    }
}

/*int main() {
    float X[7] = {-250.0, -200.0, -100.0, 0.0, 100.0, 200.0, 250.0};
    float Y[7] = {0.0, 280.0, 540.0, 640.0, 1200.0, 1600.0, 1800.0};
    float x[100000] = {

    };
    float y[100000];
    linear_interpolation_array(X, Y, x, y, 100000);
    for (int j = 0; j < (sizeof(y) / sizeof(y[0]) ); j++) {
        printf("%f\n", y[j]);
    }

    return 0;
}*/

