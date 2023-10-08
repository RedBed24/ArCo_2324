# Tarea 5

Recordemos que, como mencionamos en la [memoria general](../../tutorial.md), nos habíamos guardado una copia de los [*specs*](specs.txt) del servidor de cómputo que usamos en devcloud para la [tarea3](../task3/).
Para poder comparar con el ordenador usado para las otras tareas, tendremos que hacer lo mismo, obtener sus [*specs*](specs-local.txt).

| Estadistica | Local | Devcloud |
| :-- | :-- | :-- |
| Modelo | Intel(R) Core(TM) i7-6700HQ CPU | Intel(R) Xeon(R) Gold 6128 |
| Frecuencia(GHz) | 2.6 | 3.4 |
| Sockets | 1 | 2 |
| Cores/Socket | 8 | 6 |
| Threads/core | 2 | 2 |
| L1d | 128KiB | 384KiB |
| L1i | 128KiB | 384KiB |
| L2 | 1MiB | 12MiB |
| L3 | 6MiB | 38.5MiB |

El procesador de devcloud es en prácticamente todos los aspectos mejor que el local.
Sólo contamos con más Cores/Socket, lo cual se ve negado por el hecho de usar 2 Sockets.
El caso es que estas estadísticas (Sockets, Cores y Treads) no importan ya que nuestro programa, actualmente sólo usa un hilo principal, por lo que no podemos aprovechar estas.

La diferencia de tamaños en caché puede que no sea importante ya que todas las matrices no caben en ambas cachés L1 de datos, por lo que se producen fallos en ambas:

$$ nrows \times ncols \times nmatrix \times sizeof(double) = 300 \times 300 \times 3 \times 8B = 2160000B $$

Por tanto, lo que más marca la diferencia es la frecuencia.

