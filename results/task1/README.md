# Intro

Se ha decidido cambiar el formato de la salida de los archivos para que sea fácil comprobar si es correcto.
Para ello se han preparado unos programitas de python que se pueden ver en [la carpeta src](../../src), analizan esta salida.
Además, se ha cambiado la definición de `N` para que se pueda cambiar fácilmente mediante la herramienta `sed` y podamos hacer más fácil la comprobación de salida para diferentes valores.
Para ello se ha creado un Makefile que se encarga de ejecutar los comandos necesarios además de la limpieza de varios archivos.

Tambien había idea de crear un script que probase todos los ficheros con diferentes valores de entrada y guardase la salida para hacer comparaciones, pero por falta de tiempo no se ha hecho.

Ahora, con el trabajo como tal:

# Ideas para la mejora:

Realmente, podríamos no guardar nada en el vector y hacer todo en cada iteración:

- Generar
- Comparar y guardar, si procede
- Mostrar

Pero reducir todo a un for no cumple con la idea del ejericio, por lo que se proponen otras ideas:
Es necesario haber generado todo el vector para poder realizar las otras 2 tareas, pero ya que no interfieren entre sí, podemos hacer ambas a la vez.
Los cambios que se realizan durante las iteraciones son en las variables min y max y nos interesa que se termine de mostrar el vector para enseñar el min y max para no estropear el formato.

También es posible paralelizar cada parte:

## Generar

Realmente, la función `rand()` sigue un orden al generar aleatorios a partir de la semilla, pero no nos preocupamos de esto ya que usamos una semilla diferente en cada llamada.
Esto nos permite ignorar el orden de generación.

## Comparar

El orden de las comparaciones tambien da igual.
Pero sí debemos tener en cuenta el hecho de hacer que el min y max se reduzcan debidamente.

## Muestra

Al igual que al generar, nos da igual el orden ya que son todos aleatorios, por lo que podremos paralelizar este bucle.

# Comparaciones

En un principio se ha intentado usar advisor, pero nos hemos dado cuenta de que los ejecutables son demasiado rápidos y advisor no es capaz de recolectar información.
Por ello mismo, se ha decidido usar marcas de tiempo integradas en el código, de ahí el uso de `omp_get_wtime()`.
Estos tiempos serán los que se usen como referencias para comparar códigos.

Tras ver las ejecuciones con diferentes tamaños de entrada podemos observar:
Con la cantidad de procesadores usados, existe un empeoramiento al paralelizar.

Este empeoramiento viene del runtime que se añade al usar directivas de openmp.
El hecho de preparar los hilos y manejarlos es lo que hace que al final se gaste más tiempo.
De todas formas, a más hilos (mientras no superen la cantidad de cpus lógicas que se tengan) y más tamaño del problema, más terreno gana el usar directivas.

