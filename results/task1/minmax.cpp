/* Programa secuencial que encuentra el mínimo y máximo de un vector */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N TAMAÑO // Probar distintos tamaños de vector

#include <omp.h>

int main(int argc, char** argv)
{
	int i;
	int v[N];
	int min{0}, max{100};

	double start = omp_get_wtime();

	// Generamos los valores de la matriz dando un rango definido por el mínimo y máximo previamente dados
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		v[i] = min + rand() % (max - min);
	}

	// Intercambiamos el mínimo y el máximo para que tengan los valores opuestos
	i = min;
	min = max;
	max = i;

	for (i = 0; i < N; i++)
	{
		max = max < v[i] ? v[i] : max;
		min = min > v[i] ? v[i] : min;
	}

	// mostramos los valores en una misma línea separada por espacios para una comprobación fácil de resultados
	for (i = 0; i < N; i++)
	{
		printf("%d ", v[i]);
	}

	// mostramos los resultados obtenidos
	printf("\n%d %d\n", min, max);
	printf("%f\n", omp_get_wtime() - start);

	return 0;
}

