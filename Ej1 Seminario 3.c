#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {
    int x;

    printf("\nIntroduce el numero de hilos a ejecutar: "); scanf("%d", &x);

    omp_set_num_threads(x);

    #pragma omp parallel 
    {
        printf("\nID hilo: %d", omp_get_thread_num());

        #pragma omp barrier

        #pragma omp single
        {
            printf("\nNº de hilos usandose dentro: %d\n", omp_get_num_threads());
        } // single
    } // parallel

    printf("\nNº de hilos usandose fuera: %d\n", omp_get_num_threads());

    return 0;
}

