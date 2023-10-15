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

	// Generamos los valores de la matriz dando un rango definido por el mínimo y máximo previamente dados
	srand(time(NULL));

	// nos da igual el orden en el que generemos aleatorios ya que usamos una semilla distinta en cada momento
	#pragma omp parallel for private(i, min, max, v)
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
			#pragma omp parallel for private(i, v)
			for (i = 0; i < N; i++)
			{
				// cambiamos a if para que no se esté asignando el valor en cada iteración
				if (max < v[i])
				{
					max = v[i];
				}
				else if (min > v[i])
				{
					min = v[i];
				}
			}
		}

		#pragma omp section
		{
			// Nos da igual el orden de muestra ya que son aleatorios que no se han generado siguiendo un orden
			#pragma omp parallel for private(i, v)
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

