# Laboratorio 1: Toma de contacto con el entorno
El objetivo de esta práctica es que os familiaricéis con las herramientas con las que trabajaremos durante los laboratorios
de la asignatura.

# Tareas
1. Compila y ejecuta el programa matmul.cpp guardando el resultado de ejecución en results/task1/task1.txt. Para realizar la
   compilación utiliza el compilador g++ y añade las opciones del compilador -g y -fopenmp. La opción -g añade información de depuración y es recomendable que la uséis siempre
   que vayáis a analizar el rendimiento de un programa con Intel Advisor. La opción -fopenmp enlaza las bibliotecas de OpenMP para programación paralela.
3. Realiza un análisis **con los tipos Survey y Characterization (Trip Counts y FLOP)** del programa en tu PC haciendo uso de la interfaz gráfica de Intel Advisor:
    * Una vez realizado el análisis, en la parte de arriba debería observarse un warning con el siguiente mensaje 
    *"Some target modules are not compiled with optmization enabled and with version 15.0 or higher of the Intel compiler"* ¿Qué es lo que indica
      este aviso? ¿Como solucionarías este problema de modo que el warning desaparezca (es posible que no se eliminen todos los warnings)? 
      (**pista**: tiene que ver con el compilador usado, revisa los compiladores que dispones con intel oneAPI, una vez encuentres el
      adecuado será el que **debas usar para todas las prácticas, incluidas las tareas restantes de esta prática**). Guarda los resultados del análisis
      con el warning realizando un snapshot de intel advisor (importante no confundir con una captura de pantalla) con el nombre **warning** en 
      [results/task2](results/task2).
    * Recompila el código con el compilador apropiado. Guarda los resultados del análisis sin el warning realizando un snapshot de intel advisor. 
    Este snapshot se debe subir al repositorio en [results/task2](results/task2) con el nombre **snapshot**.
4. Realiza el mismo tipo de análisis de la tarea 2 en el entorno devcloud (compílalo el código fuente con el **compilador que usaste en la tarea 2**). Si en la tarea anterior
   no pudiste ejecutar el análisis en tu ordenador, busca la manera de utilizar dos nodos con CPUs diferentes en devcloud.
    * Indica qué comandos has utilizado para obtener tanto los resultados como el snapshot
    * Los resultados del análisis (el snaphost) se debe subir al repositorio en [results/task3](results/task3) con el nombre **snapshot-devcloud**
5. Compara y **analiza** los resultados haciendo énfasis en las medidas de tiempo, rendimiento y memoria
    * El informe se debe subir a la carpeta [results/task4](results/task4) con el nombre comparacion.md
    * El informe tiene que estar en formato markdown
6. Identifica las características clave de los sistemas sobre los que has ejecutado los análisis (procesador, memoria, caché...)
y relaciónalos con los resultados analizados
    * El informe se debe subir a la carpeta [results/task5](results/task5) con el nombre caracteristicas.md

# Calificación
La calificación de la práctica se realizará en base a las siguientes rúbricas:
1. Completitud 40%: esto quiere decir que completar las tareas de manera simple te asegurará un 4. No es necesario
que los resultados estén bien, lo que sí es necesario es que se demuestre (mediante commits) que el trabajo si se ha realizado
de manera legítima.
2. Resultados correctos 30%: Si los resultados están bien y la práctica se ha realizado de manera legítima tendrás un 7.
3. Involucración 30%: Tu oportunidad de destacar, si te interesa el tema y lo demuestras mediante análisis detallados
referencias de calidad y pensamiento crítico en los análisis podrás alcanzar el 10. Recuerda que lo importante es pensar
más allá de lo inmediato, reflexionar sobre los resultados y hacerte preguntas. Una práctica que plantea preguntas es
un muy bien indicador de que estas yendo más allá de los resultados simples. Si además estas preguntas van
acompañadas de posibles respuestas entonces has hecho un trabajo perfecto.

# Participantes
**INDICA AQUÍ LOS PARTICIPANTES**

# Enlaces de utilidad
- [¿Cómo crear un snapshot?](https://www.intel.com/content/www/us/en/develop/documentation/advisor-user-guide/top/command-line-interface/advisor-command-line-interface-reference/advisor-command-action-reference/snapshot.html): Se recomienda usar el último comando
- [¿Cómo usar advisor en el cloud?](https://www.intel.com/content/www/us/en/develop/documentation/advisor-user-guide/top/command-line-interface/advisor-command-line-interface-reference.html)
- [Sintaxis markdown](https://guides.github.com/features/mastering-markdown/)
