#include <iostream>
#include <time.h>
#include "MyGame.h"

using namespace std;


int main(void)
{
    // Esto hace que funcione la funcion de DiceRoll() en la clase Dice.
    srand(time(0));

    MyGames g;
    g.start();
    return 0;
}
