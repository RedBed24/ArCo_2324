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

Primero se hará un análisis de survey para tener una primera impresión del tiempo de ejecución y dónde se gasta más tiempo para poder elegir unos bucles a analizar con las anotaciones.

## Problemas previos

Al compilar y ejecutar una primera vez, nos hemos dado cuenta de que advisor no es capaz de encontrar las flags de debug.
Esto es porque no se han especificado la flag `-g` al compilar, aunque el makefile cuenta con estas.
Si vemos qué órdenes se ejecutan al lanzar la regla `all` del makefile, vemos que se usa g++ sin algunas flags.

Si nos damos cuenta, la variable OBJS no contiene nada ya que ningún SRC termina en .c, debería ser .cpp
Lo mismo ocurre en la regla %.o

## Primer análisis

Una vez solucionado esto, sí que podemos realizar el survey.
Observamos que hay 2 bucles en el archivo "Main\_compressor\_HW.cpp" que se llevan todo el tiempo total:

1. Lectura de datos.
2. Bucle que itera los bloques.

No tiene sentido investigar la carga de los datos ya que `fread` asegura acceso único, por lo que si paralelizamos en hilos, realmente sólo uno estaría leyendo datos.
Tampoco tiene sentido usar vectorización porque no se usan vectores.
La única mejora que se podría hacer es usar un búffer de varios elementos y leer más bytes en una iteración.

Por lo que nos fijaremos más en el segundo.
Haremos anotaciones en este y otros bucles que tenga tras la llamada a la función `HyperLCA_transform`.
El bucle de creación de un bloque no tiene interés ya que es una copia, a lo sumo se podría usar `memcpy`.
La escritura en el archivo tampoco tiene mayor complicación, al igual que la lectura, se hace de forma exclusiva.

A primera vista, parece que este bucle es un buen candidato a hacer en varios hilos, no parece tener dependencias.
El "problema" sería la escritura en el archivo porque se hace de forma exclusiva, pero esto da igual ya que tarda un tiempo ínfimo.
Por lo que es muy probable que obtengamos una mejora de paralelizar por la llamada de `HyperLCA_transform`.

Dentro de `HyperLCA_transform` hay tres funciones, `brighness`, `proyectingImg` y `subtractingInformation` que consumen bastante tiempo.
Estas tienen un gran self time, es decir, es aquí donde el código pasa más tiempo.
Tendremos que analizarlo más intensamente.

## Uso de las anotaciones

Para encontrar el archivo: "advisor-annotate.h"

``` Bash
$ find intel/oneapi/ -iname "advisor-annotate.h"
intel/oneapi/advisor/latest/sdk/include/advisor-annotate.h
```

Aunque la documentación de intel recomienda usar la variable de entorno "ADVISOR\_2023\_DIR".

La flag `-Idir` del compilador indica qué directorios usar para buscar archivos de cabecera.

Como para poder usar las annotaciones, debemos hacer `#include <advisor-annotate.h>`, también debemos indicar el directorio donde este se encuentre, para esto tendremos que añadir las flags correspondientes de compilación.

Pero no sabemos dónde se encuentra el archivo compilado con las funciones de anotación.
Incluso aunque se busque igual que se hizo con el archivo de cabecera.

Se ha encontrado "advisor\_annotate.mod".

