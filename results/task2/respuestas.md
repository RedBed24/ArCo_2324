# Conceptos previos

<!-- TODO: explicar los conceptos -->

- Gráfico Scalability of Maximum Site Gain
- Avg. Number of Iterations
- Avg. Iteration Duration
- Impact to Program Gain
- Combined Site Metrics, All Instances
- Site Instance Metrics, Parallel Time

# Problemas detectados

Los sitios a analizar dados generan una advertencia indicando que son demasiado detallados.
Se indica que consideremos vectorización para estos, cosa que también se había previsto en la tarea 1.

Para tener más información, seleccionaremos otros sitos de grano mayor:

1. Principal: Main\_Compresor\_HW.cpp: 93 a 120.
2. Lectura de datos: Main\_Compresor\_HW.cpp: 62 a 67.
3. Hyper: HyperLCA\_Transform\_Operations.cpp: 54 a 81.

Al hacer el snapshot, el threading model se guarda como "otro" en vez de OpenMP, esto altera el gráfico y datos.
Se ha creado una captura de pantalla con los resultados originales:

![captura](imgs/captura_datos_openmp.png)

# Analisis de escalabilidad

Como se había previsto en la tarea 1, el bucle de la lectura de datos empeora el tiempo si se paraleliza.
Ya se dio una breve explicación de porqué, por lo que no repetiremos esta.
Pero este análisis ha ayudado a confirmar que era así.

Para los otros dos bucles, podemos ver una muy buena mejora, sobre todo en el principal.
En cambio, para el bucle de la función Hyper\_LCA\_transform
