#ifndef LAB1_EX2_LIB
#define LAB1_EX2_LIB

#define STR(s) #s
#define XSTR(s) STR(s)
#define dtype float

// Put here the declaration of mu_fn and sigma_fn

double mu_fn(dtype *vector, int len);
double sigma_fn(dtype *vector, double mu, int len);
// ----------------------------------------------

#endif
