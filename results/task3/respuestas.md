# Observaciones importantes

Para poder paralelizar la escritura en el fichero se ha necesitado mantener abierto el archivo y modificar la posición del cursor atendiendo al bloque que se haya tratado en cada iteración.
La posición del cursor y la escritura de los datos se deben hacer seguidamente por el mismo hilo, por ello se debe usar una sección crítica.

Se ha decidido no usar ni `#pragma omp simd` ni `#pragma omp parallel for` ya que la primera generaba warnings indicando que no se había podido paralelizar y la segunda porque las snapshots del advisor indicaban que generaba un empeoramiento.

# Preguntas

Para comprobar si las ejecuciones son las mismas, podemos comprobar si el archivo compressedBitstream.bin, que es el archivo que creamos, tiene el mismo contenido.
Para ello, podemos usar checksums, los cuales deberían dar igual si el contenido es el mismo.

Pero hay que asegurarse que se ejecuta el código sin que este archivo exista, porque se van añadiendo datos a este.

# Mediciones

Secuencial = 10.86s

| Hilos | 2 | 4 | 8 | 16 | 32 | 64 |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |
| Ganancia | 3.1 | 4.26 | 4.81 | 4.13 | 4.07 | 4.01 |
| Paralelizado | 3.50 | 2.55 | 2.26 | 2.63 | 2.67 | 2.71 |

Para más de 8 threads el resultado empeora porque el ordenador con los que se ha realizado las pruebas tiene 8 threads.
Se debería usar los nodos de cómputo del devcloud para realizar esos análisis.

No se ha llegado a la ganancia que esperaba advisor de $\times 7$.
Es normal porque advisor considera unas condiciones perfectas.

