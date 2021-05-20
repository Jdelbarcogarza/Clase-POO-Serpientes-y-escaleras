INSTRUCCIONES PARA COMPILAR PROGRAMA

1. Dirigirse al subdirectorio src donde se encuentra el código fuente.
Utilize comando cd (change directory)

2. Abrir cmd en windows o terminal en mac/linux

3. Utilizando el compilador g++, pegar esta línea de código en 
terminal para compilar: g++ -o snakesGameA01284234 snakes.cpp

4. Para ejecutar programa escriba en una nueva línea lo siguiente:
(Windows): .\snakesGameA01284234.exe
(Mac/Linux): .\snakesGameA01284234

Justificación del programa y su diseño:

Toda la lógica del juego se lleva a cabo dentro de un while loop
que se rige por un único valor boleano. Esto lo decidí así porque 
es más facil, y lógico tener algo prendido que se pueda apagar con 
un simple comando. Así, muchas funciones pueden controlar un único valor de ser
necesario.

Dentro del while hay un if anidado. El if exterior maneja qué jugdor
está en turno en ese momento. El turno de los jugadores se da por 
una variable de turno que varía entre 1 y 2. En cada turno, se tira un dado
que arroja un número del 1 al 6. Con este dado, y la posición el jugador
en el tablero, se genera una nueva posición con una función miembro de la clase
MyGames. Creé esta función porque se iba a utilizar para ambos jugadores el mismo
código, simplemente cambiaban los parámetros. Ahora, el if dentro del ya mencionado
verifica si un jugador ya ha consegido tirar un número mayor a 30 o 30. Si este es el caso,
entonces se debe de verificar si en verdad a ganado el jugador 1 ó el jugador 2.

Al final, se imprimen los datos del turno que se acaba de tirar y 
ahora le toca al jugador 2 tirar el dado. Lo mismo se repite hasta que 
un jugador tire un número mayor o igual a 30. El número que se encuentre más cerca
del 30 cuando los dos jugadores tiren es el gaandor. Esto lo tomé así porque
me pareció que mantenía los juegos cortos para jugar de nuevo. Aunque bien se puede
cambiar en cualquier momento.

Algo muy importante en mi código creo que es el uso de funciones,
todo lo importante se lleva acabo en ellas, desde modificar la posición de los
jugadores en el tablero, hasta determinar quién gana el juego. Esto hace que el código
sea mantenible y se vea más limpio. Como planeo eficientarlo más, me es muy útil el tener todo
lo importante en un solo lugar, pues me permite realizar cambios más rápido.
