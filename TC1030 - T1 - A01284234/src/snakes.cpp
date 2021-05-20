#include <iostream>
#include <time.h>
#include "MyGame.h"

using namespace std;


int main(void)
{
    // Esto hace que funcione la funcion de DiceRoll() en la clase Dice.
    srand(time(0));

    // Se crea un objeto g, que contiene el juego de serpientes y escaleras.
    MyGames g;

    // Método que corre el juego de la clase MyGames.
    g.start();
    return 0;
}
