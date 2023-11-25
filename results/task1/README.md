# Tarea 1
Familiarizarse con el uso de DPC.
En primer lugar copia el código de src/task1/query.cpp en results/task1/src y compilalo con dpcpp.

## ¿Qué salida obtienes?

Al compilar se obtienen muchas advertencias indicando obsolescencia.
Pero genera un ejecutable, al ejecutarlo se obtiene:

```
Device: Intel(R) Core(TM) i7-6700HQ CPU @ 2.60GHz
```

Muestra un *device*, la CPU junto a información sobre esta.

## ¿Qué tipos de selectores tenemos en DPC? ¿Podemos obtener una GPU? ¿Qué pasa si no existe el dispositivo requerido?

- `default_selector`, selecciona el dispositivo mediante una heurística
- `cpu_selector`
- `gpu_selector`
- `accelerator_selector`, que se refiere a la fpga
- `fpga_selector_v`, en caso de existir el hardware, definido en sycl/ext/intel/fpga\_extensions.hpp

Al usar `gpu_selector`, se obtiene:

```
Device: Intel(R) HD Graphics 530
```

Que es la gráfica integrada.

Para probar qué ocurre cuando no se dispone de una gráfica, se ha usado el devcloud sin pedir una gpu, el resultado está en la siguiente sección.

## Prueba a obtener una GPU desde devcloud modificando el programa query.cpp en gpu_query.cpp

```
terminate called after throwing an instance of 'sycl::_V1::runtime_error'
  what():  No device of requested type available. Please check https://software.intel.com/content/www/us/en/develop/articles/intel-oneapi-dpcpp-system-requirements.html -1 (PI_ERROR_DEVICE_NOT_FOUND)
Aborted
```

No se encuentra disponible el dispositivo pedido.

## ¿Cómo has obtenido la GPU? ¿Cómo has solicitado a qsub que quieres un nodo con GPU?

``` Bash
qsub -l nodes=1:gpu:ppn=2 -I
```

Que devuelve:

```
Device: Intel(R) UHD Graphics [0x9a60]
```

## Modifica el programa para obtener más datos del dispositivo.

![Código fuente](src/more_query.cpp)

------
# Task 1
Get familiar with Intel DPC compiler.
First copy the code in src/task1/query.cpp to results/task1/src and compile it with dpcpp.

## Which output do you obtain?
**Answer here**

## Which different types of selectors do we have in DPC? Can we obtain a GPU? What happens if the requested device doesn't exist?
**Asnwer here**

It is very likely that some of the devices that can be used with DPC are not available in your PC. Don't worry about that, since we can use devcloud for such purpose.

## Try to obtain a GPU from devcloud by the query.cpp program into gpu_query.cpp
**store the resulting file in results/task1/src.**

## How did you obtained the GPU? How have you requested qsub that you want a node with a GPU?
**Answer here**

## Modify the program to obtain more data from the device.
**store the resulting file in results/task1/src/more_query.cpp**
