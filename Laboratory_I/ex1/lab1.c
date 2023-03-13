#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NPROBS 8

#define LEN 15
#define N 5
#define M 5

#define PRINT_RESULT_VECTOR(V, NAME)                        \
    {                                                       \
        printf("%2s: ", NAME);                              \
        for (int i = 0; i < LEN; i++) printf("%4d ", V[i]); \
        printf("\n");                                       \
    }

#define PRINT_RESULT_MATRIX(MAT, NAME)                                  \
    {                                                                   \
        printf("%2s matrix:\n\t", NAME);                                \
        for (int i = 0; i < N; i++) {                                   \
            for (int j = 0; j < M; j++) printf("%4d ", MAT[i * M + j]); \
            printf("\n\t");                                             \
        }                                                               \
        printf("\n");                                                   \
    }

// -------- uncomment these two lines when solutions are published --------
// #include "../../solutions/lab1_sol.cu"
// #define RESULTS
// ------------------------------------------------------------------------

#ifndef SOLUTION_STACKVEC_1
#define SOLUTION_STACKVEC_1 \
    {}
#endif

#ifndef SOLUTION_HEAPVEC_1
#define SOLUTION_HEAPVEC_1 \
    {}
#endif

#ifndef SOLUTION_HEAPVEC_2
#define SOLUTION_HEAPVEC_2 \
    {}
#endif

#ifndef SOLUTION_STACKVEC_2
#define SOLUTION_STACKVEC_2 \
    {}
#endif

#ifndef SOLUTION_STACKMAT_1
#define SOLUTION_STACKMAT_1 \
    {}
#endif

#ifndef SOLUTION_HEAPMAT_1
#define SOLUTION_HEAPMAT_1 \
    {}
#endif

#ifndef SOLUTION_HEAPMAT_2
#define SOLUTION_HEAPMAT_2 \
    {}
#endif

#ifndef SOLUTION_STACKMAT_2
#define SOLUTION_STACKMAT_2 \
    {}
#endif

void compute_p2(int* vec, int* a, int* b) {
    for (int i = 0; i < LEN; i++) {
        vec[i] = a[i] + b[i];
    }
}
void compute_p3(int** vec, int* a, int* b) {
    *vec = (int*)malloc(LEN * sizeof(int));
    for (int i = 0; i < LEN; i++) {
        (*vec)[i] = a[i] + b[i];
    }
}

void compute_p2_matrix(int* vec, int a[][M], int b[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vec[i * M + j] = a[i][j] + b[i][j];
        }
    }
}
void compute_p3_matrix(int** vec, int a[][M], int b[][M]) {
    *vec = (int*)malloc(N * M * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            (*vec)[i * M + j] = a[i][j] + b[i][j];
        }
    }
}

// int* compute_p4(int* a, int* b) {
//     int c4[LEN];
//     for (int i = 0; i < LEN; i++) {
//         c4[i] = a[i] + b[i];
//     }
//     return c4;  // this is dangerous
// }

int main(void) {
    // ---------- for timing ----------
    float CPU_times[NPROBS];
    for (int i = 0; i < NPROBS; i++) CPU_times[i] = 0.0;
    struct timeval temp_1, temp_2;
    // --------------------------------

#ifdef RESULTS
    printf("You are now running the \x1B[31mSOLUTION CODE\x1B[37m:\n");
#else
    printf("You are now running \x1B[31mYOUR CODE\x1B[37m:\n");
#endif
    // ---------------------- Stack vectors 1 ----------------------
    /* Generate three stack vectors a, and b of length "LEN" such
     * that for each i in {0, 1, ... LEN-1} a[i] = i, b[i] = 100 * i.
     * Then compute the vector c = a + b.
     */

#ifdef RESULTS
    SOLUTION_STACKVEC_1
    PRINT_RESULT_VECTOR(c, "c")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int a[LEN], b[LEN], c[LEN];
    for (int i = 0; i < LEN; ++i) {
        a[i] = i;
        b[i] = 100 * i;
        c[i] = a[i] + b[i];
    }

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[0] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_VECTOR(c, "c")

#endif
    // ---------------------- Heap vectors 1 -----------------------
    /* Compute the same result as c but in a heap vector c1 allocated
     * in the main but computed in an extern function.
     */
#ifdef RESULTS
    SOLUTION_HEAPVEC_1
    PRINT_RESULT_VECTOR(c1, "c1")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int* c1 = (int*)malloc(LEN * sizeof(int));
    compute_p2(c1, a, b);

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[1] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_VECTOR(c1, "c1")

#endif
    // ---------------------- Heap vectors 2 -----------------------
    /* Compute the same result as c and c1 in a heap vector c2
     * also allocated in the extern function
     */
#ifdef RESULTS
    SOLUTION_HEAPVEC_2
    PRINT_RESULT_VECTOR(c2, "c2")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int* c2;
    compute_p3(&c2, a, b);

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[2] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_VECTOR(c2, "c2")
#endif
    // ---------------------- Stack vectors 2 ----------------------
    /* Is it possible to compute the c vector as a stack vector of
     * the extern function and then return it to the main?
     */
#ifdef RESULTS
    SOLUTION_STACKVEC_2
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    // Not possible.

#endif

    /* Do now the same 4 previous exercises but with the three
     * matrices A, B, C of N rows and M columns where:
     *   1) A[i][j] = i + j
     *   2) B[i][j] = (i + j) * 100
     *   3) C = A + B
     *
     * What are the differences when you change from vectors to
     * matrices?
     */
    // --------------------- Stack matrices ----------------------

#ifdef RESULTS
    SOLUTION_STACKMAT_1
    PRINT_RESULT_MATRIX(((int*)C), "C")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int A[N][M];
    int B[N][M];
    int C[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = i + j;
            B[i][j] = A[i][j] * 100;
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[4] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_MATRIX(((int*)C), "C")
#endif

    // --------------------- Heap matrices -----------------------
#ifdef RESULTS
    SOLUTION_HEAPMAT_1
    PRINT_RESULT_MATRIX(C1, "C1")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int* C1 = (int*)malloc(sizeof(int*) * N * M);
    compute_p2_matrix(C1, A, B);

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[5] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_MATRIX(C1, "C1")
#endif

    // --------------------- Heap matrices -----------------------
#ifdef RESULTS
    SOLUTION_HEAPMAT_2
    PRINT_RESULT_MATRIX(C2, "C2")
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    gettimeofday(&temp_1, (struct timezone*)0);

    int* C2;

    compute_p3_matrix(&C2, A, B);

    gettimeofday(&temp_2, (struct timezone*)0);
    CPU_times[6] = (temp_2.tv_sec - temp_1.tv_sec) +
                   (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0;
    PRINT_RESULT_MATRIX(C2, "C2")
#endif

    // --------------------- Stack matrices ----------------------
#ifdef RESULTS
    SOLUTION_STACKMAT_2
#else
    /* |========================================| */
    /* |           Put here your code           | */
    /* |========================================| */
    // Not possible.
#endif

    for (int i = 0; i < NPROBS; i++) {
        printf("Problem %d runs in %9.8f CPU time\n", i, CPU_times[i]);
    }
    printf("\n");

    return (0);
}
