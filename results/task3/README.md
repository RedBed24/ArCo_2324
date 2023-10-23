# Tarea 3: Vectorización

## Preguntas
* Antes de comenzar la vectorización es importante conocer cuáles son las características de tu máquina ¿Cuáles son las extensions multimedia SIMD con las que cuenta tu arquitectura?

Advisor indica que AVX2 la mayor ISA disponible para la máquina.

* Observa el análisis que has realizado al programa complexmul.cpp. El propio Intel Advisor debe haber detectado que hay una infrautilización de instrucciones, esto está directamente relacionado con la vectorización, ya que lo que pretende reflejar es que tienes disponibles las extensiones SIMD y no las estás utilizando. Para vectorizar el algoritmo, el propio programa Intel Advisor te aconseja como hacerlo ¿Qué has hecho para vectorizar el bucle? Ten en cuenta que debes vectorizar lo máximo que te permita tu arquitectura.

Recomienda usar `-xCORE-AVX2` al compilar.
Por lo que para compilar, usaremos:

``` Bash
icpx -fopenmp -g -O3 -xCORE-AVX2 -o vectorized src/complexmul.cpp
```

*Nótese el uso de la flag de optimizaciones para que verdaderamente se use la ISA especificada.*

* Una vez vectorizado el programa realiza un análisis y guárdalo con el nombre task3:
    * ¿Cual es el valor del campo Vector Length? ¿Es este el valor esperado teniendo en cuenta las extensiones que estás utilizando y que el programa utiliza floats de 32 bytes? Tanto si la respuesta es afirmativa como negativa justifica cual es el valor que esperabas.

[Link a la carpeta con la snapshot](task3/).

Hay dos valores, 4 y 8.
No es el valor esperado porque 32bits, o 4Bytes es el tamaño de los floats pero en nuestro programa se acceden de 2 en 2, real y entero, los cuales están juntos en memoria.

Se esperaban 8B ya que es cómo accedemos a los vectores, en cada iteración se acceden a 8B, 4 por una parte y otros 4 por otra.
En la siguiente iteración siguiente se acceden a los 8 siguientes, por esto se esperaba una longitud de 8.

    * ¿Cuál ha sido la ganancia? Explica si es el resultado esperado, si no lo es, explica cuál crees que es la razón (Pista: Intel Advisor puede darte indicios de cuál es el problema).

Advisor no indica la ganancia porque o no se ha usado el compilador de intel en una versión nueva o no existe información de debug, lo cual no es verdadero, se ha usado icpx con la flag -g.
Para calcular la ganancia se han pasado de 1.85s a 0.71s, por lo que al ver la relación: ${1.85 \over 0.71} = 260 \%$

De todas formas, Advisor sí es capaz de identificar patrones de accesos a memoria ineficientes y baja utilización de instrucciones FMA.
Para ver si esto es así, nos recomienda hacer análisis de MAP y de Dependencias.

