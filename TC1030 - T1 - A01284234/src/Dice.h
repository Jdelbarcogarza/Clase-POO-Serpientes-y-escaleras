
#include <stdlib.h>
#include <iostream>
using namespace std;


class Dice
{

    public:

        // Función que retorna un número del 1 al 6 que representa la cantidad de pasos que da el jugador
        int diceRoll()
        {
            int DiceNum = (rand() % 6) + 1;
            return DiceNum;
        }
};
