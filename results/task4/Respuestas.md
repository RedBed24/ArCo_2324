Es deseable tener un stride uniforme porque así somos capaces de determinar dónde realizaremos el siguiente acceso a memoria.

---

*Row-order* y *column-order* indican la forma de recorrer una matriz bidimensional, atendiendo a qué se itera primero.

La forma de representar las matrices en memoria es por grupos de filas con tantas posiciones como columnas.
Todo de forma contigua.

Reservamos memoria para $SIZE * 2$ floats de forma lineal organizados por parejas.
Al situarse en la memoria, de forma lineal, la posición i (suponiendo que dividimos la memoria por tamaños iguales a los del float), que cumple i % 2 == 0, es la parte real y la posición i+1 es la imaginaria.
Esto hace que cada vez que hagamos una iteración, avancemos una pareja de floats, es decir un número imaginario.
Por lo que el stride es 2.
Lo que nos lleva a que dividamos a la mitad el tiempo entre fallos de caché que si avanzásemos sólo una posición por iteración.
Esto ocurre para los 3 vectores, sobre todo para el b que es el que más veces se recorre.

Podemos mejorar esto si juntamos todas las partes reales y todas las partes imaginarias.
Lo podemos ver mejor como un par de vectores independientes en los que avanzamos una posición en cada vector en cada iteración.
La mejora que nos aporta esto es debido a ambos vectores se cargan en diferentes líneas de caché y sólo tenemos un stride de 1 en ambos vectores.

