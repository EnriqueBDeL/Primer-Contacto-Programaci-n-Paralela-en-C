#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime()
{
	//utilizar el reloj del sistema
	static int sec=-1;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	if (sec < 0) sec = tv.tv_sec;
	return (tv.tv_sec - sec) + 1.0e-6*tv.tv_usec;
}


int main (int argc, char **argv)
{
	float *a, *b, *c;
	int dimx, dimy, i,j;
	double ini, fin;

	//CAPTURA DE DATOS DE LA LINEA DE COMANDOS
	dimx = atoi(argv[1]);
	dimy = atoi(argv[2]);

	//CREAMOS LA MEMORIA DINAMICA
	a = (float *)malloc(sizeof(float)*dimx*dimy);
	b = (float *)malloc(sizeof(float)*dimx*dimy);
	c = (float *)malloc(sizeof(float)*dimx*dimy);

	ini = wtime();
	//INICIALIZAMOS LAS MATRICES A VALORES ALEATORIOS
	for (i = 0; i < (dimx*dimy); i++)
	{
		a[i] = (rand() % 100) * 0.2;
		b[i] = (rand() % 100) * 0.2;
	}

	//SUMA DE VECTORES O SUMA DE MATRICES
	for (i = 0; i < (dimx*dimy); i++)
		c[i] = a[i]+b[i];

	//MOTRAR RESULTADOS DE MANERA MATRICIAL
	/*for (i = 0; i < dimx; i++)
	{
		for (j = 0; j < dimy; j++)
			printf("%.1f ",c[i*dimy+j]);
		printf("%n");
	}*/
	fin = wtime();
	printf("El tiempo de ejecucion: %.5lf seg.%n",fin-ini);
	return 0;

}