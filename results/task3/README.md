# Ideas para la mejora:

Para que sea más cómodo trabajar con este código, se ha decidido eliminar el pedir el dato al usuario y ponerlo como `TAMAÑO`, al igual que en los otros con objetivo de automatizar el proceso de recolección de datos.

Esta tarea es diferente a las anteriores, ahora sólo nos encontramos un bucle, pero este tiene un problema:
`xi` se calcula en cada iteración sumando el valor de la iteración anterior y `h`.
Esto supone un problema ya que para hacer la iteración $i$, debemos haber hecho antes la $i-1$, es decir, importa el orden.
Para resolver esto, tenemos que poder obtener `xi` sin depender de iteraciones "anteriores".
Lo importante es que, en cada iteración sumamos la misma cantidad, `h`.
Esto nos permite usar una multiplicación.

Una vez hecho esto, la paralelización es igual que en los casos anteriores.

# Comparaciones

En este caso, podemos observar muchas más diferencias.
El código paralelizado es capaz de superar al secuencial al aumentar el tamaño.
Pero nos damos cuenta de un problema:
El cálculo de pi difiere del secuencial.

No sabemos realmente porqué ocurre pero tenemos una suposición:
Problemas de representación para valores de punto flotante.
Hay ciertos valores que no son representables mediante doubles, en estos casos se hacen aproximaciones y suponemos que una acumulación de estas es lo que causa la discrepacia de resultados.
Esto realmente también ocurre en el secuencial, pero la diferencia con el paralelo sería al hacer una reducción, el sumar las _sub-sumas_ de cada hilo.

