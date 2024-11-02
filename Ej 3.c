#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	float *a, *b, *auxiliar;
	int dimx, iteraciones, i,j,k;
	//CAPTURA DE DATOS DE LA LINEA DE COMANDOS
	dimx = atoi(argv[1]);
	iteraciones = atoi(argv[2]);

	//CREAMOS LA MEMORIA DINAMICA
	a = (float *)malloc(sizeof(float)*dimx*dimx);
	b = (float *)malloc(sizeof(float)*dimx*dimx);

	//INICIALIZAMOS LAS MATRICES A VALORES ALEATORIOS
	for (i = 0; i < (dimx*dimx); i++)
		a[i] = (rand() % 100) * 0.2;

	//SUMA DE VECTORES O SUMA DE MATRICES
	for (k = 0; k < iteraciones; k++)
	{
		//ELEMENTOS INTERIORES DE LA MATRIZ, QUITA LOS BORDES
		for (i = 1;i < (dimx-2); i++)
			for (j = 1; j < (dimx-2); j++)
				b[i*dimx+j] = 0.2*(a[i*dimx+j] + a[(i-1)*dimx+j]+a[(i+1)*dimx+j]+a[i*dimx+j-1]+a[i*dimx+j+1]);

		auxiliar = a;
		a = b;
		b = auxiliar;		
	}

	//MOTRAR RESULTADOS DE MANERA MATRICIAL
	for (i = 0; i < dimx; i++)
	{
		for (j = 0; j < dimx; j++)
			printf("%.1f ",a[i*dimx+j]);
		printf("%n");
	}
	return 0;

}