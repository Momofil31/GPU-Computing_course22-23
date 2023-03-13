#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "include/lab1_ex4_lib.h"
// NOTE: dtype is a macro type defined in 'include/lab1_ex2_lib.h'
//          also, the functions mu_fn and sigma_fn are defined in
//          'include/lab1_ex2_lib.h'

// -------- uncomment these seven lines when solutions are published --------
// #include "../../solutions/lab1_sol.cu"
// #define RESULTS
// #ifdef RESULTS
// #include "../../solutions/lab1_ex2_lib_sol.c"
//     MU_SOL
//     SIGMA_SOL
// #endif
// ------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: lab1_ex2 n\n");
        return (1);
    }

    printf("argv[0] = %s\n", argv[1]);

    int n = atoi(argv[1]), len;
    dtype *a;

    printf("n = %d\n", n);
    printf("dtype = %s\n", XSTR(dtype));

    /* Generate now two vectors a and b of size (2^n) and fill them with random
     * integers in the range [-(2^11), (2^11)]. After this, compute the vector
     * sum c = a + b (for all i in [0, (2^n)-1] c[i] = a[i] + b[i]).
     *
     * Other tasks:
     *      1) compute the CPU time
     *      2) change now the dtype form 'int' to 'double' (go in
     * include/lab1_ex2.h) and observe how the computation time changes
     *
     * NOTE:
     * for random generation of integers in [-(2^11), (2^11)] use:
     * "rand()/(1<<11)" for random generation of doubles use:
     * "(double)rand()/((double)RAND_MAX)"
     */

    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    struct timeval temp_1, temp_2;
    gettimeofday(&temp_1, (struct timezone *)0);

    len = (1 << n);
    a = (dtype *)malloc(sizeof(dtype) * len);
    dtype *W = (dtype *)malloc(sizeof(dtype) * len);

    for (size_t i = 0; i < len; i++) {
        a[i] = rand() / (1 << 11);
    }
    printf("Initial vector:\n");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // compute prefix_sum
    for (size_t i = 0; i < len; i++) {
        dtype sum = 0;
        for (size_t j = 0; j <= i; j++) {
            sum += a[j];
        }
        W[i] = sum;
    }
    printf("Prefix sum vector:\n");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", W[i]);
    }
    printf("\n");

    gettimeofday(&temp_2, (struct timezone *)0);
    float time = (temp_2.tv_sec - temp_1.tv_sec) +
                 (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    printf("Script runs in %9.8f CPU time\n", time);

    return (0);
}
