/* Programa secuencial que calcula la suma de los elementos de un vector v[i] y la almacena en la variable sum */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N TAMAÑO // Probar distintos tamaños de vector

int main()
{
	int i, sum = 0;
	int v[N];

	// Damos valores aleatorios al vector (entre 0 y 99)
	srand(time(NULL)); // Semilla de números aleatorios

	#pragma omp simd
	for (i = 0; i < N; i++) {
		v[i] = rand() % 100;
	}

	// Cálculo del sumatorio
	#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < N; i++) {
		sum += v[i];
	}

	#pragma omp simd
	for (i = 0; i < N; i++) {
		printf("%d\t", v[i]);
	}

	printf("\n%d\n", sum); 
	return 0;
} 

