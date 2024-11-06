#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {

    int *A, *B, *C;

    A = (int *)malloc((1 << 20) * sizeof(int));
    B = (int *)malloc((1 << 20) * sizeof(int));
    C = (int *)malloc((1 << 20) * sizeof(int));

    for (int i = 0; i < (1 << 20); i++) {
        A[i] = 1;
        B[i] = 1;
    }

    int x;
    printf("\nIntroduce el numero de hilos que quieres utilizar: ");
    scanf("%d", &x);

    omp_set_num_threads(x);

    #pragma omp parallel for
    for (int j = 0; j < 1000000; j++) {
        for (int w = 0; w < (1 << 20); w++) {
            C[w] = A[w] + B[w];
            printf("\nResultado de la suma %d es: %d\n", w, C[w]);
        }
    }

    return 0;
}
