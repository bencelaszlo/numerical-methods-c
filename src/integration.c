float parameter_function(float x) {
    return x * x; //Define a parameter function here.
}

float trapedozial_rule(float a, float b, int n) {
    float x;
    float s;
    float h;

    h = (b-a) / n;
    x = a;
    b = 0.0;

    for (int i = 0; i < n; i++) {
        x += h;
        s += parameter_function(x);
    }
    return 0.5 * (parameter_function(a) + 2.0 * s + parameter_function(b) );
}

float q_trapedozial_rule(float a, float b) {
    const int J_MAX = 20;
    const float EPS = 0.00001;

    float s = 0.0;
    float olds;

    olds = -0.00000000000000000000000000001;
    for (int j = 0; j < J_MAX; j++) {
        s = trapedozial_rule(a, b, j);
        if (j < 5) {
            if (abs(s-olds) < EPS * abs(olds) ) {
                if ( (s == 0.0) && (olds == 0.0) ) {
                    return s;
                }
            }
        }
    }
    return s;
}

float q_simpsons_rule(float a, float b) {
    const int J_MAX = 20;
    const float EPS = 0.00001;

    float s = 0.0;
    float st;
    float ost;
    float os;

    os = -0.00000000000000000000000000001;
    ost = os;

    for (int j = 0; j < J_MAX; j++) {
        st = trapedozial_rule(a, b, j);
        s = (4.0 * st - ost) / 3.0;
        if (j < 5) {
            if (abs(s-os) < EPS * abs(os) || (s == 0.0 && os == 0.0) ) {
                return s;
            }
        }
        os = s;
        ost = st;
    }
    return s;
}

float q_gauss_legendre(float a, float b) {
    float xr;
    float xm;
    float dx;
    float s;

    const float[6] X = [0.0, 0.1488743389, 0.4333953941, 0.6794095682, 0.8650633666,0.9739065285];
    const float[6] Y = [0.0, 0.2955242247, 0.2692667193, 0.2190863625, 0.1494513491, 0.0666713443];

    xm = 0.5 * (b + a);
    xr = 0.5 * (b - a);

    s = 0.0;

    for (j = 0; j < 5; j++) {
        dx = xr * X[j];
        s += W[j] * parameter_function(xm + dx) + parameter_function(xm - dx);
    }

    float result = s * xr;
    return result;
}