#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv)
{
	float *a, suma = 0;
	int tam, i;
	srand(time(NULL));

	//CAPTURA DE DATOS DE LA LINEA DE COMANDOS
	tam = atoi(argv[1]);

	//CREAMOS LA MEMORIA DINAMICA
	a = (float *)malloc(sizeof(float)*tam);

	//INICIALIZAMOS LAS MATRICES A VALORES ALEATORIOS
	for (i = 0; i < tam; i++)
		a[i] = (rand() % 100) * 0.2;

	//SUMA DE VECTORES O SUMA DE MATRICES
	for (i = 0; i < tam; i++)
		suma += a[i];

	//MOTRAR RESULTADOS
	printf("Resultado: %.1f%n",suma);
	return 0;

}