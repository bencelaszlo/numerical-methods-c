#include "vec.h"
#include "vec_methods.h"
#include "utils.h"

float parameter_function(float x) {
    return x * x - 1.0f; //Define a parameter function here.
}

float trapedozial_rule(float a, float b, int n) {
    float x;
    float s;
    float h;

    h = (b - a) / n;
    x = a;
    s = 0.0;

    for (int i = 0; i < n; i++) {
        x += h;
        s += parameter_function(x);
    }
    return ( (b - a) / n) * 0.5 * (parameter_function(a) + 2.0 * s + parameter_function(b) );
}

float q_trapedozial_rule(float a, float b, int j_max) {
    const float EPS = 0.000001; //accurancy
    const int J_MIN_ITERATION_COUNT = 5;

    float s = 0.0;
    float olds;

    olds = -0.00000000000000000000000000001;
    for (int j = 0; j < j_max; j++) {
        s = trapedozial_rule(a, b, j);
        if (j > J_MIN_ITERATION_COUNT) {
            if (abs_float(s - olds) < EPS * abs_float(olds) ) {
                if ( (s == 0.0) && (olds == 0.0) ) {
                    return s;
                }
            }
        }
        olds = s;
    }
    return s;
}

float q_simpsons_rule(float a, float b, int j_max) {
    const float EPS = 0.000001; //accurancy
    const int J_MIN_ITERATION_COUNT = 5;

    float s = 0.0;
    float st;
    float ost;
    float os;

    os = -0.00000000000000000000000000001;
    ost = os;

    for (int j = 0; j < j_max; j++) {
        st = trapedozial_rule(a, b, j);
        s = (4.0 * st - ost) / 3.0;
        if (j > J_MIN_ITERATION_COUNT) {
            if (abs_float(s - os) < EPS * abs_float(os)) {
                return s;
            }
        }
        os = s;
        ost = st;
    }
    return s;
}
