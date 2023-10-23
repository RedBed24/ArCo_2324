# Tarea 4: Análisis de memoria y mejora vectorización

## Preguntas

* Compila de nuevo el programa complexmul.cpp **sin vectorizar** y genera un análisis de memoria marcando los bucles del cómputo que realizan la mutliplicación de números complejos, en concreto marca los bucles de las líneas 27 y 28 (si el análisis se demora mucho prueba a reducir el tamaño). Realiza el análisis tanto usando la interfaz gráfica de intel advisor como por línea de comandos. Además indica que comando es el que has usado para realizar el análisis por comando.

``` Bash
source ~/intel/oneapi/setvars.sh
icpx -fopenmp -g -O0 -o unvectorized src/complexmul.cpp
advisor --collect=survey --project-dir=./results/task4/analisis_no_vectorizado -- ./unvectorized
advisor --collect=map --mark-up-list=2,3 --project-dir=./results/task4/analisis_no_vectorizado -- ./unvectorized
```

Aunque advisor recomienda no usar `--mark-up-list` por lo que se ha generado también:

``` Bash
advisor --collect=map --append=src/complexmul.cpp:27,src/complexmul.cpp:28 --project-dir=./results/task4/analisis_no_vectorizado -- ./unvectorized
```

Todo esto se ha guardado en una [snapshot](map-unvectorized/).

* Abre advisor y selecciona la vista "Refinement Reports".
    * ¿Qué información nos proporciona esta vista? enumera cada elemento de la tabla resumiendo el significado
        - Localización
        - Loop-Carried Dependencies: Indica la presencia o ausencia de dependencias de diferentes tipos entre iteraciones.
        - Strides Distribution: Porcentajes de Stride de una Unidad / Constante / Variable para el bucle.
        - Patrón de acceso: Detectados en el bucle..
        - Footprint Estimate: Uso de memoria estimada.
        - Perfomance Issues: Recomendaciones para un análisis más intenso.
        - Cache Line Utilization: Líneas de caché usadas para operaciones de mover datos.
        - Memory Loads/Stores: Cargas de memoria en la primera instancia del bucle.
        - Cache Misses: Número de memory loads que se han hecho por una memoria superior. Calculado para la primera instancia del bucle.
        - RFO Cache Misses: Número de líneas de caché cargadas por una solicitud de escritura.
    * ¿Qué comportamiento de memoria se obtiene? ¿Por qué es deseable tener un stride uniforme?

Se accede de forma uniforme a la misma posición de memoria para variables como i, j, a, b y c.
Pero se tiene accesos de 2 en 2 en la memoria apuntada por a, b y c.

Es deseable tener un stride uniforme porque así somos capaces de determinar dónde realizaremos el siguiente acceso a memoria.
Además, si hacemos accesos a la misma posición de memoria, podremos cargar la caché y no tener que volver a cambiarla, evitándonos fallos y haciendo que la ejecución sea más rápida.

    * Mira el resultado del análisis de memoria de ambos bucles y comprueba que el stride es de 2.
        * ¿Por qué el stride tiene este valor? (Revisa los conceptos de row-order y column-order así como el orden en el que se reserva la memoria en C)
        
*Row-order* y *column-order* indican la forma de recorrer una matriz bidimensional, atendiendo a qué se itera primero.

La forma de representar las matrices en memoria es por grupos de filas con tantas posiciones como columnas.
Todo de forma contigua.

Reservamos memoria para $SIZE * 2$ floats de forma lineal organizados por parejas.
Al situarse en la memoria, de forma lineal, la posición i (suponiendo que dividimos la memoria por tamaños iguales a los del float), que cumple i % 2 == 0, es la parte real y la posición i+1 es la imaginaria.
Esto hace que cada vez que hagamos una iteración, avancemos una pareja de floats, es decir un número imaginario.
Por lo que el stride es 2.

        * ¿Sobre que variables se está accediendo con un stride de 2? ¿Cómo afecta esto a la caché?

Esto ocurre para los 3 vectores, sobre todo para el b que es el que más veces se recorre.
Esto nos lleva a que dividamos a la mitad el tiempo entre fallos de caché que si avanzásemos sólo una posición por iteración.
Tenemos fallos en caché de forma más frecuente.

        * ¿Se te ocurre algún modo de modificar el programa, manteniendo los dos bucles y el mismo resultado, para que
        el acceso a la variable sea uniforme? Realiza la modificación y almacena el resultado en esta misma carpeta con el nombre complexmul_unit_stride.cpp.
        
* Genera un snapshot para el análisis completo (hasta los patrones de acceso a memoria) tanto para la versión con un stride de 2 como para la versión con stride unitario (ambos vectorizando el código) y llámalos respectivamente "task4a" y "task4b", añádelos a esta misma carpeta. 
    * En "task4b" ¿Cuáles son los valores de la longitud del vector y la ganancia estimada? ¿Son los resultados que se esperaban? Justifica la respuesta.
    * Comparando estas dos soluciones ¿Cuánto ha aumentado la ganancia?

* Compara los resultados del análisis task2 y task4b:
    * ¿Cuál ha sido la ganancia real del algoritmo vectorizado? ¿Ha sido menor o mayor a la estimación?
