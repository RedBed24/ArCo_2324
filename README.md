# Objetivos
Familiarizarse con OpenMP mediante la realización de ejercicios tipo.

# Calificación
Se recomienda realizar esta tarea individualmente para asentar los conocimientos sobre OpenMP. La práctica se valorará en función del 
grado de realización, es decir, si se han hecho o no los diferentes ejercicios.
Esta prueba debe valer para mejorar el conocimiento sobre OpenMP de cara a los siguientes laboratorios y al cuestionario.

# Comparación y Análisis
En cada uno de los ejercicios se va a preguntar que se comparen los tiempos distintas de las soluciones planteadas, para ello es importante 
que se tenga claro que se considera una solución. Para empezar una solución será considerada como todo aquel programa que esté paralelizado y 
cuyo resultado sea el mismo que el del programa secuencial, si por ejemplo paralelizamos un programa que calcule el número mayor de una serie
de números y el número mayor obtenido no es el mismo que el de su versión secuencial significaría que la paralelización se ha realizado de forma errónea.

A la hora de comparar soluciones hay una serie de variables que pueden modificar el tiempo que tarda en ejecutarse el programa, estas son las
siguientes:
- Número de hilos usados
- Directivas usadas (siempre que puedan usarse en el problema, no todas las directivas son aplicables en todos los casos)
- Reparto del trabajo

Para que la tarea de comparación no sea excesivamente costosa, dado que puede llegar a haber una gran cantidad de combinaciones, es recomendable
centrarse en una única variable de las comentadas anteriormente, por ejemplo, comparar primero todas las directivas y una vez que sabemos
que directiva funciona mejor, pasar a observar que ocurre si cambiamos el número de hilos usados. Los cambios en el reparto de trabajo se recomienda estudiarlos al final, dado que implican menor impacto que las otras dos variables.

Para realizar la comparación de tiempo es recomendable hacer uso de una tabla, donde los resultados sean observables de un vistazo y a continuación
explicar las conclusiones que se obtienen de los mismos.

# Ejercicio 1
Desarrollar un programa secuencial que obtenga el mayor y el menor de los componentes de un vector.
A continuación, paralelizar el programa anterior usando las diferentes directivas de OpenMP que se ajusten al problema así como modificando
el número de hilos.
Analizar y comparar los tiempos de las diferentes soluciones que propongas para resolver el problema, así como el de la solución secuencial.
Con el fin de realizar estos análisis se recomienda que se realice una tabla, indicando la directiva usada, el número de hilos y el tiempo que
ha tardado dicha solución.

Realiza los cambios en results/task1/ ahí puedes crear un README.md con los análisis y guardar los diferentes códigos fuente.

# Ejercicio 2
Paraleliza el código [sumavector.cpp](src/sumavector.cpp) mediante OpenMP. Puedes proponer varias soluciones con distintas directivas.
Analiza y compara los resultados obtenidos en cada uno de ellos usando una tabla donde indiques tipo de solución.

Realiza los cambios en el código fuente en results/task2/ ahí puedes crear un README.md con los análisis y guardar las soluciones propuestas.

# Ejercicio 3
Paraleliza el código [pi.cpp](src/pi.cpp) mediante OpenMP. Puedes proponer varias soluciones.
Analiza y compara los resultados obtenidos en cada uno de ellos.
Es posible que para poder paralelizar correctamente debas realizar algún cambio en el propio algoritmo debido a dependencias entre iteraciones del bucle.

Realiza los cambios en el código fuente en results/task3/ ahí puedes crear un README.md con los análisis y guardar las soluciones propuestas.
