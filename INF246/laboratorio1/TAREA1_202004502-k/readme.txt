Integrantes:

- Diego Paz Letelier, 202004502-K, paralelo 200

El archivo ordenar.c es el que cumple con la primera parte de la tarea, este
toma una carpeta (ya descomprimida) Archivos_Prueba y ordena los archivos de 
texto segun se indique en la ejecución. Nótese que el programa no devuelve los 
archivos a la carpeta Archivos_Prueba, por lo que para probar ambos ordenes hay 
que borrar las carpetas creadas y proporcionar una nueva carpeta Archivos_Prueba 
para que funcione.

El archivo mostrar.c es el que cumple con la segunda parte de la tarea, este lee
las carpetas y entrega por consola los datos, para que funcione correctamente hay
que entregarle cual fue el orden en el que se movieron los archivos con el archivo
anterior.

Para ejecutar los programas, hay que posicionar la terminal en el directorio donde se
encuentre el archivo makefile, luego escribir en la terminal el comando 'make',
que compilará ambos archivos, para ejecutarlos se debe llamarlos por la terminal
con los comandos './ordenar' y './mostrar' respectivamente.
