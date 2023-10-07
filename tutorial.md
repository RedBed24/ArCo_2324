# Tarea 1

## Obtener el repositorio

### Clonar mediante ssh

Se necesita haber creado una clave ssh.
Para ello hay un [manual de github](https://docs.github.com/en/authentication/connecting-to-github-with-ssh).

``` Bash
$ git clone git@github.com:ASIGNATURA-ARCO-UCLM/lab1-samuel-espejo_noelia-diaz-alejo.git
```

### Clonar mediante https

Tendrás que poner el token.
Se puede crear uno desde las [configuraciones](https://github.com/settings/tokens).

``` Bash
$ git clone https://github.com/ASIGNATURA-ARCO-UCLM/lab1-samuel-espejo_noelia-diaz-alejo
```

---

Una vez lo tenemos clonado, tendremos que acceder a él.
Más exactamente, a donde se [encuentra el código](src/).

``` Bash
$ cd lab1-samuel-espejo_noelia-diaz-alejo/src
```

Ahora lo compilaremos mediante `g++` ya que es un archivo de código fuente de C++.
Usaremos las flags de debug (`-g`) y otra para usar directivas de OpenMP (`-fopenmp`).
Especificaremos un nombre de ejecutable mediante `-o nombre`.
Entonces, la orden a usar sería:

``` Bash
$ g++ -o executable -g -fopenmp matmul.cpp
```

Ahora, tenemos un archivo ejecutable llamado executable.
Ejecutaremos este y guardaremos su salida en la [carpeta correspondiente](results/task1/).
Esta salida se guardará en un archivo txt llamado [task1.txt](results/task1/task1.txt).
Para ello usaremos la redirección (`>`).

``` Bash
$ ./executable > ../results/task1/task1.txt
```

# Tarea 2

Para acceder a la aplicación Advisor, es necesario poner las variables de entorno de intel.

``` Bash
$ source intel/oneapi/setvars.sh
```

*Esta orden supone que la instalación de intel se encuentra en el directorio actual.
Si no es así, habría que dirigise a esta.*

Ahora, podremos ejecutar el entorno gráfico mediante `advisor-gui`.
Esto nos abrirá la aplicación, donde podremos crear un nuevo proyecto seleccionando el [ejecutable que acabamos de compilar](src/executable).

Una vez creado, seleccionaremos los análisis a realizar:

- Survey
- Characterization
  - Trip Counts
  - FLOP

Ahora, podremos ejecutar el análisis pulsando sobre el botón azul con la flecha.

El warning indica que algunos módulos (en este caso, el [único que tenemos](src/matmul.cpp)) no han sido compilados con optimizaciones ni con una versión del compilador de Intel.
Para solucionar esto, es necesario usar el compilador Intel, en vez de g++.

Ahora crearemos el snapshot y moveremos la carpeta de este a la [tarea 2](results/task2/).
El nombre es warning y este es una carpeta en el workspace seleccionado en la creación del proyecto.

Para saber qué compilador debemos usar, podemos rebuscar en las carpetas de intel por ejecutables y buscar algo como "cpp" (C++).
Observamos dpcpp y al ver su manual nos indica que es el compilador de intel.

Al recompilar el código con el compilador apropiado:

``` Bash
$ dpcpp -g -fopenmp matmul.cpp -o executable
```

Observamos una nota:
*"icpx: remark: Note that use of `-g` without any optimization-level option will turn off most compiler optimizations similar to use of `-O0`; use `-Rno-debug-disables-optimization` to disable this remark [-Rdebug-disables-optimization]"*.
Esta indica que al usar la flag `-g`, se deshabilitan las optimizaciones.
Cosa que queremos ya que el primer ejecutable tampoco contaba con estas.
Si vemos el manual de g++, `-O0` se usa por defecto, es decir, sin optimizaciones.
Para poder hacer una comparación correcta, ambos deben contar con la misma cantidad de optimizaciones.

Ejecutamos de nuevo con los mismos análisis y creamos otro snapshot que guaradaremos en [tarea 2](results/task2).

Analizando un poco las snapshots, las cuales podemos abrir como si fuese un proyecto en advisor.
Nos damos cuenta de que la ejecución del compilado con dpcpp tardó considerablemente más tiempo que la primera, 0.48s frente a 0.19s, aunque hayan sido ejecutados en el mismo ordenador.
Es posible que no fuese en las mismas condiciones ya que se tiene en uso una configuración para que el ordenador se ponga en modo ahorro de energía y por ende, baje el rendimiento dependiendo de si está enchufado a corriente o no.
Para comprobar si esto es así, se han vuelto a realizar los análisis asegurando que la configuración antes mencionada no sea una variable.
Tienen el mismo nombre pero con un 2 al final.

Tras ver los tiempos, nos damos cuenta que no hay diferencias entre usar un compilador u otro.
Todos los parámetros del resumen son lo suficientemente parecidos como para asumir que los cambios son producidos por otros factores como el scheduler del OS.

