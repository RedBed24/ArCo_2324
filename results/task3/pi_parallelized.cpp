/* Programa serie para calcular pi */
#include <math.h>
#include <stdio.h>
#include <omp.h>

int main()
{
	int n = TAMAÑO, i;
	double xi, start = omp_get_wtime();
	double pi16ds = 3.1415926535897932; // con 25 decimales 3.141592653589793238462643
	double sum = 0.0;

	omp_set_num_threads(8);

	double h = 1.0 / (double)n; // tamaño intervalo

	#pragma omp parallel for private(i, xi) reduction(+:sum)
	for (i = 0; i < n; i++) {
		xi = h * 0.5 + h * i;
		sum += (4.0 / (1.0 + xi * xi));
	}

	double pi = sum * h;

	printf("%0.16f %0.16f\n", pi, fabs(pi-pi16ds));

	printf("%f\n", omp_get_wtime() - start);

	return 0;
}

