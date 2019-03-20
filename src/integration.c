#include "vec.h"
#include "vec_methods.h"
#include "utils.h"

float parameter_function(float x) {
    return x * x; //Define a parameter function here.
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
    const float EPS = 0.00001; //accurancy
    const int J_MIN_ITERATION_COUNT = 5;

    float s = 0.0;
    float olds;

    olds = -0.00000000000000000000000000001;
    for (int j = 0; j < j_max; j++) {
        s = trapedozial_rule(a, b, j);
        if (j < J_MIN_ITERATION_COUNT) {
            if (abs_float(s - olds) < EPS * abs_float(olds) ) {
                if ( (s == 0.0) && (olds == 0.0) ) {
                    return s;
                }
            }
        }
    }
    return s;
}

void q_trapedozial_rule_vec(float a, float b, Vec_int *j_max_vec, Vec *result_vec) {
	for (unsigned i = 0; i < j_max_vec->len; i++) {
		vec_insert(result_vec, q_trapedozial_rule(a, b, j_max_vec->elements[i]) );
	}
}

float q_simpsons_rule(float a, float b, int j_max) {
    const float EPS = 0.00001; //accurancy
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
        if (j < J_MIN_ITERATION_COUNT) {
            if (abs_float(s - os) < EPS * abs_float(os) || (s == 0.0 && os == 0.0) ) {
                return s;
            }
        }
        os = s;
        ost = st;
    }
    return s;
}

void q_simpsons_rule_vec(float a, float b, Vec_int *j_max_vec, Vec *result_vec) {
	for (unsigned i = 0; i < j_max_vec->len; i++) {
		vec_insert(result_vec, q_simpsons_rule(a, b, j_max_vec->elements[i]) );
	}
}

float q_gauss_legendre(float a, float b) {
    float xr;
    float xm;
    float dx;
    float s;

    const float X[6] = {0.0, 0.1488743389, 0.4333953941, 0.6794095682, 0.8650633666, 0.9739065285};
    const float W[6] = {0.0, 0.2955242247, 0.2692667193, 0.2190863625, 0.1494513491, 0.0666713443};

    xm = 0.5 * (b + a);
    xr = 0.5 * (b - a);

    s = 0.0;

    for (unsigned j = 0; j < 5; j++) {
        dx = xr * X[j];
        s += W[j] * parameter_function(xm + dx) + parameter_function(xm - dx);
    }

    float result = s * xr;
    return result;
}