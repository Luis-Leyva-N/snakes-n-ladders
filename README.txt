Luis Omar Leyva Navarrete
A01570367

Para ejecutar el programa solo es necesario correr el archivo de main.cpp. Si el programa no corre despues de algunos usos es necesario cerrar y volver a abrir.

Debido a tiempo y otras tareas no pude encontrar la solucion de todo los errores.

---Probables Errores y como resolverlos---
Cuando se ejecute el programa no de enter cuando le pidan un dato si no ha puesto el dato ya que esto puede llevar a un error.

Algunas combinaciones de numeros de tablero no funcionan el error es mas comun entre mas grande sea el tablero o entre mas casillas 
especiales pongas y la cantidad de penalty o reward se la mayor.

Al ingrsar los nombres y claves de los jugadores puede que el juegue tenga un error una solucion es cerrarlo y volverlo a abrir. 
Solo sucede cuando se ingresan nombres despues no hay mas errores.

Si se requiere finalizar el juego a media partida es necesario darle 2 veces f para confirmar.

---Datos importantes---
El jugador ganador se decide como el primer jugador en lograr sobrepasar la ultima casilla.

La cantidad de casillas serpiente y escalera puede tener un error de +-2 debido a que el programa aleatorio no es realmente 
tan aleatorio y las restricciones usadas para no crear un loop infinito entre un serpiente y una escalera.

---Descripcion de el uso de lo aprendido en clase---
La herencia se presenta en casi todas las clases. y El poliformismo se presenta en las clase de las casillas y sus funciones.
Originalmente la clase jugadores heredaba directo a la clase tablero pero el programa no corria, la solución fue hacer que
herede directo a la clase tiles.

La sobrecarga de operadores se presenta en la clase de tablero se sustitulle la funcion de imprimir por la sobrecarga del 
operador <<, el cual pide como parametro el vector de la lista de jugadores. Tambien se presenta en la clase jugadores para poder hacer
el cambio de posicion del jugador.