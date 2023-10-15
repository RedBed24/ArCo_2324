/* Programa paralelo que encuentra el mínimo y máximo de un vector */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N TAMAÑO // Probar distintos tamaños de vector

#include <omp.h>

int main(int argc, char **argv)
{
	int i;
	int v[N];
	int min{0}, max{100};

	double start = omp_get_wtime();

	omp_set_num_threads(8);

	// Generamos los valores de la matriz dando un rango definido por el mínimo y máximo previamente dados
	srand(time(NULL));

	// nos da igual el orden en el que generemos aleatorios ya que usamos una semilla distinta en cada momento
	#pragma omp parallel for private(i)
	for (i = 0; i < N; i++)
	{
		v[i] = min + rand() % (max - min);
	}

	// Intercambiamos el mínimo y el máximo para que tengan los valores opuestos
	i = min;
	min = max;
	max = i;

	#pragma omp sections
	{
		#pragma omp section
		{
			#pragma omp parallel for private(i) reduction(min:min) reduction(max:max)
			for (i = 0; i < N; i++)
			{
				max = max < v[i] ? v[i] : max;
				min = min > v[i] ? v[i] : min;
			}
		}

		#pragma omp section
		{
			// Nos da igual el orden de muestra ya que son aleatorios que no se han generado siguiendo un orden
			#pragma omp parallel for private(i)
			for (i = 0; i < N; i++)
			{
				printf("%d ", v[i]);
			}
		}
	}

	printf("\n%d %d\n", min, max);
	printf("%f\n", omp_get_wtime() - start);

	return 0;
}

