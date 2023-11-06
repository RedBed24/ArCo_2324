# Preguntas previas

Indica el modelo de procesador y de cuantos núcleos dispones.
¿Cuántos hilos pueden ser ejecutados por un núcleo?

Usaremos `lscpu` para obtener esta información:

| Campo | Valor |
| :-- | --: |
| Architecture | x86\_64 |
| CPU op-mode(s) | 32-bit, 64-bit |
| Address sizes | 39 bits physical, 48 bits virtual|
| Byte Order | Little Endian |
| CPU(s) | 8 |
| On-line CPU(s) list | 0-7 |
| Vendor ID | GenuineIntel |
| Model name | Intel(R) Core(TM) i7-6700HQ CPU @ 2.60GHz |
| CPU family | 6 |
| Model | 94 |
| Thread(s) per core | 2 |
| Core(s) per socket | 4 |
| Socket(s) | 1 |
| L1d cache | 128 KiB (4 instances) |
| L1i cache | 128 KiB (4 instances) |
| L2 cache | 1 MiB (4 instances) |
| L3 cache | 6 MiB (1 instance) |

Se ha dejado toda la información que pueda ser relevante.

# Anotaciones

Para encontrar el archivo: "advisor-annotate.h"

``` Bash
$ find intel/oneapi/ -iname "advisor-annotate.h"
intel/oneapi/advisor/latest/sdk/include/advisor-annotate.h
```

La flag `-Idir` del compilador indica qué directorios usar para buscar archivos de cabecera.

Como para poder usar las annotaciones, debemos hacer `#include "advisor-annotate.h"`, también debemos indicar el directorio donde este se encuentre, es decir, intel/oneapi/advisor/latest/sdk/include/.
**bind with .o??**

No tiene sentido investigar la carga de los datos ya que `fread` asegura acceso único, por lo que si paralelizamos en hilos, realmente sólo uno estaría leyendo datos.
Tampoco tiene sentido usar vectorización porque no se usan vectores.
La única mejora que se podría hacer es usar un búffer de varios elementos y leer más bytes en una iteración.

