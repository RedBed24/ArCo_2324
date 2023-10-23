# Tarea 2: Roofline
## Preguntas
1. Genera un roofline y analiza la información representada. Copia una captura del roofline en la respuesta
para apoyar tu análisis. Finalmente genera un snapshot con el nombre "task2" y añádelo a esta misma carpeta.

Roofline nos permite modelar la línea de techo de rendimiento de un sistema en función de la intensidad aritmética.
Está se representa a través de un gráfico donde el eje X representa la intensidad aritmética y el eje Y el rendimiento.

En la siguiente imagen, podemos distinguir tres zonas: una clara, otra intermedia y una más oscura. Dependiendo de la zona en la que estemos el cuello de botella será uno u otro. En la zona clara, la CPU no para de generar datos, y la memoria no puede seguir el ritmo. Por lo tanto el cuello de botella es la memoria. En la zona oscura, la CPU no es capaz de generar datos. Por lo que el cuello de botella es la CPU. Por último, en la zona intermedia no sabemos con exactitud quién puede ser el cuello de botella. 
El punto rojo representa el bucle del main. Se encuentra en la zona intermedia. Como está más a la izquierda, suponemos que es la memoria, pero no podemos asegurarlo. El bucle está vinculado a la memoria, pero también puede estar vinculado a la CPU. Como hemos supuesto que es la memoria, el rendimiento del bucle se puede mejorar mediante la optimización de la memoria. Cualquier optimización que hagamos puede cambiar el rendimientiento pero no la intensidad aritmética.

También aparecen varias líneas que representan las límitaciones del hardware de nuestro sistema: rendimiento máximo de la CPU para diferentes tipos de operaciones, restrincciones del ancho de banda de diferentes niveles de caché, etc


2. ¿Por qué está limitado el algoritmo? ¿Qué técnicas podríamos aplicar para mejorar el rendimiento?

Como dijimos anteriormente, se encuentra limitado por la memoria. Para solucionarlo es necesario vectorizar el bucle.
