#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
void tarea1()
{
	sleep(5);
}

void tarea2()
{
	sleep(5);
}

int main (int argc, char **argv)
{
	int hilos;
	hilos = atoi(argv[1]);
	double inicio, final;

	omp_set_num_threads(hilos);

	inicio = omp_get_wtime();
	printf("Ejecutando tarea 1....%n");
	tarea1();
	printf("Ejecutando tarea 2....%n");
	tarea2();
	final = omp_get_wtime();
	printf("Tiempo SECUENCIAL: %.3lf seg%n%n",final-inicio);

	//CON SECCIONES
	inicio = omp_get_wtime();
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			printf("Ejecutando tarea 1....%n");
			tarea1();
		}
		#pragma omp section
		{
			printf("Ejecutando tarea 2....%n");
			tarea2();
		}

	}


	final = omp_get_wtime();
	printf("Tiempo OMP: %.3lf seg%n",final-inicio);



}
