/* Programa paralelo que encuentra el mínimo y máximo de un vector */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500000 // Probar distintos tamaños de vector

#include <omp.h>

int main(int argc, char **argv)
{
	int i;
	int v[N];
	int min{0}, max{100};

	// Generamos los valores de la matriz dando un rango definido por el mínimo y máximo previamente dados
	srand(time(NULL));

	// nos da igual el orden en el que generemos aleatorios ya que usamos una semilla distinta en cada momento
	#pragma omp simd
	for (i = 0; i < N; i++)
	{
		v[i] = min + rand() % (max - min);
	}

	// Intercambiamos el mínimo y el máximo para que tengan los valores opuestos
	i = min;
	min = max;
	max = i;

	// TODO: Ver otras posibles formas de paralelizar el bucle
	#pragma omp parallel for
	for (i = 0; i < N; i++)
	{
		if (max < v[i])
		{
			#pragma omp atomic
			max = v[i];
		}
		else if (min > v[i])
		{
			#pragma omp atomic
			min = v[i];
		}
	}

	// Como comprobación, se visualizan los valores del vector y la suma
	printf("\nVector de números: \n ");

	// Nos da igual el orden de muestra ya que son aleatorios que no se han generado siguiendo un orden
	#pragma omp simd
	for (i = 0; i < N; i++)
	{
		printf("%d\t", v[i]);
	}

	printf("\nmin: %d\nmax: %d\n", min, max);

	return 0;
}

