/* Programa secuencial que calcula la suma de los elementos de un vector v[i] y la almacena en la variable sum */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N TAMAÑO // Probar distintos tamaños de vector

#include <omp.h>

int main()
{
	int sum = 0;
	int v[N];

	double start = omp_get_wtime();

	omp_set_num_threads(8);

	// Damos valores aleatorios al vector (entre 0 y 99)
	srand(time(NULL)); // Semilla de números aleatorios

	#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		v[i] = rand() % 100;
	}

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			// Cálculo del sumatorio
			#pragma omp parallel for reduction(+:sum)
			for (int i = 0; i < N; i++) {
				sum += v[i];
			}
		}

		#pragma omp section
		{
			#pragma omp parallel for
			for (int i = 0; i < N; i++) {
				printf("%d ", v[i]);
			}
		}
	}

	printf("\n%d\n", sum);
	printf("%f\n", omp_get_wtime() - start);

	return 0;
}

