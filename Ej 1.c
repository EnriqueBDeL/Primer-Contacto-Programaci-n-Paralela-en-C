#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
	int numero_hilos;
	double ini, fin;

	//CAPTURA DE DATOS DE LA LINEA DE COMANDOS
	numero_hilos = atoi(argv[1]);
	omp_set_num_threads(numero_hilos);
	printf("El numero de hilos paralelos es : %d\n",omp_get_num_threads());
	#pragma omp parallel
	{

		int tmp_hilo = omp_get_thread_num();
		printf("El numero de hilos paralelos es : %d y soy el hilo %d\n",omp_get_num_threads(), tmp_hilo);
	}


	//printf("El tiempo de ejecucion: %.5lf seg.\n",fin-ini);
	return 0;

}