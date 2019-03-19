#ifndef _INTEGRATION_H_
#define _INTEGRATION_H_

    float parameter_function(float x);

    float trapedozial_rule(float a, float b, int n);

    float q_trapedozial_rule(float a, float b, int j_max);

    void q_trapedozial_rule_vec(float a, float b, Vec_int *j_max_vec, Vec *result_vec);

    float q_simpsons_rule(float a, float b, int j_max);

    void q_simpsons_rule_vec(float a, float b, Vec_int *j_max_vec, Vec *result_vec);

    float q_gauss_legendre(float a, float b);

#endif