#include "../include/lab1_ex2_lib.h"
#include <stddef.h> 

// Put here the implementation of mu_fn and sigma_fn
double mu_fn(dtype *vector, int len) {
    long long sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += vector[i];
    }
    return sum / len;
}
double sigma_fn(dtype *vector, double mu, int len) {
    long long sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += (vector[i] - mu) * (vector[i] - mu);
    }
    return sum / len;
}

// -------------------------------------------------
