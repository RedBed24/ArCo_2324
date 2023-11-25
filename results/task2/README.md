# Tarea 2
El código en src/task2/buffer.cpp debería representar el siguiente flujo:
1. Inicializar el buffer A
2. Sumar al valor de cada posición de A el índice de la iteración
3. Inicializar el buffer B Del mismo modo que A
4. Calcular B como resultado del valor de B multiplicado por A

## Comprueba el resultado y muéstralo a continuación

```
0
2
8
18
32
50
72
98
128
162
200
242
288
338
392
450
```

## ¿Qué abstracción se está usando para los contenedores de datos?

Accesos a búffers, el contendor es range con una dimensión, tamaño 16.

## ¿Cómo se está formando el DAG? ¿implicitamente? ¿explicitamente?

Implicíta, por el uso de accesos.

## Enumera todas las dependencias y el tipo de dependencias

- Kernel 2 y Kernel 1 RAW por buffer A.
  - En este caso, se indica que es sólo de lectura, por lo que podemos pensar que es WAW, pero la operación que se hace es `+=`, por lo que se lee.
- Kernel 4 y Kernel 2 RAW por buffer A.
- Kernel 4 y Kernel 3 RAW por buffer B.

----

# Task 2
Code in src/task2/buffer.cpp should represent the following flow:
1. Initialize buffer A
2. Add to each item in A the index of the iteration
3. Initialize buffer B the same way than A
4. Compute B as the result of B multiplied by A

## Check the result and show it below
**Answer here**

## Which abstraction is being used for data containers?
**Answer here**

## How is the DAG being built implicitly or explicitly?
**Answer here**

## Enumerate all dependencies and their types
**Answer here**
